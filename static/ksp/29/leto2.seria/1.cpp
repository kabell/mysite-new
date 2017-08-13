#include <iostream>
#include <vector>
using namespace std;

int pole[10000005];
bool navs[1000005];




int main(){

long long n;
cin>> n;

for (long long i=1; i<=n; i++){
navs[i]=false;
}



int err=1;
for (long long i=1; i<=n; i++){
long long temp;
cin>>temp;
pole[i]=temp;
}

int pos=1;




while(true){
if(navs[pole[pos]]!=true){
navs[pole[pos]]=true;
pos=pole[pos];


}
else break;
}



for (long long i=1; i<=n; i++){
if(navs[i]!=true)
err=0;
}



if(err==1) cout<<"Ano"<<endl;
else cout<<"Nie"<<endl;




}
