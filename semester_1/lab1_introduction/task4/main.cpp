#include <iostream>

int main() {
    int n, num1, num2, sum;

    num1 = 0;
    num2 = 1;

    std::cin >> n;

    std::cout << num1 << '\n' << num2 << std::endl;

    for(int i = 0; i < n - 2; i++){
       sum = num1 + num2;

       std::cout << sum << std::endl;
       
       num1 = num2;
       num2 = sum;
    }

}