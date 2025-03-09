#include "DDServer.h"

DDServer::DDServer(DDLogger& logger) : logger(logger), serverSocket(logger), wsaData()
{
}

DDServer::~DDServer()
{
	WSACleanup();
}

bool DDServer::Init()
{
	int result = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (result != 0)
	{
		logger.LogError("Server initialization failed");
		return false;		
	}

	logger.LogInfo("Server initialized");
	return true;
}

void DDServer::WaitForConnection(DDString portToListenOn)
{
    if (serverSocket.BindAndListen("8080"))
    {
        while (true)
        {
            SOCKET client = serverSocket.AcceptConnection();
            if (client != INVALID_SOCKET)
            {
                logger.LogInfo("New client connection established.");
                closesocket(client);
            }
        }
    }
}
