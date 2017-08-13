#include<iostream>

using namespace std;




int main(){
int n;
cin>>n;

for(int i=0; i<n; i++){
string s;
cin>>s;

if((s[s.length()-1]=='a' && s!="Gejza") || s=="Dagmar") cout<<"femmina"<<endl;
else cout<<"maschio"<<endl;
}














}
