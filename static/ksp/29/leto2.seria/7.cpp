#include <iostream>
#include <queue>

using namespace std;


int pole[1000047];
int length[1000047][2];
int sum[1000047];
long long suc=0;



priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> F;
int main(){


int n;
cin>>n;

for(int i=0; i<n; i++)
cin>>pole[i];


for(int i=0; i<n; i++){

while(F.top()<pole[i]){
auto temp=F.top();
length[temp.second][1]=i-temp.first;
F.pop();
}

}








for(int i=0; i<n; i++){
int min=pole[i];
int max=pole[i];
for(int j=i; j<n; j++){
if(pole[j]>max) max=pole[j];
if(pole[j]<min) min=pole[j];

suc+=max-min;
}



}

cout<<suc<<endl;
}
