#include<iostream>

using namespace std;

int p=2;


int main(){

for(int i=3; i<=550; i++){

int err=0;
for(int j=2; j<i; j++)
	if(i%j==0)err=1;

if(err==0){
	if(i-p==2)cout<<"c";
	else if(i-p==4)cout<<"d";
	else if(i-p==6)cout<<"e";
	else if(i-p==8)cout<<"f";
	else if(i-p==10)cout<<"g";
	else if(i-p==12)cout<<"h";
	else if(i-p==14)cout<<"i";
	
	p=i;
}
}


}
