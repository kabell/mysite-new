#include<iostream>
#include<map>

using namespace std;


map<int,int> prvy;
map<int,int> druhy;


int main(){
int p,d;

cin>>p>>d;

for(int i=1; i<=p; i++)
{
int temp;
cin>>temp;
prvy[temp]=1;
}


for(int i=1; i<=d; i++)
{
int temp;
cin>>temp;
druhy[temp]=1;
}

int naj=0;

for(auto it=prvy.begin(); it!=prvy.end(); it++)
if(druhy[(*it).first]!=1){ cout<<(*it).first<<endl; break;}





}
