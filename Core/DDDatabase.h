#pragma once

#include "../Services/Logging/DDLogger.h"
#include "../Services/Networking/Server/DDServer.h"

class DDDatabase
{
	// Members
private:
	DDServer& server;
	DDLogger& logger;

	// Constructors
public:
	DDDatabase(DDLogger& logger, DDServer& server);
	~DDDatabase();

	// Private Functions
private:

	// Public functions
public:
	bool Init();
	void Run();
};

