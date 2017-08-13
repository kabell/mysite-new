#include <iostream>
#include <string>
#include <stdlib.h>
#include <sstream>
#include <math.h>
#include <stdio.h>
#include <vector>
using namespace std;



bool pole[15000][15000];



int main(){
int n,m,k;

cin>>n>>m>>k;

for(int i=0; i<m; i++){
int p1,p2;
cin>>p1>>p2;
pole[p1][p2]=true;
pole[p2][p1]=true;
}



for(int i=0; i<k; i++)
{

int p,q,ok=0;
cin>>p>>q;
if(p==q)ok=1;
if(pole[p][q]==true) ok=1;
if(ok==0){
vector <int> V;
for(int i=1; i<=n; i++){
if(pole[p][i]==true) V.push_back(i);
}

for(int i=n; i>0; i--){
if(pole[q][i]==true){
int d=0;
while(ok==0 && !V.empty()){

if(V.back()>=i){
d=V.back();
V.pop_back();
}
else break;
if(d==i){ ok=1;}

}

}
if(ok==1) break;

}


}
if(ok==1) cout<<"Ano"<<endl;
else cout<<"Nie"<<endl;
}










}
