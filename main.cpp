#include "Core/DDDatabase.h"
#include "Services/Logging/DDLogger.h"

int main()
{
	DDLogger logger = {};
	DDDatabase DatabaseInstance(logger);
	if (DatabaseInstance.Init())
	{
		DatabaseInstance.Run();
	}

	return 0;
}