#pragma once

#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdio.h>
#pragma comment(lib, "Ws2_32.lib")

#include "List/DDList.h"
#include "Logging/DDLogger.h"
#include "ServerSocket/DDServerSocket.h"

#include "DatabaseActions/DDDatabaseQuery.h"

class DDServer
{
	// Members
private:
	WSADATA _wsaData;
	DDLogger& _logger;
	DDServerSocket _serverSocket;

	// Constructors
public:
	DDServer();
	~DDServer();

	// Private Functions
private:
	DDDatabaseQuery ParseRequest(const char* requestData);
	void SendResponse(SOCKET client);

	// Public functions
public:
	static DDServer& GetInstance();

	bool Init();
	DDDatabaseQuery WaitForRequest(DDString portToListenOn);
};