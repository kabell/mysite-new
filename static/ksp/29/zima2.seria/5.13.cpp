#include <iostream>
#include <string>
#include <stdlib.h>
#include <sstream>
#include <math.h>
#include <stdio.h>
using namespace std;


int main(){
    long pocet = 0;
    char c;
string slovo;
int err=0;
int poc1=0;
int poc2=0;
    while(cin>>slovo){
while(slovo.find_first_of(".:,'-()")!=string::npos){
int pos=slovo.find_first_of(".:,-'()");
slovo.replace(pos,1," ");
}
cout<<slovo<<endl;
   } 
    

    cin.get();
    cin.get();
    
}
