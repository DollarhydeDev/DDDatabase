#include "DDDatabase.h"

DDDatabase::DDDatabase() : _server(DDServer::GetInstance()), _logger(DDLogger::GetInstance())
{
}

DDDatabase::~DDDatabase()
{
	_logger.LogInfo("Database cleaning up...");
	_logger.LogInfo("Cleanup finished");
}

bool DDDatabase::Init()
{
	_logger.LogInfo("Database initializing...");
	if (!_server.Init())
	{
		_logger.LogError("Database failed to initialize");
		return false;
	}

	_logger.LogInfo("Database initialized");
	return true;
}

void DDDatabase::Run()
{
	_logger.LogInfo("Database started");
	//server.WaitForConnection("8000");
}
