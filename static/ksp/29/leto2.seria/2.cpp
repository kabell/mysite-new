#include <iostream>

using namespace std;

int main(){


int n;
cin>>n;
int arp;
long double gep;
int min,temp;
bool ar=true,ge=true;

cin>>temp>>min;

arp=min-temp;

if(temp)
gep=(long double)((long double)min/(long double)temp);
else gep =0;




for (int i=2; i<n; i++){

int k;
cin>>k;
if(k-min!=arp) ar=false;
if(gep*min!=k) ge=false;

min=k;




}


if(ar) cout<<"ano"<<endl;
else cout<<"nie"<<endl;
if(ge) cout<<"ano"<<endl;
else cout<<"nie"<<endl;




}
