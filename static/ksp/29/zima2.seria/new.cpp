#include <iostream>
#include <string>
#include <stdlib.h>
#include <sstream>
#include <math.h>
#include <stdio.h>
#include <map>
#include <vector>
using namespace std;


map<char, map < int,map < string,string > >  > M;
map<char, map < int,map < string, string > >  >::iterator it;
 map < string, string >::iterator it1;



int main(){

string slovo;


while(cin>>slovo){
if(slovo.length()>2){
string temp="00";
temp[0]=slovo[1];
temp[1]=slovo[2];

M[slovo[0]][0][temp]=temp;

for(int i=1; i<slovo.length()-1; i++){
temp[0]=slovo[i-1];
temp[1]=slovo[i+1];

M[slovo[i]][1][temp]=temp;
}
temp[0]=slovo[slovo.length()-2];
temp[1]=slovo[slovo.length()-1];
M[slovo[slovo.length()-1]][2][temp]=temp;

}
}
char kon='z';
kon++;
for(char c='a'; c!=kon; c++)
for(int i=0; i<=2; i++){
cout<<c<<i<<"-----------------------------------"<<endl;
for(it1=M[c][i].begin(); it1 != M[c][i].end(); it1++)
cout <<(*it1).second<<endl;

}




















}
