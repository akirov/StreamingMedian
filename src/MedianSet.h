#ifndef __MEDIANSET_H__
#define __MEDIANSET_H__

#include <queue>
#include <vector>

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

  private:
    // Will use std::priority_queue - it is implemented as a max heap
    std::priority_queue<double,  std::vector<double> > mLowerMaxHeap;  // lower half
    std::priority_queue<double,  std::vector<double>, std::greater<double> > mUpperMinHeap;  // upper half
};

} // namespace MyMedian


#endif // __MEDIANSET_H__
