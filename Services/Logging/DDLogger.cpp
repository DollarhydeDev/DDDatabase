#include "DDLogger.h"

DDLogger::DDLogger()
{

}

void DDLogger::LogInfo(DDString message)
{
	std::cout << message << std::endl;
}
void DDLogger::LogInfo(const char* message)
{
	std::cout << message << std::endl;
}
