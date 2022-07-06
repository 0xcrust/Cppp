/**
 * @file Ex_4.cpp
 * @author Ademola
 * @brief 
 * Write a function, char* strdup(const char*), that copies a C-style string
 * into memory it allocates on the free store. Do not use any standard library
 * functions.
 * @version 0.1
 * @date 2022-06-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>

char* strdup(const char* s) {
    int size = 0;
    for(int i = 0; s[i]; ++i) {
        ++size;
    }

    char* a = new char[size];
    for(int i = 0; i < size; ++i) {
        a[i] = s[i];
    }

    std::cout << "\n\nstrdup(): Contents of copied string: \n\t";
    for(int i = 0; i < size; ++i) {
        std::cout << a[i]; 
    }

    return a;
}

int main() {
    char c[] = "rascallion";
    char d[] = "test";

    strdup(c);
    strdup(d);

}