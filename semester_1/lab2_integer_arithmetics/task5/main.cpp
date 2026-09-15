#include <iostream>
#include <cmath>

bool if_pal(int n){

    int k = n;
    bool flag = 1;
    int count = 1;
    int div2 = 1;
    int div = 10;

  while(k > 9){
    count++;
    k /= 10;
    div2 *= 10;
  } 

  for(int i = 0; i < (count/2); i++){
    int first = n / div2;
    int last = n % 10;
    if(first == last){
      flag = 1;
    }
    else{
      flag = 0;
      return flag;
    }
    div *= 10;
    div2 /= 10;
    n /=  10;
    n -= first * div2;
    div2 /= 10;
  }

  return flag;
}
bool if_pal2(int n){
  int orig = n;
  int clone = 0;
  int count = 1;
  while(orig > 9){
    orig /= 10;
    count *= 10;
  }
  orig = n;
  while(n > 0){
    clone += (n % 10)*count;
    n /= 10;
    count /= 10;
  }
  if(orig == clone){
    return 1;
  }
  else{
    return 0;
  }

}

int main() {

    int n;
    std::cout << "Enter n" << std::endl; 
    if(!(std::cin >> n) || n < 0){
      std::cout << "Error wrong input" << std::endl;
      return 1;
    }   
    for(int i = 0; i <= n; i++){
      if(if_pal2(i) && if_pal2(i*i)){
        std::cout << i << " is double palindrom" << std::endl; 
      }
    }

}