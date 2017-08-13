#include<iostream>
#include<cstdlib>
#include<vector>
using namespace std;

int main(){

vector<pair<int,int> >V;
int n;
cin>>n;
V.resize(n+47);
for(int i=1; i<=n; i++)
    cin>>V[i].first>>V[i].second;

string s;
while(cin>>s){
if(s=="v" || s=="SATISFABLE" || s=="s")continue;
int p=atoi(s.c_str());
if(p>0)cout<<V[p].first<<" "<<V[p].second<<endl;;

}




}
