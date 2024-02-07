#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <iostream>
#include <set>

#include <map>


/** Complete the setIntersection and setUnion functions below
 *  in this header file (since they are templates).
 *  Both functions should run in time O(n*log(n)) and not O(n^2)
 */
template <typename T>
std::set<T> setIntersection(std::set<T>& s1, std::set<T>& s2)
{
    //potential option: iterate through both sets and add them all to a new set
    //create a map that has the keys as the elemens of the set and the member
    //as a number that indicates the number of appearances.
    //iterate through the map and add the elements that have a member of 2 to the new set

    std::map<T, int> counterMap;
    for(typename std::set<T>::iterator it = s1.begin(); it != s1.end(); it++) {
        counterMap.insert(std::make_pair(*it, 0));
        counterMap[*it] = counterMap[*it] + 1;
    }
    for(typename std::set<T>::iterator it = s2.begin(); it != s2.end(); it++) {
        counterMap.insert(std::make_pair(*it, 0));
        counterMap[*it] = counterMap[*it] + 1;
    }

    std::set<T> intersectionSet;
    for(typename std::map<T, int>::iterator it = counterMap.begin(); it != counterMap.end(); it++) {
        if(it->second == 2) {
            intersectionSet.insert(it->first);
        }
    }
    return intersectionSet;
}
template <typename T>
std::set<T> setUnion(std::set<T>& s1, std::set<T>& s2)
{
    std::set<T> unionSet;
    for(typename std::set<T>::iterator it = s1.begin(); it != s1.end(); it++) {
        unionSet.insert(*it);
    }
    for(typename std::set<T>::iterator it = s2.begin(); it != s2.end(); it++) {
        unionSet.insert(*it);
    }
    return unionSet;

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
