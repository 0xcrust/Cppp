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
    char word[] = "indefatigibility";

    char d[] = "inde";
    char e[] = "wrong";
    char f[] = "fatigibi";
    char g[] = "gibility";
    char h[] = "frank";
    char i[] = "bili";
    char j[] = "defi";

    findx(word, d);
    findx(word, e);
    findx(word, f);
    findx(word, g);
    findx(word, h);
    findx(word, i);
    findx(word, j);

}

