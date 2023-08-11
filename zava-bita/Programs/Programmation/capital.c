#include<stdio.h>
#include<math.h>
int main(){
	float x=0,
	      r=0,
	      n=0,
	 e=0,     a=0;
	printf("euro  x=");
	scanf("%f",&x);
	printf("\ntaux r=");
	scanf("%f",&r);
	printf("\nannee n=");
	scanf("%f",&n);

	e=(float)pow((1+r),n);
	a=x*e;
	printf("\nla capitale a=%f\n",a);
	return 0;
}
