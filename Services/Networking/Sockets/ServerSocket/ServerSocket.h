#pragma once

#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdio.h>
#pragma comment(lib, "Ws2_32.lib")

#include "Logging/DDLogger.h"

class ServerSocket
{
	// Members
private:
	DDLogger& _logger;
	addrinfo _socketSettings;
	SOCKET _listenSocket;

	// Constructors
public:
	ServerSocket();
	~ServerSocket();

private:
	

public:
	bool BindAndListen(const char* port, int backlog = SOMAXCONN);
	SOCKET AcceptConnection();

	void CloseSocket();
};

