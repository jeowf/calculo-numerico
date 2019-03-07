#include <iostream>
#include <cmath>

using namespace std;

const float LIMIAR = 0.00001;
const float LIMIAR2 = 0.001;

float f(float x){
	return pow(x,3)-1.7*pow(x,2)-12.78*x-10.08;
}

float g(float x){
	return (pow(x,3)-1.7*pow(x,2)-10.08)/12.78;
}

template <typename T>
float bissection(float a, float b, T func){
	float m = a + (b-a)/2;
	float y_m = func(m);
	float y_a = func(a);

	if (fabs( y_m ) <= LIMIAR){
		return m;
	} else if (y_a * y_m < 0) {
		return bissection( a, m, func );
	} else {
		return bissection( m, b, func );
	}

}

template <typename T>
float fixed_p(float p, T func){
	//cout << func(p) << " ";
	if (fabs(p - func(p)) <= LIMIAR2){
		return p;
	}
	else{
		return fixed_p(func(p), func);
	}
}

int main(){
	cout << "Bisseção: \n";
	cout << bissection(-3,-1.5,f) << endl;
	cout << bissection(-1.5,0,f) << endl;
	cout << bissection(2,6,f) << endl;

	cout << endl;

	cout << "Ponto Fixo: \n";
	cout << fixed_p(-2.0,g) << endl;
	cout << fixed_p(-1.0,g) << endl;
	cout << fixed_p(4.9,g) << endl;


}