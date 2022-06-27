/**
 * @file Ex_5.cpp
 * @author Ademola
 * @brief 
 * Write a function, char* findx(const char* s, const char* x), that finds the 
 * first occurence of the C-style string x in s.
 * @version 0.1
 * @date 2022-06-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>

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

