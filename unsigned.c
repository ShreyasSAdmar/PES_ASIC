#include <stdio.h>
#include <math.h>

int main(){
	unsigned long long int max = (unsigned long long int) (pow(2,64) -1);
	unsigned long long int min = (unsigned long long int) (pow(2,64) *(-1));
	printf("Smallest number represented by unsigned 64-bit integer = %llu\n",min);
	printf("Biggest number represented by unsigned 64-bit integer = %llu\n",max);
	return 0;
}