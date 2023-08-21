#include <stdio.h>
#include <math.h>

int main(){
	long long int max = (long long int) (pow(2,63) -1);
	long long int min = (long long int) (pow(2,63) *(-1));
	printf("Smallest number represented by signed 64-bit integer is %lld\n",min);
	printf("Largest number represented by signed 64-bit integer is %lld\n",max);
	return 0;
}