#include "ServerSocket.h"

ServerSocket::ServerSocket(DDLogger& logger) : logger(logger)
{
    listenSocket = INVALID_SOCKET;
    ZeroMemory(&socketSettings, sizeof(socketSettings));
    socketSettings.ai_family = AF_INET;
    socketSettings.ai_socktype = SOCK_STREAM;
    socketSettings.ai_protocol = IPPROTO_TCP;
}
ServerSocket::~ServerSocket()
{
    CloseSocket();
}

bool ServerSocket::BindAndListen(const char* port, int backlog)
{
    logger.LogInfo("Initializing server socket...");

    addrinfo* addressInfo = nullptr;
    if (getaddrinfo(NULL, port, &socketSettings, &addressInfo) != 0)
    {
        logger.LogInfo("getaddrinfo failed");
        return false;
    }

    listenSocket = socket(addressInfo->ai_family, addressInfo->ai_socktype, addressInfo->ai_protocol);
    if (listenSocket == INVALID_SOCKET)
    {
        logger.LogInfo("Socket creation failed.");
        freeaddrinfo(addressInfo);
        return false;
    }

    if (bind(listenSocket, addressInfo->ai_addr, (int)addressInfo->ai_addrlen) == SOCKET_ERROR)
    {
        logger.LogInfo("Bind failed.");
        freeaddrinfo(addressInfo);
        closesocket(listenSocket);
        return false;
    }

    freeaddrinfo(addressInfo);

    if (listen(listenSocket, backlog) == SOCKET_ERROR)
    {
        logger.LogInfo("Listen failed.");
        closesocket(listenSocket);
        return false;
    }

    logger.LogInfo("Server socket is now listening");
    return true;
}

SOCKET ServerSocket::AcceptConnection()
{
    SOCKET clientSocket = accept(listenSocket, NULL, NULL);
    if (clientSocket == INVALID_SOCKET)
    {
        logger.LogInfo("Failed to accept client connection.");
        return INVALID_SOCKET;
    }

    logger.LogInfo("Client connected!");
    return clientSocket;
}

void ServerSocket::CloseSocket()
{
    if (listenSocket != INVALID_SOCKET)
    {
        closesocket(listenSocket);
        listenSocket = INVALID_SOCKET;
        logger.LogInfo("Socket closed.");
    }
}