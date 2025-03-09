#pragma once

#include "../../DataTypes/String/DDString.h"

class DDLogger
{
private:
	DDString infoPrefix;

public:
	DDLogger();

	void LogInfo(DDString message);
	void LogInfo(const char* message);
};

