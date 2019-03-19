#include <iostream>
#include <cmath>

using namespace std;

const float LIMIAR = 0.00001;
const float LIMIAR2 = 0.00001;

float f(float x){
	return pow(x,3)-1.7*pow(x,2)-12.78*x-10.08;
}

float f_d(float x){
	return 3*x*x - 3.4*x - 12.78;
}

float g(float x){
	return (pow(x,3)-1.7*pow(x,2)-10.08)/12.78;
}

float g2(float x){
	return cbrt(1.7*pow(x,2)+12.78*x+10.08);
}

template <typename T>
float bissection(float a, float b, T func, int & i){
	i+=1;
	float m = a + (b-a)/2;
	float y_m = func(m);
	float y_a = func(a);

	if (fabs( y_m ) <= LIMIAR){
		return m;
	} else if (y_a * y_m < 0) {
		return bissection( a, m, func, i);
	} else {
		return bissection( m, b, func, i);
	}

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

template <typename T>
float newton_raphson(float p, T func, int & i){
	//cout << func(p) << " ";
	i+=1;

	if (p > 2000000 && p < -2000000)
		return p;

	//if (fabs(p - func(p)) <= LIMIAR2){
	if (fabs(func(p)) <= LIMIAR2){
		return p;
	}
	else{
		
		return newton_raphson(p - func(p)/f_d(p), func, i);
	}
}

template <typename T>
float secant(float p, float q, T func, int & i){
	//cout << func(p) << " ";
	i+=1;

	if (p > 2000000 && p < -2000000)
		return p;

	//if (fabs(p - func(p)) <= LIMIAR2){
	if (fabs(func(p)) <= LIMIAR2){
		return p;
	}
	else{
		return secant(p - (func(p) * (q-p))/(func(q) - func(p)), p, func, i);
	}
}

template <typename T>
float regula_falsi(float p, float q, T func, int & i){
	//cout << func(p) << " ";
	i+=1;

	if (p > 2000000 && p < -2000000)
		return p;

	//if (fabs(p - func(p)) <= LIMIAR2){
	if (fabs(func(p)) <= LIMIAR2){
		return p;
	}
	else{
		float pn = p - (func(p) * (q-p))/(func(q) - func(p));
		if (func(pn)*func(p) < 0)
			return regula_falsi(p,pn,func,i);
		else

			return regula_falsi(pn, p, func, i);
	}
}


int main(){

	int i = 0;
	
	cout << "Bisseção: \n";
	cout << bissection(-3,-1.5,f, i); cout << " it: " << i << endl; i = 0;
	cout << bissection(-1.5,0,f, i); cout << " it: "  << i << endl; i = 0;
	cout << bissection(2,6,f, i); cout << " it: "     << i << endl; i = 0;

	cout << endl;

	cout << "Ponto Fixo (1): \n";
	cout << fixed_p(-2.0,g, i); cout << " it: " << i << endl; i = 0;
	cout << fixed_p(-1.0,g, i); cout << " it: " << i << endl; i = 0;
	cout << fixed_p(4.9,g, i); cout << " it: "  << i << endl; i = 0;

	cout << endl;

	cout << "Ponto Fixo (2): \n";
	cout << fixed_p(-2.0,g2, i); cout<< " it: " << i << endl; i = 0;
	cout << fixed_p(-1.0,g2, i); cout<< " it: " << i << endl; i = 0;
	cout << fixed_p(4.9,g2, i); cout << " it: " << i << endl; i = 0;

	cout << endl;

	cout << "Newton-Raphson: \n";
	cout << newton_raphson(-2.0,f, i); cout << " it: " << i << endl; i = 0;
	cout << newton_raphson(-1.0,f, i); cout << " it: " << i << endl; i = 0;
	cout << newton_raphson(4.9,f, i); cout << " it: "  << i << endl; i = 0;

	cout << endl;

	cout << "Secante: \n";
	cout << secant(-2.0, -4.0 ,f, i); cout << " it: " << i << endl; i = 0;
	cout << secant(-1.0, -2.0,f, i); cout << " it: " << i << endl; i = 0;
	cout << secant(6, 4.9,f, i); cout << " it: "  << i << endl; i = 0;

	cout << endl;
	
	cout << "Regula Falsi: \n";
	cout << regula_falsi(-2.0, -4.0 ,f, i); cout << " it: " << i << endl; i = 0;
	cout << regula_falsi(-1.0, -2.0,f, i); cout << " it: " << i << endl; i = 0;
	cout << regula_falsi(6, 4.9,f, i); cout << " it: "  << i << endl; i = 0;




}