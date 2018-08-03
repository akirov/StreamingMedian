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


TEST(MedianTest, getEmptyMedianValue) {
    MedianSet m;
    EXPECT_DOUBLE_EQ(m.getMedianValue(), 0.0);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest( &argc, argv );
    return RUN_ALL_TESTS();
}
