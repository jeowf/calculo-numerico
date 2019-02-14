#include <iostream>
#include <cmath>

float dydx(float x){
  return std::cos(x) - x * std::sin(x);
}

int main(){
  float x = 0;
  float y = 1;

  float dx = 0.01;

  for (x = 0; x < 10; x+=dx){
    std::cout << x << " " << y << std::endl;
    y += dydx(x) * dx;
  }

  return 0;
}
