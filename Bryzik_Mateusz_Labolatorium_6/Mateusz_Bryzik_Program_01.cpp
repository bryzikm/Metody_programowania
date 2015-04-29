#include<iostream>
#include<fstream>
using namespace std;

int fmax(fstream &plik_we); //funkcja zwracajaca max czyli ilosc wierzcholkow grafu
void wypis(int **T,int max); //funkcja wypisujaca na ekran wyniki dzialania programu dzialajaca z argumentami: tablica 2D i zmienna max
void przypisz(fstream &plik_we, int **T); //przypisanie warto�ci 1 do tablicy dla wierzcho�k�w s�siednich
/*************************/
struct vertex //struktura vertex
{
	int value; //warto�� danego wierzcho�ka (numer)
	vertex *next; //wska�nik do nast�pnego elementu listy
	vertex(); //konstruktor
};
/************************/
vertex::vertex() //konstruktor
{
	next = NULL; //wpisanie do warto�ci nast�pnego elementu NULL
}
/*************************/
int main()
{
	int n, i, j, max=0, x, y;	//deklaracja zmiennych n - l. krawedzi, i, j - zmienne indeksowe, max - zmienna przechowywujaca max wierzcho�ek
	fstream plik_we("dane.txt"); //strumie� plikowy

	//wywo�anie funkcji obliczajacej maxymalny wierzcho�ek (liczbe wierzcho�k�w)
	max = fmax(plik_we);
	plik_we.close();//zamkniecie strumienia pliku

	//deklaracja i utworzenie dynamicznej tablicy dwuwymiarowej (dwuwymiarowej tablicy wska�nik�w) o wymiarach max x max
		int **T = new int *[max];
		for(i = 0; i<max; i++)
		{
			T[i] = new int [max];
		}
				//otwarcie strumienia pliku
				plik_we.open("dane.txt");

				przypisz(plik_we,T);

				//zamkniecie strumienia pliku
				plik_we.close();
				
				//wywolanie funkcji wypisujacej na ekranie wyniki dzialania programu
				cout<<"Macierz sasiedztwa:"<<endl;
				wypis(T,max);
				plik_we.close();
				//zwolnienie dynamicznej tablicy wskaznikow
				 for(int i = 0; i < max; i++)
						 delete[] T[i];
					delete[] T;

				plik_we.open("dane.txt");
					
				vertex *V = new vertex [max]; //dynamiczne tablice oparte na strukturze vertex
				vertex *nowy;

	for(i=0; i<max; i++); 
		{
			V[i].value = 0; //wyzerowanie warto�ci pocz�tkowej w ka�dej li�cie
		}

	plik_we>>n; //wczytanie liczby zestaw�w kraw�dzi

	for(i = 0; i < n; i++)
  {
    plik_we >> x >> y; // odczytujemy kraw�d�

	//pierwszy element
    nowy = new vertex; //nowy element listy
    nowy->next = V[x-1].next; //wska�nik przypisujemy do T[x-1]
	nowy->value = y; //przypisujemy nowej zmiennej warto�� pobranej zmiennej
	V[x-1].next = nowy; //koniec przesuwamy na nowy

	//drugi element
    nowy = new vertex; //nowy element listy
    nowy->next = V[y-1].next;  //ustawienie wska�nika dla T[x-1]
	nowy->value = x; //zmienna value przyjmuje now� warto�� od zmiennej x przes�anej z pliku
	V[y-1].next = nowy; // koniec przesuwamy na nowy
  }
			  //wypisanie listy s�siedztwa
  cout<<"Lista sasiedztwa:"<<endl;
  for(int i = 0; i < max; i++)
  {
    cout << i + 1 << ": ";
    nowy = V[i].next; //ustawienie wska�nika na pocz�tek listy

    while(nowy) //dop�ki !=NULL
    {
      cout << nowy->value << " "; //wy�uskanie value
      nowy = nowy->next; //przesuniecie wska�nika na next (na ko�cu nowy przyjmie warto�� NULL)
    }
    cout << endl;
  }

	cin.get();
	cin.get();
	return 0;
}
/***********************************************************/
int fmax(fstream &plik_we)
	{
		int i, j, n, max = 0; //zmienne: n - l. zestawow krawedzi, i, j - indeksy, max - maxymalny wierzcholek

				plik_we>>n;
		
		for(int k=0; k<n; k++) //p�tla ktora obraca si� n razy (liczba krawedzi)
		{
			plik_we>>i>>j; //wczytanie pary liczb polaczonych krawedzia z pliku

			max = (i>max) ? i : max; //sprawdzenie warunku

			max = (j>max) ? j : max;
		}
		 //zwrocenie wartosci maxymalnego wierzcholka przez funkcje
	return max;
	}
/**********************************/
void wypis(int **T,int max)
	{
		for(int i=0; i<max; i++) //p�tla odpowiedzialna za przeskok do kolejnego wiersza
		{
			for(int j=0; j<max; j++) //przeskok indeksow w kolumnach
			{
				if(T[i][j] == 1) //sprawdzenie czy krawedz miedzy indeksami (wierzcholkami) istnieje
					cout<<T[i][j]<<" "; //wypis
				else
					cout<<"0 ";
			}
			cout<<endl;
		}
	}
void przypisz(fstream &plik_we, int **T)
	{
		int n, i, j;		
		plik_we>>n;//wczytanie liczby zestawow krawedzi grafu

				while(n!=0) //sprawdzenie warunku
				{
					plik_we>>i>>j; //wczytanie 2 wierzcholkow z pliku

					T[i-1][j-1] = T[j-1][i-1] = 1; //przypisanie w macierzy wartosci 1 dla wartosci indeksow polaczonych krawedziami

					n--; //postdekrementacja zmiennej n
				}
	}
/***************************************************************/