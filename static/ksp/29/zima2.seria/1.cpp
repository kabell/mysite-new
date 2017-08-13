#include <iostream>
#include <string>
#include <stdlib.h>
#include <sstream>
#include <math.h>
#include <stdio.h>
#include <vector>
using namespace std;



int main(){
vector< vector<int> >V;
V.resize(6);
int n;
cin>>n;
int pocet=0;
for(int i=0; i<6; i++)
V[i].push_back (0);

for(int i=0; i<n; i++){
int a,b;


cin >>a>>b;
while(V[a-1].back()>b){
pocet++;
V[a-1].pop_back();
}

if(V[a-1].back()<b){
pocet++;
V[a-1].push_back(b);
}


}


cout<<pocet<<endl;
}
