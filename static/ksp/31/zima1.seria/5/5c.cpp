#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>>V;

int main(){
int n,h;
cin>>n>>h;

V.resize(n+47);

for(int i=1; i<=h; i++){
int a,b;
cin>>a>>b;
V[a].push_back(i);
V[b].push_back(i);
}

int poc=0;
for(int i=0; i<n; i++){
poc+=(V[i].size()*(V[i].size()-1)*(V[i].size()-2))/6;
poc+=1<<((V[i].size()*(V[i].size()-1))/2);

}

cout<<"p cnf "<<h<<" "<<poc<<endl;


for(int i=0; i<n; i++){
vector<pair<int,int>>P;


for(auto it=V[i].begin(); it!=V[i].end(); it++){
for(auto it1=it+1; it1!=V[i].end(); it1++){
    P.push_back(make_pair(*it,*it1));
    for(auto it2=it1+1; it2!=V[i].end(); it2++)
        cout<<-*it<<" "<<-*it1<<" "<<-*it2<<" 0\n";
    }
}
//cout<<P.size()<<" lol"<<endl;
for(int s=0; s<(1<<P.size()); s++){
int p=s;

    for(int j=0; j<P.size(); j++){
if(p%2==1)cout<<P[j].second<<" ";
else cout<<P[j].first<<" ";
p/=2;
    }
    cout<<"0\n";
    
}


}





}
