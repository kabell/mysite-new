#include<iostream>
#include<vector>


using namespace std;


vector<long long> V;


vector<long long>S,T,U,W;


long long naj=0;

int main(){


int n;
long long pocet=0;
cin>>n;

V.resize(n+47);
T.resize(n+47);
S.resize(n+47);
U.resize(n+47);
W.resize(n+47);

V[0]=0;
V[n]=0;
for(int i=1; i<n; i++){
cin>>V[i];
if(V[i]<1)fork();
}

long long suc=0,suct=0,najsucet=0,pz=1,pk=0,posk=0,posz=1;
long long z=0,k=0;
long long sucet=0;
long long suc1=0,suc2=0;

for(int i=1; i<n; i++){

if(V[i-1]==1){ suc1=0;}

suc1+=V[i]-(V[i])%2;
suc2+=V[i]-(V[i]+1)%2;

suc-=V[i-1];

if(V[i]!=1) {

pk++;

if(V[i-1]==1) {
sucet=suc; pz=i; pk=i;
}


 if(V[i]%2==0)sucet++;
else sucet--;

S[i]=suc1;
T[i]=suc2;



if(najsucet<sucet) {najsucet=sucet; posk=pk; posz=pz;suc2=suc1;}
}


U[i]=max(suc1,suc2);
}

 suc=0;suct=0;najsucet=0;pz=n-1;pk=n;posk=n;posz=n-1;
 sucet=0;
 suc1=0;suc2=0;



for(int i=n-1; i>0; i--){

if(V[i+1]==1){ suc1=0;}

suc1+=V[i]-(V[i])%2;
suc2+=V[i]-(V[i]+1)%2;

suc-=V[i+1];

if(V[i]!=1) {

pk++;

if(V[i+1]==1) {
sucet=suc; pz=i; pk=i;
}


 if(V[i]%2==0)sucet++;
else sucet--;

S[i]=suc1;
T[i]=suc2;



if(najsucet<sucet) {najsucet=sucet; posk=pk; posz=pz;suc2=suc1;}
}


W[i]=max(suc1,suc2);
}



/*
cout<<endl;
for(int i=0; i<=n; i++)
cout<<S[i]<<" ";
cout<<endl;
cout<<endl;
for(int i=0; i<=n; i++)
cout<<T[i]<<" ";
cout<<endl;
for(int i=0; i<=n; i++)
cout<<U[i]<<" ";
cout<<endl;
for(int i=0; i<=n; i++)
cout<<W[i]<<" ";
cout<<endl;
*/

//cout<<best<<endl;

long long najviac=0;

for(int i=1; i<n-1; i++)
if(U[i]+W[i+1]>najviac)najviac=U[i]+W[i+1];


if(n>2)
cout<<najviac<<endl;
else cout<<V[1]<<endl;
}

