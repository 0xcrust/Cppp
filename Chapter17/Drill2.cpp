/**
 * @file 0. Drill2.cpp
 * @author Ademola
 * @brief 
 * @version 0.1
 * @date 2022-06-25
 * 
 * 1. Allocate an int , initialize it to 7, and assign its address to a variable p1 .
 * 2. Print out the value of p1 and of the int it points to.
 * 3. Allocate an array of seven int s; initialize it to 1, 2, 4, 8, etc.; and assign its
 *    address to a variable p2 .
 * 4. Print out the value of p2 and of the array it points to.
 * 5. Declare an int* called p3 and initialize it with p2 .
 * 6. Assign p1 to p2 .
 * 7. Assign p3 to p2 .
 * 8. Print out the values of p1 and p2 and of what they point to.
 * 9. Deallocate all the memory you allocated from the free store.
 * 
 * 
 */

#include <iostream>
#include <vector>


int main() {
    // (1)
    int a = 7;
    int* p1 = &a;

    // (2)
    std::cout << "Value of pointer p1 is: " << p1;
    std::cout << "\nNumber being pointed to is: " << *p1;

    // (3)
    int* p2 = new int[7]{1, 2, 4, 6, 16, 32, 64};

    // (4)
    std::cout << "\n\nValue of pointer p2 is:" << p2;
    std::cout << "\nArray pointed to by p2 is: \n";
    for(int i = 0; i < 7; ++i) {
        std::cout << '\t' << p2[i] << '\n';
    }

    // (5)
    int* p3 = p2;

    // (6)
    p2 = p1;

    // (7)
    p2 = p3;

    // (8)
    std::cout << "\n\nNew value of p1 is: " << p1;
    std::cout << "\nNew value of p2 is: " << p2;

    std::cout << "\n\np1 points to: " << *p1;
    std::cout << "\np2 points to: " << *p2;

    // (9)
    delete[] p2;

    // (10)
    int arr1[10]{1, 2, 4, 8, 16, 32, 64, 128, 256, 512};
    
    // (11)
    int arr2[10];

    // (12)
    for(int i = 0; i < 10; ++i) {
        arr2[i] = arr1[i];
    }
    std::cout << "\n\nContents of arr2: \n";
    for(int i = 0; i < 10; ++i) {
        std::cout << '\t' << arr2[i] << '\n';
    }

    // (13)
    std::vector<int> v1 = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};
    std::vector<int> v2(10);

    v2 = v1;
    std::cout << "\n\nContents of v2: \n";
    for(int i = 0; i < v2.size(); ++i) {
        std::cout << '\t' << v2[i] << '\n';
    }
}