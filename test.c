#include <stdio.h> 

/* Describe the code below */ 

struct s { 
double f; 
int i; 
char c[3]; 
void *p; 
int x[0]; 
}; 

int main( int argc, char ** argv ) { 

struct s temp; 

printf("The size of the struct is %d \n", sizeof(temp)); 

printf("The size of the double is %d \n", sizeof(temp.f)); 

printf("The size of a character array is %d \n", sizeof(temp.c)); 

printf("The size of a void pointer is %d \n", sizeof(temp.p)); 

printf("The size of a integer array is %d \n", sizeof(temp.x)); 

printf("The size of a integer is %d \n", sizeof(temp.i)); 

char *s = "Hello";
s[0] = 'J';
printf("%s", s);

return 0; 

} 
