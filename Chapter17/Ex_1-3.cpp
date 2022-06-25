/**
 * @file Ex_1-3.cpp
 * @author Ademola
 * @brief 
 * @version 0.1
 * @date 2022-06-25
 * 
 * 1. What is the output format of pointer values on your implementation?
 *    Hint: Don't read the documentation.
 * 2. How many bytes are there in an int? In a double? In a bool? Do not use
 *    sizeof except to verify your answer.
 * 3. Write a function, void to_lower(char* s) , that replaces all uppercase char-
 *    acters in the C-style string s with their lowercase equivalents. For ex-
 *    ample, Hello, World! becomes hello, world! . Do not use any standard
 *    library functions. A C-style string is a zero-terminated array of characters,
 *    so if you find a char with the value 0 you are at the end.
 * 
 */

#include <iostream>
#include <cassert>

void to_lower(char*);

int main() {
    // (1)
    char c = 'c';
    char* o = &c;
    int* p = new int{3};
    double* q = new double{4.5};
    float* r = new float{5.47653};

    std::cout << "\n char pointer: " << o;
    std::cout << "\n int pointer: " << p; 
    std::cout << "\n double pointer: " << q; 
    std::cout << "\n float pointer: " << r; 

    // (2)
    assert(sizeof(int) == 4); 
    assert(sizeof(double) == 8);
    assert(sizeof(bool) == 1);

    // (3)
    char* s = "rAtTAtoUiLlE0";
    char* t = "wEEkEnd0";

    to_lower(s);
    to_lower(t);

}


void to_lower(char* s) {
    std::cout << "\n\n to_lower(): Printing initial string..: \n\t";
    for(char* c = s; *c!=0; ++c) {
        std::cout << *c;
    }

    for(char* c = s; *c!=0; ++c) {
        *c = tolower(*c);
    }

    std::cout << "\n to_lower(): Printing final string..: \n\t";
    for(char* c = s; *c != 0; ++c) {
        std::cout << *c;
    }

}