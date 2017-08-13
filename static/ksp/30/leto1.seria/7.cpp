#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

struct str{

int p;
int pole[10];

};



bool compare(str a, str b){

int pa=0;

for(int i=1; i<=5; i++)
if(a.pole[i]<b.pole[i])
pa++;

//cout<<a.p<<" "<<b.p<<endl;
if (pa>2) return 1;
return 0;

}



vector<str> V;


int main(){

int n;

cin>>n;
V.resize(n+47);
for(int i=1; i<=n; i++)
V[i].p=i;


//for(int i=0; i<=n; i++)
//cout<<V[i].p<<endl;

for(int k=1; k<=5; k++)
for(int i=1; i<=n; i++){
int t;
cin>>t;
V[t].pole[k]=i;

}

//cout<<"ok"<<endl;

sort(V.begin()+1,V.begin()+n+1,compare);
//cout<<"ok1"<<endl;

for(int i=1; i<n; i++)
cout<<V[i].p<<" ";
cout<<V[n].p;
cout<<endl;






}
