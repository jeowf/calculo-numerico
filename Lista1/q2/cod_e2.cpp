#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <deque>


struct pair{
	float x; 
	float y;
};


bool comp(pair lhs, pair rhs){
	if (lhs.x < rhs.y)
		return true;
	return false;
}

float dydx(float x){
  return std::cos(x) - x * std::sin(x);
}

int main(){
  float x = 0;
  float y = 1;

  float dx = 0.1;

  std::deque<pair> out;


  for (x = 0; x > -6; x-=dx){
    //std::cout << x << " " << y << std::endl;
    pair p;
    p.x = x;
    p.y = y;
    out.push_front(p);
    y -= dydx(x) * dx;
  }


  x = 0;
  y = 1;


  for (x = 0; x < 6; x+=dx){
    //std::cout << x << " " << y << std::endl;
    pair p;
    p.x = x;
    p.y = y;
    out.push_back(p);
    y += dydx(x) * dx;
  }

  //std::sort(out.begin(), out.end(), comp);

  for (auto & c : out)
  {
  	std::cout << c.x << " " << c.y << std::endl;
  }

  
  return 0;
}
