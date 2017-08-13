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
if(slovo=="<text") err=1;
if(err==1)
cout<<slovo<<endl;
if(slovo=="</text>") err=0;

   } 
    

    cin.get();
    cin.get();
    
}
