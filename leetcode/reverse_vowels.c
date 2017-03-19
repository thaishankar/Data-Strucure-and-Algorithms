#include <stdio.h>
#include <stdlib.h>

int isVowel(char s) {
    switch(s) {
        case 'a':
        { return 1; break;}
        case 'e':
        { return 1; break;}
        case 'i':
        { return 1; break;}
        case 'o':
        { return 1; break;}
        case 'u':
        { return 1; break;}
        default:
        return 0;
    }
}

char* reverseVowels(char* s) {
    char *start, *end;
    char tmp;
    start = end = s;
    while(*end!='\0')
        end++;
    end--;
    
    while(start < end) {
        while(!isVowel(*start))
            start++;
        
        while(!isVowel(*end))
            end--;
        
        if (start >= end)
            break;
            
        tmp = *start;
        *start = *end;
        *end = tmp;
	start ++;
	end --;
    }
    return s;
}

int main()
{
	char s[6] = "hello";
	s[5] = '\0';
	char *res;
	printf("String is %s", s);
	res = reverseVowels(s);
	printf("reversed vowels is %s\n", res);
}
