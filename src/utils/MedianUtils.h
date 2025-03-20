/******************************************************************************
 * Group Name: Bisection
 * 
 * Group Members:
 * 1. Vera Fan (esemsc-3f9bc883)
 * 2. Jiawei Zhan (esemsc-jz1224)
 * 3. Simranjeet Singh (esemsc-ss2524)
 * 4. George Sokolik (esemsc-gts124)
 * 5. Qihan Zhang (esemsc-qz624)
 * 6. Yixiao Zheng (esemsc-yz1824)
 * 7. Miles Weberman (esemsc-mw2124)
 *
 ******************************************************************************/

#ifndef MEDIAN_UTILS_H
#define MEDIAN_UTILS_H

#include <algorithm>
#include <iterator>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()

// Partition function (Hoare's partitioning scheme)
template <typename Iterator>
Iterator partition(Iterator left, Iterator right) {
    // Choose a random pivot
    auto pivotIndex = left + rand() % (right - left);
    auto pivotValue = *pivotIndex;
    
    // Move pivot to the end temporarily
    iter_swap(pivotIndex, right - 1);
    
    // Partition elements
    Iterator storeIndex = left;
    for (Iterator it = left; it < right - 1; ++it) {
        if (*it < pivotValue) {
            iter_swap(it, storeIndex);
            ++storeIndex;
        }
    }
    
    // Put pivot in its final place
    iter_swap(storeIndex, right - 1);
    return storeIndex;
}

// Quickselect to find the kth smallest element (zero-based index)
template <typename Iterator>
Iterator quickselect(Iterator left, Iterator right, int k) {
    while (left < right) {
        Iterator pivotIndex = partition(left, right);
        int pivotRank = pivotIndex - left;

        if (pivotRank == k) {
            return pivotIndex;
        } else if (pivotRank > k) {
            right = pivotIndex;
        } else {
            left = pivotIndex + 1;
            k -= pivotRank + 1;  // Adjust k for the reduced range
        }
    }
    return left;
}

template <typename Iterator>
typename std::iterator_traits<Iterator>::value_type 
findMedian(Iterator begin, Iterator end) {
    using ValueType = typename std::iterator_traits<Iterator>::value_type;
    
    int N = end - begin;
    if (N == 0) {
        throw std::invalid_argument("Cannot find median of empty range");
    }
    
    // Use rand() instead of mt19937
    static bool seeded = false;
    if (!seeded) {
        srand(static_cast<unsigned int>(time(nullptr)));
        seeded = true;
    }
    
    if (N % 2 == 1) {
        // Odd number of elements - find middle element
        return *quickselect(begin, end, N / 2);
    } else {
        // Even number of elements - average of two middle elements
        Iterator mid1 = quickselect(begin, end, N / 2 - 1);
        ValueType val1 = *mid1;
        Iterator mid2 = quickselect(begin, end, N / 2);
        ValueType val2 = *mid2;
        
        // Handle integer division correctly
        if (std::is_integral<ValueType>::value) {
            return (val1 + val2) / 2;
        } else {
            return (val1 + val2) / 2.0;
        }
    }
}

#endif // MEDIAN_UTILS_H