#pragma once

#include "List/DDList.h"
#include "Logging/DDLogger.h"
#include "Server/DDServer.h"

class DDDatabase
{
	// Members
private:
	DDServer& _server;
	DDLogger& _logger;

	// Constructors
public:
	DDDatabase();
	~DDDatabase();

	// Private Functions
private:

	// Public functions
public:
	bool Init();
	void Run();
};

