#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


vector<vector<int>>V;


int main(){

int n;
cin>>n;
V.resize(n+47);

for(int i=0; i<n; i++){
	int t;
	cin>>t;
	for(int j=1; j<=t; j++){
	int k;
	cin>>k;
	V[i].push_back(k);
	}
}


int pocet=0;

for(int i=0; i<n; i++){
	int p1=0, p2=0;

	for(int j=0; j<V[i].size(); j++){
		int po1=0, po2=0;
		for(int k=p1; k<V[(i+1+n)%n].size(); k++)
			if(V[(i+1+n)%n][k]<V[i][j])
				po1++;
			else break;
		for(int k=p2; k<V[(i-1+n)%n].size(); k++)
			if(V[(i-1+n)%n][k]<V[i][j])
				po2++;
			else break;
		if(po1!=po2)
			pocet++;
		p1+=po1;
		p2+=po2;

	}



}


cout<<pocet<<endl;




}
