#include <iostream>
#include <vector>


int main() {
    //Static storage
    int arr[6] = {1, 2, 3, 4, 5, 6};
    std::cout << "Static storage: \n";

    for(int i = 0; arr[i]; ++i) 
        std::cout << " \t=> " << &arr[i] << '\n';


    //Heap storage
    std::cout << "\nHeap storage: \n";

    int* p = new int[6];
    for(int i = 0; p[i]; ++i) {
        *(p+i) = i*2;
    }
    
    for(int i = 0; p[i]; ++i) {
        std::cout << " \t=>" << p+i << '\n';
    } 

    //Stack storage
    std::cout << "\nStack storage: \n";
    std::vector<char> char_vec;

    for(int i = 0; i < 6; ++i) {
        char ch;
        std::cin >> ch;
        char_vec.push_back(ch);
    } 
    for(int i = 0; i < char_vec.size(); ++i) {
        char* p = &(char_vec[i]);
        std::cout << " \t=> " << p << '\n';
    }

    

    

}