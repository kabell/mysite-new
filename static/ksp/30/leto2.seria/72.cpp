#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;

struct s{
long long vaha;
long long predmety;

};


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

C.resize(47,0);
V.resize(47,0);
Sc.resize(47,0);
Sv.resize(47,0);

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
//r(0,1,0,0);



unordered_map<long long,s>M1,M2;

M2[0]={0,0};

for(int i=1; i<=n+1; i++){

swap(M1,M2);
M2.clear();
M2[C[i]]={V[i],1};



for(auto it=M1.begin(); it!=M1.end(); it++){


long long cena=it->first, vaha=it->second.vaha, k=it->second.predmety;

//cout<<"Kabell "<<k<<endl;

if(vaha+Sv[i]<=h){

if(vaha+Sv[i]>=d){

if(cena+Sc[i]>najcena){
//cout<<"LOL"<<k<<endl;
for(int j=i; j<=n; j++)
	k=k*2+1;
najcena=cena+Sc[i];
P=k;
//cout<<"Upgrade"<<k<<endl;
}
}
continue;
}

if(vaha+Sv[i]<d) continue;
if(vaha>h) continue;

if(cena>najcena && vaha<=h && vaha >=d){
long long x=k;
for(int j=i; j<=n; j++)
x*=2;
P=x;
najcena=cena;
//cout<<"P="<<P<<endl;
}
if(i==n+1) continue;
if(M2.find(cena)==M2.end()){
	M2[cena]={vaha,k*2};
//cout<<"Pridavam "<<k*2<<endl;
}
else if(M2[cena],vaha>vaha){
	M2[cena]={vaha,k*2};
//	cout<<"k"<<endl;
}



if(M2.find(cena+C[i])==M2.end()){
	M2[cena+C[i]]={vaha+V[i],k*2+1};

//cout<<"pridavam "<<k*2+1<<endl;
}
else if(M2[cena+C[i]].vaha>vaha+V[i]){
	M2[cena+C[i]]={vaha+V[i],k*2+1};
//	cout<<"l"<<endl;

}

}
}

//cout<<"L "<<P<<endl;
/*
for(auto it=M2.begin(); it!=M2.end(); it++)
	cout<<"Preyeram "<<it->first<<" "<<it->second.predmety<<endl;
*/
//cout<<P<<endl;
////////////////////////////////////////////////
////////////////////////////////////////////////
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
