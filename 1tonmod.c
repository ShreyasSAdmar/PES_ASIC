#include <stdio.h>
  
extern int load(int x, int y);
  
int main()
{
	int count,result = 0;
	printf("Enter value of  n : \t");
	scanf("%d",&count);
    	result = load(0x0, count+1);
	printf("Sum of numbers from 1 to %d is %d\n",count, result);
}