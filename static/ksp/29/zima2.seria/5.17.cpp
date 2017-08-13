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

for(int i1=0; i1<=l; i1++){

if(slovo.rfind(pat[i1])==slovo.length()-pat[i1].length()){
 cout<<slovo.substr(0,slovo.length()-pat[i1].length())<<endl;
break;
}
if(i1==l) cout<<slovo<<endl;
}
}








    

    cin.get();
    cin.get();
    
}

