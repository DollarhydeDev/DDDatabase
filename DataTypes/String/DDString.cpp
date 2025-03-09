#include "DDString.h"

DDString::DDString()
{
	bufferSize = 0;
	bufferCapacity = 10;
	PerformSafetyChecks();

	buffer = new char[bufferCapacity];
	buffer[bufferSize] = '\0';
}
DDString::DDString(char* inBuffer)
{
	if (!inBuffer)
	{
		bufferSize = 0;
		bufferCapacity = 10;
		PerformSafetyChecks();

		buffer = new char[bufferCapacity];
		buffer[0] = '\0';
		return;
	}

	bufferSize = 0;
	while (inBuffer[bufferSize] != '\0') bufferSize++;

	bufferCapacity = bufferSize + 1;
	PerformSafetyChecks();

	char* newBuffer = new char[bufferCapacity];
	buffer = BufferCopy(newBuffer, inBuffer, bufferSize);
}
DDString::DDString(const char* inBuffer)
{
	if (!inBuffer)
	{
		bufferSize = 0;
		bufferCapacity = 10;
		PerformSafetyChecks();

		buffer = new char[bufferCapacity];
		buffer[0] = '\0';
		return;
	}

	bufferSize = 0;
	while (inBuffer[bufferSize] != '\0') bufferSize++;

	bufferCapacity = bufferSize + 1;
	PerformSafetyChecks();

	char* newBuffer = new char[bufferCapacity];
	buffer = BufferCopy(newBuffer, inBuffer, bufferSize);
}
DDString::DDString(const DDString& otherString)
{
	bufferSize = otherString.bufferSize;
	bufferCapacity = otherString.bufferCapacity;
	PerformSafetyChecks();

	char* newBuffer = new char[bufferCapacity];
	buffer = BufferCopy(newBuffer, otherString.buffer, bufferSize);
}
DDString::DDString(DDString&& otherString) noexcept
{
	bufferSize = otherString.bufferSize;
	bufferCapacity = otherString.bufferCapacity;
	PerformSafetyChecks();

	buffer = otherString.buffer;
	buffer[bufferSize] = '\0';

	otherString.bufferSize = 0;
	otherString.bufferCapacity = 0;
	otherString.buffer = nullptr;
}
DDString::~DDString()
{
	if (buffer)
	{
		delete[] buffer;
		buffer = nullptr;
	}

	bufferSize = 0;
	bufferCapacity = 0;
}

void DDString::PerformSafetyChecks()
{
	if (bufferSize > bufferCapacity)
	{
		int resizeAmount = (bufferSize - bufferCapacity) + 1;
		IncreaseBufferSize(resizeAmount);
	}
}

void DDString::IncreaseBufferSize(int increaseAmount)
{
	bufferCapacity += increaseAmount;

	char* newBuffer = new char[bufferCapacity];
	bool deleteSourceBuffer = true;
	buffer = BufferCopy(newBuffer, buffer, bufferSize, deleteSourceBuffer);
}
char* DDString::BufferCopy(char* destBuffer, char* sourceBuffer, const int sourceBufferSize, const bool deleteSourceBuffer)
{
	std::memcpy(destBuffer, sourceBuffer, sourceBufferSize);
	destBuffer[sourceBufferSize] = '\0';

	if (deleteSourceBuffer)
	{
		delete[] sourceBuffer;
	}

	return destBuffer;
}
char* DDString::BufferCopy(char* destBuffer, const char* sourceBuffer, int sourceBufferSize)
{
	std::memcpy(destBuffer, sourceBuffer, sourceBufferSize);
	destBuffer[sourceBufferSize] = '\0';

	return destBuffer;
}
