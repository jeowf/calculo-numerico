#include <bits/stdc++.h>

using namespace std;

const int MAX = 100000;

int main(){
	double sumx = 0;
	double sumxx = 0;
	double sumx3 = 0;
	double sumx4 = 0;
	double sumxy = 0;
	double sumx2y = 0;
	double sumy = 0;
	double x,y;
	double n = 0;

	double minx = 99999, maxx = -1;

	while (cin >> x >> y  ){
		n++;
		sumx += x;
		sumy += y;
		sumxx += x*x;
		sumx3 += x*x*x;
		sumx4 += x*x*x*x;
		sumxy += x*y;
		sumx2y += x*x*y;


		if (x > maxx) maxx = x;
		if (x < minx) minx = x;
	}

	cout << n << " " << sumx << " " << sumxx << " " << sumy << endl;
	cout << sumx << " " << sumxx << " " << sumx3 << " " << sumxy << endl;
	cout << sumxx << " " << sumx3 << " " << sumx4 << " " << sumx2y << endl;

	cout << endl;

	cout << minx << ".." << maxx << endl;
	
	return 0;
} 