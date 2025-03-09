#include "DDServer.h"

DDServer::DDServer(DDLogger& logger)
{
	wsaData = {};
	this->logger = logger;
}

DDServer::~DDServer()
{
	WSACleanup();
}

bool DDServer::Init()
{
	int result = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (result == 0)
	{
		logger.LogInfo("Database initialized");
	}
	else
	{
		logger.LogInfo("Database initialization failed");
	}
}
