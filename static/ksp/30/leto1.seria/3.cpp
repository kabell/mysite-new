#include<iostream>
#include<vector>
#include<cstdio>

using namespace std;


vector<long long>V;

int main(){

	int n;

	cin>>n;
	V.resize(n+47);

	for(int i=1; i<=n; i++)
		scanf("%lld",&V[i]);//alebo pouzi cin>>V[i]
	V[n+1]=47474747474747;		//konstanta na konci / najvacsia palicka
	int naj=987654329;
	int h=2;			//tretia palicka moze byt minimalne 2(pretoze 1 a 2 je testovana)

	if(n<3){ cout<<"0"<<endl; return 0;}	//osetrenie / aj ked vo vstupe nieje taky test

	for(int i=1; i<n-1; i++){		//prejdeme vsetky dvojice paliciek

		for(int j=max(h,i+2); j<=n+1; j++){	//najdeme najmensiu nevyhovujucu
			if(V[i]+V[i+1]<=V[j]){			//takto ju otestujem
				h=j;					//h=...
				break;}
		}
		int sum=n-(h-i);			//vypocitam sucet kolko musim odstranit

		if(sum<naj)naj=sum; 			//a testujem

	}
	cout<<naj<<endl;			//vypisem
}
