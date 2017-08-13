#include<vector>
#include<iostream>
#include<set>

using namespace std;

vector<int>V;


int main(){

int n,c,A,B;
cin>>n>>c>>A;
cout<<"accept\n";
fflush(stdout);
while(true){
cin>>B;

if(B<A){cout<<"accept"<<endl; A=B;}
else {cout<<"decline"<<endl;}
if(A==0)break;
}
//cout<<"1 krok"<<endl;
while(true){
cin>>B;
if(B>A){cout<<"accept\n"; V.push_back(B-A);A=B;fflush(stdout);}
else {cout<<"decline\n";fflush(stdout);}
if(V.size()==n)break;
}
//cout<<"druhy krok"<<endl;



int moc=1<<n;
//cout<<"mocnina "<<moc<<endl;
int naj=0,najt=0;;


for(int i=0; i<moc; i++){
int suc=0;
int t=i;

for(int j=0; j<n; j++){
if(t%2==1)suc+=V[j];
t/=2;
}

if(suc<=c && suc>naj){naj=suc;najt=i;}
}
//cout<<"najsuc= "<<naj<<endl;
multiset<int>S;
for(int i=0; i<n; i++)
{
if(najt%2==1)S.insert(V[i]);
najt/=2;
}
/*
for(auto it=S.begin(); it!=S.end(); it++)
cout<<*it<<" ";
cout<<endl;
*/
while(true){
        cin>>B;
        if(S.size()==0 && B==0){cout<<"stop"<<endl; return 0;}
            if(B<A){cout<<"accept\n"; A=B;fflush(stdout);}
                else {cout<<"decline\n";fflush(stdout);}
                    if(A==0)break;
}





while(true){

cin>>B;
if(S.find(B-A)!=S.end()){S.erase(S.find(B-A)); if(S.size()>0){cout<<"accept\n";A=B;fflush(stdout);} else {cout<<"stop\n";fflush(stdout); return 0;}}
else {cout<<"decline\n"; fflush(stdout);}
}
}
