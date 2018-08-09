#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <iterator>

#include "MedianSet.h"

using namespace MyMedian;

/**
 * A command-line demo for the library.
 */
int main(int argc, char* argv[])
{
    MedianSet m;

    std::cout << "Please enter one or several numbers (separated by spaces) per line." << std::endl;
    std::cout << "After first non-number rest of the line is ignored. Exit with 'exit':" << std::endl;
    std::cout << "> ";
    std::string input;
    while( std::getline( std::cin, input ) )
    {
        if( input == "exit" ) break;

        // Parse input into vector of numbers
        std::vector<double> numbers;
        std::istringstream ss( input );
        std::copy( std::istream_iterator<double>( ss ), std::istream_iterator<double>(),
                   std::back_inserter( numbers ) );  // C++ parsing idiom

        for( const auto& num : numbers )
        {
            m.insertNumber(num);
        }
        std::cout << "New median : " << m.getMedianValue() << std::endl;

        std::cout << "> ";
    }

    return 0;
}
