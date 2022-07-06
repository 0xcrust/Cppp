/**
 * @file Drill_array.cpp
 * @author Ademola (crustydev)
 * @brief 
 * @version 0.1
 * @date 2022-07-06
 * 
 * @copyright Copyright (c) 2022
 * 
 *  1. Define a global int array ga of ten int s initialized to 1, 2, 4, 8, 16, etc.
    2. Define a function f() taking an int array argument and an int argument
   indicating the number of elements in the array.
    3. In f() :  
        a. Define a local int array la of ten int s.
        b. Copy the values from ga into la .
        c. Print out the elements of la .
        d. Define a pointer p to int and initialize it with an array allocated on the
        free store with the same number of elements as the argument array.
        e. Copy the values from the argument array into the free-store array.
        f. Print out the elements of the free-store array.
        g. Deallocate the free-store array.
    4. In main() :
        a. Call f() with ga as its argument.
        b. Define an array aa with ten elements, and initialize it with the first ten
        factorial values (1, 2*1, 3*2*1, 4*3*2*1, etc.).
        c. Call f() with aa as its argument.
 */

#include <iostream>

int ga[10] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};

void f(int arr[], int size);

int factorial(int n) {
    if (n <= 0) {
        std::cerr << "Can't find the factorial of a zero or non-positive number\n";
        return 0;
    }
    if (n == 1) return 1;
    return n * factorial(n - 1);
}

int main() {
    f(ga, 10);

    int aa[10];
    for(int i = 0; i < 10; ++i) {
        aa[i] = factorial(i+1);
    }
    f(aa, 10);
}

void f(int arr[], int size) {
    std::cout << "\n\nf()...\n";
    int la[10];

    for(int i = 0; i < size; ++i) {
        la[i] = arr[i];
    }

    std::cout << "Printing elements of la: \n";
    for(int i = 0; i < size; ++i) {
        std::cout << "\tla["<<i<< "]: " << la[i] << '\n';
    }

    int* p = new int[size];

    for(int i = 0; i < size; ++i) {
        p[i] = arr[i];
    }

    std::cout << "\nPrinting elements of free-store array: \n";
    for(int i = 0; i < size; ++i) {
        std::cout << "\tp["<<i<< "]: " << p[i] << '\n';
    }

    delete[] p;
}