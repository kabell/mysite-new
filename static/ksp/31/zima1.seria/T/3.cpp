#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#define ll long long

using namespace std;

vector<pair<ll,ll>>V,F;
vector<ll>T,H;



int main(){

ll n;
cin>>n;
V.resize(n+47);
T.resize(n+47,0);

for(int i=1; i<=n; i++){
cin>>V[i].first;
}
for(int i=1; i<=n; i++)
cin>>V[i].second;

ll naj=V[n].first*V[1].second;
ll pos=0;

F.push_back(make_pair(0,1));


for(int i=2; i<n; i++){
while(pos<F.size()-1 && (T[F[pos].second]+V[F[pos].second].second*V[i].first>T[F[pos+1].second]+V[F[pos+1].second].second*V[i].first)){
    pos++;
}
if((long double)(T[F[pos].second])+((long double)V[F[pos].second].second)*((long double)V[i].first)>(long double)naj)
    T[i]=naj;
    else
    T[i]=T[F[pos].second]+V[F[pos].second].second*V[i].first;
if(!((long double)(T[F[pos].second])+((long double)V[F[pos].second].second)*((long double)V[i].first)>(long double)naj)){
auto last=*(F.end()-1);
while((long double)last.first*(long double)V[i].second+(long double)T[i]<(long double)last.first*(long double)V[last.second].second+(long double)T[last.second]){
F.pop_back();
last=*(F.end()-1);
}
F.push_back(make_pair(ceil((long double)(T[last.second]-T[i])/(long double)(V[i].second-V[last.second].second)),i));
pos=min(pos,(long long)(F.size()-1));
if((long double)T[i]+(long double)V[n].first*(long double)V[i].second<(long double)naj)
naj=min(naj,T[i]+V[n].first*V[i].second);
}
}
cout<<naj<<endl;
}
