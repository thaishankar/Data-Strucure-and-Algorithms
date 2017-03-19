#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    char *res;
    int i, j, shortest = strlen(strs[0]);
    int index;
    
    if (strsSize == 0)
        return "";
    
    for (i=0; i<strsSize; i++) {
        if (shortest < strlen(strs[i])) {
            shortest = strlen(strs[i]);
            index = i;
        }
            
    }
    
    res = (char *)malloc(shortest+1);
    
    for (i=0; i<shortest; i++) {
        for (j=0; j<strsSize; j++) {
            if(strs[j][i] != strs[index][i]) {
                break;
            }
        }
        if(j == strsSize)
            res[i] = strs[index][i];
        else
            break;
    }
    
    return res;
 
}

int main()
{
	char *str1[] = {"shash","shank","shashank","sha"};
	char *str2[] = {"ab","abc","def","defgh","sha"};
	printf(longestCommonPrefix(str1 ,4));
	printf(longestCommonPrefix(str2 ,5));
	return 0;
}
