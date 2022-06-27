/**
 * @file Exercise7.cpp
 * @author Ademola
 * @brief 
 * Write a program that reads characters from cin into an array that you
 * allocate on the free store. Read individual characters until an exclamation
 * mark ( ! ) is entered. Do not use a std::string . Do not worry about mem-
 * ory exhaustion.
 * @version 0.1
 * @date 2022-06-26
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>

int main() {
    int size = 100;
    char* ch = new char[size];
    char input;
    
    std::cout << "\nEnter a character followed by whitespace, '!' to quit\n";
    for(int i = 0; i < size; ++i) {
        std::cin >> input;
        if(input == '!') break;
        ch[i] = input;
    }
    std::cout << "\nLoop terminated!";
}