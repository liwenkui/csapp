#include <iostream>
#include <string>
using namespace std;
int main(){
	string text="maduiersnfotvbylSo you think you can stop the bomb with ctrl-c, do you?";
	string text2="flyers";
	int cnt[6]={};
	int i=0;
	for(auto c: text2){
		size_t posi=text.find_first_of(c);
		cnt[i++]=posi;
	}
	for(auto i:cnt)
		cout<<(char)(i+16*7)<<' ';
	cout<<endl;
	return 0;
}
