/**
 * @file Exercise3.cpp
 * @author Ademola
 * @brief 
 * @version 0.1
 * @date 2022-07-06
 * 
 * @copyright Copyright (c) 2022
 * 
 * 3.
 * Write a function, int strcmp(const char* s1, const char* s2) , that compares
   C-style strings. Let it return a negative number if s1 is lexicographically
   before s2 , zero if s1 equals s2 , and a positive number if s1 is lexicograph-
   ically after s2 . Do not use any standard library functions. Do not use
   subscripting; use the dereference operator * instead.
 * 4.
   Consider what happens if you give strdup() , findx() , and strcmp() an argu-
   ment that is not a C-style string. Try it! First figure out how to get a char*
   that doesn’t point to a zero-terminated array of characters and then use
   it (never do this in real — non-experimental — code; it can create havoc).
   Try it with free-store-allocated and stack-allocated “fake C-style strings.”
 */

#include <iostream>


int strcmp(const char* s1, const char* s2) {
    while(*s1) {
        if(!*s2) {
            std::cout << "s1 is after s2!\n\n";
            return 1;
        }
       
        if(*s1 < *s2) {
            std::cout << "s1 is before s2!\n\n";
            return -1;
        }
        if(*s1 > *s2) {
            std::cout << "s1 is after s2!\n\n";
            return 1;
        }
        ++s1;
        ++s2;
    }
    if(!*s2) {
        std::cout << "s1 is equal to s2!\n\n";
        return 0;
    } else {
        std::cout << "s1 is before s2!\n\n";
        return -1;
    }
}

int main() {
    
    char aa[] = "royal";
    char ab[] = "royal";

    char ac[] = "royalty";
    char ad[] = "roy";

    char ae[] = "arena";
    char af[] = "arteta";

    char ag[] = "brent";
    char ah[] = "brentford";

    char ai[] = "a";
    char aj[] = "a";
    char ak[] = "ada";

    std::cout << "=> arena, royal\n\t";
    //arena, royal
    strcmp(ae, aa);

    std::cout << "=> arena, arteta\n\t";
    //arena, arteta
    strcmp(ae, af);

    std::cout << "=> arteta, brentford\n\t";
    //arteta, brentford
    strcmp(af, ag);

    std::cout << "=> royal, royal\n\t";
    //royal, royal
    strcmp(aa, ab);

    std::cout << "=> roy, royalty\n\t";
    //roy, royalty
    strcmp(ad, ac);

    std::cout << "=> royalty, royal\n\t";
    //royalty, royal
    strcmp(ac, aa);

    std::cout << "=> brent, brentford\n\t";
    //brent, brentford
    strcmp(ag, ah);

    std::cout << "=> brentford, brent\n\t";
    //brentford, brent
    strcmp(ah, ag);

    std::cout << "=> a, a\n\t";
    //a, a
    strcmp(ai, aj);

    std::cout << "=> ada, a\n\t";
    //ada, a
    strcmp(ak, aj);

    // Exercise 4
    char c[] {'r', 'o', 'y', 'a', 'l'};
    char d[] {'r', 'o', 'y'};
    char e[] {'r', 'o', 'y', 'a', 'l', 't', 'y'};
    char f[] {'p', 'r', 'i', 'd', 'e'};
    char g[] {'b', 'r', 'e', 'n', 't', 'f', 'o', 'r', 'd'};
    char h[] {'b', 'r', 'e', 'n', 't'};

    try {
        strcmp(c, d); //incorrect result
        strcmp(d, e); //incorrect result
        strcmp(c, e); //works fine
        strcmp(e, f); //works fine
        strcmp(g, h); //incorrect result
        strcmp(h, g); //incorrect result
        strcmp(c, c); //works fine
        strcmp(g, g); //works fine

    } catch(std::exception& e) {
        std::cerr << e.what() << '\n';
        return 1;
    } catch(...) {
        std::cerr << "Unknown exception\n";
        return 2;
    }
}