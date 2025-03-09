#pragma once

#include "../Services/Logging/DDLogger.h"

class DDDatabase
{
	// Members
private:
	DDLogger& logger;

	// Constructors
public:
	DDDatabase(DDLogger& logger);
	~DDDatabase();

	// Private Functions
private:

	// Public functions
public:
	bool Init();
	void Run();


};

