/**
 * @file Exercise14.cpp
 * @author Ademola
 * @brief
 * Write the example in 17.10.1 using a singly-linked list
 * @version 0.1
 * @date 2022-06-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>


class Link{
public:
    std::string value;
    Link* succ;

    Link(const std::string& v, Link* s = nullptr)
        :value{v}, succ{s} {}

    Link* insert(Link* n);                  
    Link* add(Link* n);
    Link* erase();
    Link* find(const std::string& s);
    const Link* find(const std::string& s) const;
    const Link* advance(int n) const;

    Link* next() const { return succ; }
};

Link* Link::insert(Link* n) {
    if(n == nullptr) return this;
    if(this == nullptr) return n;
    n->succ = this;
    return n;
}

Link* Link::add(Link* n) {
   if(n == nullptr) return this;
   if(this == nullptr) return n;
   n->succ = this->succ;
   this->succ = n;
   return this;
}

Link* Link::erase() {
    if(this == nullptr) return this;
    Link* p = this->succ;
    this->succ = nullptr;
    return p;

}

Link* Link::find(const std::string& s) {
    Link* p = this;
    while(p) {
        if (p->value == s) return p;
        p = p->succ;
    }
    return nullptr;
}

// Exercise 12. This second find() handles a case where we want to call find() for
// a const Link
const Link* Link::find(const std::string& s) const {
    if(value == s) return this;
    else if(succ) return succ->find(s);
    return nullptr;
}

const Link* Link::advance(int n) const {
    if(0 < n) {
        if(succ == nullptr) return nullptr;
        return succ->advance(--n);
    }
    else if (n < 0) {
        std::cerr << "Can't move backwards through list";
    }
    return this;
}

void print_all(Link* p) {
    std::cout << "\nPrinting..";
    while(p) {
        std::cout << "\n\t" << p-> value;
        p = p->succ;
    }
}

int main() {

    Link* norse_gods = new Link{"Freia"};
    norse_gods = norse_gods->add(new Link{"Thor"});
    norse_gods = norse_gods->add(new Link{"Odin"});
    norse_gods = norse_gods->add(new Link{"Loki"});

    print_all(norse_gods);
    std::cout << "\n";

    Link* greek_gods = new Link{"Poseidon"};
    greek_gods = greek_gods->add(new Link{"Zeus"});
    greek_gods = greek_gods->add(new Link{"Hades"});
    greek_gods = greek_gods->add(new Link{"Ares"});

    print_all(greek_gods);
    std::cout << "\n";

    Link* roman_gods = new Link{"Jupiter"};
    roman_gods = roman_gods->add(new Link{"Neptune"});
    roman_gods = roman_gods->add(new Link{"Pluto"});
    roman_gods = roman_gods->add(new Link{"Mars"});

    print_all(roman_gods);
    std::cout << "\n";
}