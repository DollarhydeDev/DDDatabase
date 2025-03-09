#include "DDDatabase.h"

DDDatabase::DDDatabase()
{
	wsaData = {};
	logger = {};
}

DDDatabase::~DDDatabase()
{
	logger.LogInfo("Database cleaning up...");
	WSACleanup();
	logger.LogInfo("Cleanup finished");
}

bool DDDatabase::Init()
{
	logger.LogInfo("Database initializing...");

	int result = WSAStartup(MAKEWORD(2, 2), &wsaData);
	return result == 0 ? true : false;
}

void DDDatabase::Run()
{
	logger.LogInfo("Database started");
}
