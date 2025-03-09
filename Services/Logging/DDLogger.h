#pragma once

#include "../../DataTypes/String/DDString.h"

class DDLogger
{
private:


public:
	DDLogger();

	void LogInfo(DDString message);
	void LogInfo(const char* message);
};

