#pragma once

#include <vector>

class CircularBuffer
{
public:
	CircularBuffer(size_t size = 20);

	void add(int newElement);
	int pop();
	size_t getSize() const;
	size_t getAllocatedSize() const;

private:
	std::vector<int> buffer;
	const size_t maxSize;
	size_t oldest;
};