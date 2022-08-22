#include "pch.h"
#include "..\Dell-Client\Header.h"

//int calculateAverage(int total, int count);

TEST(TestClient, TestAverage1) {
	int average = calculateAverage(999, 3);
  EXPECT_EQ(average, 333);
  //EXPECT_TRUE(true);
}
TEST(TestClient, TestAverage2) {
	int average = calculateAverage(3, 3);
	EXPECT_EQ(average, 1);
}
TEST(TestClient, TestAverage3) {
	int average = calculateAverage(4444, 22);
	EXPECT_EQ(average, 202);
	//EXPECT_TRUE(true);
}
TEST(TestClient, TestAverage4) {
	int average = calculateAverage(1, 1);
	EXPECT_EQ(average, 1);
	//EXPECT_TRUE(true);
}
TEST(TestClient, TestAverage5) {
	int average = calculateAverage(10000, 100);
	EXPECT_EQ(average, 100);
	//EXPECT_TRUE(true);
}
TEST(TestClient, TestAverage6) {
	int average = calculateAverage(0, 3);
	EXPECT_EQ(average, 0);
	//EXPECT_TRUE(true);
}
TEST(TestClient, TestAverage7) {
	int average = calculateAverage(6666,33);
	EXPECT_EQ(average, 202);
	//EXPECT_TRUE(true);
}
TEST(TestClient, TestAverage8) {
	int average = calculateAverage(8888, 8);
	EXPECT_EQ(average, 1111);
	//EXPECT_TRUE(true);
}