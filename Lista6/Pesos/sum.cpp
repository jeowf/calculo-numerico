#include <bits/stdc++.h>

using namespace std;

const int MAX = 100000;

int main(){
	double sumx = 0;
	double sumxx = 0;
	double sumxy = 0;
	double sumy = 0;
	double x,y;
	double n = 0;
	while (cin >> x >> y  ){
		n++;
		sumx += x;
		sumy += y;
		sumxx += x*x;
		sumxy += x*y;


	}

	//cout << n << " " << sumx << " " << sumy << endl;
	cout << "1 " << sumx << " " << sumy << endl;
	cout << sumx << " " << sumxx << " " << sumxy << endl;


	return 0;
}