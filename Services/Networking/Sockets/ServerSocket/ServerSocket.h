#pragma once

#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdio.h>
#pragma comment(lib, "Ws2_32.lib")

#include "../../../Logging/DDLogger.h"

class ServerSocket
{
	// Members
private:
	DDLogger& logger;
	addrinfo socketSettings;
	SOCKET listenSocket;

	// Constructors
public:
	ServerSocket(DDLogger& logger);
	~ServerSocket();

private:
	

public:
	bool BindAndListen(const char* port, int backlog = SOMAXCONN);
	SOCKET AcceptConnection();

	void CloseSocket();
};

