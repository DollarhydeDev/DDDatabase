#pragma once

#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdio.h>
#pragma comment(lib, "Ws2_32.lib")

#include "../../../DataTypes/List/DDList.h"
#include "../../Logging/DDLogger.h"
#include "../Sockets/ServerSocket/ServerSocket.h"

class DDServer
{
private:
	WSADATA _wsaData;
	DDLogger& _logger;
	DDList<ServerSocket> _serverSockets;

public:
	DDServer();
	~DDServer();

	static DDServer& GetInstance();

public:
	bool Init();
	void WaitForConnection(DDString portToListenOn);
};

