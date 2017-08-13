#include <iostream>
#include <cmath>

using namespace std;

bool prvocislo(long long p){
long long sqr=sqrt(p);
for(long long i=2; i<=sqr; i++)
if(p%i==0) return false;

return true;
}


int mocnina(int k, long long n){
long long p=k;

while(p<n)
p*=k;



if(p==n) return true;
else return false;
}

int test(){
long long n,k;
cin>>n>>k;

if(n==k){
cout<<"ano"<<endl;
 return 0;



}

if(sqrt(k)==(double)((int)sqrt(k)) && mocnina((int)sqrt(k),n)==true){ cout<<"ano"<<endl;return 0;}


if(prvocislo(k)==true && n%k==0){ cout<<"ano"<<endl;return 0;}




cout<<"nie"<<endl;

return 0;
}


int main(){



test();







}
