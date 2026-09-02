#include <iostream>

int main() {
    int a, b, d, first;
    std::cin >> a >> b >> d;
    first = a;
    while(first <= b)
    {
        if(first % 3 == 0){
            std::cout << first << std::endl;
        }
        first += d;  
    }
}