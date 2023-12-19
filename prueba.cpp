#include <iostream>
#include <bitset>

using namespace std;

string numberToBinary(int number) {
    string binary;
    while (number > 0) {
        binary = to_string(number % 2) + binary;
        number /= 2;
    }
    return binary;
}

// Esta función convierte un número decimal a su representación binaria en formato IEEE 754.
string decimalToBinaryIEEE754(float number) {
    // Convert the float number to an unsigned int using reinterpret_cast.
    // This allows us to access the binary representation of the float.
    bitset<32> binary(*reinterpret_cast<unsigned int*>(&number));
    
    // Convert the binary representation to a string.
    string binaryString = binary.to_string();
    
    // Extract the sign, mantissa, and exponent from the binary string.
    string sign = binaryString.substr(0, 1);
    string mantissa = binaryString.substr(9, 23);
    string exponent = binaryString.substr(1, 8);
    
    // Return the binary representation in the format: sign | mantissa | exponent.
    return sign + "|" + mantissa + "|" + exponent;
}

int main() {
    int input;
    cout << "Enter a number: ";
    cin >> input;

    string binary = numberToBinary(input);
    cout << "Binary: " << binary << endl;

    float decimal;
    cout << "Enter a decimal number: ";
    cin >> decimal;

    string binaryIEEE754 = decimalToBinaryIEEE754(decimal);
    cout << "Binary (IEEE754): " << binaryIEEE754 << endl;

    return 0;
}
