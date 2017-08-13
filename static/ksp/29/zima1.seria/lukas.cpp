#include <iostream>
#include <ctime>
#include <unistd.h>
#include <pthread.h>
using namespace std;
double pole[1000]={0};
double pole2[1000]={0};
int prvky;
int pomoc;
class katalog
{
      public:
             void zadavanie()
             {
                  prvky=0;
                  pomoc=-1;
                  int while1=1, while2=0, pouzi=1;
                  while (while1>while2)
                  {
                        cout<<"\n\nZadajte "<<pouzi<<". hodnotu(0 pre ukoncenie)";
                        cin>>pole[pouzi-1];
                        if(pole[pouzi-1]==0)
                        {
                                            while2++;
                        }
                        else
                        {
                            pomoc++;
                            pole2[pomoc]=pole[pouzi-1];
                            prvky++;
                        }
                        pouzi++;
                  }
             }
             void pis()
             {
                  cout<<"\n\n\n\n";
                  int pouzi=1;
                  int pouzi2=prvky;
                  while (pouzi2>0)
                  {
                        cout<<"Polozka "<<pouzi<<". = "<<pole2[pouzi-1]<<"\n\n";
                        pouzi2--;
                        pouzi++;
                  }
             }
             void zmena()
             {
                 int pouzi, pouzi2, while1=1, while2=0;
                 while (while1>while2)
                 {
                       cout<<"\n\n\nZadajte cislo polozky pre zmenu(alebo 0, ak nechcete zmenit nic): ";
                       cin>>pouzi;
                       if (pouzi==0)
                       {
                                    while2++;
                       }
                       else
                       {
                           cout<<"\n\nNa aku hodnotu chcete polozku c. "<<pouzi<<". zmenit: ";
                           cin>>pouzi2;
                           pole2[pouzi-1]=pouzi2;
                       }
                 }
             }
             void percenta(char a[10], int b)
             {
                  int pouzi, while1=0, while2=1;
                        cout<<"\n\n\nO kolko percent chcete vsetky hodnoty "<<a<<endl<<"(alebo 0, ak nechcete "<<a<<" nic): ";
                        cin>>pouzi;
                        int pouzi2=1000, pouzi3=0;
                        if (b==0)
                        {
                                 while(pouzi3<pouzi2)
                                 {
                                                     double c=(pole2[pouzi3]/100)*pouzi;
                                                     pole2[pouzi3]=pole2[pouzi3]+c;
                                                     pouzi3++;
                                 }
                        }
                        else
                        {
                            pouzi2=1000;
                            pouzi3=0;
                            double pouzi4[1000];
                            while(pouzi2>pouzi3)
                            {
                                                pouzi4[pouzi3]=(pole2[pouzi3]/100)*pouzi;
                                                pole2[pouzi3]=pole2[pouzi3]-pouzi4[pouzi3];
                                                pouzi3++;
                            }
                        }
             }
             void spolu()
             {
                  zadavanie();
                  pis();
                  zmena();
                  pis();
                  percenta("zvysit", 0);
                  pis();
                  percenta("znizit", 1);
                  pis();
                  cout<<"\n\nStlac enter\n";
                  cin.get();
                  cin.get();
                  cout<<"ukoncovanie";
sleep(5);
             }
};

sleep(unsigned int seconds);

int main()
{
   katalog nieco;
   nieco.spolu();
   return 0;
}
