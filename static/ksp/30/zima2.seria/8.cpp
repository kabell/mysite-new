#include<iostream>
#include<map>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

struct str{

int pre;
int p;
int next;

};

struct s{
int a;
int b;
int p;

};

struct last2{

int p1;
int p2;


};

s make_s(int a,int b,int p){
s t;
t.a=a;
t.b=b;
t.p=p;
return t;
}

struct s1{
int i;
int p;


};

s1 make_s1(int i,int p){
s1 t;
t.i=i;
t.p=p;
return t;
}

vector <s> Q;
vector <s1> V;

int pole[400047]={0};
map<int,int> p;
map<int,int> pr;
str last[400047];
int kon[400047]={0};

map<int,int> M;
map<int,last2> M1;



int n,pocet,all=0;

#define MAX_FIN 1000000

 

int fin[MAX_FIN];

 

void init(){

    for(int i = 0; i < MAX_FIN; i++)

         fin[i]=0;

}

 

int lastone(int a){

    return a&(a^(a-1));

}

 

void set(int pos, int c){

     for(int i = pos; i < MAX_FIN; i+=lastone(i))

          fin[i]+=c;

}

 

int get(int pos){

     int ret = 0;

     for(int i = pos; i > 0; i-=lastone(i))

          ret+=fin[i];

     return ret;

}

bool compare(s a,s b){
return a.b<b.b;

}

bool compare1(s1 a,s1 b){
return a.i<b.i;

}



int main(){

cin>>n>>pocet;
//n=400000;
//pocet=0;

for(int i=1; i<=n; i++){
//cin>>pole[i];

scanf("%d",&pole[i]);
}

for(int i=1; i<=n; i++){


last[i]={pr[pole[i]],pole[i],0};
last[pr[pole[i]]].next=i;
pr[pole[i]]=i;
}

for(int i=1; i<=n; i++){
//cout<<"i="<<i<<endl;
if(M.find(pole[i])==M.end()){
M[pole[i]]=1;
//cout<<"inicialiyujem "<<pole[i]<<endl;
}
else{
 M[pole[i]]++;
//cout<<"pripocitavam "<<pole[i]<<endl;
}
if(M[pole[i]]==1){
p[pole[i]]=i;
//cout<<"init "<<i<<endl;
}

if(M[pole[i]]>=pole[i]){
//cout<<"Nastavujem interval "<<i<<" - "<<p[pole[i]]<<endl;
kon[i]=p[pole[i]];
p[pole[i]]=last[p[pole[i]]].next;
}
//cout<<endl;


}







/*
for(int i=1; i<=n; i++){
if(pole[i]==1){
kon[i]=i;

}
else{
if(M.find(pole[i])==M.end())
M[pole[i]]=1;
else M[pole[i]]++;


last[i]={pr[pole[i]],pole[i],0};
last[pr[pole[i]]].next=i;
pr[pole[i]]=i;


if(M[pole[i]]==1)
p[pole[i]]=i;


if(M[pole[i]]>=pole[i]){
kon[i]=p[pole[i]];
p[pole[i]]=last[p[pole[i]]].next;

}

}
}
*/
//cout<<endl;
/*
for(int i=1; i<=n; i++)
cout<<last[i].pre<<" "<<last[i].p<<" "<<last[i].next<<endl; 
*/
/*
for(int i=1; i<=n; i++)
cout<<kon[i]<<endl;
*/


for(int i=1; i<=pocet; i++){
int a,b;
cin>>a>>b;
Q.push_back(make_s(a,b,i));
}



sort(Q.begin(),Q.end(),compare);

//cout<<"lllllllll"<<endl;
auto it=Q.begin();
for(int i=1; i<=n; i++){
if(kon[i]>0){
set(n-kon[i]+100,1);

if(M1.find(pole[i])==M1.end())
M1[pole[i]]={0,0};

if(M1[pole[i]].p2>0)
set(n-M1[pole[i]].p2+100,1);

M1[pole[i]].p2=M1[pole[i]].p1;

if(M1[pole[i]].p1>0)
set(n-M1[pole[i]].p1+100,-2);
M1[pole[i]].p1=kon[i];

//cout<<"pridavam"<<i<<endl;
}
//cout<<get(n-5+1)<<endl;;

while(it->b==i){
//cout<<it->a<<" to "<<it->b<<" = "<<get(n-it->a)<<endl;;
V.push_back(make_s1(it->p,get(n-it->a+100)));
it++;
if(it==Q.end())break;
}


}
//cout<<" llllllllllllllllll"<<endl;
sort(V.begin(),V.end(),compare1);
 

for(auto it1=V.begin(); it1!=V.end(); it1++)
printf("%d\n",it1->p);


/*
for(int i=1; i<=pocet; i++){
int a,b;
cin>>a>>b;

int g=0;
for(int j=b; j>=a; j--){
if(kon[j]>=a)
g++;


}

cout<<g<<endl;


}
*/
}
