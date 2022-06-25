/**
 * @file Drill.cpp
 * @author Ademola
 * @version 0.1
 * @date 2022-06-24
 * 
 * 1. Allocate an array of ten int s on the free store using new .
 * 2. Print the values of the ten int s to cout .
 * 3. Deallocate the array (using delete[] ).
 * 4. Write a function print_array10(ostream& os, int* a) that prints out the
 *    values of a (assumed to have ten elements) to os .
 * 5. Allocate an array of ten int s on the free store; initialize it with the values
 *    100, 101, 102, etc.; and print out its values.
 * 6. Allocate an array of 11 int s on the free store; initialize it with the values
 *    100, 101, 102, etc.; and print out its values.
 * 7. Write a function print_array(ostream& os, int* a, int n) that prints out the
 *    values of a (assumed to have n elements) to os .
 * 8. Allocate an array of 20 ints on the free store; initialize it with the values
 *    100, 101, 102, etc.; and print out its values.
 * 9. Did you remember to delete the arrays? (If not, do it.)
 * 10. Do 5, 6, and 8 using a vector instead of an array and a print_vector()
 *      instead of print_array() .
 * 
 */

#include <iostream>
#include <ostream>

void print_array10(std::ostream&, int*);
void print_array(std::ostream&, int*, int);

int main() {
    // (1) Allocate array of ten ints on free store
    int* numbers = new int[10];
    // (2) Print numbers"
    std::cout << "Printing contents of array numbers:\n";
    for(int i = 0; i < 10; ++i) {
        std::cout << '\t' << numbers[i] << '\n';
    }
    // (3) Deallocate numbers
    delete[] numbers;

    // (5)
    int* a = new int[10];
    std::cout << "\nThe contents of array a: \n";
    for(int i = 0; i < 10; ++i) {
        a[i] = 100 + i;
        std::cout << '\t' << a[i] << '\n';
    }

    // (6)
    int* b = new int[11];
    std::cout << "\nThe contents of array b are:\n";
    for(int i = 0; i < 11; ++i) {
        b[i] = 100 + i;
        std::cout << '\t' << b[i] << '\n';
    } 

    // (8)
    int* c = new int[20];
    std::cout << "\nThe contents of array c are:\n";
    for(int i = 0; i < 20; ++i) {
        c[i] = 200 + i;
        std::cout << '\t' << c[i] << '\n';
    }

    print_array10(std::cout, a);
    print_array(std::cout, c, 20);

    // (9)
    delete[] a;
    delete[] b;
    delete[] c;

}

// (4)
void print_array10(std::ostream& os, int* a) {
    // a is assumed to have ten elements
    std::cout << "\nPrinting elements of array: \n";
    for(int i = 0; i < 10; ++i) {
        os << '\t' << a[i] << '\n';
    }
}

// (7)
void print_array(std::ostream& os, int* a, int n) {
    // n is size of array a
    std::cout << "\nPrinting out array: \n";
    for(int i = 0; i < n; ++i) {
        os << '\t' << a[i] << '\n';
    }
}