#include<iostream>

using namespace std;


int pole[1000047]={};
int main(){
int n;
cin>>n;

for(int i=1; i<=n; i++)
{
int d,t;
cin>>d>>t;
if(pole[d]<t) pole[d]=t;
}
int pocet=0;
for(int i=1; i<=n; i++)
if(pole[i]>0) pocet++;



cout<<pocet<<endl;




}
