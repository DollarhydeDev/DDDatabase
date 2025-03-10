#include "DDServer.h"

DDServer::DDServer() : _logger(DDLogger::GetInstance())
{
    _wsaData = {};
}
DDServer::~DDServer()
{
	WSACleanup();
}

DDServer& DDServer::GetInstance()
{
    static DDServer instance;
    return instance;
}

bool DDServer::Init()
{
	int result = WSAStartup(MAKEWORD(2, 2), &_wsaData);
	if (result != 0)
	{
		_logger.LogError("Server initialization failed");
		return false;		
	}

	_logger.LogInfo("Server initialized");
	return true;
}

void DDServer::WaitForConnection(DDString portToListenOn)
{
    ServerSocket serverSocket = _serverSockets.Data()[0];

    if (serverSocket.BindAndListen(portToListenOn.Data()))
    {
        while (true)
        {
            SOCKET client = serverSocket.AcceptConnection();
            if (client != INVALID_SOCKET)
            {
                _logger.LogInfo("New client connection established.");
                closesocket(client);
            }
        }
    }
}
