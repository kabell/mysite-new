#include<iostream>

using namespace std;

int main(){

int n,h,f;
cin>>n>>h;
f=11;

//pre kazdy vrchol bude f farieb
//pre kazdz vrchol bude prave 1 farba aktivna
cout<<"p cnf "<<n*f<<" "<<n*(f+((f-2)*(f-1))/2)+h*f<<endl;


for(int i=0; i<n; i++){
//pre kazdy vrchol su to farby i*f+1 az i*f+f;
for (int j=i*f+1; j<=i*f+f; j++)
    cout<<j<<" ";
cout<<"0"<<endl;

for(int j=i*f+1; j<=i*f+f; j++){
//su ostatne prazdne
for(int k=j+1; k<=i*f+f; k++)
    cout<<-j<<" "<<-k<<" 0\n";
}

}


for(int i=1; i<=h; i++){
int a,b;
cin>>a>>b;
for(int j=1; j<=f; j++)
    cout<<-(f*a+j)<<" "<<-(f*b+j)<<" 0\n";
}
}
