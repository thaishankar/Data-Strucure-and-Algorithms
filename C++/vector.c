#include <iostream>
#include <vector>
 
class loc {
	public:
		int i;
		int j;
	private:
};

int main()
{
    // Create a vector containing integers
    std::vector<loc> v;

    int i = 0, j = 0;


    for (i = 0; i < 5; i++) {
	for(j = 0; j < 5; j++) {
		loc l;
		l.i = i;
		l.j = j;
		v.push_back(l);
	}
    }	

   int size = 5 * 5;
 
   for (i = 0; i < 5; i++) {
	for (j =0; j < 5; j++) {
		if (size <= 1)
			break;
		srand (time(NULL));
		int r = rand() % ( size - 1);
		loc temp = v[size];
		v[size] = v[r];
		v[r] = temp;
		size--;
	}
    }


 
    // Iterate and print values of vector
    for(loc n : v) {
        std::cout << n.i << n.j << '\n';
    }
}
