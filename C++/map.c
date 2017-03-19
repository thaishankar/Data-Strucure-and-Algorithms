#include <iostream>
#include <map>

void frequency(int arr[], int n) {
	std::map<int, int> m;
	for (int i = 0; i < n; i++) {
		if (m.get(arr[i]) != m.end()) {
			m.put(arr[i], m.get(arr[i)+1);
		}
		else
			m.put(arr[i], 1);
	}
	
}
 
int main() {
	int arr[] = {1, 2, 3, 4, 1, 1, 2, 4, 7};
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << frequency(arr, n);
}
