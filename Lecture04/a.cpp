#include<iostream>
#include<conio.h>
int main(){
	std::cout << "hello" <<std::endl;
	while(true){
		std::cout<<"*";
		if(-kbhit()){
			if(getch() == 27){
			    break;
			}
		}
	}
	return 0;
}
