/**
 * @file Ex_1-3.cpp
 * @author Ademola
 * @brief 
 * 1. What is the output format of pointer values on your implementation?
 *    Hint: Don't read the documentation.
 * 2. How many bytes are there in an int? In a double? In a bool? Do not use
 *    sizeof except to verify your answer.
 * 3. Write a function, void to_lower(char* s) , that replaces all uppercase char-
 *    acters in the C-style string s with their lowercase equivalents. For ex-
 *    ample, Hello, World! becomes hello, world! . Do not use any standard
 *    library functions. A C-style string is a zero-terminated array of characters,
 *    so if you find a char with the value 0 you are at the end.
 * @version 0.1
 * @date 2022-06-25
 * 
 */


#include <iostream>
#include <cassert>

void to_lower(char*);
void to_lower2(char*);

int main() {
    // (1)
   
    char* char_pointer = new char{'c'};
    int* int_pointer = new int{3};
    double* double_pointer = new double{4.5};
    float* float_pointer = new float{5.47653};

    // std::cout is overloaded to treat a char* as a pointer to (the first character of) a
    // C-style string and print the contents of that. If you want the address instead,
    // you should cast it to a pointer that isn't treated that way
    std::cout << "\n char pointer: " << static_cast<const void*> (char_pointer);
    std::cout << "\n int pointer: " << int_pointer; 
    std::cout << "\n double pointer: " << double_pointer; 
    std::cout << "\n float pointer: " << float_pointer; 

    // (2)
    assert(sizeof(int) == 4); 
    assert(sizeof(double) == 8);
    assert(sizeof(bool) == 1);

    // (3)
    std::string s = "rAtTAtoUiLlE";
    std::string t = "wEEkEnd";

    char* s_pointer = &s[0];
    char* t_pointer = &t[0];

    char x[] = "testTestInvalidTrust";
    char y[]= "ratataTITIlily"; 

    to_lower(s_pointer);
    to_lower(t_pointer);

    to_lower(x);
    to_lower(y);

}

void to_lower(char* s) {
    // difference between uppercase and lowercase equivalent ascii representations
    constexpr int difference = 32;
    // representation of uppercase A
    constexpr int lower_bound = 65;
    // representation of uppercase B
    constexpr int upper_bound = 90;

    std::cout << "\n\n to_lower(): Printing initial string..: \n\t";
    for(int i = 0; s[i]; ++i) {
        std::cout << s[i];
    }

    std::cout << "\n to_lower(): making lower case..";
    for(int i = 0; s[i]; ++i) {
        if(s[i] >= lower_bound && s[i] <= upper_bound ) {
            s[i] += difference;
        }
    }


    std::cout << "\n to_lower(): Printing final string..: \n\t";
    for(int i = 0; s[i]; ++i) {
        std::cout << s[i];
    }
}

void to_lower2(char* s)
    // If any char code falls between A & Z increase their code by 32, the
    // difference between upper and lower-case counterparts in ASCII.
{

    std::cout << "\n\nto_lower2(): Making into lower case..:";

    constexpr int A = 65;
    constexpr int Z = 90;
    constexpr int diff = 32;

    for (int i = 0; s[i]; ++i) {
        int code = int(s[i]);

        if (A <= code && code <= Z)
            s[i] += diff;
            std::cout << s[i];
    }
}