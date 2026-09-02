#include <iostream>

int main(){
    int n;
    std::cin >> n;
    int first = n / 1000;
    int second = n / 100 - first * 10;
    int third = n / 10 - second * 10 - first * 100;
    int fourth = n - third * 10 - second * 100 - first * 1000;
    if(first == fourth && second == third){
        std::cout << "Yes" << std::endl;
    }
    else{
        std::cout << "No" << std::endl;  
    }
    return 0;
}