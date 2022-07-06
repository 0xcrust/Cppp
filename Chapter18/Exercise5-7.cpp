/**
 * @file Exercise_5-7.cpp
 * @author Ademola
 * @brief 
 * @version 0.1
 * @date 2022-07-06
 * 
 * @copyright Copyright (c) 2022
 * 
 *  5.)
 *  Write a function, string cat_dot(const string& s1, const string& s2) ,
    that concatenates two strings with a dot in between. For example, cat_
    dot("Niels", "Bohr") will return a string containing Niels.Bohr.

    6.)
    Modify cat_dot() from the previous exercise to take a string to be used as
    the separator (rather than dot) as its third argument.

    7.)
    Write versions of the cat_dot() s from the previous exercises to take
    C-style strings as arguments and return a free-store-allocated C-style string
    as the result. Do not use standard library functions or types in the im-
    plementation. Test these functions with several strings. Be sure to free
    (using delete ) all the memory you allocated from free store (using new ).
    Compare the effort involved in this exercise with the effort involved for
    exercises 5 and 6.
 * 
 */

#include <iostream>

using namespace std;

//5
string cat_dot(const string& s1, const string& s2) {
    string result = s1 + '.' + s2;
    return result;
}

//6 
string cat_dot(const string& s1, const string& separator, const string& s2) {
    string result = s1 + separator + s2;
    return result;
}

//7
char* cat_dot(const char* s1, const char* s2) {
    int s1_size = 0;
    int s2_size = 0;

    for(int i = 0; s1[i]; ++i) s1_size+=1; 
    for(int i = 0; s2[i]; ++i) s2_size+=1;

    char* p = new char[s1_size + s2_size + 1];
    
    for(int i = 0; i < s1_size; ++i) p[i] = s1[i];
    p[s1_size] = '.';
    for(int i = 0; i < s2_size; ++i) p[s1_size + 1 + i] = s2[i];

    return p;
}

char* cat_dot(const char* s1, const char* sep, const char* s2) {
    int s1_size = 0;
    int s2_size = 0;
    int sep_size = 0;

    for(int i = 0; s1[i]; ++i) s1_size++;
    for(int i = 0; s2[i]; ++i) s2_size++;
    for(int i = 0; sep[i]; ++i) sep_size++;

    char* p = new char[s1_size + s2_size + sep_size];

    for(int i = 0; i < s1_size; ++i) p[i] = s1[i];
    for(int i = 0; i < sep_size; ++i) p[s1_size + i] = sep[i];
    for(int i = 0; i < s2_size; ++i) p[s1_size + sep_size + i] = s2[i];

    return p;
}

// Helper function to print array of chars
void print(char* p) {
    while(*p) {
        cout << *p;
        p = p+1;
    }
    std::cout << '\n';
}


int main() {
    // 5
    string aa = "google";
    string bb = "com";
    string cc = "dancing";
    string dd = "man";
    cout << cat_dot(aa, bb) << '\n';
    cout << cat_dot(cc, dd) << '\n';
    cout << cat_dot(cc, bb) << '\n';

    // 6
    cout << cat_dot("cat", " and ", "dog") << '\n';
    cout << cat_dot("pin", "noch", "io") << '\n';
    cout << cat_dot("nig", "er", "ia") << '\n';

    // 7a
    char ch1[] = "google";
    char ch2[] = "com";
    char ch3[] = "dancing";
    char ch4[] = "monkey";
    char ch5[] = "money";
    char ch6[] = "io";


    char* a = cat_dot(ch1, ch2);
    char* b = cat_dot(ch3, ch4);
    char* c = cat_dot(ch5, ch6);

    print(a);
    print(b);
    print(c);

    delete[] a;
    delete[] b;
    delete[] c;

    // 7b
    char* d = cat_dot(ch1, ch3, ch4);
    char* e = cat_dot(ch4, ch5, ch2);

    print(d);
    print(e);

    delete[] d;
    delete[] e;


}