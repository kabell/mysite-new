#include<iostream>
#include<map>
#include<vector>

using namespace std;

map<int,vector<int>> X;
map<int,vector<int>> Y;

int main(){


int n;
cin>>n;
for(int i=1; i<=n; i++)
{
int x,y;
cin>>x>>y;
X[x].push_back(y);
Y[y].push_back(x);

}
long long sum=0;
for(auto it=X.begin(); it!=X.end(); it++)
{
for(auto iv=(*it).second.begin(); iv!=(*it).second.end(); iv++)

sum+=((*it).second.size()-1)*(Y[(*iv)].size()-1);


}



cout<<sum<<endl;


}
