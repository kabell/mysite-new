#include<iostream>
#include<vector>
#include<queue>


using namespace std;

struct sur{
int x;
int y;
long long pos;
int typ;
};


sur ms(int x,int y,long long pos,int typ){
sur t;
t.x=x;
t.y=y;
t.pos=pos;
t.typ=typ;
return t;
}

vector<vector<int> > V;
vector<vector<int> > Tf[7];
vector<vector<int> > T[7];

int r,s;
int a,b,c;
int sx,sy;




void rataj1(int su,vector<vector<int> > &v)
{
v.resize(r+47,vector<int>(s+47,-2));

for(int i=1; i<=r; i++){

int sum=0;
for(int j=1; j<=su; j++)
sum+=V[i][j];

v[i][1]=sum;

for(int j=su+1; j<=s; j++){
sum-=V[i][j-su];
sum+=V[i][j];
v[i][j-su+1]=sum;
}

}
}

void rataj(int su,vector<vector<int> > &va,vector<vector<int> > &vt){

vt.resize(r+47,vector<int>(s+47,-2));

for(int i=1; i<=s; i++){

int sum=0;
for(int j=1; j<=su; j++)
sum+=va[j][i];

vt[1][i]=sum;

for(int j=su+1; j<=r; j++){
sum-=va[j-su][i];
sum+=va[j][i];
vt[j-su+1][i]=sum;
}

}




}



int main(){

cin>>r>>s;
cin>>a>>b>>c;



V.resize(r+47,vector<int>(s+47,-2));
for(int i=1; i<=r; i++)
for(int j=1; j<=s; j++){
char x;
cin>>x;
if(x=='#')
V[i][j]=1;
else V[i][j]=0;

if(x=='X'){sx=i;sy=j;}
}

if(a>s || b>r){
cout<<-1<<endl; return 0;


}


rataj1(a,T[0]);
rataj1(b,T[1]);
rataj1(c,T[2]);



rataj(a,T[1],Tf[0]);	//axb
rataj(a,T[2],Tf[1]);	//axc
rataj(b,T[0],Tf[2]);	//bxa
rataj(b,T[2],Tf[3]);	//bxc
rataj(c,T[0],Tf[4]);	//cxa
rataj(c,T[1],Tf[5]);	//cxb

for(int i=0; i<=r; i++){
for(int j=0; j<=s; j++)
cout<<Tf[4][i][j]<<" ";
cout<<endl;

}

int typy [][4]={{a,b,5,1},{a,c,3,0},{b,a,4,3},{b,c,1,2},{c,a,2,5},{c,b,0,4}};	//very super constants




queue<sur> Q;
Q.push(ms(1,1,0,0));

int poc=0;

while(Q.size()>0){
sur t=Q.front();
Q.pop();




//if(t.x==3 && t.y==5)
//cout<<t.typ<<" "<<(t.x+typy[t.typ][0]<=r)<<" "<<t.y<<" "<<typy[t.typ][1]<<" "<<(t.x>0)<<" "<<(t.y>0)<<" "<<(Tf[t.typ][t.x][t.y]==0)<<endl;


if(t.x+typy[t.typ][0]<=r+1 && t.y+typy[t.typ][1]<=s+1 && t.x>0 && t.y>0){
if(Tf[t.typ][t.x][t.y]!=0) continue;
Tf[t.typ][t.x][t.y]=-1;
//cout<<t.x<<" "<<t.y<<" "<<t.pos<<" "<<t.typ<<endl;

if(sx>=t.x && sx<t.x+typy[t.typ][0] && sy>=t.y && sy<t.y+typy[t.typ][1]){cout<<t.pos<<endl; return 0;}


Q.push(ms(t.x+typy[t.typ][0],t.y,t.pos+1,typy[t.typ][2]));
//cout<<"push "<<t.x+typy[t.typ][0]<<" "<<t.y<<" "<<typy[t.typ][2]<<endl;
Q.push(ms(t.x-typy[typy[t.typ][2]][0],t.y,t.pos+1,typy[t.typ][2]));
//cout<<"push "<<t.x-typy[typy[t.typ][2]][0]<<" "<<t.y<<" "<<typy[t.typ][2]<<endl;

Q.push(ms(t.x,t.y+typy[t.typ][1],t.pos+1,typy[t.typ][3]));
//cout<<"push "<<t.x<<" "<<t.y+typy[t.typ][1]<<" "<<typy[t.typ][3]<<endl;
Q.push(ms(t.x,t.y-typy[typy[t.typ][3]][1],t.pos+1,typy[t.typ][3]));
//cout<<"push "<<t.x<<" "<<t.y-typy[typy[t.typ][3]][1]<<" "<<typy[t.typ][3]<<endl;






}


}






cout<<"-1"<<endl;













}
