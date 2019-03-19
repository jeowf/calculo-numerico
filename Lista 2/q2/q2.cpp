#include <iostream>
#include <cmath>

using namespace std;

const float LIMIAR2 = 0.00001;

const float s0 = 300, m = 0.25, k = 0.1, g = 32.17, e = 2.7182;

float s(float t){
	return s0 - t*(m*g)/k + (1 - pow(e,(-k*t)/m))*(m*m*g)/(k*k);
}

float r(float t){
	return (s0 + (1 - pow(e,(-k*t)/m))*(m*m*g)/(k*k))*k/(m*g);
}

template <typename T>
float fixed_p(float p, T func, int & i){
	//cout << func(p) << " ";
	i+=1;
	if (p > 2000000)
		return p;

	if (fabs(p - func(p)) <= LIMIAR2){
		return p;
	}
	else{
		return fixed_p(func(p), func,i);
	}
}

int main(){

	int i = 0;

	cout << fixed_p(0.0, r, i) << endl;

	return 0;
}