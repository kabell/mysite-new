#include <iostream>
#include <string>
#include <stdlib.h>
#include <sstream>
#include <math.h>
#include <stdio.h>
using namespace std;

string pole[1000000][3];

int main(){

string slovo;
int i1=0;

string k="abcdecdefgh";
cout<<k.rfind("cde")<<endl;

string pat[]={"skych","ovia","nymi","iach","ujem","neho","nemu","vane","vanie","nych","ujes","ych","ske","val","nej","uje",
"ovi","och","nou","nie","nia","niu","any","nom","nym","ami","ach","ala","alo","ali","iam","uje", "mi","ov","al","ou","am","om","no","na","ne","nu","ny","ie","ia","iu","at","ej","us","a","e","o","i","u","y"};
int l=54;

    while(cin>>slovo){
pole[i1][1]=slovo;
i1++;
   } 
cout<<"ok"<<endl;


for (int i=0; i<i1; i++){
for(int i1=0; i1<=l; i1++){
if(pole[i][1].find(pat[i1])==string::npos && i1<l) continue;
if(pole[i][1].find(pat[i1])==string::npos && i1==l){
pole[i][0]=pole[i][1];
 break;
}
if(pole[i][1].rfind(pat[i1])==pole[i][1].length()-pat[i1].length()){
 pole[i][0]=pole[i][1].substr(0,pole[i][1].length()-pat[i1].length());

break;
}
if(i1==l){pole[i][0]=pole[i][1]; break;}
}
}


for (int i=0; i<i1; i++) cout<<pole[i][0]<<endl;





    

    cin.get();
    cin.get();
    
}

