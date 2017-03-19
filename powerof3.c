#include <stdio.h>

int isPowerofThree(int n);

int isPowerofThree(int n) {
    int i = 0;
    while((3^i) < n)
    {
        i++;
    }
    if((3^i) == n)
        return 1;
    else
        return 0;
}

int main() {
	if(isPowerofThree(28))
		printf("Power of 3\n");
	else
		printf("Not power of 3\n");
	return 0;
}
