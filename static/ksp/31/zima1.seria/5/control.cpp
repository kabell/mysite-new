#include<iostream>
#include<vector>
using namespace std;
vector<pair<int,int>>V;
int main(){

int n,h;
cin>>n>>h;
V.resize(h+47);

for(int i=1; i<=h; i++)
cin>>V[i].first>>V[i].second;

string s;
while(cin>>s){
cin>>s;
vector<pair<int,int>>T;
for(int i=1; i<=n; i++){
int t;
cin>>t;
T.push_back(V[t]);
}
int start=T[0].second;
int pos=0;
int last=T[0].first;
int poc=1;
cout<<last<<" ";
while(last!=start){
poc++;
for(int j=0; j<T.size(); j++)
    if((T[j].first==last || T[j].second==last) && j!=pos){
    if(T[j].first==last){pos=j;last=T[j].second; break;}
    else {pos=j;last=T[j].first; break;}
    }
cout<<last<<" ";
}
if(poc==n)cout<<"dobre"<<endl;
else cout<<"zle"<<endl;
}

}

