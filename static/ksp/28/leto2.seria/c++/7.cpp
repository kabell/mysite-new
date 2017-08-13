#include <iostream>   
using namespace std;   
int main()   
{
    long zoznam[100001][2];
    long cesta[100001];
    long fronta[100001];
    bool obsadene[100001];
    long n,a,b;
    cin >> n;
    for (long i = 1; i <= n-1; i++){
        cin >> a >> b;
        zoznam[i][1]=a;
        zoznam[i][2]=b;
        }
    
        int x=1;
        a=0;
        b=0;
        do{
            for(long i = 1; i <= n; i++){
                     if (zoznam[i][1]==x || zoznam[i][2]==x){
                                       if (zoznam[i][1]==x){
                                                          cesta[zoznam[i][2]]=x;
                                                          a++;
                                                          fronta[a]=zoznam[i][2];
                                                          }
                                       else {
                                            cesta[zoznam[i][1]]=x;
                                            a++;
                                            fronta[a]=zoznam[i][1];
                                            }
                                       zoznam[i][1]=0;
                                       zoznam[i][2]=0;
                                       }
                                       }
            b++;
            
            x=fronta[b];
            }
            while (x!=0);
            
            
          
            
        for (long i=1; i<=n; i++){
            cin >> a;
            x=0;
            if (a==1){
                      cout << "0\n";
                      obsadene[1]=true;
                      }
            else {obsadene[a]=true;
            
            do {
                a=cesta[a];
                if (obsadene[a]==true) x++;
                }
                while (a!=1);
                cout << x;
                cout << "\n";
                }
                }
                cin.get();
                cin.get();
                return 0;
                }
                 
                 
            
        
        
