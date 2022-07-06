#include <iostream>

const char* findx(const char* s, const char* x) {
    for(int i = 0; *(s+i); ++i) {
        if(*(s+i) == x[0]) {
            int index = i;

            for(int j = 0; *(s+j); ++j) {
                if(!*(x+j)) {
                    std::cout << "\nfound!";
                    return s+index;
                } else if(*(x+j) != *(s+i+j)) break;
            }
        }
    }
    std::cout << "\nnot found!";
    return nullptr;
}


int main() {

    char word[] = "indefatigibility";

    char d[] = "inde";
    char e[] = "wrong";
    char f[] = "fatigibi";
    char g[] = "gibility";
    char h[] = "frank";
    char i[] = "bili";
    char j[] = "defi";
    char k[] = "lityfreestyle";

    findx(word, d);
    findx(word, e);
    findx(word, f);
    findx(word, g);
    findx(word, h);
    findx(word, i);
    findx(word, j);
    findx(word, k);

}