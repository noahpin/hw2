#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>
#include "util.h"

using namespace std;
std::string convToLower(std::string src)
{
    std::transform(src.begin(), src.end(), src.begin(), ::tolower);
    return src;
}

/** Complete the code to convert a string containing a rawWord
    to a set of words based on the criteria given in the assignment **/
std::set<std::string> parseStringToWords(string rawWords)
{   
    set<string> words;
    string word;
    stringstream ss(rawWords);
    while (ss >> word)
    {
        word = convToLower(word);
        word = trim(word);
        //first, we need to split at punctuation, which will (hopefully) only be , and . and '
        string filteredWord = "";
        int punctuationCount = 3;
        char * punctuation[] = {",", ".", "'"};
        for(int i = 0; i < punctuationCount; i++) {
            int punctuationPosition = word.find(punctuation[i]);
            if(punctuationPosition != string::npos) {
                string temp = word.substr(0, punctuationPosition);
                string temp2 = word.substr(punctuationPosition + 1);
                if(temp.length() >= 2) {
                    filteredWord = temp;
                }
                if(temp2.length() >= 2) {
                    filteredWord = temp2;
                }
            }else {
                filteredWord = word;
            
            }
        }
        if(filteredWord.length() >= 2) {
            words.insert(filteredWord);
        }
    }
    return words;
}

/**************************************************
 * COMPLETED - You may use the following functions
 **************************************************/

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// trim from start
std::string &ltrim(std::string &s) {
    s.erase(s.begin(), 
	    std::find_if(s.begin(), 
			 s.end(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

// trim from end
std::string &rtrim(std::string &s) {
    s.erase(
	    std::find_if(s.rbegin(), 
			 s.rend(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))).base(), 
	    s.end());
    return s;
}

// trim from both ends
std::string &trim(std::string &s) {
    return ltrim(rtrim(s));
}
