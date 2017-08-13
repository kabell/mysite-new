#include <iostream>
#include <string>
#include <stdlib.h>
#include <sstream>
#include <math.h>
#include <stdio.h>
#include <vector>
using namespace std;

struct par{
int first;
int second;
};

vector < par > V;
int n,m,k;

bool findk(int s, int t){
bool ok=0;
for(int i=0; i<V.size(); i++){

if(V[i].second==s && V[i].first==t){ ok=1; break;
}

if(V[i].first==s && V[i].second==t){ok=1; break;
}
}



return ok;
}



bool find(int s,int t){
bool ok=0;
for(int i=0; i<V.size(); i++){
if(V[i].first==s){
if(V[i].first==s && V[i].second==t){
ok=1; break; 
}
if(findk(V[i].second,t)==true){
ok=1;break;
}
}
if(V[i].second==s){
if(V[i].second==s && V[i].first==t){
ok=1; break;
}
if(findk(V[i].first,t)==true){
ok=1; break;
}
}

}

return ok;
}





int main(){


cin>>n>>m>>k;
V.resize(m);

for(int i=0; i<m; i++){
par p;
cin>>p.first>>p.second;
V[i]=p;
}



for(int i=0; i<k; i++)
{
int b,c;
cin>>b>>c;
if(find(b,c)==true || b==c) cout<<"Ano"<<endl; else cout<<"Nie"<<endl;
}










}
