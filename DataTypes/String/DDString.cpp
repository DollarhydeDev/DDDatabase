#include "DDString.h"

DDString::DDString()
{
	bufferSize = 0;
	bufferCapacity = 10;

	buffer = new char[bufferCapacity];
	buffer[bufferSize] = 0x00;
}
DDString::DDString(char* inBuffer)
{
	if (!inBuffer)
	{
		bufferSize = 0;
		bufferCapacity = 10;

		buffer = new char[bufferCapacity];
		buffer[bufferSize] = 0x00;
		return;
	}

	bufferSize = 0;
	while (inBuffer[bufferSize] != 0x00) bufferSize++;
	bufferCapacity = bufferSize + 1;

	buffer = new char[bufferCapacity];
	memcpy(buffer, inBuffer, bufferSize);
	buffer[bufferSize] = 0x00;
}
DDString::DDString(const char* inBuffer)
{
	if (!inBuffer)
	{
		bufferSize = 0;
		bufferCapacity = 10;

		buffer = new char[bufferCapacity];
		buffer[bufferSize] = 0x00;
		return;
	}

	bufferSize = 0;
	while (inBuffer[bufferSize] != 0x00) bufferSize++;
	bufferCapacity = bufferSize + 1;

	buffer = new char[bufferCapacity];
	memcpy(buffer, inBuffer, bufferSize);
	buffer[bufferSize] = 0x00;
}
DDString::DDString(const DDString& otherString)
{
	if (!otherString.buffer || otherString.bufferSize <= 0)
	{
		bufferSize = 0;
		bufferCapacity = 10;

		buffer = new char[bufferCapacity];
		buffer[bufferSize] = 0x00;
		return;
	}

	bufferSize = otherString.bufferSize;
	bufferCapacity = (bufferSize >= otherString.bufferCapacity) ? (bufferSize + 1) : otherString.bufferCapacity;
	buffer = new char[bufferCapacity];

	memcpy(buffer, otherString.buffer, bufferSize);
	buffer[bufferSize] = 0x00;
}
DDString::DDString(DDString&& otherString) noexcept
{
	buffer = otherString.buffer;
	bufferSize = otherString.bufferSize;
	bufferCapacity = otherString.bufferCapacity;

	otherString.buffer = nullptr;
	otherString.bufferSize = 0;
	otherString.bufferCapacity = 0;
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

void DDString::IncreaseBufferSize(int increaseAmount)
{
	bufferCapacity += increaseAmount;
	char* newBuffer = new char[bufferCapacity];

	if (buffer)
	{
		memcpy(newBuffer, buffer, bufferSize);
		delete[] buffer;
	}

	buffer = newBuffer;
	buffer[bufferSize] = 0x00;
}