//a test file that tests the parseStringToWords function

#include <iostream>
#include <string>
#include <set>
#include "util.h"

using namespace std;

int main()
{
    string s = "Men's Fitted Shirt i'll";
    set<string> words = parseStringToWords(s);
    cout << words.size() << endl;
    for (set<string>::iterator it = words.begin(); it != words.end(); ++it)
    {
        cout << *it << endl;
    }
    return 0;
}