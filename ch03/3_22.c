#include <stdio.h>
int main(){
	int fact=1;
	int pre_fact=1;
	int n=1;
	do{
		pre_fact=fact;
		++n;
		fact*=n;	
	}while(fact/n==pre_fact);
	--n;
	printf("lagest n = %d",n);
	return 0;	
}
//int main(){
//	int fact=1;
//	int n=1;
//	do{
//		++n;
//		fact*=n;	
//	}while(fact>0);
//	--n;
//	printf("lagest n = %d",n);
//	return 0;	
//}
