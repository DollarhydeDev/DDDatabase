#include "DDLogger.h"

DDLogger::DDLogger()
{
	infoPrefix = "[INFO] ";
}

void DDLogger::LogInfo(DDString message)
{
	std::cout << infoPrefix << message << std::endl;
}
void DDLogger::LogInfo(const char* message)
{
	std::cout << infoPrefix << message << std::endl;
}
