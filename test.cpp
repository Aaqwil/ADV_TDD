#include "test.h"

#include "CircularBuffer.h"

struct CircularBufferTest : public ::testing::Test
{
	CircularBuffer buffer{ 5 };

	void SetUp() override
	{
		for (auto i : { 5, 4, 3, 2 })
			buffer.add(i);
	}
	
	void TearDown() override {}
};

TEST_F(CircularBufferTest, popTest)
{
	int i = 5;
	while (buffer.getSize())
		EXPECT_EQ(buffer.pop(), i--);
}

TEST_F(CircularBufferTest, maxSizeTest)
{
	buffer.add(1); buffer.add(0);
	ASSERT_EQ(buffer.getSize(), 5);
}

TEST(CircularBufferSize, sizeTest)
{
	CircularBuffer buffer{ 5 };
	for (auto i : { 1, 2, 3, 4, 5, 5, 5, 5, 5, 5 })
	{
		buffer.add(i);
		EXPECT_EQ(buffer.getSize(), i);
	}
}

TEST(CircularBufferAddTest, circularAddingTest)
{
	CircularBuffer buffer{ 3 };
	for (auto i : { 1, 2, 3 })
		buffer.add(i);
	for (auto i : { 5, 5, 5 })
		buffer.add(i);
	while (buffer.getSize())
		EXPECT_EQ(buffer.pop(), 5);
}

TEST(CircularBufferOldest, oldestBufferedObjectTest)
{
	CircularBuffer buffer{ 4 };
	for (auto i : { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 })
		buffer.add(i);
	int i = 7;
	while(buffer.getSize())
		EXPECT_EQ(buffer.pop(), i++);
}

TEST(NotFullCircularBuffer, notFullBufferTest)
{
	CircularBuffer buffer{ 5 };
	for (auto i : { 1, 2, 3 })
		buffer.add(i);

	int i = 1;
	while (buffer.getSize())
		EXPECT_EQ(buffer.pop(), i++);
}