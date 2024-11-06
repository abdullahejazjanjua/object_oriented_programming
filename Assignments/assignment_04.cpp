#include <iostream>
using namespace std;

// Define the engine class
class engine
{
    int no_of_cylinders;
    int horse_power;
public:
    // Constructor to initialize engine with default values
    engine() : no_of_cylinders(0), horse_power(0) {}

    // Method to set values for engine
    void setForE(int no_of_cylinders, int horse_power)
    {
        this->horse_power = horse_power;
        this->no_of_cylinders = no_of_cylinders;
    }

    // Getter methods for engine attributes
    int getForE_CY() const { return no_of_cylinders; }
    int getForE_HP() const { return horse_power; }
};

// Define the car class
class car
{
    string make;
    string model;
    engine E; //reference to another class
public:
    // Constructor to initialize car with default values
    car() : make("TBA"), model("TBA") {}

    // Method to set values for car and its engine
    void set(string make, string model, int no_of_cylinders, int horse_power)
    {
        this->make = make;
        this->model = model;
        E.setForE(no_of_cylinders, horse_power);
    }

    // Getter methods for car attributes
    string getForC_MA() const { return make; }
    string getForC_MO() const { return model; }

    // Method to print car information
    void printInfo() const
    {
        cout << "MAKE: " << getForC_MA();
        cout << "\nMODEL: " << getForC_MO();
        cout << "\nNo Of Cylinders: " << E.getForE_CY();
        cout << "\nHorse Power: " << E.getForE_HP();
    }
};

int main()
{
    car C1, C2;

    // Display information for C1 with provided details
    cout << "\n+----------------------+\n";
    cout << "  With INFO provided: \n";
    cout << "+-----------------------+\n\n";
    
    C1.set("Ford", "Mustang", 3, 120);
    C1.printInfo();

    // Display information for C2 without provided details
    cout << "\n\n+----------------------+\n";
    cout << "  With NO INFO provided: \n";
    cout << "+-----------------------+\n\n";

    C2.printInfo();
}