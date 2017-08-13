#include <iostream>
#include <string>
#include <stdlib.h>
#include <sstream>
#include <math.h>
#include <stdio.h>
#include <map>
using namespace std;




int main(){

string slovo="AbCdEfGhIj";
for (int i=0; i<slovo.length(); i++){
int c=(int)slovo[i];
if(c>64 && c<91) c+=32;

slovo[i]=(char)c;

}

cout<<slovo<<endl;



    
    

    cin.get();
    cin.get();
    
}
