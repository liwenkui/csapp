#include <iostream>
typedef struct ELE{
	struct ELE *next;
	long data;
}list_ele,*list_ptr;
long list_len(list_ptr ls){
	long len=0;
	while(ls){
		len++;
		ls=ls->next;
	}
	return len;
}
int main(){
	list_ptr header=(list_ptr)malloc(100*sizeof(list_ele));
	list_ptr ls=header;
	for(int i=0;i<100;i++){
		ls->data=i;
		ls->next=(i!=99)?(ls+1):0;
		ls=ls->next;
	}
	ls=header;
	while(ls){
		std::cout<<ls->data<<std::endl;
		ls=ls->next;
	}
	return 0;
}
