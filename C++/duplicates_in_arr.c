#include<bits/stdc++.h>

void find_duplicates(int arr[], int n) {
	std::map<int, bool> m;
	std::vector<int> res;
	for (int i = 0; i < n; i++) {
		if(m[arr[i]] == m.end())
			res.push_back(arr[i]);
		
}

int main() {
	int arr[] = {1, 3, 3, 4, 5, 7, 6, 5, 3};
	int n = sizeof(arr) / sizeof(arr[0]);
	find_duplicates(arr, n);
}
