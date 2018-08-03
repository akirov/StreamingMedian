#include <random>
#include "MedianSet.h"
#include "gtest/gtest.h"

using namespace MyMedian;


void insertVectorInMSet( const std::vector<double>& v, MedianSet& m )
{
    for( const auto& num : v )
    {
        m.insertNumber(num);
    }
}


TEST(MedianTest1, EmptyMedianValue) {
    MedianSet m;
    EXPECT_DOUBLE_EQ(m.getMedianValue(), 0.0);
}


TEST(MedianTest2, OneTwoThreeElementMedian) {
    MedianSet m;
    m.insertNumber(1);
    EXPECT_DOUBLE_EQ(m.getMedianValue(), 1.0);
    m.insertNumber(2);
    EXPECT_DOUBLE_EQ(m.getMedianValue(), 1.5);
    m.insertNumber(3000);
    EXPECT_DOUBLE_EQ(m.getMedianValue(), 2.0);
}


TEST(MedianTest3, DuplicatedValues) {
    MedianSet m;
    std::vector<double> v{2, 2, 2, 3, 1, 2, 2, 2};
    insertVectorInMSet(v, m);
    ASSERT_EQ(m.getSize(), v.size());
    EXPECT_DOUBLE_EQ(m.getMedianValue(), 2.0);
}


TEST(MedianTest4, UniformRandomMean) {
    MedianSet m;
    std::uniform_real_distribution<double> unif(-5, 5);
    std::default_random_engine re;
    int N = 100000;
    for( int i=0; i<N; i++ )
    {
        double num = unif(re);
        m.insertNumber(num);
    }
    ASSERT_EQ(m.getSize(), N);
    ASSERT_NEAR(m.getMedianValue(), 0.0, 0.05);  // median should be near the mean
}


TEST(MedianTest5, SequentialNumbers) {
    MedianSet m;
    int N = 100000;
    for( int n=0; n<=N; n++ )
    {
        m.insertNumber(n);
    }
    ASSERT_EQ(m.getSize(), N+1);
    EXPECT_DOUBLE_EQ(m.getMedianValue(), (double)N/2.0);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest( &argc, argv );
    return RUN_ALL_TESTS();
}
