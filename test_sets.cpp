//test the set intersection and union functions

#include <iostream>
#include <string>
#include <set>
#include "util.h"
using namespace std;

int main()
{
    set<string> s1;
    set<string> s2;
    s1.insert("hello");
    s1.insert("world");
    s1.insert("this");
    s1.insert("is");
    s1.insert("a");
    s1.insert("test");

    s2.insert("hello");
    s2.insert("world");
    s2.insert("this");
    s2.insert("is");
    s2.insert("another");
    s2.insert("test");
    set<string> s3 = setUnion(s1, s2);
    set<string> s4 = setIntersection(s1, s2);
    cout << "==set 1==" << endl;
    cout << s1.size() << endl;
    for (set<string>::iterator it = s1.begin(); it != s1.end(); ++it)
    {
        cout << *it << endl;
    }
    cout << "==set 2==" << endl;
    cout << s2.size() << endl;
    for (set<string>::iterator it = s2.begin(); it != s2.end(); ++it)
    {
        cout << *it << endl;
    }
    cout << "==set union==" << endl;
    cout << s3.size() << endl;
    for (set<string>::iterator it = s3.begin(); it != s3.end(); ++it)
    {
        cout << *it << endl;
    }
    cout << "==set intersection==" << endl;
    cout << s4.size() << endl;
    for (set<string>::iterator it = s4.begin(); it != s4.end(); ++it)
    {
        cout << *it << endl;
    }
}