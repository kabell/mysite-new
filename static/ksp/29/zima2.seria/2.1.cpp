#include <iostream>
#include <string>
#include <stdlib.h>
#include <sstream>
#include <math.h>
#include <stdio.h>
#include <vector>
using namespace std;

int main(){
int n,a,b;

cin>>n>>a>>b;

int minuta=0,bavenie=0,najbav=1000000000,min=0;

for (int i=0; i<=n; i++){
int prichod, cas,rozdiel;

if(i<n){
cin>>prichod>>cas;
}
else{
prichod=b;
cas=0;
}
rozdiel=prichod-minuta;
bavenie-=rozdiel;




if(bavenie<=0 && prichod+bavenie>=a && prichod+bavenie<=b){min=prichod+bavenie; najbav=0;break;}
if(bavenie<=0 && prichod>=a && a>prichod+bavenie && prichod+bavenie<=b){min=a; najbav=0; break;}
if(bavenie>0 && prichod>=a && prichod+bavenie<=b){
if(bavenie<najbav){najbav=bavenie; min=prichod;}
}



if(bavenie<0) bavenie=0;

minuta=prichod;
bavenie+=cas;
}

if(najbav==1000000000) cout<<"ZAJTRA"<<endl;
else cout<<min<<" "<<najbav<<endl;




}
