#include "DDDatabase.h"

DDDatabase::DDDatabase(DDLogger& logger)
{
	this->logger = logger;
}

DDDatabase::~DDDatabase()
{
	logger.LogInfo("Database cleaning up...");
	logger.LogInfo("Cleanup finished");
}

bool DDDatabase::Init()
{
	logger.LogInfo("Database initializing...");
	logger.LogInfo("Database initialized");
}

void DDDatabase::Run()
{
	logger.LogInfo("Database started");
}
