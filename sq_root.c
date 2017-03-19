#include<iostream>
#include<math.h>

double sq_api(double val, double low, double high ) {
	double mid = low + (high - low) / 2;
	double res = mid * mid;


	if (low >= high) return low;
//	if (fabs(val - res) < 0.000001) return mid;
	
	if (res == val)
		return mid;
	else if (res > val)
		return sq_api(val, low, mid);
	else
		return sq_api(val, mid, high);

	return -1;
}


double sq_root(double val) {
	return sq_api(val, 0, val);
}

int main() {
	double val = 15;
	std::cout << "Sq root = " << sq_root(val);
}
