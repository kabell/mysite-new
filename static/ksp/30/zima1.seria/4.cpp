#include<iostream>
#include<cstdio>

using namespace std;


struct str{

int nad;
int pod;
int seen;
};


str kor[300000];

str plan[300000];

 
int main(){
int k,t,p,prev;


cin>>k>>p>>t;

for(int i=1; i<=p; i++)
{
plan[i].nad=0;
plan[i].pod=0;
}

for (int i=1; i<=k; i++){
int l;
scanf("%d",&l);
if(i==1){
kor[l].pod=0;
plan[1].pod=l;
}
else
kor[l].pod=prev;

if(i>1)
kor[prev].nad=l;

if(i==k)
{
kor[l].nad=0;
plan[1].nad=l;

}
prev=l;
}

/////nacitanie;


for(int i=1; i<=t; i++){
int tur,policko,tah,nad,pod;




//cin>>tur>>policko>>tah;
scanf("%d",&tur);
scanf("%d",&policko);
scanf("%d",&tah);





nad=kor[tur].nad;
pod=kor[tur].pod;
int plan_nad=plan[policko].nad;

//odpojime korytnacku
if(kor[tur].pod>0){
kor[kor[tur].pod].nad=0;
kor[tur].pod=0;
}
if(tur==plan[policko].pod)
{
plan[policko].pod=0;
plan[policko].nad=0;
}
else{

plan[policko].nad=pod;

}


/*
for(int j=1; j<=p; j++)
cout<<plan[j].pod<<" "<<plan[j].nad<<endl;
cout<<endl;
for(int j=1; j<=k; j++)
cout<<kor[j].pod<<" "<<kor[j].nad<<endl;
cout<<endl;
*/


//pripojime korytnacku 
if(plan[policko+tah].nad==0){		//ak je policko prazdne
plan[policko+tah].pod=tur;		//na spodok dame aktualnu
plan[policko+tah].nad=plan_nad;		//na vrch dame vrchnu zobratu
kor[tur].pod=0;				//pod prvou nic nieje
}
else
{
kor[plan[policko+tah].nad].nad=tur;		//nad poslednu na novom mieste ju dame 
kor[tur].pod=plan[policko+tah].nad;		//pod aktualnu dame poslednu

plan[policko+tah].nad=plan_nad;		// na vrch dame vrchnu
}	

/*
for(int j=1; j<=p; j++)
cout<<plan[j].pod<<" "<<plan[j].nad<<endl;
cout<<endl;
for(int j=1; j<=k; j++)
cout<<kor[j].pod<<" "<<kor[j].nad<<endl;
cout<<endl;
*/
}




for(int i=1; i<=p; i++)
{
int pocet=0;
int next=plan[i].pod;
while(next!=0){



pocet++;


next=kor[next].nad;




}

cout<<pocet;
/////////////////////////////////////////////////////////


next=plan[i].pod;
while(next!=0){



cout<<" "<<next;


next=kor[next].nad;




}
cout<<"\n";


}

















}
