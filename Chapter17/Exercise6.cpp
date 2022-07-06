/**
 * @file Ex_6.cpp
 * @author Ademola
 * @brief 
 * This chapter does not say what happens when you run out of memory
 * using new . That’s called memory exhaustion. Find out what happens. You have
 * two obvious alternatives: look for documentation, or write a program with
 * an infinite loop that allocates but never deallocates. Try both. Approxi-
 * mately how much memory did you manage to allocate before failing?
 * @version 0.1
 * @date 2022-06-26
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>

int main() {
    long long int loop_count = 0;
    try {
        while(true) {
        ++loop_count;
        std::cout << "\nLoop count: " << loop_count;
        char* c = new char[500000];
    }

    }
    catch(std::exception& e) {
        std::cerr << "Failed with error: " << e.what() << '\n';
        std::cerr << "Allocated 500,000 chars " << loop_count << " times.\n";
    }
}

/*
I ran this experiment on an hp pavilion 14 and got as far as 1,369,801 loops before
a crash. Doing the math (multiplied by 500,000 bytes for each allocation), that gives
684,900,500,000 bytes(684,900,500 kilobytes).
*/