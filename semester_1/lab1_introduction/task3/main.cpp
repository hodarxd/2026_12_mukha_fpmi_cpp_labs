#include <iostream>

int main() {
    int n;
    
    std::cin >> n;
    
    int first = n / 100000;
    int second = (n / 10000) - first * 10;
    int third = (n / 1000) - second * 10 - first * 100;
    int fourth = (n/100) - third * 10 - second * 100 - first * 1000;
    int fifth = (n/10) - fourth * 10 - third * 100 - second * 1000 - first * 10000;
    int sixth = n - fifth * 10 - fourth * 100 - third * 1000 - second * 10000 - first * 100000;
    
    if((first + second + third) == (fourth + fifth + sixth)){
        std::cout << "Yes" << std::endl;
    }
    else{
        std::cout << "No" << std::endl; 
    }

    return 0;
}