#include <iostream>
#include <string>
#include <stdlib.h>
#include <sstream>
#include <math.h>
#include <stdio.h>
using namespace std;


int main(){
    long pocet = 0;
    string slovo;
int err=0;
    while(cin>>slovo){

while(slovo.find_first_not_of("abcdefghijklmnopqrstuvwxyz ")!=string::npos){
int pos=slovo.find_first_not_of("abcdefghijklmnopqrstuvwxyz ");
slovo.replace(pos,1," ");
}








 cout<<slovo<<endl;
   } 
    

    cin.get();
    cin.get();
    
}
