#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;



vector<int> pole;



priority_queue<long long, vector<long long>,greater<long long> > F;





int main(){
int n,k;
cin>>n>>k;


for(int i=1; i<=n; i++){
int t;
cin>>t;
pole.push_back(t);
}

sort(pole.begin(), pole.end());
int pocet=k;





for(int i=1; i<=n; i++)
{
long long get=pole.back();
pole.pop_back();

if(pocet==0){ get+=F.top();
F.pop();
}

F.push(get);
if(pocet>0)
pocet--;



}


while(F.size()>1){

F.pop();




}

cout<<F.top()<<endl;



}
