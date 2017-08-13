#include<iostream>
#include<vector>

using namespace std;

vector<long long>C,V,Sc,Sv;
long long n,d,h;
long long najcena=0;
long long P;

void r(long long k,long long z,long long cena, long long vaha){

if(vaha+Sv[z]<=h){

if(vaha+Sv[z]>=d){

if(cena+Sc[z]>najcena){

for(int i=z; i<=n; i++)
	k=k*2+1;
najcena=cena+Sc[z];
P=k;

}
}
return;
}

if(vaha+Sv[z]<d) return;
if(vaha>h) return;

if(cena>najcena && vaha<=h && vaha >=d){
long long x=k;
for(int i=z; i<=n; i++)
x*=2;
P=x;
najcena=cena;
//cout<<"P="<<P<<endl;
}
if(z==n+1) return;
k*=2;
r(k,z+1,cena,vaha);
k+=1;
r(k,z+1,cena+C[z],vaha+V[z]);



}





int main(){

cin>>n>>d>>h;

C.resize(47);
V.resize(47);
Sc.resize(47);
Sv.resize(47);

for(int i=1; i<=n; i++)
	cin>>V[i]>>C[i];
long long sum1=0,sum2=0;
for(int i=n; i>0; i--){

sum1+=V[i];
sum2+=C[i];
Sc[i]=sum2;
Sv[i]=sum1;

}
/*
for(int i=1; i<=n; i++)
	cout<<Sc[i]<<" ";
	cout<<endl;
for(int i=1; i<=n; i++)
	cout<<Sv[i]<<" ";
	cout<<endl;
*/
vector<int>X;
r(0,1,0,0);

//cout<<P<<endl;


for(int i=n; i>0; i--){
	if(P%2==1)
		X.push_back(i);
	P/=2;
}

cout<<X.size()<<endl;
if(X.size()>0){
for(auto it=X.end()-1; it!=X.begin(); it--)
	cout<<*it<<" ";
	cout<<*X.begin()<<endl;
}

}
