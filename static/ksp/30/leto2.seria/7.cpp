#include<iostream>
#include<map>
#include<vector>

using namespace std;

struct p{
long long v;
long long c;

};

struct s{

long long vaha;
long long predmety;

};



int main(){

long long n,d,h;
cin>>n>>d>>h;

map<long long,s>M1,M2;
vector<long long>V,C1;
V.resize(47);
C1.resize(47);

for(int i=1; i<=n; i++){
cin>>V[i]>>C1[i];
}

vector<long long>S,T;
S.resize(47);
T.resize(47);

long long sum=0,sum1=0;
for(int i=n; i>0; i--){
sum+=V[i];
sum1+=C1;
S[i]=sum;
T[i]=sum1;
}



M2[0]={0,0};

for(int i=1; i<=n; i++){
	long long cenat=C1[i],vahat=V[i];
//	cin>>vahat>>cenat;

	swap(M1,M2);
	M2.clear();
	if(vahat<=h)
	M2[cenat]={vahat,1};
	map<long long,s>N;
	for(auto it=M1.begin(); it!=M1.end(); it++){
//	cout<<"Prezeram "<<it->first<<" "<<it->second.vaha<<endl;
		long long cena=it->first;
		long long vaha=it->second.vaha;
		long long predmety=it->second.predmety*2;

		if(M2.find(cena)==M2.end())
			M2[cena]={vaha,predmety};
		else if(M2[cena].vaha>vaha)
			M2[cena]={vaha,predmety};

		if(S[i]+vaha<d) continue;
		if(S[i]+vaha<=h){
			predmety++;
			for(int j=i+1; j<=n; j++)
				predmety=predmety*2+1;
			N[T[i]+cena]={S[i]+vaha,predmety};
			continue;
			
		
		}
		cena+=cenat;
		vaha+=vahat;
		predmety++;

		if(vaha<=h){
		if(M2.find(cena)==M2.end())
			M2[cena]={vaha,predmety};
		else if(M2[cena].vaha>vaha)
			M2[cena]={vaha,predmety};
		}

}

}
/*
cout<<endl;
for(auto it=M2.begin(); it!=M2.end(); it++)
	cout<<"Prezeram "<<it->first<<" "<<it->second.vaha<<endl;
*/
auto it=M2.end();
it--;

//cout<<it->first<<" "<<it->second.predmety<<endl;
vector<int>C;

if(it->second.vaha>h)
	while(true)
		cout<<endl;


if(it->second.vaha>=d){

long long k=it->second.predmety;
for(int i=n; i>0; i--){
if(k%2==1)
	C.push_back(i);
k/=2;
}


}

cout<<C.size()<<endl;
if(C.size()>0){
for(int i=C.size()-1; i>0; i--)
	cout<<C[i]<<" ";
if(C.size()>0)
cout<<C[0]<<endl;
}

}

