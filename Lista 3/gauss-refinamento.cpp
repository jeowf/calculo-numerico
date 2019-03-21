#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

const int MAX = 100;
const float LIMIAR = 0.0000001;


int main(int argc, char const *argv[]) {
	
	float m[MAX][MAX];
	float mb[MAX][MAX];
	float r[MAX];

	float res[MAX];
	float old[MAX] = {0};

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n+1; ++j) {
			cin >> m[i][j];
			mb[i][j] = m[i][j];
		}
	}

	float x;

    if (argc > 1 && *argv[1]=='P'){
    	for (int i = 0; i < n; ++i) {
    		int s = i;
    		for (int j = i+1; j < n; ++j)	{
    			if (fabs(m[j][i]) > fabs(m[i][i]))
    				s = j;
    		}

    		if (s != i){
    			float aux;
    			for (int k = 0; k < n+1; ++k) {
    				aux = m[i][k];
    				m[i][k] = m[s][k];
    				m[s][k] = aux;    			
    			}
    		}

			for (int j = i+1; j < n; ++j) {
				x = m[j][i]/m[i][i];
				for (int k = i; k < n+1; ++k) {
					m[j][k] -= m[i][k]*x;
				}
			}
		}

    } else {
    	for (int i = 0; i < n; ++i) {
			for (int j = i+1; j < n; ++j) {
				x = m[j][i]/m[i][i];
				for (int k = i; k < n+1; ++k) {
					m[j][k] -= m[i][k]*x;
				}
			}
		}
    }
    
    

	for (int i = n-1; i >= 0; --i) {
		r[i] = m[i][n];
		for (int j = n-1; j > i; --j) {
			r[i] -= m[i][j]*r[j];
		}
		r[i] /= m[i][i];
	}
	

	for (int i = 0; i < n; ++i) {
		res[i] = m[i][n];
		for (int j = 0; j < n; ++j) {
			res[i] -= r[j] * m[i][j];
		}
	}

	float n_res = 0; // normal do vetor residual

	for (int i = 0; i < n; ++i) {
		n_res += res[i]*res[i];
	}

	n_res = sqrt(n_res);

	cout << "NORMA DO VETOR RESIDUAL: " << n_res << endl;

	int it = 0;
	while (n_res > LIMIAR && it < 20){

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n+1; ++j) {
				m[i][j] = mb[i][j];
			}
		}

		for (int i = 0; i < n; ++i) {
			m[i][n] = res[i];
			old[i] = r[i];
		}

		

		if (argc > 1 && *argv[1]=='P'){
	    	for (int i = 0; i < n; ++i) {
	    		int s = i;
	    		for (int j = i+1; j < n; ++j)	{
	    			if (fabs(m[j][i]) > fabs(m[i][i]))
	    				s = j;
	    		}

	    		if (s != i){
	    			float aux;
	    			for (int k = 0; k < n+1; ++k) {
	    				aux = m[i][k];
	    				m[i][k] = m[s][k];
	    				m[s][k] = aux;    			
	    			}
	    		}

				for (int j = i+1; j < n; ++j) {
					x = m[j][i]/m[i][i];
					for (int k = i; k < n+1; ++k) {
						m[j][k] -= m[i][k]*x;
					}
				}
			}

	    } else {
	    	for (int i = 0; i < n; ++i) {
				for (int j = i+1; j < n; ++j) {
					x = m[j][i]/m[i][i];
					for (int k = i; k < n+1; ++k) {
						m[j][k] -= m[i][k]*x;
					}
				}
			}
	    }
	    
		for (int i = n-1; i >= 0; --i) {
			r[i] = m[i][n];
			for (int j = n-1; j > i; --j) {
				r[i] -= m[i][j]*r[j];
			}
			r[i] /= m[i][i];
		}


		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n+1; ++j) {
				m[i][j] = mb[i][j];
			}
		}

		for (int i = 0; i < n; ++i)
		{
			r[i] += old[i];
		}
		
		for (int i = 0; i < n; ++i) {
			//res[i] = r[i];
			res[i] = m[i][n];
			for (int j = 0; j < n; ++j) {
				res[i] -= (r[j])* m[i][j];
			}
		}

		n_res = 0; // normal do vetor residual
		for (int i = 0; i < n; ++i) {
			n_res += res[i]*res[i];
		}
		n_res = sqrt(n_res);

		cout << "NORMA DO VETOR RESIDUAL: " << n_res << endl;


		it++;
	}

	return 0;
}