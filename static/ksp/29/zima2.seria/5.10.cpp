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
int err=0;
int poc1=0;
int poc2=0;
    while(scanf("%c", &c)!=EOF){
if(c=='[') err++;
if(err==0) cout<<c;
if(c==']') err--;
if(c=='>') err=0;
   } 
    

    cin.get();
    cin.get();
    
}
