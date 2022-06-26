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

const char* findx(const char* s, const char* x) {
    for(int i = 0; s[i]; ++i) {
        if(s[i] == x[0]) {
            const char* possible_occurence = &s[i];
            int j = 0;
            
            while(true) {
                ++j;
                if(!x[j]) {
                    std::cout << "\nfound!";
                    return possible_occurence;
                } else if(x[j] != s[i+j]) break;
            } 
        }
    }
    std::cout << "\nnot found!";
    return nullptr;
}

int main() {
    const char* c = "indefatigibility";

    const char* d = "inde";
    const char* e = "wrong";
    const char* f = "fatigibi";
    const char* g = "gibility";
    const char* h = "frank";
    const char* i = "bili";
    const char* j = "defi";

    findx(c, d);
    findx(c, e);
    findx(c, f);
    findx(c, g);
    findx(c, h);
    findx(c, i);
    findx(c, j);

}

