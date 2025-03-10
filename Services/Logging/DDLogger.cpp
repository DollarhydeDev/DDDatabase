#include "DDLogger.h"

DDLogger::DDLogger()
{
	infoPrefix = "[INFO] ";
	errorPrefix = "[ERROR] ";
}

DDLogger& DDLogger::GetInstance()
{
	static DDLogger instance;
	return instance;
}

void DDLogger::LogInfo(DDString message)
{
	std::cout << infoPrefix << message << std::endl;
}
void DDLogger::LogInfo(const char* message)
{
	std::cout << infoPrefix << message << std::endl;
}

void DDLogger::LogError(DDString message)
{
	std::cout << errorPrefix << message << std::endl;
}
void DDLogger::LogError(const char* message)
{
	std::cout << errorPrefix << message << std::endl;
}
