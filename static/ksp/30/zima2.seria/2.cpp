#include<iostream>
#include<map>
using namespace std;





int main()
{

int n,pred=0,za=0,pos=0;
cin>>n;

for(int i=1; i<=n; i++){

string s;

cin>>s;

if (s=="Luxusko") pos=i;

else if(s.compare("Luxusko")<0) pred++;
else za++;
}

if(pred<pos-1) cout<<"o "<<pos-pred-1<<" dopredu"<<endl;
else if(pred+1>pos) cout<<"o "<<pred-pos+1<<" dozadu"<<endl;
else cout<<"neposunie sa"<<endl;

//cout<<pred<<" "<<za<<" "<<pos<<endl;














}
