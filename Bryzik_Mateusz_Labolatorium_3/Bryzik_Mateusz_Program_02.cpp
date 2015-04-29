#include<iostream>
#include<fstream>
using namespace std;

int p[6]; //zmienna globalna, deklaracja zbioru liczb przeznaczonych do permutacji
int licznik = 1; //zlicza liczbe permutacji zbioru
ofstream plik_wy("dane.txt"); //strumien pliku wyjsciowego
/***************************************/
void odwroc(int m) //funkcja odpowiedzialna za odwracanie kolejno�ci liczb w tablicy
	{
		int i = 1, j = m; //przyjecie wartosci przez zmienne

			while(i<j) //sprawdzenie warunku czy i jest mniejsza od j
			{
				swap(p[i],p[j]); //funkcja zamienia wartosci dw�ch elementow tablicy
				i++;
				j--;					
			}
	}
/***************************************/
void antylex(int m) //funkcja ustawiajaca liczby w porz�dku antyleksykograficznym 
	{
		int i = 1;

		if(m==1) //sprawdzenie warunku
		{
			for(i=1; i<=5; i++)
			{
				plik_wy<<p[i]<<", "; //zapis do pliku danej permutacji zbioru
			}	
			plik_wy<<endl;
		}
		else
		{
			for(i=1; i<=m; i++)
			{
				antylex(m-1); //wywo�anie funkcji dla m-1
				if(i<m)
				{
					swap(p[i],p[m]); //wywo�anie funkcji swap oraz odwroc jesli spelniony zosta� warunek
					licznik++; //zmienna zliczajaca ilosc permutacji zbioru
					odwroc(m-1);
				}
			}
		}
	}
/*************************************/
int main()
{
	int m = 5; //za m przyjmij 5
	for(int i=1; i<=m; i++) //p�tla zapisujaca do tablicy elementy (zaczyna indeksowanie od 1)
	{
		p[i] = i; // za p[i] przyjmij i
	}
			antylex(m); //wywolanie funkcji w bloku g�ownym programu
			plik_wy<<"Liczba permutacji: "<<licznik<<endl;	//zapis do pliku liczby permutacji
	cin.get();
	cin.get();
	return 0;
}
/*Program generuje plik tekstowy zawieraj�cy wszystkie permutacje zbioru {1,2,3,4,5} oraz ich liczbe.
Autor:
Bryzik Mateusz
WIEiK
gr. 11i
*/