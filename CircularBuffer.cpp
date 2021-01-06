#include "CircularBuffer.h"

CircularBuffer::CircularBuffer(size_t size) : maxSize{ size }, oldest{ 0 }
{
	buffer.reserve(size);
}

void CircularBuffer::add(int newElement)
{
	if (buffer.size() == maxSize)
	{
		buffer.at(oldest) = newElement;
		oldest = (oldest + 1) % maxSize;
	}

	else
		buffer.push_back(newElement);
}

int CircularBuffer::pop()
{
	int temp = buffer.at(oldest);
	buffer.erase(buffer.begin() + oldest - 1);
	oldest = (oldest + 1) % getSize();
	return temp;
}

size_t CircularBuffer::getSize() const
{
	return buffer.size();
}

size_t CircularBuffer::getAllocatedSize() const
{
	return maxSize;
}