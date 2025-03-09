#pragma once

#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdio.h>
#pragma comment(lib, "Ws2_32.lib")

#include "../../Logging/DDLogger.h"
#include "../Sockets/ServerSocket/ServerSocket.h"
	
class DDServer
{
private:
	WSADATA wsaData;
	DDLogger& logger;
	ServerSocket serverSocket;

public:
	DDServer(DDLogger& logger);
	~DDServer();

public:
	bool Init();
	void WaitForConnection(DDString portToListenOn);
};

