/**
 * @file Exercise1.cpp
 * @author Ademola
 * @brief 
 * @version 0.1
 * @date 2022-07-06
 * 
 * @copyright Copyright (c) 2022
 * 
 * Write a function, char* strdup(const char*) , that copies a C-style string
   into memory it allocates on the free store. Do not use any standard li-
   brary functions. Do not use subscripting; use the dereference operator * instead.
 */

#include <iostream>

char* strdup(const char* str) {
    int size = 0;

    std::cout << "C-style string passed into function: \n\t";
    for(int i = 0; *(str + i); ++i) {
        ++size;
        std::cout << *(str + i);
    }

    char* ch = new char[size];

    std::cout << "\nCopied string: \n\t";
    for(int i = 0; i < size; ++i) {
        *(ch + i) = *(str + i);
        std::cout << *(ch + i);
    }
    std::cout << "\n\n";

    delete[] ch;
}

int main() {
    char aa[] = "Ademola";
    char ab[] = "Perspicacity";

    strdup(aa);
    strdup(ab);
}