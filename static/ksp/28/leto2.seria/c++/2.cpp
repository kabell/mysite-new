#include <iostream>
using namespace std;

int main(){
    long pole[100003]={0};
    long data[100003]={false};
    long n,i1;
    
    cin >> n;
    for(long i=1; i<=n; i++){
             cin >> pole[i];
             }
             
             pole[n+1]=2000000;
             
    for(long i=1; i<=n; i++){
             if (pole[i]>i)
                            data[pole[i]]=true;
             else if(pole[i]==i){
                                i1=0;
                                do {
                                    i1++;
                                    } while(pole[i1]<=pole[i] && i1<n);
                                    if(pole[i1]>pole[i]) data[pole[i]]=true;
                                    }
             else if(pole[i]<i){
                                i1=i;
                                do {
                                    i1++;
                                    } while(pole[i1]>=pole[i] && i1<n);
                                    if(pole[i1]<pole[i]) data[pole[i]]=true;
                                    };
                                    };
             for (long i=1; i<=n; i++){
                
                  if(data[i]==true){
                                   cout << i << "\n";
                                   };
                  };
             cin.get();
             cin.get();
                                    
                                    
    return 0;
    
    
    
    
    
    
    }
