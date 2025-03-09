#pragma once

#include <iostream>

class DDString
{
private:
	char* buffer;
	int bufferSize;
	int bufferCapacity;

public:
	// Default constructor
	DDString();

	// Parameterized constructor
	DDString(char* inBuffer);

	// Parameterized constructor
	DDString(const char* inBuffer);

	// Copy constructor constructor
	DDString(const DDString& otherString);

	// Move constructor
	DDString(DDString&& otherString) noexcept;

	// Destructor
	~DDString();

private:
	// Ensures that buffersize does not exceed buffer capacity
	void PerformSafetyChecks();

	// Increases buffer capacity by increase amount
	void IncreaseBufferSize(int increaseAmount);

	// Copies source buffer into dest buffer and returns source (null terminated). Optionally can destroy source buffer
	char* BufferCopy(char* destBuffer, char* sourceBuffer, int sourceBufferSize, bool deleteSourceBuffer = false);

	// Copies source buffer into dest buffer and returns source (null terminated)
	char* BufferCopy(char* destBuffer, const char* sourceBuffer, int sourceBufferSize);

public:
	const char* Data() const { return buffer; }

public:
	// Copy assignment
	DDString& operator=(const DDString& otherString)
	{
		if (this == &otherString) return *this;
		if (buffer) delete[] buffer;

		bufferSize = otherString.bufferSize;
		bufferCapacity = otherString.bufferCapacity;
		PerformSafetyChecks();

		char* newBuffer = new char[bufferCapacity];
		buffer = BufferCopy(newBuffer, otherString.buffer, bufferSize);

		return *this;
	}

	// Move assignment
	DDString& operator=(DDString&& otherString) noexcept
	{
		if (this == &otherString) return *this;
		if (buffer) delete[] buffer;

		bufferSize = otherString.bufferSize;
		bufferCapacity = otherString.bufferCapacity;
		PerformSafetyChecks();

		buffer = otherString.buffer;

		otherString.bufferSize = 0;
		otherString.bufferCapacity = 0;
		otherString.buffer = nullptr;

		return *this;
	}

	// Stream operator
	friend std::ostream& operator<<(std::ostream& stream, const DDString& string);
};

inline std::ostream& operator<<(std::ostream& stream, const DDString& string)
{
	stream << string.Data();
	return stream;
}