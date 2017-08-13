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

    while(cin>>slovo){

int err=0;
for(int i=0; i<slovo.length(); i++)
if (slovo[i]==slovo[i+1] && (slovo[i]!='n' || slovo[i]!='k')) err=1;







if(err==0)
 cout<<slovo<<endl;
   } 
    

    cin.get();
    cin.get();
    
}
