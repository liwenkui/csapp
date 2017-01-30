#include <stdio.h>
int func4(int edi,int esi,int edx,unsigned ecx){
	int res=edx-esi;
	ecx=res;
	ecx>>=31;
	res+=ecx;
	res>>=1;
	ecx=res+esi;
	if(edi>ecx){
		edx=ecx-1;
		res=func4(edi,esi,edx,ecx);
		res*=2;
	}else{
		res=0;
		if(edi<ecx){
			esi=1+ecx;
			res=func4(edi,esi,edx,ecx);
			res=2*res+1;
		}
	}
	return res;
}
int main(){
	for(int i=0;i<=14;i++){
		int res=func4(i,0,14,0);
		if(res==0)
			printf("for i = %d",i);
	}
	printf("not have macthing i");
	return 0;
}
