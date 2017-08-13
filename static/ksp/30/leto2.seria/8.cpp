#include<iostream>
#include<vector>


using namespace std;

long long n;
long long super=10301;

vector<long long>comp(long long a){


vector<vector<long long>>V;
vector<long long>D;
V.resize(2*n+47,vector<long long>(2*n+47,0));
D.resize(2*n+47,0);
V[a][a]=1;
for(int i=a; i<=n; i++)
	V[2*i][i]=1;
	
for(int i=2*a; i<n; i++){

	for(int j=1; j<=n; j++){
		V[i+j][j]+=V[i][j];
		V[i+j][j]%=super;
		V[i+1][j+1]+=V[i][j];
		V[i+1][j+1]%=super;
		D[i+1]+=V[i][j];
		D[i+1]%=super;
	}


}

//cout<<"ok"<<endl;
vector<long long>K;
K.resize(n+47);
for(int i=1; i<=n; i++){
	long long suc=0;
	for(int j=1; j<=n; j++)
		suc+=V[i][j];
		suc%=super;
	K[i]=suc-D[i]+super;
	K[i]%=super;
}

return K;
}




int main(){

int a,b;
cin>>n>>a>>b;

vector<long long>U,V;
U=comp(a);
V=comp(b);

long long suc=0;
long long s=0;
for(int i=a; i<n-b+1; i++){
s+=U[i];
s%=super;
//cout<<s<<" l "<<V[n-i]<<endl;
suc+=s*V[n-i];
suc%=super;
}
/*
for(int i=1; i<=n; i++)
	cout<<U[i]<<" ";
	cout<<endl;
for(int i=1; i<=n; i++)
	cout<<V[i]<<" ";
	cout<<endl;

*/

cout<<suc%super<<endl;

//cout<<"hotovo"<<endl;
}
