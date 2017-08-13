#include <iostream>
#include <string>
#include <stdlib.h>
#include <sstream>
#include <math.h>
#include <stdio.h>
#include <map>
using namespace std;
map<string,int> M;
map<string,int>::iterator it;

int main(){
    long pocet = 0;
    string slovo;

    while(cin>>slovo){
for (int i=0; i<slovo.length(); i++){
int c=(int)slovo[i];
if(c>64 && c<91) c+=32;
slovo[i]=(char)c;
}
if(slovo.length()<11){
if(!(M[slovo]>0)) M[slovo]=1;
else M[slovo]++;
}
}



for ( it=M.begin() ; it != M.end(); it++ )
if((*it).second>150)
cout <<(*it).first<<".";





    
    

    cin.get();
    cin.get();
    
}
