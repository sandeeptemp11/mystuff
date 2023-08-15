#include <iostream>
using namespace std;

class car{
    public:
    string name;
    int milage;

    car(string name, int milage){
        this->name = name;
        this->milage = milage;
    }
};

int main(){
    car creta("Thar", 20);
    cout << creta.name << "\n";
}
