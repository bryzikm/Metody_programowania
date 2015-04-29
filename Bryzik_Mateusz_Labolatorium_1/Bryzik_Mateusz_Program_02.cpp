#include <iostream>
#include <conio.h>
using namespace std;
/****************************/
int wprowadzenie (int x) //funkcja odpowiedzialna a wprowadzenie liczb bo tablicy
		{
				do
				{
				cin>>x;
				}
				while((x<1)||(x>1000000)); //sprawdzenie czy podana liczba spe³nia warunek
				
		return x; //przyjecie przez funkcje wartosci x
		}
/****************************/

int main()
{
int *tablica, i=0, N=0, M=0, FALSE = 0; //deklaracja zmiennych: wskaŸnik do tablicy, licznik pêtli, dzielna, ilosc dzielników

	//wprowadzenie zmiennych N (dzielna) i M (liczba dzielników)								
		do
		{
			cin>>N;
		}
		while((N<1)||(N>1000000)); //sprawdzenie warunku
		
		do
		{
			cin>>M;
		}
		while((M<1)||(M>1000000));
cout<<endl<<endl;
tablica = new int [M]; //utworzenie dynamicznej tablicy rezerwujacej w pamieci miejsce dla M zmiennych
				
				for(i=0; i<M; i++)
				{
					tablica[i] = wprowadzenie(tablica[i]); //wprowadzenie liczb do tablicy za pomoc¹ funkcji
				}
				for(i=0; i<M; i++)
				{
					//sprawdzenie czy N mo¿na podzieliæ przez tablica[i]
					if(N%tablica[i]==0)
					{
						cout<<"TAK"<<endl;
						break;
					}
					else
					{
						FALSE = 0;
					}
				}				
				if(FALSE==0)
				{
					cout<<"NIE"<<endl;
				}
			delete [] tablica; //zwolnienie dynamicznej tablicy
getch();
return 0;
}
