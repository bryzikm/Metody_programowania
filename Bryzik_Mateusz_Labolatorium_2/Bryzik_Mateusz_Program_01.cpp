#include<iostream>
#include <fstream>
#include<string>
using namespace std;

int main()
{
	char nazwa[80]; //zmienna przechowywujaca nazwe pliku wyjsciowego
	unsigned long int m, n, p = 0; // zmienne: m - ilosc liczb w I tablicy, n - w drugiej, p - ilosc liczb powtarzajacych sie
	int dl, i, j, k; //zmienne: dl - dlugosc zmiennej nazwa, i, j, k - zmienne inkrementowane

	ifstream plik_we("odczyt.txt"); //deklaracja pliku wejsciowego do odczytu danych
	if (!plik_we) //sprawdzenie czy plik istnieje
	{
		cout << "Plik nie zostal wykryty" << endl;
		cin.get();
	}
	//wczytanie liczby z pierwszego wiersza oznaczajacej ilosc liczb w drugim wierszu
	plik_we >> m;
		if(m>140000) //sprawdzenie poprawnosci
			return 0;

	
	unsigned long int *tab_m = new unsigned long int[m]; //deklaracja dynamicznej tablicy dla m elementow
	unsigned long int *tab_wynikow = new unsigned long int[m]; //dynamiczna tablica przechowywujaca wyniki ( liczby powtarzajace sie)

	for (i = 0; i<m; i++)
	{
		plik_we >> tab_m[i]; //zapis liczb z pliku do tablicy
		
		if(tab_m[i]>3000000000) //sprawdzenie czy liczba przekroczyla podany zakres
			return 0;
	}
	//wczytanie liczby elementow drugiej tablicy
	plik_we >> n;
		if(n>140000) //sprawdzenie poprawnosci
			return 0;

	unsigned long int *tab_n = new unsigned long int[n]; //dynamiczna tablica n elementowa

	for (j = 0; j<n; j++)
	{
		plik_we >> tab_n[j]; //zapis liczb z pliku do tablicy

			if(tab_n[j]>3000000000) //sprawdzenie poprawnosci
				return 0;
	}
		//p�tle sprawdzajace czy liczby powtarzaja sie
	for (i = 0; i<m; i++)
	{
		for (j = 0; j<n; j++)
		{
			if (tab_m[i] == tab_n[j]) //jesli liczba z tablicy m jest r�wna liczbie z tablicy n to:
			{
				bool istnieje = false; //ustawiamy zmienn�, kt�ra b�dzie nas informowa�a o istnieniu tej liczby w tablicy
				
				for (k = 0; k < m; k++)
				{
					if (tab_wynikow[k] == tab_n[j]) //sprawdzamy czy dany element jest ju� w tablicy wynik�w
					{
						istnieje = true; //jesli jest to zmieniamy na TRUE
					}
				}

				if (!istnieje) //je�eli elementu nie by�o w tablicy elementow ( istnieje == false )
				{
					tab_wynikow[p] = tab_m[i]; //jest to p-ty element w tablicy wynikow, podstawiamy pod niego wartosc liczby z tablicy m
					p++; //zwi�kszamy ilo�� powt�rze�, kt�re wyst�pi�y
				}		
			}
		}
	}

	delete[] tab_m; // zwalniamy dynamiczne tablice ktore nie sa nam potrzebne
	delete[] tab_n;
ofstream plik_wy;	//strumien odpowiedzialny za zapis do pliku
	
	cout << "Podaj nazwe pliku" << endl; //wprowadzanie nazwy pliku
	cin >> nazwa;
	dl = strlen(nazwa); //zmienna przyjmuje ilosc znakow wystepujacych w podanej nazwie
//sprawdzenie czy podana nazwa jest poprawna
	if ((dl <= 4) && (dl>0))//skoro ilosc znakow <=4 oznacza, ze brak rozszerzenia .txt
	{
		strcat(nazwa, ".txt"); //funkcja z��czaj�ca 2 ci�gi znakowe
	}
	else if (nazwa[i = dl - 4] != '.' && nazwa[i + 1] != 't' && nazwa[i + 2] != 'x' && nazwa[i + 3] != 't')//sprawdzenie czy nazwa konczy sie na .txt
	{
		strcat(nazwa, ".txt");
	}
	plik_wy.open(nazwa); //otwarcie pliku sluzacego za zapis
	plik_wy << p << endl; //zapis do pliku ilosci powtorzen liczb

	for (k = 0; k<p; k++) //w tablicy jest p element�w, kt�re si� powt�rzy�y 
	{
			plik_wy << tab_wynikow[k] << " "; //zapis do pliku liczb powtarzajacych sie oddzielonych spacja
	}
	plik_wy.close(); //zamkniecie strumienia pliku

	delete[] tab_wynikow; //zwolnienie tablicy przechowywujacej wyniki

	cin.get();
	cin.get();
	return 0;
}
/* Program maj�cy na celu po wczytaniu liczb z pliku odczyt.txt, w ktorym:
I wiersz oznacza ilosc liczb w II wierszu ( m )
II wiersz zawiera m liczb
III wiersz oznacza liczb w IV wierszu ( n )
IV wiersz zawiera n liczb,
wyszuka� kt�re liczby z II wiersza powtarzaj� si� w IV, obliczy� ich ilo��. 
Po wykonaniu tych czynnosci program ma zapisa� wyniki do pliku, kt�rego
nazwe ma poda� uzytkownik. Zapisy maj� by� wykonane w nast�puj�cy spos�b:
I wiersz - ilo�� liczb powtarzajacych si�
II wiersz - liczby kt�re sie powtarza�y w kolejnosci wejscia ( wyniki nie mog� sie powtarza� ).

Autor:
Mateusz Bryzik
WIEiK
gr. 11i
*/