#include "Core/DDDatabase.h"

int main()
{
	DDDatabase DatabaseInstance;
	if (DatabaseInstance.Init())
	{
		DatabaseInstance.Run();
	}

	return 0;
}