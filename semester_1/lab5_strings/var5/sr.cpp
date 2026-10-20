#include <iostream>

int main(){
    int a = 10, b = 100;
    std::cout<<((a=b)?"not":"yes");
    return 0;
}