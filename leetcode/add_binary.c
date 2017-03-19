#include <stdio.h>
#include <stdint.h>

char* addBinary(char* a, char* b) {
    int la, lb, carry = 0;
    int first_bit, second_bit;
    char *res, *tmp;
    int i, j;
    
    la = strlen(a);
    lb = strlen(b);
    
    // Make equal legth strings
    if (la < lb) {
        tmp = (char *)malloc(la + (lb-la));
        memset(tmp, '0', la + (lb-la));
        memcpy(tmp + (lb-la), a, la );
        b = tmp;
        la = lb;
    }
    else {
        tmp = (char *)malloc(lb + (la-lb));
        memset(tmp, '0', lb + (la-lb));
        memcpy(tmp + (la-lb), b, lb );
        b = tmp;
        lb = la;
    }
    
    res = (char *) malloc(sizeof(lb+1));
    memset(res, '0' , lb+1);

   for (i=lb-1; i >= 0; i--) {
        first_bit = (a[i] - '0');
        second_bit = (b[i] - '0');
        res[i] = first_bit ^ second_bit ^ carry + '0';
        carry = first_bit & second_bit | second_bit & carry | first_bit & carry;
    }

    if (carry) {
        *res = carry + '0';
        return res;
    }
    else
        return res;
    
}

int main()
{
	printf("res = %s\n", addBinary("11", "11"));
}
