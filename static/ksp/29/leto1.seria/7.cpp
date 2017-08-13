# include<iostream>
# include<vector>
using namespace std;
int pole[100009];
int pole1[100009];

vector <vector<int> > cesty;
vector<int>::iterator it;






int main(){
int n,m;

cin>>n;
cesty.resize(100009);
for(int i=0; i<n; i++){
cin>>pole[i];
pole1[pole[i]]=i;
}

cin>>m;
for(int i=0; i<m; i++){
int t,u;
cin>>t>>u;
cesty[t].push_back(u);
cesty[u].push_back(t);
}





int zac=0,kon=1,max=1,pocet=0;


while(true){
pocet++;
for(int i=zac; i<kon; i++)
for(it=cesty[pole[i]].begin(); it<cesty[pole[i]].end(); it++)
if(pole1[(*it)]>max) max=pole1[(*it)];


zac=kon;
kon=max+1;
if(max>=n-1) break;
}


cout<<pocet<<endl;;
}
















