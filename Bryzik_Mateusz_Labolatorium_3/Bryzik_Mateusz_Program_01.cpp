#include<iostream>
#include<time.h>
#include<fstream>
using namespace std;

int p[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9}; //tablica 9 kolejnych liczb 1-9

int main()
{
int n = 9, k = 0, i = 0; //zmienne: n - liczba elementow tablicy, k - zmienne przyjmujaca losowa wartosc, i - zmienna dekrementowana

srand( time (NULL));

		for(n = 8, i = 9; n>1; n--, i--) //za ostatnia liczbe tablicy (n), program podstawia liczbe z tablicy o k losowanym z coraz mniejszego
		{								 // przedzialu (i jest dekrementowane)
			k = rand()%i; //podstawienie za k liczby z przedzialu i (i siê zmniejsza)

			swap(p[k],p[n]); //funkcja zamieniajaca ostatni niezamieniony element tablicy z elementem o indeksie losowym k
		}
n = 9;

ofstream plik_wy("dane.txt"); //deklaracja strumienia pliku s³u¿¹cego do zapisu danych
		for(i=0; i<n; i++)
			plik_wy<<p[i]<<", "; //zapis do pliku k losowych permutacji zbioru
cin.get();
cin.get();
	return 0;
}
/*Program generuj¹cy plik tekstowy zawieraj¹cy k losowych permutacji zbioru {1,2,3,4,5,6,7,8,9}.
Autor:
Bryzik Mateusz
WIEiK
gr. 11i
*/