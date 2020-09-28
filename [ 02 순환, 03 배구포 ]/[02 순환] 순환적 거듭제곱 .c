#include <stdio.h>

double slow_power (double x, int n){
	int i;
	double result =1.0;
	for (i=0;i<n;i++){
		result *= x;
		printf("slow_power> res: %.0f, i: %d\n", result, i);
	}
	return result;
}

double power (int x, int n){
	printf("x: %d, n: %d\n", x,n);
	if (n==0)
		return 1;
	else if (n%2==0 )
		return power (x*x, n/2);
	else 
		return x*power (x*x, (n-1)/2);
}
int main (){
	//slow_power(2,100);
	//printf("\n\n");
	double dd=power(2,10);
	printf("\n\ndd = %.0f", dd);
}
