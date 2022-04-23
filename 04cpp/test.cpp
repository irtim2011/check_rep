#include "pch.h"


#define protected public
#define private   public
#include "BigInt.hpp"
#undef protected
#undef private

TEST(TestBigInt, mult_neg_both_small) {
	BigInt x = -2;
	BigInt y = -2;
	BigInt check = 4;
	EXPECT_EQ(x * y, check);
}


TEST(TestBigInt, Test1) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}
TEST(TestBigInt, Test_x_EQ1) {
	BigInt x = 1;
	EXPECT_EQ(x.length, 10); //в реализации с запасом чтобы max int влез
	EXPECT_EQ(x.ptr[0], 1);
	for (int i = 1; i < 10; i++) {
		EXPECT_EQ(x.ptr[i], 0);
	}
}

TEST(TestBigInt, Test_x_EQ_minus1) {
	BigInt x = -1;
	EXPECT_EQ(x.length, 10); //в реализации с запасом чтобы max int влез
	for (int i = 0; i < 10; i++) {
		EXPECT_EQ(x.ptr[i], 9);
	}
}

TEST(TestBigInt, Test_x_EQ_y) {
	BigInt x = 1;
	BigInt y = 1;
	EXPECT_EQ(x, y);
}

TEST(TestBigInt, Test_x_EQ_y_big_num) {
	BigInt x = 100500;
	BigInt y = 100500;
	EXPECT_EQ(x, y);
}

TEST(TestBigInt, Test_x_EQ_y_big_num_negative) {
	BigInt x = -100500;
	BigInt y = -100500;
	EXPECT_EQ(x, y);
}

TEST(TestBigInt, Test_x_NEQ_y_big_num_negative) {
	BigInt x = -100500;
	BigInt y = -100501;
	EXPECT_TRUE(x!=y);
}

TEST(TestBigInt, Test_sum) {
	BigInt x = 2;
	BigInt y = 2;
	BigInt check = 4;
	EXPECT_EQ(x + y, check);
}

TEST(TestBigInt, Test_sum_neg) {
	BigInt x = 25;
	BigInt y = -30;
	BigInt check = -5;
	EXPECT_EQ(x + y, check);
}

TEST(TestBigInt, Test_sum_neg_2) {
	BigInt x = -25;
	BigInt y = -30;
	BigInt check = -55;
	EXPECT_EQ(x + y, check);
}

TEST(TestBigInt, Test_sub) {
	BigInt x = 25;
	BigInt y = 30;
	BigInt check = -5;
	EXPECT_EQ(x - y, check);
}

TEST(TestBigInt, Test_sub_both_negative) {
	BigInt x = -25;
	BigInt y = -30;
	BigInt check = 5;
	EXPECT_EQ(x - y, check);
}

TEST(TestBigInt, Test_sub_pos_neg) {
	BigInt x = 25;
	BigInt y = -30;
	BigInt check = 55;
	EXPECT_EQ(x - y, check);
}

TEST(TestBigInt, un_minus) {
	BigInt x = 25;
	BigInt check = -25;
	EXPECT_EQ(-x, check);
}

TEST(TestBigInt, un_minus_neg) {
	BigInt x = -25;
	BigInt check = 25;
	EXPECT_EQ(-x, check);
}

TEST(TestBigInt, mult) {
	BigInt x = 2;
	BigInt y = 2;
	BigInt check = 4;
	EXPECT_EQ(x*y, check);
}

TEST(TestBigInt, mult_neg_1) {
	BigInt x = -2;
	BigInt y = 2;
	BigInt check = -4;
	EXPECT_EQ(x * y, check);
}

TEST(TestBigInt, mult_neg_2) {
	BigInt x = 2;
	BigInt y = -2;
	BigInt check = -4;
	EXPECT_EQ(x * y, check);
}


TEST(TestBigInt, mult_neg_both) {
	BigInt x = -20;
	BigInt y = -200;
	BigInt check = 4000;
	EXPECT_EQ(x * y, check);
}

TEST(TestBigInt, mult_many) {
	BigInt x = 1;
	BigInt y = 10;
	BigInt check = 100000;
	for (int i = 0; i < 5; i++) {
		x *= y;
	}
	EXPECT_EQ(x, check);
}






