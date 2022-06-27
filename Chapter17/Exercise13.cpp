/**
 * @file Exercise13.cpp
 * @author Ademola
 * @brief
 * Modify the Link class from §17.10.1 to hold a value of a struct God .
 * struct God should have members of type string : name, mythology, ve-
 * hicle, and weapon. For example, God{"Zeus", "Greek", "", "lightning"}
 * and God{"Odin", "Norse", "Eight-legged flying horse called Sleipner",
 * Spear called Gungnir"} . Write a print_all() function that lists gods with
 * their attributes one per line. Add a member function add_ordered() that
 * places its new element in its correct lexicographical position. Using the
 * Link s with the values of type God , make a list of gods from three mythol-
 * ogies; then move the elements (gods) from that list to three lexicographi-
 * cally ordered lists — one for each mythology. 
 * @version 0.1
 * @date 2022-06-26
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <vector>

struct God {
    God(const std::string& n, const std::string& m, const std::string&v,
            const std::string&w) : name{n}, mythology{m}, vehicle{v}, weapon{w} {};
    std::string name;
    std::string mythology;
    std::string vehicle;
    std::string weapon;
};

std::ostream& operator<<(std::ostream& os, God g) {
    return os << '\n' << g.name << "\n\t" << g.mythology << "\n\t" << g.vehicle << 
                "\n\t" << g.weapon;
}

class Link{
public:
    God value;

    Link(const std::string& n, const std::string& m, const std::string& v,
            const std::string& w, Link* p = nullptr, Link* s = nullptr)
        :value{n,m,v,w}, prev{p}, succ{s} {}

    Link* insert(Link* n);                  
    Link* add(Link* n);
    Link* erase();
    Link* find(const std::string& s);

    const Link* find(const std::string& s) const;
    const Link* advance(int n) const;

    Link* add_ordered(Link* n);

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
        if (p->value.name == s) return p;
        p = p-> next();
    }
    return nullptr;
}

// Exercise 12. This second find() handles a case where we want to call find() for
// a const Link
const Link* Link::find(const std::string& s) const {
    if(value.name == s) return this;
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


Link* Link::add_ordered(Link* n) {
    if(value.name > n->value.name) {
        prev = n;
        n->succ = this;
        return n;
    }
    else {
        Link* p = this;
        while(p->succ) {
            if(p->value.name < n->value.name &&
                    n->value.name < p->succ->value.name) {
                p->add(n);
                return this;
            }
            p = p->succ;
        }
        p->add(n);
    }
    return this;
}

void print_all(Link* p) {
    while(p) {
        std::cout << p-> value;
        if(p=p->next()) std::cout << '\n';
    }
}

int main() {

    Link* thor = new Link{"Thor", "Norse", "Chariot", "Mjolnir"};
    Link* odin = new Link{"Odin", "Norse", "Eight-legged flying horse called Sleipner", "Spear called Gungnir"};
    Link* loki = new Link{"Loki", "Norse", "Beast", "Wits and trickery"};
    Link* freia = new Link{"Freia", "Norse", "Chariot","Spear"};
    std::vector<Link*> norse_gods = {thor, odin, loki, freia};

    Link* hera = new Link{"Hera", "Greek", "Pegasus", "Scepter"};
    Link* athena = new Link{"Athena", "Greek", "Chariot", "Dagger"};
    Link* ares = new Link{"Ares", "Greek", "Big horse", "Big sword"};
    Link* poseidon = new Link{"Poseidon", "Greek", "Chariot", "Trident"};
    std::vector<Link*> greek_gods = {hera, athena, ares, poseidon};

    Link* jupiter = new Link{"Jupiter", "Roman", "Clouds", "Lightning bolt"};
    Link* neptune = new Link{"Neptune", "Roman", "Sea-beasts", "Trident"};
    Link* pluto = new Link{"Pluto", "Roman", "Skeletal horses", "Sceptre of death"};
    Link* mars = new Link{"Mars", "Roman", "Big chariot", "Big horse"};
    std::vector<Link*> roman_gods = {jupiter, neptune, pluto, mars};

    Link* ordered_norse_gods = new Link{"Tyr", "Norse", "Horse", "Scythe"};
    Link* ordered_greek_gods = new Link{"Athena", "Greek", "Chariot", "Dagger and a sharp wit"};
    Link* ordered_roman_gods = new Link{"Minvera", "Roman", "Chariot", "Dagger"};

    for(auto p : norse_gods) {
        ordered_norse_gods = ordered_norse_gods->add_ordered(p);
    }
    
    for(auto q : greek_gods) {
        ordered_greek_gods = ordered_greek_gods->add_ordered(q);
    }

    for(auto r : roman_gods) {
        ordered_roman_gods = ordered_roman_gods->add_ordered(r);
    }

    std::cout << "ORDERED NORSE GODS: \n";
    print_all(ordered_norse_gods);
    std::cout << "\n";

    std::cout << "\n\nORDERED GREEK GODS: \n";
    print_all(ordered_greek_gods);
    std::cout << "\n";

    std::cout << "\n\nORDERED ROMAN GODS: \n";
    print_all(ordered_roman_gods);
    std::cout << "\n";
}