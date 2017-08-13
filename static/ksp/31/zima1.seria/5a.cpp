#include<iostream>
#include<cstdlib>
using namespace std;

int main(){

string s;
while(cin>>s){
if(s=="v" || s=="SATISFABLE" || s=="s")continue;
int p=atoi(s.c_str());
if(p>0)cout<<"("<<p/100<<","<<(p-1)%100<<"), ";

}




}
