#include <iostream>

int isPalin(char *str) {
	char *start, *end, temp;
	start = str;
	end = start + strlen(str) - 1;
	
	while(start < end) {
		if (*start != *end) 
			return -1;
		start++;
		end--;
	}
	return 0;
}

int main () {
	char str[]="civaic";
	std::cout << isPalin(str);
}
