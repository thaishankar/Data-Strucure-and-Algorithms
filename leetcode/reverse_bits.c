#include <stdio.h>
#include <stdint.h>

uint32_t reverseBits(uint32_t n) {
    int res = 0;
    int bit = 0;
    int i;
    for(i = 0; i<32-1; i++)  {
        bit = n & 1;
        if (bit) {
            res = res | 1;
        }
        res = res << 1;
        n = n >> 1;
    }
    return res;
    
}

int main()
{
	printf("reverse = %d\n", reverseBits(43261596));
}
