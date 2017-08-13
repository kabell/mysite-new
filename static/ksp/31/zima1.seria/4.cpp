#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>

using namespace std;
struct str{
int l;
int c;
int r;
};


vector<str>forwardlist;

unordered_set<int>S;

int main(){

int n;
cin>>n;
forwardlist.resize(n+47);

for(int i=1; i<=n; i++){
int t;
cin>>t;
forwardlist[i]={i-1,t,i+1};
S.insert(i);
}
forwardlist[n+1]={n,0,0};
forwardlist[0]={0,0,1};

int poc=0;
queue<int>Q;
queue<int>bin;

while(true){

    for(auto it=S.begin(); it!=S.end(); it++){
    if(forwardlist[*it].c>forwardlist[forwardlist[*it].r].c && forwardlist[*it].r<=n)
        Q.push(forwardlist[*it].r);
    else bin.push(*it);
    }
    
    if(Q.size()==0)break;


    while(Q.size()>0){
    int t=Q.front();
    forwardlist[forwardlist[t].r].l=forwardlist[t].l;
    forwardlist[forwardlist[t].l].r=forwardlist[t].r;
    bin.push(t);
    Q.pop();
    }

    while(bin.size()>0){
    int t=bin.front();
    S.erase(t);
    bin.pop();

    }


    
poc++;
}


cout<<poc<<endl;

}
