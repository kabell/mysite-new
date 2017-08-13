#include<iostream>
#include<vector>
#include<map>
using namespace std;

struct s{

long long cena;
long long predmety;

};


vector<long long>C,V,Sc,Sv;
long long n,d,h;
long long najcena=0;
long long P;
map<long long,s>M;
long long k1=0,k2=0;




void r(long long k, long long z,long long cena, long long vaha){


if(z==n/2+1){
if(M.find(-vaha)==M.end())
	M[-vaha]={cena,k};	
else if(M[-vaha].cena<cena)
	M[-vaha]={cena,k};	
	
return;
}
else{
r(k*2,z+1,cena,vaha);
r(k*2+1,z+1,cena+C[z],vaha+V[z]);
}
}



void r1(long long k, long long z,long long cena, long long vaha){

if(z<n+1){
r1(k*2,z+1,cena,vaha);
r1(k*2+1,z+1,cena+C[z],vaha+V[z]);

}
else{

auto it=M.lower_bound(-h+vaha);
if(it==M.end()) return;
long long cena1=cena+it->second.cena;
if(cena1>=d){
	najcena=cena1;
	k1=it->second.predmety;
	k2=k;
}
//else cout<<"Too low"<<endl;
}

}




int main(){

cin>>n>>d>>h;

C.resize(47);
V.resize(47);

for(int i=1; i<=n; i++)
	cin>>V[i]>>C[i];


r(0,1,0,0);

/*
for(auto it=M.begin(); it!=M.end(); it++)
{
set(it->first,it->first);

}
*/
r1(0,n/2+1,0,0);
//cout<<najcena<<endl;

vector<int>X;
for(int i=n; i>n/2; i--){
	if(k2%2==1)
		X.push_back(i);
	k2/=2;
}

for(int i=n/2; i>0; i--){
if(k1%2==1)
	X.push_back(i);
k1/=2;

}



cout<<X.size()<<endl;
if(X.size()>0){
for(auto it=X.end()-1; it!=X.begin(); it--)
	cout<<*it<<" ";
	cout<<*X.begin()<<endl;
}

}
