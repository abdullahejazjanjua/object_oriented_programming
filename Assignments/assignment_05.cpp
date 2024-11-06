// Include necessary libraries
#include <iostream>
using namespace std;

// Define the CMString class
class CMString
{
    char *userInput; // Pointer to store the string
    int size = 50; // Default size for the string

public:
    // Constructors and Destructor
    CMString() // Default constructor
    {
        userInput = new char[size];
        userInput[0] = '\0'; // Initialize with null character
    }
    //Csonstructor that takes size of string
    CMString(int size) 
    { 
        this->size = size;
        userInput = new char[size + 1];
        userInput[size] = '\0'; 
    }
    CMString(string s) //constructor which takes string
    {
        int len = s.length();
        userInput = new char[len + 1];
        userInput[len] = '\0';
        for (int i = 0; i < len; i++)
        {
            userInput[i] = s[i];
        }
    }
    ~CMString() { delete[] userInput; } // Destructor

    // Copy constructor
    CMString(const CMString &other)
    {
        int len = length(other.userInput) + 1;
        userInput = new char[len];
        userInput[len] = '\0';
        for (int i = 0; i < len; i++)
        {
            userInput[i] = other.userInput[i];
        }
    }

    // Copy assignment operator
    CMString &operator=(const CMString &other);
    // Concatenation operators
    CMString operator+(const CMString &temp);
    CMString operator+=(const CMString &temp);
    // Comparison operators
    bool operator==(const CMString &temp);
    bool operator!=(const CMString &temp);
    bool operator>(const CMString &temp);
    bool operator<(const CMString &temp);
    // Subscript operator
    char& operator[](int position);
    // Friend functions for input and output
    friend ostream& operator<<(ostream &output, CMString other);
    friend istream& operator>>(istream &input, CMString other);
    // Substring extraction and shifting operators
    CMString operator()(int start, int length);
    CMString operator>>(int shift);
    CMString operator<<(int shift);
    //Gets length of char array
    int length(const char *s);
    //gets lenght of string
    int length() { return length(userInput); }

};

// Main function
int main()
{
    // Create instances of CMString
    CMString a("ABCDEFG");
    CMString b("1234567");
    CMString c, d;
    string s;
    cout << "\na: " << a;
    cout << "\nb: " << b;
    // Concatenation and compound assignment
    c = a + b;
    a += b;
    cout << "\n\nc = a + b: " << c;
    cout << "\na += b: " << a;

    // Comparison operations
    cout << "\n\n\nCOMPARISON OPERATOR TEST: \n";
    if (a == c)
    {
        cout << "\na is equal to c";
    }
    if (a != b)
    {
        cout << "\na is NOT equal to b";
    }
    if (a > b)
    {
        cout << "\na is greater than b";
    }
    if (b < a)
    {
        cout << "\nb is less than a";
    }
    cout << "\n\n\nCIN OPERATOR TEST: \n";
    cout << "\nEnter a string: ";
    cin >> s;
    CMString e(s), f;
    cout << "cin: " << e;
    // Subscript operator and substring extraction
    cout << "\n\na[1]: " << a[1];
    d = a(0, 3);
    cout << "\n\nSubstring: " << d;
    f = e;
    cout << "\n\nf = e: " << f;
    e[0] = '2';
    cout << "\n\ne[0] = '2': " << e; 
    // Shifting operators
    cout << "\n\n\nLEFT & RIGHT SHIFT: \n";
    c = b << 1;
    cout << "\nc = b << 1: " << c;
    cout << "\nb: " << b;
    c = b >> 1;
    cout << "\nc = b >> 1: " << c;
    cout << "\nb: " << b;

    return 0;
}

// Member function definitions
CMString CMString :: operator+(const CMString &temp)
{
    // Concatenate two strings
    int len = length(userInput) + length(temp.userInput) + 1;
    char *buffer = new char[len];
    int i;
    for (i = 0; userInput[i] != '\0'; i++)
    {
        buffer[i] = userInput[i];
    }
    for (int j = 0; j < length(temp.userInput); j++, i++)
    {
        buffer[i] = temp.userInput[j];
    }
    buffer[i] = '\0';
    CMString result(buffer);
    delete[] buffer;
    return result;
}

CMString CMString :: operator+=(const CMString &temp)
{
    // Append a string to the current string
    int len = length(userInput) + length(temp.userInput) + 1;
    char *buffer = new char[len];
    int i;
    for (i = 0; userInput[i] != '\0'; i++)
    {
        buffer[i] = userInput[i];
    }
    for (int j = 0; j < length(temp.userInput); j++, i++)
    {
        buffer[i] = temp.userInput[j];
    }
    buffer[i] = '\0';
    userInput = buffer;
    return *this;
}

int CMString :: length(const char *s)
{
    // Calculate the length of a string
    int len = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        len++;
    }
    return len;
}

CMString& CMString :: operator=(const CMString &other)
{
    // Assignment operator
    if (this != &other)
    {
        delete[] userInput;
        int len = length(other.userInput) + 1;
        userInput = new char[len];
        userInput[len] = '\0';
        for (int i = 0; i < len; i++)
        {
            userInput[i] = other.userInput[i];
        }
    }
    return *this;
}

char& CMString :: operator[](int position)
{
    // Subscript operator
    if (position >= 0 || position < length(userInput))
        return userInput[position];
}

bool CMString :: operator==(const CMString &other)
{
    // Equality operator
    for (int i = 0; i < length(other.userInput); i++)
    {
        if (userInput[i] == other.userInput[i])
            return true;
    }
    return false;
}

bool CMString :: operator!=(const CMString &other)
{
    // Inequality operator
    if (this != &other)
        return true;
    return false;
}

bool CMString :: operator>(const CMString &other)
{
    // Greater than operator
    for (int i = 0; i < length(other.userInput); i++)
    {
        if (userInput[i] > other.userInput[i])
            return true;
    }
    return false;
}

bool CMString :: operator<(const CMString &other)
{
    // Less than operator
    for (int i = 0; i < length(other.userInput); i++)
    {
        if (userInput[i] < other.userInput[i])
            return true;
    }
    return false;
}

CMString CMString :: operator()(int start, int l)
{
    // Substring extraction operator
    int last = 0, subStrLength;
    if (start < 0)
        cout << "\nInvalid start point";

    last = l - start;
    if (last > length(userInput))
        cout << "\nInvalid end point";
    subStrLength = last - start + 1;
    char *buffer = new char[subStrLength];
    for (int i = start; i < subStrLength; i++)
    {
        buffer[i] = userInput[i];
    }
    buffer[subStrLength] = '\0';
    CMString result(buffer);
    delete[] buffer;
    return result;
}

ostream& operator<<(ostream &output, CMString other)
{
    // Overloaded output operator
    output << other.userInput;
    return output;
}

istream& operator>>(istream &input, CMString other)
{
    // Overloaded input operator
    input >> other.userInput;
    return input;
}

CMString CMString::operator<<(int shift) 
{
    // Right shift operator
    if (shift <= 0) {
        return CMString(""); // Return an empty string if shift is invalid
    }

    int len = length(userInput);
    int shiftedLen = len - shift;

    char* newInput = new char[shiftedLen + 1]; // Allocate memory for the new string
    char* removed = new char[shift + 1]; // Allocate memory for the removed string

    for (int i = 0; i < shiftedLen; i++) 
    {
        newInput[i] = userInput[i + shift];
    }
    newInput[shiftedLen] = '\0';

    for (int i = 0; i < shift; i++) 
    {
        removed[i] = userInput[i];
    }
    removed[shift] = '\0';

    CMString temp(removed);
    
    delete[] userInput;
    userInput = newInput;
    
    delete[] removed; // Deallocate memory for removed characters
    return temp;
}


CMString CMString::operator>>(int shift) {
    // Left shift operator
    if (shift <= 0) 
    {
        return CMString(""); // Return an empty string if shift is invalid
    }

    int len = length(userInput);
    int shiftedLen = len - shift;

    char* newInput = new char[shiftedLen + 1]; // Allocate memory for the new string
    char* removed = new char[shift + 1]; // Allocate memory for the removed string

    for (int i = 0;  i < shiftedLen; i++) 
    {
        newInput[i] = userInput[i];
    }
    newInput[shiftedLen] = '\0';
    int j = 0;
    int i = len - 1; // Start from the last index of the string
    while (j < shift) 
    {
        removed[j] = userInput[i]; // Copy characters in reverse order
        j++;
        i--;
    }
    removed[j] = '\0'; // Null terminate the removed string


    CMString temp(removed);

    delete[] userInput;
    userInput = newInput;

    delete[] removed; // Deallocate memory for removed characters
    return temp;
}
