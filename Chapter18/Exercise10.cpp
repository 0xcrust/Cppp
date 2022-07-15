/**
 * @file Exercise10.cpp
 * @author Ademola
 * @brief 
 * Look at the “array solution” to the palindrome problem in §18.7.2. Fix it
   to deal with long strings by (a) reporting if an input string was too long
   and (b) allowing an arbitrarily long string. Comment on the complexity
   of the two versions.
 * @version 0.1
 * @date 2022-07-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <cstring>

using namespace std;

bool is_palindrome(const char s[], int n) {
    int first = 0;
    int last = n-1;
    while(first < last) {
        if(s[first]!=s[last]) return false;
        ++first;
        --last;
    }
    return true;
}

std::istream& read_word(std::istream& is, char* buffer, int max)
{
    is >> buffer;

    if (strlen(buffer) >= max)
        throw std::runtime_error("string too large to check");

    return is;
}

int main() {

    try {
        constexpr int max = 128;
        for(char s[max]; read_word(cin, s, max);) {
        cout << s << " is";
        if(!is_palindrome(s, strlen(s))) cout << " not";
        cout << " a palindrome\n";
    }
    } catch (std::exception& e){
        std::cerr << "Exception: " << e.what() << '\n';
        return 1;
    } catch(...) {
        std::cerr << "Unknown exception!\n";
        return 2;
    }

}