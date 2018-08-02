Median of streaming data
========================

A data structure containing a set of numbers (sample) with two operations:
- add a number to the sample set
- calculate the median of the set


Possible implementations:
-------------------------

Method 1 (naive):
Put new data at the end of a dynamic array (vector). Generic sort on every new
element, take the middle element. If we compare elements O(n*log(n)) on average,
O(n^2) in the worst case. For integers, if we can afford more memory, we can use
counting sort ~ O(n).

Method 2:
Some kind of balanced binary search tree (AVL, red-black, others). Approximate
median will be the root. Hard to implement. Complexity ~ O(log(n)).
May be good for large data sets.

Method 3:
Put data in a dynamic array (vector). Keep it sorted by inserting new elements
in the appropriate place (insertion sort). Need to shift/move elements.
Complexity O(n). No memory overhead. Slow for large data sets.

Method 4:
Keep the elements in a sorted doubly-linked list and remember the pointer to the
middle element. Change this pointer to previous or next element when adding new
elements. Adding is O(n) - need to traverse the list to find the insertion
place. Memory overhead for the additional pointers. Good for large data elements
(no data moving).

Method 5:
"Median of medians" algorithm ~O(n). Complex.

Method 6:
Estimate the probability distribution of the numbers in the set and calculate
the median from distribution parameters. Update periodically. Will be
approximate.

Method 7:
Maintain two heaps - max heap for the lower half and min heap for the upper half
of the set. Add new elements in the appropriate heap. Maintain difference of at
most 1 element between the two, moving elements if needed. Roots will be the
middle elements. Take the one with more elements or the average if heaps have
equal number of element.
Complexity : O(log(n)) to O(n) if heaps are unbalanced.

Method 7 is implemented in MedianSet class and compiled in `libmedian` library.
A console demo and automatic tests are provided.
Note: Google Test Framework 1.7.0 source is included in tests folder! It should
not conflict with other Google Test Framework installations, but if it does you
may need to disable the local build in tests/CMakeLists.txt.


How to build from command line:
-------------------------------

Need CMake version > 3.1 and a C++ compiler to build.
Tested on Windows 10 x64 with MinGW GCC 5.3.0_32 and with Cygwin GCC 7.3.0_32.
Also on Ubuntu Linux 16.04 x64 with GCC 5.4.0_64. Corresponding binaries are
provided in `bin` subfolders.

Cygwin or Linux:
```
mkdir build
cd build
cmake ..
make
make install
```

MinGW with MSYS make:
```
mkdir build
cd build
cmake .. -G "MSYS Makefiles"
make
make install
```

The library, demo and test executables will be installed in `bin` folder.
To run tests: `build> make test` or directly `bin> median_test`.
The demo exe reads numbers from the console and prints the current median.
