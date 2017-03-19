#include <bits/stdc++.h>
using namespace std;
 
//  Method to compare two versions. Returns 1 if v2 is
// smaller, -1 if v1 is smaller, 0 if equal
int versionCompare(string v1, string v2)
{
    //  vnum stores each numeric part of version
    int vnum1 = 0, vnum2 = 0;
    int i = 0, j = 0;
    int len1 = v1.length();
    int len2 = v2.length();
    while(i < len1 || j < len2) {
	while( i < len1 && v1[i] != '.') {
		vnum1 = vnum1*10 + (v1[i] - '0'); 
		i++;
	}
	while (j < len2 && v2[j] != '.') {
		vnum2 = vnum2*10 + (v2[j] - '0');
		j++;
	}
	cout << "v1 " << vnum1 << "v2 " << vnum2 << "\n";
	if (vnum1 > vnum2) return 1;
	else if (vnum1 < vnum2) return -1;
	
	vnum1 = vnum2 = 0;
	i++;
	j++;

    }

    return 0;
}
 
//  Driver method to check above comparison function
int main()
{
    string version1 = "1.10.3";
    string version2 = "1.0.7";
 
    if (versionCompare(version1, version2) < 0)
        cout << version1 << " is smaller\n";
    else if (versionCompare(version1, version2) > 0)
        cout << version2 << " is smaller\n";
    else
        cout << "Both version are equal\n";
    return 0;
}
