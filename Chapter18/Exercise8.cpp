/**
 * @file Chapter_8.cpp
 * @author Ademola
 * @brief 
 * @version 0.1
 * @date 2022-07-06
 * 
 * @copyright Copyright (c) 2022
 * 
 * Rewrite all the functions in §18.7 to use the approach of making a back-
   ward copy of the string and then comparing; for example, take "home" ,
   generate "emoh" , and compare those two strings to see that they are
   different, so home isn’t a palindrome.
 */

#include <iostream>

//using strings
bool is_palindrome(const std::string& s) {
    std::string backwards = "";
    for(int i = s.size()-1; i >= 0; --i) backwards += s[i];

    for(int i = 0; i < s.size(); ++i) {
        if(s[i] != backwards[i]) {
            std::cout << "false!\n";
            return false;
        }
    }
    std::cout << "true!\n";
    return true;
}

//using arrays
bool is_palindrome(const char s[], int n) {
    char backwards[n];
    for(int i = 0; i < n; ++i) backwards[i] = s[n-i-1];

    for(int i = 0; i < n; ++i) {
        if(s[i] != backwards[i]) {
            std::cout << "false!\n";
            return false;
        }
    }
    std::cout << "true!\n";
    return true;
}

//using pointers
bool is_palindrome(const char* first, const char* last) {
    int size = 0;
    auto p = first;
    while(p != last) {
        size++;
        ++p;
    }
    char* backwards = new char[size];

    for(int i = 0; i < size; ++i) {
        *(backwards+i) = *(last -i);
    }

    for(int i = 0; i < size; ++i) {
        if(*(first+i) != *(backwards-i)) {
            std::cout << "false!\n";
            return false;
        }
    }
    std::cout << "true!\n";
    return true;
}


int main() {
    std::string test = "nursesrun";
    std::string test2 = "catscat";

    is_palindrome(test);
    is_palindrome(test2);

    char p[] = "wasitacatisaw";
    char q[] = "cascade";

    is_palindrome(p);
    is_palindrome(q);

    char* x = "madam";
    char* y = "truffle";
    char* z = "civic";

    is_palindrome(x);
    is_palindrome(y);
    is_palindrome(z);
}