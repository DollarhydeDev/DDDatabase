#pragma once

#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdio.h>

#include "../Services/Logging/DDLogger.h"

#pragma comment(lib, "Ws2_32.lib")

class DDDatabase
{
	// Members
private:
	WSADATA wsaData;
	DDLogger logger;

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

