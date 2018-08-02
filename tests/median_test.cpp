#include "MedianSet.h"
#include "gtest/gtest.h"

using namespace MyMedian;


void addVectorToMSet( const std::vector<double>& vd, MedianSet& m)
{
    for( const auto& num : vd )
    {
        m.addNumber(num);
    }
}



TEST(MedianTest, getMedianValue) {
    MedianSet m;
    EXPECT_DOUBLE_EQ(m.getMedianValue(), 0.0);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest( &argc, argv );
    return RUN_ALL_TESTS();
}
