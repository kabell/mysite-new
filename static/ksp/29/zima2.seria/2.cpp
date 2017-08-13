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

int t=0,h=0,time=0,naj=10000000,pos=0,pocet=0;
cin>>t>>h;

for (int i=1; i+time<=b; i++){



if(time<naj && i>=a && i+time<=b){ naj=time; pos=i;}

if(i>=t && pocet<n){ 

time+=h;

if(pocet<n-1){//cin>>t>>h;
scanf("%d",&t);
scanf("%d",&h);
}
pocet++;
}

if(t<a-1){
int add=t-i;
i+=add;

time-=add;




}

if(time>0)time--;





//cout<<"minuta "<<i<< "wait "<<time<<endl;
}
if(naj==10000000) cout<<"ZAJTRA"<<endl;
else 
cout<<pos<<" "<<naj<<endl;





}
