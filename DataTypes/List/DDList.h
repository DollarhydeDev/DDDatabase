#pragma once

#include <iostream>

template <typename T>
class DDList
{
private:
	T* buffer;
	int bufferSize;
	int bufferCapacity;

public:
	DDList()
	{
		bufferSize = 0;
		bufferCapacity = 1;

		buffer = new T[bufferCapacity];
	}
	DDList(const DDList<T>& otherList)
	{
		if (!otherList.buffer || otherList.bufferSize <= 0)
		{
			bufferSize = 0;
			bufferCapacity = 1;

			buffer = new T[bufferCapacity];
			return;
		}

		bufferSize = otherList.bufferSize;
		bufferCapacity = (bufferSize >= otherList.bufferCapacity) ? (bufferSize + 1) : otherList.bufferCapacity;
		buffer = new char[bufferCapacity];

		std::copy(otherList.buffer, otherList.buffer + otherList.bufferSize, buffer);
	}
	DDList(DDList<T>&& otherList) noexcept
	{
		buffer = otherList.buffer;
		bufferSize = otherList.bufferSize;
		bufferCapacity = otherList.bufferCapacity;

		otherList.buffer = nullptr;
		otherList.bufferSize = 0;
		otherList.bufferCapacity = 0;
	}
	~DDList()
	{
		if (buffer)
		{
			delete[] buffer;
			buffer = nullptr;
		}

		bufferSize = 0;
		bufferCapacity = 0;
	}

private:
	// Increases buffer capacity by increase amount
	void IncreaseBufferSize(int increaseAmount)
	{
		bufferCapacity += increaseAmount;
		T* newBuffer = new T[bufferCapacity];

		if (buffer)
		{
			std::copy(buffer, buffer + bufferSize, newBuffer);
			delete[] buffer;
		}

		buffer = newBuffer;
	}

public:
	const T* Data() const { return buffer; }

	void AddItem(const T& itemToAdd)
	{
		if ((bufferSize + 1) > bufferCapacity) IncreaseBufferSize((bufferSize + 1) - bufferCapacity);
		buffer[bufferSize++] = itemToAdd;
	}

	int Length()
	{
		return bufferSize;
	}

	T& GetAt(int at)
	{
		return buffer[at];
	}

public:
	// Copy assignment
	DDList& operator=(const DDList& otherList)
	{
		if (this == &otherList) return *this;
		delete[] buffer;

		if (!otherList.buffer || otherList.bufferSize <= 0)
		{
			bufferSize = 0;
			bufferCapacity = 1;

			buffer = new T[bufferCapacity];
			return;
		}

		bufferSize = otherList.bufferSize;
		bufferCapacity = (bufferSize >= otherList.bufferCapacity) ? (bufferSize + 1) : otherList.bufferCapacity;
		buffer = new char[bufferCapacity];

		std::copy(otherList.buffer, otherList.buffer + otherList.bufferSize, buffer);

		return *this;
	}

	// Move assignment
	DDList& operator=(DDList&& otherList) noexcept
	{
		if (this == &otherList) return *this;
		delete[] buffer;

		buffer = otherList.buffer;
		bufferSize = otherList.bufferSize;
		bufferCapacity = otherList.bufferCapacity;

		otherList.buffer = nullptr;
		otherList.bufferSize = 0;
		otherList.bufferCapacity = 0;

		return *this;
	}
};

