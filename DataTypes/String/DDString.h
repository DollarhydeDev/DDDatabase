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
	// Increases buffer capacity by increase amount
	void IncreaseBufferSize(int increaseAmount);

public:
	const char* Data() const { return buffer; }

public:
	// Copy assignment
	DDString& operator=(const DDString& otherString)
	{
		if (this == &otherString) return *this;
		delete[] buffer;

		if (!otherString.buffer || otherString.bufferSize <= 0)
		{
			bufferSize = 0;
			bufferCapacity = 10;

			buffer = new char[bufferCapacity];
			buffer[bufferSize] = 0x00;
			return *this;
		}

		bufferSize = otherString.bufferSize;
		bufferCapacity = (bufferSize >= otherString.bufferCapacity) ? (bufferSize + 1) : otherString.bufferCapacity;
		buffer = new char[bufferCapacity];

		memcpy(buffer, otherString.buffer, bufferSize);
		buffer[bufferSize] = 0x00;

		return *this;
	}

	// Move assignment
	DDString& operator=(DDString&& otherString) noexcept
	{
		if (this == &otherString) return *this;
		delete[] buffer;

		buffer = otherString.buffer;
		bufferSize = otherString.bufferSize;
		bufferCapacity = otherString.bufferCapacity;

		otherString.buffer = nullptr;
		otherString.bufferSize = 0;
		otherString.bufferCapacity = 0;

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