/*
meno: Michal Korbela
úloha č.3 - program
program má pamäťovú zložitosť O(n^2), kde n je strana štvorca
časová zložitosť O(n^2) - každé políčko prezrieme konštantný počet krát
originál popisu
http://kabell.6f.sk/3.html

*/
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <queue>
using namespace std;

int pole[10000][10000];
int poc=0;


int s(int f,int x,int y){		//rekurzívne prehľadávame
poc++;
pole[x][y]=0;
if(pole[x][y+1]==f){ s(f,x,y+1);}
if(pole[x+1][y]==f){ s(f,x+1,y);}


}




int main(){
srand ( time(NULL) );

int n,f;
cin>>n>>f;

vector<h> P;
int naj=0;



for(int a1=0; a1<=n+10; a1++)		//vynulujeme pole
for(int a2=0; a2<=n+10; a2++)
pole[a1][a2]=0;

for(int a1=1; a1<=n; a1++)		//zapíšeme náhodné čísla
for(int a2=1; a2<=n; a2++){
pole[a1][a2]=rand() % f + 1;


}

for(int a1=1; a1<=n; a1++){		//vypíšeme pole
for(int a2=1; a2<=n; a2++)
cout<<pole[a1][a2]<<" ";
cout<<endl;
}
int anjo=0;
for(int a1=1; a1<=n; a1++)		//vypočítame max
for(int a2=1; a2<=n; a2++)
if(pole[a1][a2]!=0){
poc=0;
s(pole[a1][a2],a1,a2);
if(anjo<poc) anjo=poc;
}


cout<<anjo<<endl;			//vypíšeme max



}





