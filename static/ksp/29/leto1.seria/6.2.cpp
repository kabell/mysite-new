#include <iostream>
#include <cstdio>
#include <vector>
#include <stdlib.h>

using namespace std;
int bato[200009];
int pole[200009];
struct po{
int b;
int d;
};

struct f{
long long batop;
long long sump;
long long sum;
};

f data[200009];


long long batsum=0;
long long mini=1000000000000;

int n;


vector < vector < po > > P;

void p(int vrch,int z){

vector<po>:: iterator it;
long long sump=0;
long long batop=0;

for(it=P[vrch].begin(); it<P[vrch].end(); it++)
if((*it).b!=z){
p((*it).b, vrch);
sump+=data[(*it).b].sump+(data[(*it).b].batop+bato[(*it).b])*(*it).d;
batop+=data[(*it).b].batop+bato[(*it).b];
}
data[vrch].batop=batop;
data[vrch].sump=sump;


}


void s(int z, int cur,int d){

long long sump1=data[cur].sump+(data[cur].batop+bato[cur])*d;
long long sumz1=data[z].sum-sump1;
long long sumz = sumz1+(batsum-bato[cur]-data[cur].batop)*d;

data[cur].sum=sumz+data[cur].sump;
vector<po>:: iterator it;
for(it=P[cur].begin(); it<P[cur].end(); it++)
if((*it).b!=z)
s(cur,(*it).b, (*it).d);




}



int main(){
srand ( time(NULL) );


cin>>n;
P.resize(n+1);
for(int i=1; i<=n; i++)
scanf("%d",&bato[i]);

for(int i=1; i<n; i++){
int a,b,d;
//cin>>a>>b>>d;
scanf("%d%d%d",&a,&b,&d);
po temp;
temp.b=b;
temp.d=d;
P[a].push_back(temp);
temp.b=a;
P[b].push_back(temp);
}

int zac=1;

for(int i=1; i<=n; i++)
batsum+=bato[i];





vector<po>:: iterator it;
for(it=P[zac].begin(); it<P[zac].end(); it++)
p((*it).b,zac);

long long sum=0;
for(it=P[zac].begin(); it<P[zac].end(); it++){
sum+=data[(*it).b].sump+(data[(*it).b].batop+bato[(*it).b])*(*it).d;
}
data[zac].sum=sum;
mini=sum;

for(it=P[zac].begin(); it<P[zac].end(); it++)
s(zac,(*it).b,(*it).d);


for(int i=1; i<=n; i++)
if(data[i].sum<mini) mini=data[i].sum;

cout<<mini<<endl;

}

