#include<stdio.h>
#include<string.h>
 #include <stdlib.h>

    int canWin(char arr[5]) {
        for(int i = 1; i < strlen(arr); i++) {
            if(arr[i] == '+' && arr[i - 1] == '+') {
                arr[i] = '-';
                arr[i - 1] = '-';
                int win = canWin(arr);
                arr[i] = '+';
                arr[i - 1] = '+';
		if (!win)
			return 1;
            }
        }
        
        return 0;
    }

int main() {
	char s[5] = "++++";
	printf("Win = %d\n", canWin(s));
		
}

