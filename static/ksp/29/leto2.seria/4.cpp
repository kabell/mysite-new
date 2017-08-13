#include <iostream>
using namespace std;


int navstivene [1000009];
int susedia[1000009];

int pocet=0;




int rec(int cur){



if(navstivene[cur]==1){
pocet++;
navstivene[cur]=2;
rec(susedia[cur]);

}



else if(navstivene[cur]==0){


navstivene[cur]=1;
rec(susedia[cur]);


}


return 0;
}


int vymaz(int cur){

if(navstivene[cur]!=0 && navstivene[cur]!=10){
navstivene[cur]=10;
vymaz(susedia[cur]);
}


}

int main(){
int n;
cin>>n;

for(int i=1; i<=n; i++)
cin>>susedia[i];

for(int i=1; i<=n; i++)
navstivene[i]=0;


for(int i=1; i<=n; i++)
if(navstivene[i]==0){
rec(i);
vymaz(i);
}











cout<<pocet<<endl;





}
