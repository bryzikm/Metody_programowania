#include <iostream>
#include "conio.h"
using namespace std;
/*******************************/
int wprowadzenie(int x) //funkcja odpowiedzialna za wprowadzanie liczb do tablicy
		{
			do
			{
				cin>>x;
			}
			while((x<1)||(x>1000000));
return x;
		}
/******************************/
int liczba_M(int M) //funkcja odpowiedzialna za wprowadzanie ilosci liczb w ka¿dym zestawie
		{
			do
			{
				cin>>M;
			}
			while((M<1)||(M>1000));
return M;
		}
/******************************/
int main()
{
int *tablica, MIN[1000], MAX[1000], i=0, N=0, M=0, j=0; //deklaracja zmiennych
		do
		{
		cin>>N;
		}
		while((N<1)||(N>1000));
cout<<endl;
tablica = new int [N]; //utworzenie dynamicznej tablicy

					for(j=0; j<N; j++)
					{
					  M = liczba_M(M);
					  		//wprowadzanie liczb do tablicy
							for(i=0; i<M; i++)	
								tablica[i] = wprowadzenie(tablica[i]);
							//przyjecie za MIN i MAX pocz¹tkowych wartosci tablicy
							MAX[j] = tablica[0];
							MIN[j] = tablica[0];
								//sprawdzanie MIN i MAX								
								for (i = 0; i<M; i++)
								{
									if (tablica[i]>MAX[j])
										MAX[j] = tablica[i];

									if (tablica[i]<MIN[j])
										MIN[j] = tablica[i];
								}
								
					}		//wypisywanie MIN i MAX
							for(j=0; j<N; j++)
							{
								cout<<MIN[j]<<" "<<MAX[j]<<endl;
							}
					delete [] tablica; //zwolnienie dynamicznej tablicy
getch();
return 0;
}
