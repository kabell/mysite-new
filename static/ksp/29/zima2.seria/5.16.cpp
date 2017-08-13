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

    while(cin>>slovo)
if(!(M[slovo]>0)) M[slovo]=1;
else M[slovo]++;




for ( it=M.begin() ; it != M.end(); it++ )
if((*it).second>3)
cout <<(*it).first<<" ";





    
    

    cin.get();
    cin.get();
    
}
