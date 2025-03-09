#pragma once

#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdio.h>
#pragma comment(lib, "Ws2_32.lib")

#include "../Logging/DDLogger.h"
	
class DDServer
{
private:
	WSADATA wsaData;
	DDLogger& logger;

public:
	DDServer(DDLogger& logger);
	~DDServer();

public:
	bool Init();
};

