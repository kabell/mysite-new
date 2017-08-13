#include<iostream>
#include<vector>
using namespace std;

int cislo,tahy;

vector<string>V;
int size=1000000;

void rec(string s,int d,int h,int poc){
if(d>cislo || h>cislo || s.size()>tahy) return;

if((d==cislo || h==cislo) && s.length()==tahy){
//cout<<s<<" "<<poc<<endl;
if(poc<size){
V.clear();
size=poc;
}
if(poc==size && s.length()==tahy)
V.push_back(s);
 return;
}


rec(s+"D",d+h,h,s[s.length()-1]=='D' ? poc+1 : poc);
rec(s+"H",d,h+d,s[s.length()-1]=='H' ? poc+1 : poc);




}




int main(){

cin>>tahy>>cislo;

rec("H",1,1,0);


if(V.size()>0)
for(auto it=V.begin(); it!=V.end(); it++){
cout<<*it<<endl;
break;
}
else cout<<"Neexistuje"<<endl;



}
