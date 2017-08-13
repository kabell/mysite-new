#include<iostream>
#include<vector>
#include<algorithm>
#define INF 999999999
using namespace std;

vector<vector<int>>V;
vector<vector<int>>G;

vector<vector<int>>A;

int curr;
int cesta=0;

void r(int f,int c,int m){

A[curr][c]=cesta-m+V[curr][c];
for(auto it=G[c].begin(); it!=G[c].end(); it++)
    if(*it!=f)
        r(c,*it,max(m,V[c][*it]));


}




int main(){
int n;
cin>>n;
V.resize(n+47,vector<int>(n+47,0));
A.resize(n+47,vector<int>(n+47,0));
for(int i=1; i<=n; i++)
    for(int j=1; j<=n; j++)
        cin>>V[i][j];

vector<int>seen;
vector<int>dst;
vector<int>fdst;
G.resize(n+47);

seen.resize(n+47,0);
dst.resize(n+47,INF);
fdst.resize(n+47,INF);


dst[1]=0;
fdst[1]=0;
for(int i=1; i<=n; i++){
    int naj=INF;
    int vrch=0;
    for(int j=1; j<=n; j++)
        if(seen[j]==0 && dst[j]<naj)
            {naj=dst[j]; vrch=j;}
    //cout<<"nasiel som vrchol "<<vrch<<endl;
    seen[vrch]=1;
    G[fdst[vrch]].push_back(vrch);
    if(fdst[vrch]!=0)
    G[vrch].push_back(fdst[vrch]);

    for(int j=1; j<=n; j++)
        if(seen[j]==0 && V[vrch][j]<dst[j]){
            dst[j]=V[vrch][j];
            fdst[j]=vrch;
        }

}
for(int i=1; i<=n; i++)
cesta+=dst[i];


/*
for(int i=1; i<=n; i++){
    cout<<"vrchol "<<i<<endl;
for(auto it=G[i].begin(); it!=G[i].end(); it++)
    cout<<*it<<" ";
cout<<endl;

}
cout<<"odpoved"<<endl;
cout<<cesta<<endl;
*/
for(int i=1; i<=n; i++){
curr=i;
for(auto it=G[i].begin(); it!=G[i].end();it++)
    r(i,*it,V[i][*it]);

}

for(int i=1; i<=n; i++)
{
for(int j=1; j<=n-1; j++)
    cout<<A[i][j]<<" ";
cout<<A[i][n]<<endl;

}



}

