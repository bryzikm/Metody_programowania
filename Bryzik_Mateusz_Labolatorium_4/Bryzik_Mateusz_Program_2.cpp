#include<iostream>
#include<fstream>
#include<time.h>
using namespace std;
/***************************/
int partition(long int T[], int p, int r) //funkcja dziel¹ca tablice na 2 podtablice oraz sortujaca elementy
		{
			int x, i;
			x = T[r];
			i = p-1;

				for(int a=p; a<=r-1; a++)
				{
					if(T[a]<=x)
					{
						i++;
						swap(T[i],T[a]);
					}
				}
					swap(T[i+1],T[r]);
				
		return i+1; //zwracanie wartosci indeksu przez funkcje
		}
/**************************/
void quicksort(long int T[], int p, int r) //f. odpowiedzialna za sortowanie elementow tablicy
		{						//dzia³a na podstawie rekursji oraz zasady dziel i zwyciê¿aj
			int q;

				if(p<r) //sprawdzenie warunku
				{
					q=partition(T,p,r); //funkcja zwracajaca wartoœæ indeksu na podstawie ktorego tablica bedzie podzielona na 2 elementy
					quicksort(T,p,q-1); //rekursja - wywo³anie funkcji w funkcji
					quicksort(T,q+1,r);
				}
		}
/*************************/
int main()
{
int p = 0, r; //indeks tablicy i iloœæ elementow w tablicy
long int z; //zmienna przechowywujaca liczbe zestawow
ifstream plik_we("dane.txt"); //strumien plikowy wejsciowy
ofstream plik_wy("wynik.txt"); //plik wyjciowy
time_t start, end; //zmienne czasowe

		plik_we>>z; //wczytanie z plikow liczby zestawow do posortowania

		while(z!=0) //sprawdzenie warunku koñcz¹cego dzia³anie wczytywania z pliku
		{	
			plik_we>>r; //wczytanie liczby elementow w tablicy

long int *T = new long int [r]; //deklaracja dynamicznej tablicy r elementowej

				for(p=0; p<r; p++)
				{
					plik_we>>T[p]; //wczytanie z pliku r elementow tablicy
				}

				p=0; //przyjecie 0 za p, aby móc wywo³aæ funkcje quicksort (tylko dla p = 0)

			start=clock(); //zmienna start przyjmuje wartoœæ czasow¹ przed sortowaniem
			
			quicksort(T,p,r); //wywo³anie f. quicksort
		
			end=clock(); //end przyjmuje wartosc czasowa po sortowaniu

			// plik_wy<<(double)difftime(end,start)/1000<<endl; //funkcja obliczajaca czas sortowania tablicy w milisekundach
													// difftime - f. odpowiedzialna za obliczenie róznicy end - start
			for(p=1; p<=r; p++)
			{
				plik_wy<<T[p]<<" "; //zapis posortowanego elementu do pliku
			}
			plik_wy<<endl;

z--;//dekrementacja liczby z, zmniejszenie ilosci tablic do wczytania
delete [] T; //zwolnienie elementow tablicy aktualnie operujacej
		}

	cin.get();
	cin.get();
	return 0;
}
/*
Program wykonuj¹cy operacjê sortowania Quicksort.
Mateusz Bryzik
WIEiK
gr. 11i

Czas dzia³ania programu dla tablicy 1000-elementowych:
a) losowej: 0.001 s
b) posortowanej rosnaco: 0.003 s
c) posortowanej malej¹co: 0.026 s
d) czêœciowo posortowanej (10% elementów jest na zlym miejscu): 0.002 s

Wnioski:
Tablice, które by³y posortowane program sortuje najd³uzej. Wynika z tego, ze dla tablic nieposortowanych
(lub czêœciowo posortowanych) czas dzia³ania programu jest najkrótszy i program jest najbardziej efektywny.
*/