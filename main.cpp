#include "Core/DDDatabase.h"

int main()
{
	// Launch new DB instance
	DDDatabase databaseInstance;
	{
		if (!databaseInstance.Init()) return 1;
		databaseInstance.Run();
	}

	return 0;
}