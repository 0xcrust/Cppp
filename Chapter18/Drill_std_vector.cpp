/**
 * @file Drill_std_vector.cpp
 * @author Ademola
 * @brief 
 * @version 0.1
 * @date 2022-07-06
 * 
 * @copyright Copyright (c) 2022
 * 
 *  1. Define a global vector<int> gv ; initialize it with ten int s, 1, 2, 4, 8, 16, etc.
    2. Define a function f() taking a vector<int> argument.
    3. In f() :
        a. Define a local vector<int> lv with the same number of elements as the
        argument vector .
        b. Copy the values from gv into lv .
        c. Print out the elements of lv .
        d. Define a local vector<int> lv2 ; initialize it to be a copy of the argument
        vector .
        e. Print out the elements of lv2 .
    4. In main() :
        a. Call f() with gv as its argument.
        b. Define a vector<int> vv , and initialize it with the first ten factorial val-
        ues (1, 2*1, 3*2*1, 4*3*2*1, etc.).
        c. Call f() with vv as its argument.
 */

#include <iostream>
#include <vector>

int factorial(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    return n * factorial(n - 1);
}

std::vector<int> gv {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};

void f(std::vector<int> v) {
    std::cout << "\n\nf()...\n";

    std::vector<int> lv(v.size());
    for(int i = 0; i < v.size(); ++i) {
        lv[i] = v[i];
    }

    std::cout << "Printing elements of lv: \n";
    for(int i = 0; i < lv.size(); ++i) {
        std::cout <<  "\tlv[" << i << "]: " << lv[i] <<  "\n";
    }

    std::vector<int> lv2 = v;
    std::cout << "Printing elements of lv2: \n";
    for(int i = 0; i < lv2.size(); ++i) {
        std::cout << "\tlv2[" << i << "]: " << lv[i] << "\n";
    }
}

int main() {
    f(gv);

    std::vector<int> vv(10);
    for(int i = 0; i < vv.size(); ++i) {
        vv[i] = factorial(i+1);
    }
    f(vv);

}