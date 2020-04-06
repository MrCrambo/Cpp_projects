#include <iostream>

using namespace std;

class Animal{
public:
    Animal(const string& n) 
        :Name(n)
    { };

    const string Name;
};

class Dog : public Animal{
public:
    Dog(const string& n)
        :Animal(n)
    { };

    void Bark(){
        cout << Name << " barks: woof!" << endl;
    }
};
