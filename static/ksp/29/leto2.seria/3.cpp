#include <iostream>

using namespace std;

int pole[1000109][2];

int main(){

int n,k;
cin>>n>>k;

for(int p=0; p<=n; p++){
pole[p][0]=0;
pole[p][1]=0;
}
for(int i=1; i<=k; i++){


while(true){


int f;
cin>>f;
if(f==0) break;
if(pole[f][1]<i){pole[f][0]++;
pole[f][1]=i;
}


}
}

int max=0,name=0;
for(int i=1; i<=n; i++)
if(pole[i][0]>max){
max=pole[i][0];
name=i;
}
cout<<name<<endl;


}
