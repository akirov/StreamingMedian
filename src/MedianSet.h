#ifndef __MEDIANSET_H__
#define __MEDIANSET_H__

#include <queue>
#include <vector>
#include <cstddef>

namespace MyMedian
{

/**
 * This could be a template with a parameter T instead of double...
 */
class MedianSet
{
  public:
    MedianSet();
    ~MedianSet() {}

    double getMedianValue() const;
    void insertNumber( double number );

    size_t getSize() const
    {
        return mLowerMaxHeap.size() + mUpperMinHeap.size();
    }

  private:
    // Will use std::priority_queue - it is implemented as max-heap
    std::priority_queue<double,  std::vector<double> > mLowerMaxHeap;  // lower half
    // std::greater<> (instead of default std::less<>) makes min-heap
    std::priority_queue<double,  std::vector<double>, std::greater<double> > mUpperMinHeap;  // upper half
};

} // namespace MyMedian


#endif // __MEDIANSET_H__
