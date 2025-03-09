#include "DDDatabase.h"

DDDatabase::DDDatabase(DDLogger& logger, DDServer& server) : logger(logger), server(server)
{
}

DDDatabase::~DDDatabase()
{
	logger.LogInfo("Database cleaning up...");
	logger.LogInfo("Cleanup finished");
}

bool DDDatabase::Init()
{
	logger.LogInfo("Database initializing...");
	if (!server.Init())
	{
		logger.LogError("Database failed to initialize");
		return false;
	}

	logger.LogInfo("Database initialized");
	return true;
}

void DDDatabase::Run()
{
	logger.LogInfo("Database started");
}
