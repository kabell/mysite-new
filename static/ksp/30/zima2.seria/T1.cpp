#include<iostream>


using namespace std;
int pole[1047];
int n;

int mod(int i)
{
int k=i%n;

if(k<0) return k+n;
return k;



}
int main(){


//cout<<-100%7<<endl;

cin>>n;



for(int i=1; i<=n; i++)
cin>>pole[i];

int pocet=0;

if(pocet%2==0){

for(int i=1; i<=n; i++){


int p1=0;
for(int j=i; j>0; j=j-2)
if(pole[j]%2==1)p1++;


for(int j=i+2; j<=n; j+=2)
if(pole[j]%2==1)p1++;

int p2=0;
for(int j=i-1; j>0; j=j-2)
if(pole[j]%2==1)p2++;


for(int j=i+1; j<=n; j+=2)
if(pole[j]%2==1)p2++;


if(p1>p2){
pocet++;
cout<<i<<endl;
}
}






}





cout<<pocet<<endl;





}
