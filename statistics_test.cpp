/** Test cases for functions defined in statistics.h
@file statistics_test.cpp
@author YOUR NAME HERE
*/
// TODO: Fill in your name above.

#include "statistics.h"

#include <gtest/gtest.h>

#include <algorithm>
using namespace std;

class StatisticsTest : public ::testing::Test {
 protected:
  // TODO: Write your test cases here.
  int array1[SIZE] = {0};
  int n1 = 0;
  int expected_min1 = 0;
  int expected_max1 = 0;
  int expected_med1 = 0;
  int expected_avg1 = 0;

  int array2[SIZE] = {0};
  int n2 = 0;
  int expected_min2 = 0;
  int expected_max2 = 0;
  int expected_med2 = 0;
  int expected_avg2 = 0;

  int array3[SIZE] = {0};
  int n3 = 0;
  int expected_min3 = 0;
  int expected_max3 = 0;
  int expected_med3 = 0;
  int expected_avg3 = 0;

  int array4[SIZE] = {0};
  int n4 = 0;
  int expected_min4 = 0;
  int expected_max4 = 0;
  int expected_med4 = 0;
  int expected_avg4 = 0;

  int array5[SIZE] = {0};
  int n5 = 0;
  int expected_min5 = 0;
  int expected_max5 = 0;
  int expected_med5 = 0;
  int expected_avg5 = 0;

  // Don't change anything below this comment!
};

#define GENERATE_TEST(f, v, i)                     \
  {                                                \
    sort(array##i, array##i + n##i);               \
    EXPECT_EQ(f(array##i, n##i), expected_##v##i); \
  }

#define GENERATE_TESTS(f, v) \
  {                          \
    GENERATE_TEST(f, v, 1);  \
    GENERATE_TEST(f, v, 2);  \
    GENERATE_TEST(f, v, 3);  \
    GENERATE_TEST(f, v, 4);  \
    GENERATE_TEST(f, v, 5);  \
  }

TEST_F(StatisticsTest, MinimumTest) { GENERATE_TESTS(minimum, min); }

TEST_F(StatisticsTest, MaximumTest) { GENERATE_TESTS(maximum, max); }

TEST_F(StatisticsTest, MedianTest) { GENERATE_TESTS(median, med); }

TEST_F(StatisticsTest, AverageTest) { GENERATE_TESTS(average, avg); }

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  RUN_ALL_TESTS();
  return 0;
}
