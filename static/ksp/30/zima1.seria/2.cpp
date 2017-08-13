#include<iostream>


using namespace std;


int main(){
 long long n,k,l,sum=0,ruka=1;

cin>>n>>k>>l;

for(int i=1; i<=n; i++){
long long nota;
cin>>nota;
if(nota<ruka){sum+=ruka-nota; ruka-=ruka-nota;}
else if(nota>ruka+l-1){ sum+=nota-ruka-l+1; ruka+=nota-ruka-l+1;}
//cout<<ruka<<" "<<ruka+l-1<<endl;
}



cout<<sum<<endl;

}
