#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<map>
#include<queue>

#define ll long long


using namespace std;

struct zatarasa{
    ll z;
    ll k;
    ll c;
    ll pred;
    ll ch;
    ll s;
    bool prechod;
    ll pos;
};



struct classcomp {
      bool operator() (const ll& lhs, const ll& rhs) const
            {return lhs>rhs;}
};




vector<zatarasa>V;
vector<zatarasa>P;

map<ll,zatarasa>Z,T;
vector<map<int,zatarasa>>Tree;

queue<int>Q;

ll naj=999999,najc=999999;


void d(){


int q=0;
while (Q.size()>0){

int t=Q.front();
Q.pop();

int strom=P[t].s;
int par=P[t].pred;
int pstrom=P[par].s;


if(P[t].z<P[t].k){
    while(true){

        auto it=Tree[strom].upper_bound(P[t].z);
            if(it==Tree[strom].end())break;

            if(it->first>P[t].k)break;
            int poc=P[t].pos-it->second.pos+1;
            if(poc<naj){
                naj=poc;
                najc=it->second.c;
            }
            Tree[strom].erase(it);
            

        }
}
else{
    while(true){
        auto it=Tree[strom].rbegin();
            if(it==Tree[strom].rend())break;
            if(it->second.z<P[t].z)break;

            int poc=P[t].pos-it->second.pos+1;
            if(poc<naj){
                
                naj=poc;
                najc=it->second.c;
            }
            Tree[strom].erase(Tree[strom].find(it->first));
            }

    while(true){
        auto it=Tree[strom].begin();
        if(it==Tree[strom].end())break;
        if(it->second.z>P[t].k)break;
        int poc=P[t].pos-it->second.pos+1;
        if(poc<naj){
            naj=poc;
            najc=it->second.c;
        }
        Tree[strom].erase(it);


    }


}


if(P[t].prechod==false)
Tree[strom][P[t].z]=P[t];

if(P[par].prechod==false){

if(Tree[pstrom].size()==0){
    P[par].s=strom;
    P[par].pos=P[t].pos+1;
}
else{
if(Tree[strom].size()>Tree[pstrom].size()){
int roz=P[par].pos-P[t].pos+1;
    for(auto it=Tree[pstrom].begin(); it!=Tree[pstrom].end(); it++){
        Tree[strom][it->first]=it->second;
        Tree[strom][it->first].s=strom;
        Tree[strom][it->first].pos-=roz;

        }
P[par].s=strom;
P[par].pos=P[t].pos+1;
}
else{
    int roz=P[par].pos-P[t].pos-1;
    for(auto it=Tree[strom].begin(); it!=Tree[strom].end(); it++){
        Tree[pstrom][it->first]=it->second;
        Tree[pstrom][it->first].s=pstrom;
        Tree[pstrom][it->first].pos+=roz;
    }

}
}

}
if(Tree[strom].size()==0)break;

P[t].ch--;
P[par].ch--;
if(P[par].ch<=1)
    Q.push(par);

if(P[par].prechod==true){
    P[par].s=strom;
    P[par].pos=P[t].pos+1;

}    
P[t].prechod=true;
q++;
}




}


int main(){

    ll n,m;
    cin>>m>>n;

    P.resize(n+47);
    Tree.resize(n+47);

    for(ll i=0; i<n; i++){
        ll x,l;
        cin>>x>>l;
        if(l==m){cout<<"1"<<endl<<i+1<<endl; return 0;}

        if(Z.find(x)!=Z.end()){
            if(Z[x].k<l+x)
                Z[x]={x,l+x,i+1,0,0,i+1,0,0};
        }
        else Z[x]={x,l+x,i+1,0,0,i+1,0,0};

        if(Z.find(x+m)!=Z.end()){
            if(Z[x+m].k<l+x+m)
                Z[x+m]={x+m,l+x+m,i+1,0,0,i+1,0,0};
            }
        else Z[x+m]={x+m,l+x+m,i+1,0,0,i+1,0,0};
        
        
        V.push_back({x,l+x,i+1,0,0,i+1,0,0});
        V.push_back({x+m,l+x+m,i+1,0,0,i+1,0,0});
        P[i+1]={x,(l+x)%m,i+1,0,0,i+1,0,0};
    }

ll zac,kon;
zac=Z.begin()->second.z;
kon=Z.begin()->second.k;

for(auto it=Z.begin(); it!=Z.end(); it++){

if(zac!=it->second.z && kon!=it->second.k)
    if(it->second.k>kon){
    
        T[it->first]=it->second;
        kon=it->second.k;


    }


}


map<ll,zatarasa,classcomp>S;
map<ll,zatarasa>N;


zatarasa last=T.rbegin()->second;

for(auto it=T.rbegin(); it!=T.rend(); it++){
    if(S.size()>0)
        while (S.begin()->first>it->second.k){

            if(N[S.begin()->second.k].c==S.begin()->second.c)
                N.erase(N.find(S.begin()->second.k));
            S.erase(S.begin());
        }

    ll naj=0;
    if(N.size()>0)
        naj=N.rbegin()->second.c;
    
    
    S[it->first]=it->second;
    P[it->second.c].pred=naj;
    N[it->second.k]=it->second;

    last=it->second;
}


for(int i=1; i<=n; i++){
P[P[i].pred].ch++;
P[i].ch++;

}


for(int i=1; i<=n; i++)
P[i].s=i;



for(int i=1; i<=n; i++)
    if(P[i].ch==1 && P[i].pred!=0)
    Q.push(i);

d();

for(int i=1; i<=n; i++)
if(P[i].prechod==false && P[i].pred!=0){


Q.push(i);
d();


}

if(najc==999999){while(true)cout<<"47"<<endl;;}
ll c=najc;
ll pos=najc,poc=0;
bool ok=false;

vector<ll>X;

X.push_back(c);
while(true){

if(P[pos].z>P[pos].k)ok=true;
if((P[c].z<=P[pos].k && ok) || (P[pos].z>P[pos].k && P[pos].k+m>=P[c].z && P[pos].z<P[c].z)  && poc>0)break;


    poc++;
    pos=P[pos].pred;
    X.push_back(pos);
}

cout<<X.size()<<endl;
sort(X.begin(),X.end());
for(auto it=X.begin(); it!=X.end()-1; it++)
cout<<*it<<" ";
if(X.size()>0)
cout<<X[X.size()-1]<<endl;
else while(true) cout<<"47"<<endl;

    
}
