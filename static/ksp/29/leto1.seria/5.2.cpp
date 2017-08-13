#include <iostream>
#include <queue>
#include <vector>
#include <time.h>
#include <stdio.h>

using namespace std;
vector<priority_queue<vector<int>,vector<vector<int> >,less<vector<int> > > > F;
int pocet=20000;






int main(){
F.resize(32);
vector<int> h;
h.push_back(3);
h.push_back(1);
F[1].push(h);



int n;
cin>>n;
time_t rawtime;
  struct tm * timeinfo;

  time ( &rawtime );
  timeinfo = localtime ( &rawtime );
cout<<asctime (timeinfo)<<endl;

for(int i=1; i<=n; i++){





int j=0;
while(j<pocet && F[i].size()>0){
vector<int>::iterator it,suce,it1,pos,sumx,konx,kon,c,a1,a2,a3;
vector<int>::iterator u;
vector<int> x,y;
x=F[i].top();




y=x;


y.push_back(0);

sumx=x.begin();
konx=x.end()-1;
suce=y.begin();
kon=y.end()-1;

int zac=*(kon-1),koni=(*suce);



for(int k=zac+1; k<=koni+1; k++){
(*suce)=(*sumx);
(*kon)=k;

int ok=1;
do{
ok=0;
for(a1=y.begin()+1; a1<y.end(); a1++){
if((*a1)==(*suce)+1) {ok=1; (*suce)++;}

for(a2=y.begin()+1; a2<y.end(); a2++){
if((*a1+*a2)==(*suce)+1) {ok=1; (*suce)++;}

for(a3=y.begin()+1; a3<y.end(); a3++){
if((*a1+*a2+*a3)==(*suce)+1) {ok=1; (*suce)++;}
}
}
}


}while (ok==1);


F[i+1].push(y);
}
F[i].pop();
j++;
}
vector<int> sa;
sa=F[i+1].top();
vector<int>::iterator s;
for(s=sa.begin(); s<sa.end(); s++)
cout<<(*s)<<" ";
cout<<endl;
}
time_t rawtime1;
  struct tm * timeinfo1;
  time ( &rawtime1 );
  timeinfo1 = localtime ( &rawtime1 );
cout<<asctime (timeinfo1)<<endl;

}

