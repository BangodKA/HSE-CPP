#include <iostream>
#include <limits>

#include "types.hpp"

namespace types {

namespace {

char c = '1';    // символ
bool b = true;   // логическая переменная, принимает значения false и true
int i = 42;      // целое число (занимает, как правило, 4 байта)
short int si = 17;           // короткое целое (занимает 2 байта)
long li = 12321321312;       // длинное целое (как правило, 8 байт)
long long lli = 12321321312; // длинное целое (как правило, 8 байт)
float f = 2.71828;           // дробное число с плавающей запятой (4 байта)
double d = 3.141592;         // дробное число двойной точности (8 байт)
long double ld = 1e15;       // длинное дробное (как правило, 16 байт)

}

void PrintSizes() {
    std::cout << "char: " << sizeof(char) << "\n";                 //  1
    std::cout << "bool: " << sizeof(bool) << "\n";                 //  1
    std::cout << "short int: " << sizeof(short int) << "\n";       //  2 (по стандарту >= 2)
    std::cout << "int: " << sizeof(int) << "\n";                   //  4 (по стандарту >= 2)
    std::cout << "long int: " << sizeof(long int) << "\n";         //  8 (по стандарту >= 4)
    std::cout << "long long int: " << sizeof(long long) << "\n";   //  8 (по стандарту >= 8)
    std::cout << "float: " << sizeof(float) << "\n";               //  4
    std::cout << "double: " << sizeof(double) << "\n";             //  8
    std::cout << "long double: " << sizeof(long double) << "\n";   // 16
}

template<HasMaxValues T>
void PrintMaxVal() {
    std::cout << "minimum value: " << std::numeric_limits<T>::min() << "\n"
              << "maximum value: " << std::numeric_limits<T>::max() << "\n";
}

template void PrintMaxVal<int>();
template void PrintMaxVal<double>();

}  // namespace types
