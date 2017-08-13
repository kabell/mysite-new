#include<iostream>
#include<algorithm>
#include<cstdio>
#include<queue>

using namespace std;





long long n,l,k;



void keep_low();
void keep_high();
void add(int);
void del(int);
void udrz();








priority_queue<long long , vector<long long>, less<long long> > high_top;
priority_queue<long long , vector<long long>, less<long long> > high_del;

priority_queue<long long , vector<long long>, greater<long long> > low_top;
priority_queue<long long , vector<long long>, greater<long long> > low_del;





long long high_top_size=0;


long long pole[100047];
long long sum_high=0;
long long sum_low=0;
long long naj=0;
long long max_minus=0;




void add(int p){
if(p<0){
//cout<<"pridavam "<<p<<" do high"<<endl;
high_top.push(p);
high_top_size++;
sum_high+=p;
udrz();
}
else{
//cout<<"pridavam "<<p<<" do low"<<endl;
low_top.push(p);
sum_low+=p;
}
}


void del(int p){
int del=0;
if(low_top.size()>0){
if(low_top.top()<=p){
//cout<<"odoberam "<< p<<" z low"<<endl;
low_del.push(p);
sum_low-=p;
del=1;
}
}
if(del==0) {
high_del.push(p);
sum_high-=p;
high_top_size--;
//cout<<"odoberam "<< p<<" z high"<<endl;
}

keep_low();
keep_high();
udrz();


}

void keep_low(){
if(low_top.size()>0 && low_del.size()>0)
while(low_top.top()==low_del.top()){
low_top.pop();
low_del.pop();
if(low_top.size()==0 || low_del.size()==0) break;
}

}


void keep_high(){
if(high_top.size()>0 && high_del.size()>0)
while(high_top.top()==high_del.top()){
high_top.pop();
high_del.pop();
if(high_top.size()==0 || high_del.size()==0) break;
}

}


void udrz(){

if(high_top_size<max_minus){
if(low_top.size()>0){
if(low_top.top()<0){
high_top.push(low_top.top());
high_top_size++;
sum_high+=low_top.top();
sum_low-=low_top.top();
low_top.pop();
keep_low();
}
}
}

else if(high_top_size>max_minus){
low_top.push(high_top.top());
sum_low+=high_top.top();
sum_high-=high_top.top();
high_top.pop();
high_top_size--;
keep_high();
}





}




int main(){



cin>>n>>l;
for(int i=1; i<=n; i++)
cin>>pole[i];

cin>>k;
max_minus=k;


for(int i=1; i<=n; i++){

add(pole[i]);
//cout<<i<<endl;
//cout<<sum_high<<" highsize"<<endl;;
//cout<<sum_low<<" lowsize"<<endl;;
//cout<<endl;
///cout<<i<<" "<<l<<endl;

if(high_top.size()>0)
//cout<<"hightop "<<high_top.top()<<endl;

if(low_top.size()>0)
//cout<<"lowtop "<<low_top.top()<<endl;

if(i==l)
if(sum_low-sum_high>naj)
naj=sum_low-sum_high;


if(i>l){
//cout<<"Mal by som odobrat "<<pole[i-l]<<endl;
del(pole[i-l]);
//cout<<sum_low-sum_high<<" koooooooooooooooooooooo "<<i<<endl;
if(sum_low-sum_high>naj)
naj=sum_low-sum_high;


}


}

while(high_top.size()>0)
high_top.pop();
while(low_top.size()>0)
low_top.pop();
while(high_del.size()>0)
high_del.pop();
while(low_del.size()>0)
low_del.pop();

high_top_size=0;



sum_high=0;
sum_low=0;

for(int i=1; i<=n; i++)
pole[i]*=-1;

for(int i=1; i<=n; i++){

add(pole[i]);
//cout<<i<<endl;
//cout<<sum_high<<" highsize"<<endl;;
//cout<<sum_low<<" lowsize"<<endl;;
//cout<<endl;
//cout<<i<<" "<<l<<endl;

if(high_top.size()>0)
//cout<<"hightop "<<high_top.top()<<endl;

if(low_top.size()>0)
//cout<<"lowtop "<<low_top.top()<<endl;

if(i==l)
if(sum_low-sum_high>naj)
naj=sum_low-sum_high;


if(i>l){
//cout<<"Mal by som odobrat "<<pole[i-l]<<endl;
del(pole[i-l]);
//cout<<sum_low-sum_high<<" koooooooooooooooooooooo "<<i<<endl;
if(sum_low-sum_high>naj)
naj=sum_low-sum_high;


}


}

cout<<naj<<endl;













}
