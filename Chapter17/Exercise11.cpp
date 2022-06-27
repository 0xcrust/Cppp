/**
 * @file Exercise11.cpp
 * @author Ademola
 * @brief
 * Complete the "list of gods" example and run it. 
 * @version 0.1
 * @date 2022-06-26
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>


class Link{
public:
    std::string value;

    Link(const std::string& v, Link* p = nullptr, Link* s = nullptr)
        :value{v}, prev{p}, succ{s} {}

    Link* insert(Link* n);                  
    Link* add(Link* n);
    Link* erase();
    Link* find(const std::string& s);
    const Link* find(const std::string& s) const;
    const Link* advance(int n) const;

    Link* next() const { return succ; }
    Link* previous() const { return prev; } 
private:
    Link* prev;
    Link* succ;
};

Link* Link::insert(Link* n) {
    if(n == nullptr) return this;
    if(this == nullptr) return n;
    n -> succ = this;
    if (prev) prev -> succ = n;
    n -> prev = prev;
    prev = n;
    return n;
}

Link* Link::add(Link* n) {
    if(n == nullptr) return this;
    if(this == nullptr) return n;
    n -> prev = this;
    if(succ) succ -> prev = n;
    n -> succ = succ;
    succ = n;
    return n;
}

Link* Link::erase() {
    if(this == nullptr) return nullptr;
    if(succ) succ -> prev = prev;
    if(prev) prev -> succ = succ;
    return succ;
}

Link* Link::find(const std::string& s) {
    Link* p = this;
    while(p) {
        if (p->value == s) return p;
        p = p-> next();
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
        if(prev == nullptr) return nullptr;
        return prev->advance(++n);
    }
    return this;
}

void print_all(Link* p) {
    std::cout << "{";
    while(p) {
        std::cout << p-> value;
        if(p=p->next()) std::cout << ",";
    }
    std::cout << "}";
}

int main() {

    Link* norse_gods = new Link{"Thor"};
    norse_gods = norse_gods->insert(new Link{"Odin"});
    norse_gods = norse_gods->insert(new Link{"Zeus"});
    norse_gods = norse_gods->insert(new Link{"Freia"});

    Link* greek_gods = new Link{"Hera"};
    greek_gods = greek_gods->insert(new Link{"Athena"});
    greek_gods = greek_gods->insert(new Link{"Mars"});
    greek_gods = greek_gods->insert(new Link{"Poseidon"});

    Link* p = greek_gods->find("Mars");
    if (p) p->value = "Ares";

    Link* p2 = norse_gods->find("Zeus");
    if (p2) {
        if (p2==norse_gods) norse_gods = p2->next();
        p2->erase();
        greek_gods = greek_gods->insert(p2);
    }

    print_all(norse_gods);
    std::cout << "\n";

    print_all(greek_gods);
    std::cout << "\n";
}