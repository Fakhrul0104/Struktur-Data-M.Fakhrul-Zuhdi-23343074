#include <stdio.h>

int main (){
	int rr;
	int nil [0];
	
	nil[0]= 80;
	nil[2]= 90;
	
	rr = (nil[0] + nil[1] + nil[2]) / 3;
	printf("The average of the 3 grades is : %d", rr);
	
	return 0;
}