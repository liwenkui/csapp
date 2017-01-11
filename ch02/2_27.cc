#include <iostream>
#include <climits>
using namespace std;
int uadd_ok(unsigned x,unsigned y){
	unsigned sum=x+y;
	return sum>=x;
}
int tadd_ok(int x,int y){
	int sum=x+y;
	if(x>0&&y>0&&sum<=0)return 0;
	if(x<0&&y<0&&sum>=0)return 0;
	return 1;
	// int neg_over=x<0&&y<0&&sum>=0;
	// int pos_over=s>=0&&y>=0&&sum<=;
	// return !neg_over&&!pos_over;
}
int tmult_ok(int x,int y){
	int p=x*y;
	return !x||p/x==y;
}
int tmult_ok2(int x,int y){
	int64_t pll = (int64_t)x*y;
	return pll==(int)pll;
}
int main(){
	unsigned x=UINT_MAX/2,y=UINT_MAX/1.5;
	cout<<uadd_ok(x,y)<<endl;
	return 0;
}
	
