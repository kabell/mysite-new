#include <iostream>
#include <string>
#include <stdlib.h>
#include <sstream>
#include <math.h>
#include <stdio.h>
#include <vector>
using namespace std;
vector <string> pole;

int main(){
    long pocet = 0;
    string slovo;

    while(cin>>slovo){


pole.push_back(slovo);

   } 



for(int i=0; i<=pole.size(); i++){
for(int i1=i+1; i1<=pole.size(); i1++){
if(pole[i1][0]!=pole[i][0]) break;
if(pole[i1].find(pole[i])!=string::npos){ pole.erase (pole.begin()+i); break;};
}
cout<<i<<endl;
}
    
for(int i=0; i<=pole.size(); i++)cout<<pole[i]<<endl;
    cin.get();
    cin.get();
    
}
