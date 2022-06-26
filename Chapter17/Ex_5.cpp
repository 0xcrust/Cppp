/**
 * @file Ex_5.cpp
 * @author Ademola
 * @brief 
 * 5. Write a function, char* findx(const char* s, const char* x), that finds the 
 *    first occurence of the C-style string x in s.
 * @version 0.1
 * @date 2022-06-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>

// for each char in s
// if char = first letter of s:
//   start a loop from first char of s till *s=0
//     compare *s == *x in each iteration of the loop
//      and make sure both are incremented by one in each iteration.
//      return false if any of the comparisons within the loop is false
// if loop terminates without returning false, then return true
// if outer loop terminates without the char = first of letter condition triggering,
// return false

const char* findx(const char* s, const char* x, int& i) {
    ++i;
    /*
    for(auto c = s; *c!=0; ++c) {
        std::cout << *c;
    }*/
    
    for(auto c = s; *c!='0'; ++c) {
        
    }

}

int main() {
    int count = 0;
    const char* c = "indefatigibility0";

    const char* d = "inde0";
    const char* e = "wrong";
    const char* f = "fatigibi0";
    const char* g = "gibility";
    const char* h = "gibility0";
    const char* i = "bili";

    //findx(c, d, count);
    //findx(c, e, count);
    //findx(c, f, count);
    findx(c, g, count);
    findx(c, h, count);
    findx(c, i, count);

}

