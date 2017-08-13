#include<iostream>
#include <stdlib.h>
#include <time.h>
#include<vector>
#include<cstdio>
#include<string.h>

using namespace std;
int T[4000000][27]={0};


int nextp=2;
int ok;

char  S[300047];
int slength;
int convert(char c){
return (int)c-97;

}



void add(char * s){

int len=strlen(s);
int pos=1;
for(int j=len-1; j>=0; j--){
if(T[pos][convert(s[j])]>0)
{
pos=T[pos][convert(s[j])];
}
else{
 T[pos][convert(s[j])]=nextp;
pos=nextp;
nextp++;
}
}
T[pos][26]=1;

}




int control(int pos){

int pozicia=pos,tpos=1;
int naj=0;

while(true){

if(pos>slength) break;
if(T[tpos][26]==1) naj=pos-pozicia;
if(T[tpos][convert(S[pos])]>0){
tpos=T[tpos][convert(S[pos])];
pos--;

}
else break;

}

return naj;
}



/////////////////////////////////////////////////////////////////////////////
void add1(char * s){

int len=strlen(s);
int pos=1;
for(int j=0; j<len; j++){
if(T[pos][convert(s[j])]>0)
{
pos=T[pos][convert(s[j])];
}
else{
 T[pos][convert(s[j])]=nextp;
pos=nextp;
nextp++;
}
}
T[pos][26]=1;

}




int control1(int pos){

int pozicia=pos,tpos=1;
int naj=0;

while(true){
if(pos>slength) break;
if(T[tpos][26]==1) naj=pos-pozicia;
if(T[tpos][convert(S[pos])]>0){
tpos=T[tpos][convert(S[pos])];
pos++;
}
else break;

}

return naj;
}
//////////////////////////////////////////////////////////////////////////////



int main(){

int p;
scanf("%s",&S);
slength=strlen(S);
cin>>p;




int pocet=0;

  srand ( time(NULL) );

  /* generate secret number: */
  ok = rand() % 2;


if(ok==0){


for(int i=1; i<=p; i++){
char peciatka[5047];
scanf("%s",&peciatka);
add(peciatka);
}

int zac=0,kon=300047;
for(int i=slength-1; i>=0; i--){
int temp=control(i);

if(kon>i+temp)kon=i+temp+1;

if(kon>i) pocet++;
}


}

else{

for(int i=1; i<=p; i++){
char peciatka[5047];
scanf("%s",&peciatka);
add1(peciatka);
}

int zac=0,kon=-1;
for(int i=0; i<slength; i++){
int temp=control1(i);

if(kon<i+temp)kon=i+temp-1;

if(kon<i) pocet++;
}


}



cout<<pocet<<endl;




}
