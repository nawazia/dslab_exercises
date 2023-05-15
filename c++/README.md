## Debugging Problem ##
 
The code in `pearson_problem.cpp` compiles successfully with
 
    g++ -o pearson pearson_problem.cpp
 
However, the unit tests fail during runtime:
 
    ./pearson

    Assertion failed: (std::abs(numeric::correlation(x, n, z, n)) - (-1.0)
    < tolerance), function main, file pearson_problem.cpp, line 106.
 
Find and correct 7 logical errors in `pearson_problem.cpp`.

**ANSWER:** See `pearson_problem.cpp`

## Code Comprehension ##

Review the code in `numeric.hpp` and answer the following questions.

1. What is the worse-case time and space complexities of the following function?

    ```c++
    template <typename T> inline double mad(T* xs, size_t n)
    ```
    **ANSWER:** Decomposing `mad()`, we can see it is composed of 2 `median()` function calls, as well as a O(n) for loop. `median()` itself involves a divide-and-conquer sorting algorithm via `select()` and `partition()` (this is an implementation of Quicksort with random pivot choosing). Therefore, we can see that in the worst case, partitioning the array creates one empty subarray. If this happens at every step, we apply the partitioning method to arrays of size n, then n − 1, then n − 2, until we reach 1 (as the pivot is _not_ included in subarrays). The complexity of these recurvise function calls adds up to n/(n-1)/2. Ignoring non-dominant terms, we can see that the worst-case time complexity of `mad()` is O(n^2). In terms of space complexity, we can see that each recursive call has O(1) space complexity. Therefore, we can say that the total space complexity is proportional to the height of the recursion tree. In the worst case, the space complexity is thus O(n).
    
2. What is the average-case time complexity of the following function?

    ```c++
    template <typename T> inline double median(T* xs, size_t n)
    ```
    
    **ANSWER:** As discussed previously, `median()` is composed of sorting the array, then selecting the middle value(s). The avarage time complexity of sorting the array is O(nlog(n)), as it involves comparing O(n) items against the pivot, for each O(logn) recursive call.
    
## Problem Solving ##

Write a program that finds the fourth most frequent value 
in an integer array. In the case of ties in frequency among multiple values, 
return the smallest of such values.

For example, given the values (as command-line argument inputs)

    4 4 1 2 2 2 2 3 3 3 5 5 5 6 1 5 9

the program should print

    1
    
**ANSWER:** See `K_frequency.cpp`. Here, I used a hashmap to store all distinct ints, by first iterating through the entire input. This is of course in linear time, but I also sort the unordered hashmap, in order to select the 4th most frequent int. Therefore, the time compelxity of the algorithm is O(DlogD), where D is the number of distinct ints. The space complexity is O(D), as the hashmap has D key-value pairs.
