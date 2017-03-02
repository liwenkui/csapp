#include <iostream>
#include <arpa/inet.h>
#include <string>
int main(int argc,char* argv[]){
	struct in_addr inaddr;
	uint32_t addr;
	char buf[1000];
	if(argc!=2){
		std::cerr<<"usage: "<<argv[0]<<" <hex number>"<<std::endl;
		exit(0);
	}
	addr =std::stoul(std::string(argv[1]),0,16); 
	inaddr.s_addr=htonl(addr);
	if(!inet_ntop(AF_INET,&inaddr,buf,1000))
		std::cerr<<"error"<<std::endl;
	std::cout<<buf<<std::endl;
	exit(0);
}
