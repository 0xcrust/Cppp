/**
 * @file Exercise8.cpp
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
    int size = 10000;
    std::string str = "";
    char input;
    
    std::cout << "\nEnter a character followed by whitespace, '!' to quit\n";
    while(std::cin >> input && input != '!') 
        str+=input;
    
    std::cout << "\nLoop terminated!\n";
    std::cout << "String result is: " << str;
}