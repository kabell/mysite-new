#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;


struct pol{
int c;
int b;
};


int mina=210000;
vector< vector< pol > > prvky;
vector<pol>::iterator it;

bool zakl[200009]; 
int kroky[200009];
int prvk[200009];
int poc=0;









int main(){
int k,m,n;


prvky.resize(200009);



cin>>k>>n>>m;



for(int i=0; i<n; i++){
int temp;
cin>>temp;
zakl[temp]=true;
kroky[temp]=0;
prvk[poc++]=temp;
}
//cout<<"lol"<<endl;


for(int i=0; i<m; i++){

int a,b,c;
cin>>a>>b>>c;
pol temp;
temp.c=c;
temp.b=b;
prvky[a].push_back(temp);
temp.b=a;
prvky[b].push_back(temp);

}

int zac=0,kon=poc-1,krok=1;

while(kon+1<k){


for(int i=zac; i<=kon; i++){
for(it=prvky[prvk[i]].begin(); it<prvky[prvk[i]].end(); it++){

	if(zakl[(*it).b]==true && kroky[(*it).b]<krok && zakl[(*it).c]!=true) {
	prvk[poc++]=(*it).c;
	kroky[(*it).c]=krok;
	zakl[(*it).c]=true;
	}
}

}
zac=kon+1;
kon=poc-1;
krok++;

}

for(int i=1; i<=k; i++) printf("%d\n",kroky[i]);











}









