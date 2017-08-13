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



for(int i=0; i<n; i++)
cin>>pole[i];

int pocet=0;

for(int i=0; i<n; i++){

int h[2]={0};


int l=mod((i-1));
int p=mod((i+1));

if(pole[i]%2==1)
h[0]++;
//cout<<i<<endl;
//cout<<l<<" "<<p<<" "<<h[0]<<" "<<h[1]<<endl;
int t=1;
while(l!=p){
if(pole[p]%2==1) {h[t%2]++; p=mod((p+1));}
else if(pole[l]%2==1) {h[t%2]++; l=mod((l-1));}

else if(pole[(l-1)%n]%2==0) {l=mod((l-1));}
else if(pole[(p+1)%n]%2==0) {p=mod((p+1));}
else l=mod((l-1));
t++;
//cout<<l<<" "<<p<<" "<<h[0]<<" "<<h[1]<<endl;
}

if(pole[l]%2==1)h[t%2]++;
//cout<<endl;
if(h[0]>h[1]){ pocet++;
cout<<i<<endl;
//cout<<"Vie vzhrat hrac 0"<<endl;
}
//else cout<<"nevie vyhrac hrac 0"<<endl;


}





cout<<pocet<<endl;





}
