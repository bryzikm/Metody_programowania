#include<iostream>
using namespace std;

int w[4]={1,1,1,1}, skok[3], n = 5, k = 3, m; //deklaracja zmiennych
/********************************/
int index(int m) //deklaracja funkcji zwracaj�cej warto�� indeksu i
	{
		int i = 0;

		while(m % n==0)
			{
			i++;
			m = m / n;
			}

		return i;
	}
/**************************************/
int main()
{
int i, m; //deklaracja zmiennych

		for(i = 1; i<=k; i++) //wype�nienie tablicy skok[]
		{
			skok[i] = 1;
		}
			m = 0;
 //rozpocz�cie algorytmu s�u��cego do wyznaczenia wariacji zbioru
		do
		{		//wypisanie poszczeg�lnej wariacji
				for(i = 1; i<=k; i++)
				{
					cout<<w[i];
				}				
				cout<<endl;

				m++;
				i = index(m) + 1; //wywo�anie funkcji index, i przyjmuje waro�� kt�r� zwraca funkcja +1

						if(i<=k)//sprawdzenie poprawno�ci
						{
							w[i] = w[i] + skok[i]; //przepisanie warto�ci do elementu w[i]

								if(w[i]==1) //przypisanie warto�ci elementowi tablicy skok[i] zale�nie od warto�ci w[i]
								{
									skok[i] = 1;
								}
								else if(w[i]==n)
								{
									skok[i] = -1;
								}
						}
		}
		while(i<=k); //sprawdzenie warunku ko�cz�cego p�tl�
	

cin.get();
cin.get();
return 0;
}
/*Program ma na celu wypisa� 3-elementowe wariacje zbioru {1,2,3,4,5}.
Autor:
Bryzik Mateusz
WIEiK
gr. 11i
*/