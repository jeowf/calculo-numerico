#include <bits/stdc++.h>

using namespace std;

const int MAX = 100000;

struct pt{
	double x;
	double y;

	pt(){}
	pt(double a, double b) : x(a), y(b) { }
};

int m = 4;
vector<pt> pts;

double ak(int k){

	double sum = 0;
	for(int i = 0; i < (2*m-1); i++){
		sum += pts[i].y * cos(k*pts[i].x);
	}
	sum /= m;
}

double bk(int k){

	double sum = 0;
	for(int i = 0; i < (2*m-1); i++){
		sum += pts[i].y * sin(k*pts[i].x);
	}
	sum /= m;
}

int main(){	
	double x, y;

	while (cin >> x >> y){
		//cout << x << "  " << y << endl;
		pt p(x,y);
		pts.push_back(p);

	}

	int n;
	//cout << "Digite n: ";
	//cin >> n;
	n = 8;

	printf("a%d/2 = %.4lf\n", 0, ak(0)/2);
	printf("a%d = %.4lf\n", n, ak(n));

	for(int i = 1; i < n; i++){
		printf("a%d = %.4lf\n", i, ak(i));
		printf("b%d = %.4lf\n", i, bk(i));
	}


	return 0;
}