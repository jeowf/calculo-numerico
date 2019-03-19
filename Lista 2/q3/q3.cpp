#include <iostream>
#include <cmath>

using namespace std;

const float LIMIAR = 0.00001;

float f(float x){

	return 1/sqrt(30*30 - x*x) + 1/sqrt(20*20-x*x) - 1/8.0;
}


template <typename T>
float bissection(float a, float b, T func, int & i){
	i+=1;
	//float m = a + (b-a)/2;
	float m = (a + b)/2;
	float y_m = func(m);
	float y_a = func(a);

	if (i > 20)
		return 0;

	if (fabs( y_m ) <= LIMIAR){
		return m;
	} else if (y_a * y_m < 0) {
		return bissection( a, m, func, i);
	} else{
		return bissection( m, b, func, i);
	}

}


int main(){

	int i = 0;
	cout << bissection(0.1, 19.9999, f, i) << endl;

	return 0;
}