#pragma once

#include <vector>

class CircularBuffer
{
public:
	CircularBuffer(size_t size = 20) : maxSize{ size }, oldest{ 0 }
	{
		buffer.reserve(size);
	}

	void add(int newElement)
	{
		if (buffer.size() == maxSize)
		{
			buffer.at(oldest) = newElement;
			oldest = (oldest + 1) % maxSize;
		}

		else
			buffer.push_back(newElement);
	}

	int pop()
	{
		int temp = buffer.at(oldest);
		buffer.erase(buffer.begin() + oldest - 1);
		oldest = (oldest + 1) % getSize();
		return temp;
	}

	int getSize() const
	{
		return buffer.size();
	}

	int getAllocatedSize() const
	{
		return maxSize;
	}

private:
	std::vector<int> buffer;
	const size_t maxSize;
	size_t oldest;
};