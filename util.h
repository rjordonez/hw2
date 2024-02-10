#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <iostream>
#include <set>


/** Complete the setIntersection and setUnion functions below
 *  in this header file (since they are templates).
 *  Both functions should run in time O(n*log(n)) and not O(n^2)
 */
// template <typename T>
// std::set<T> setIntersection(std::set<T>& s1, std::set<T>& s2)
// {
//     // Choose the smaller set to iterate over
//     std::set<T>& smaller = (s1.size() <= s2.size()) ? s1 : s2;
//     std::set<T>& larger = (s1.size() > s2.size()) ? s1 : s2;

//     std::set<T> result;

//     // Iterate over the smaller set
//     for (const T& element : smaller) {
//         // Check if element is in the larger set
//         if (larger.find(element) != larger.end()) {
//             result.insert(element);
//         }
//     }

//     return result;



// }
// template <typename T>
// std::set<T> setUnion(std::set<T>& s1, std::set<T>& s2)
// {
//     std::set<T> result;

//     // Insert all elements from both sets into the result set
//     result.insert(s1.begin(), s1.end());
//     result.insert(s2.begin(), s2.end());

//     return result;



// }
template<typename T>
std::set<T> setIntersection(const std::set<T>& s1, const std::set<T>& s2) {
    std::set<T> result;
    std::set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(),
                          std::inserter(result, result.begin()));
    return result;
}

template<typename T>
std::set<T> setUnion(const std::set<T>& s1, const std::set<T>& s2) {
    std::set<T> result;
    std::set_union(s1.begin(), s1.end(), s2.begin(), s2.end(),
                   std::inserter(result, result.begin()));
    return result;
}
/***********************************************/
/* Prototypes of functions defined in util.cpp */
/***********************************************/

std::string convToLower(std::string src);

std::set<std::string> parseStringToWords(std::string line);

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// Removes any leading whitespace
std::string &ltrim(std::string &s) ;

// Removes any trailing whitespace
std::string &rtrim(std::string &s) ;

// Removes leading and trailing whitespace
std::string &trim(std::string &s) ;
#endif
