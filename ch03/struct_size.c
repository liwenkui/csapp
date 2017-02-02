#include <stdio.h>
struct test{
	int a;
	char b;	
};
int main(){
	struct test a0;
	a0.a=1;a0.b='a';
	struct test a1[2];
	a1[0]=a0;
	a1[0]=a0;
	size_t a=sizeof(a0);
	size_t b=sizeof(a1);	
	printf("%d %d",a,b);
}
