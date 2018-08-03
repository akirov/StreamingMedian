#include <cassert>
#include "MedianSet.h"

using namespace MyMedian;


MedianSet::MedianSet():
        mLowerMaxHeap(),
        mUpperMinHeap()
{
}


double MedianSet::getMedianValue() const
{
    const size_t lsz = mLowerMaxHeap.size(), hsz = mUpperMinHeap.size();

    // We must guarantee maximum 1 difference between two heaps sizes
    assert(abs((int)lsz - (int)hsz) <= 1);

    double val;

    if( lsz == 0  &&  hsz == 0 )
    {
        val = 0.0;
    }
    else if( lsz >  hsz )
    {
        val = mLowerMaxHeap.top();
    }
    else if( lsz <  hsz )
    {
        val = mUpperMinHeap.top();
    }
    else // ( lsz == hsz > 0 )
    {
        val = ((mLowerMaxHeap.top() + mUpperMinHeap.top()) / 2.0);
    }

    return val;
}


void MedianSet::insertNumber( double number )
{
    const size_t lsz = mLowerMaxHeap.size(), hsz = mUpperMinHeap.size();

    if( lsz == 0  &&  hsz == 0 )  // Empty set
    {
        mLowerMaxHeap.push(number);  // Puth first nulber in the lower heap
    }
    else if( lsz >  hsz )  // Lower half is larger
    {
        if( number >= mLowerMaxHeap.top() )  // Number belongs to upper half
        {
            mUpperMinHeap.push(number);  // Put it in the upper half
        }
        else  // Number belongs to the lower half (which is larger)
        {
            mLowerMaxHeap.push(number);  // Put the new number in the lower half
            double lowerMax = mLowerMaxHeap.top();
            mLowerMaxHeap.pop();          // Remove lowerMax from lower half
            mUpperMinHeap.push(lowerMax);  // Move lowerMax to the upper half
        }
    }
    else if( lsz <  hsz )  // Upper half is larger
    {
        if( number <= mUpperMinHeap.top() )  // Number belongs to lower half
        {
            mLowerMaxHeap.push(number);  // Put the new number in the lower half
        }
        else  // Number belongs to the upper half (which is larger)
        {
            mUpperMinHeap.push(number);  // Put the new number in the upper half
            double upperMin = mUpperMinHeap.top();
            mUpperMinHeap.pop();          // Remove upperMin from upper half
            mLowerMaxHeap.push(upperMin);  // Move upperMin to the lower half
        }
    }
    else // ( lsz == hsz > 0 )
    {
        if( number <= mUpperMinHeap.top() )
        {
            mLowerMaxHeap.push(number);
        }
        else
        {
            mUpperMinHeap.push(number);
        }
    }
}
