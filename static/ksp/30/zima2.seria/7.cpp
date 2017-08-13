#include<iostream>

using namespace std;

struct str{
int pocet;
char pismeno;
};

int main(){
int cislo,tahy,naj=1000047,sp=0,is0=0;
str najs[47];
cin>>tahy>>cislo;
int pocet=0;


for(int i=0; i<47; i++)
najs[i]={0,'X'};

if(cislo==1 && tahy==1)
{
najs[1]={1,'H'};
sp=2;
}
for(int i=1; i<cislo; i++){
//cout<<"_________________________"<<endl;
//cout<<"i="<<i<<endl;
int h=cislo;
int d=i;
int najv=0;
int len=0;
int p=1;
int is0t=0;
str s[47];

while(h!=d && h>0 && d>0){
//cout<<"p"<<endl;

if(h>d){
//if(p+(int)(h/d)>tahy) break;
//s.append((int)(h/d),'D');
s[p++]={(int)(h/d),'D'}	;
len+=(int)(h/d);
najv+=(int)(h/d)-1;
//p+=(int)(h/d);
h=h%d;
}
else {
//if(p+(int)(d/h)>tahy) break;
len+=(int)(d/h);
najv+=(int)(d/h)-1;
//s.append((int)(d/h),'H');
s[p++]={(int)(d/h),'H'};
//p+=(int)(d/h);	
d=d%h;
}

//cout<<naj<<endl;
//cout<<h<<" "<<d<<" "<<najv<<endl;
//cout<<"s="<<s<<endl;
//p++;
}

//if(p>pocet) pocet=p;
if(len==tahy && (d==1^h==1)){
//cout<<"pred"<<s<<endl;

if(s[p-1].pismeno=='D'){
s[p]={1,'H'};

s[p-1].pocet--;

if(s[p-1].pocet>0)
najv--;
p++;
}

/*
if(s[s.length()-1]=='D'){
s[s.length()-1]='H';
if(s[s.length()-2]=='D')
najv--;



//else najv++;

}
*/
/*
else if(s[s.length()-1]=='H' && s[s.length()-2]=='H')
{
for(int l=0; l<s.length()-1; l++)
if(s[l]=='D')
s[l]='H';
else s[l]='D';
najv--;
}
*/

else if(s[p-1].pismeno=='H' && s[p-1].pocet>1)
{
s[p]={1,'H'};
p++;
s[p-1].pocet--;
for(int l=1; l<p-1; l++)
if(s[l].pismeno=='H')
s[l].pismeno='D';
else s[l].pismeno='H';


}
//cout<<"po"<<s<<endl;
/*
if(s[0]==s[1]){
if(s[0]=='D')
s[0]='H';
else s[0]='D';
}
*/
if(s[1].pocet>1)
{
if(s[1].pismeno=='D')
s[0].pismeno='H';

else s[0].pismeno='D';
is0t=1;
s[1].pocet--;
}


if(najv<naj){
//najs=s;
sp=p;
for(int j=0; j<45; j++)
najs[j]=s[j];
is0=is0t;
naj=najv;
//cout<<"Toto slovo ma mensiu dlzku!!!"<<endl;
}

}
//cout<<"_________________________"<<endl;
}

if(sp>0){

for(int i=1; i<sp; i++)
for(int j=1; j<=najs[sp-i].pocet; j++)
cout<<najs[sp-i].pismeno;
if(is0==1)
cout<<najs[0].pismeno;
cout<<endl;

}
else cout<<"Neexistuje"<<endl;


//cout<<pocet<<endl;
}
