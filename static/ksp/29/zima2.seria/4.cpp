#include <iostream>
#include <string>
#include <stdlib.h>
#include <sstream>
#include <stdio.h>
#include <cmath>
#include <map>
#include <vector>
using namespace std;

int main(){

int n,m;
cin>>n>>m;
for(int i=0; i<m; i++){
long long x,x1;
long long pole[32];
cin>>x;

if(x==0) cout<<pow(2,n)<<" ";
else for(int k=0; k<=n; k++)
if(x%(long long)pow(2,k+1)==pow(2,k)){ cout<<pow(2,k)<<" "; break;}

for(int k=0; k<=n; k++){
pole[k]=x%2;
x=x/2;
}




long long sum=pow(2,n);
for(int k=0; k<=n; k++){
if(pole[k]%2==1) sum--;

}
cout<<sum<<endl;






}
}


