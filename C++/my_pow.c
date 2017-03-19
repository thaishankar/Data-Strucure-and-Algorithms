#include<iostream>
#include<bits/stdc++.h>
#include<math.h>

double my_pow(double a, int b) {
	if ( a == 0 && b == 0) return INT_MIN;
	
	if ( a == 0 ) return 0;

	if (b == 0 ) return 1;

	if ( b == 1 ) return a;

	bool posA = a > 0 ? true : false;
	bool posB = b > 0 ? true : false;

	b = abs(b);
	a = fabs(a);

	double res = 0;

	if ((b & 1) == 0) {
		res = my_pow ( a * a, b / 2);
	}
	else {
		res = my_pow ( a * a, b / 2) * a;
	}

	if ( posB == false) {
		res = 1/res;
	}
	if ( posA == false && ((b & 1) != 0)) {
		res *= -1;
	}
	return res;

}

int main() {
	std::cout << my_pow(-0.5, -7) << "\n";
}
