#include <iostream>   
using namespace std;   
int main()   
{
    int n;
    int x;
    int d=0,naj=0;
cin >> n;
for (int i=1; i<=n; i++){
    cin >> x;
    if(x>0) d++;
    else d--;
    if (d>naj) naj=d;
}
cout << naj;
cin.get();
cin.get();
}
            
