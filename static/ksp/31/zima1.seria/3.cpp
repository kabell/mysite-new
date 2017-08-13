#include<iostream>
#include<map>

using namespace std;

map<int,int>M;

int main(){
int n,m;
cin>>n>>m;
for(int i=1; i<=n; i++){
int t;
cin>>t;
M[t]=i;
}

for(int i=1; i<=m; i++)
{
int t;
cin>>t;
if(M.find(t)!=M.end())
    cout<<M[t]<<endl;
else cout<<"-1"<<endl;

}

}
