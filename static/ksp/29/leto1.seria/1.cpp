#include<iostream>
#include<vector>
#include <tr1/unordered_map>
using namespace std::tr1;



int main(){
int n, k,poc=0;

unordered_map<int, int>pole;


std::cin>>n>>k;
for (int i=0; i<k; i++){
int t;
std::cin>>t;
pole[t]=0;
}
int pocet=0;
for(int i=1; i<=n; i++){
if(pole.find(i)==pole.end()){ std::cout<<i<<" "; pocet++;}
if(pocet==10) break;
}

std::cout<<std::endl;



}
