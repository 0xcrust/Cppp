/**
 * @file Exercise9.cpp
 * @author Ademola
 * @brief 
 * Which way does the stack grow: up (toward higher addresses) or down (to-
 * ward lower addresses)? Which way does the free store initially grow (that
 * is, before you use delete )? Write a program to determine the answers.
 * @version 0.1
 * @date 2022-06-26
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>

int main() {
    // Stack experiment
    std::cout << "\nSTACK EXPERIMENT: \n";
    int x = 2;
    int y = 3;
    int z = 4;

    std::cout << &x << std::endl;
    std::cout << &y << std::endl;
    std::cout << &z << std::endl;

    // Free store experiment
    std::cout << "\nHEAP EXPERIMENT: \n";
    int* p = new int[3];

    std::cout << &p[0] << std::endl;
    std::cout << &p[1] << std::endl;
    std::cout << &p[2] << std::endl;
}