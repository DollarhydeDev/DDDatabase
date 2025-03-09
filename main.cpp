#include "Core/DDDatabase.h"
#include "Services/Logging/DDLogger.h"
#include "Services/Networking/Server/DDServer.h"

int main()
{
	// Setup dependencies
	DDLogger logger{};
	DDServer server{ logger };

	// Launch new DB instance with dependencies
	DDDatabase DatabaseInstance(logger, server);
	{
		if (!DatabaseInstance.Init()) return 1;
		DatabaseInstance.Run();
	}

	return 0;
}