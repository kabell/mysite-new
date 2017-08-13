#include<iostream>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<vector>
#include<algorithm>

using namespace std;

struct str{

int p;
set<int> S;
};


vector<vector<int>> V;
vector<int>P;

bool compare(const str & a,const str & b){
	return a.S.size()<b.S.size();
}




str r(int cur,int z){


if(V[cur].size()==1)
{
str t;
t.p=P[cur];
t.S.insert(0);
return t;


}


	vector<str>M;

	for(auto it=V[cur].begin(); it!=V[cur].end(); it++){
		if(*it!=z)
			M.push_back(r(*it,cur));
	}

	sort(M.begin(),M.end(),compare);

	str T;
	T=*(M.end()-1);

	int p=(M.end()-1)->p;

	cout<<p<<endl;

	for(auto it=M.begin(); it!=M.end(); it++){
		for(auto it1=it->S.begin(); it1!=it->S.end(); it++){
			int s=*it1+it->p;
			cout<<s<<endl;
			if(T.S.find(-s)!=T.S.end()) cout<<"Nasiel som ho "<<s<<endl;
			if(T.S.find(s)==T.S.end()) T.S.insert(s-T.p);
		}
	}
		
	return T;
}

int main(){

int n;
cin>>n;

P.resize(n+47);
V.resize(n+47);

for(int i=0; i<n; i++){
	char c;
	cin>>c;
	if(c=='L') P[i]=-1;
	else P[i]=1;
}

for(int i=1; i<n; i++){
	int a,b;
	cin>>a>>b;
	V[a].push_back(b);
	V[b].push_back(a);
}






}
