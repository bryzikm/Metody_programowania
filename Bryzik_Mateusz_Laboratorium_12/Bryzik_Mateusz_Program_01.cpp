#include<iostream>
#include<time.h>
using namespace std;
/******************/
bool In(long double x, long double y, long double r) //funkcja: sprawdza czy punkt le¿y w œrodku ko³a
{
	if(x*x + y*y <= r*r)
	{
		return true;
	}
	else
	{
		return false;
	}
}
/******************/
void PI_value() //funkcja: oblicza i wypisuje liczbe PI, wprowadza sie równie¿ dane: ilosc punktow losowych, promien kola
{
	long double pi = 0, x, y, r;
	int freq = 0, a = 0, b, n; 

	cout<<"Podaj ilosc punktow:\n";
	cin>>n;
	cout<<"Podaj promien:\n";
	cin>>r;

	b =r;

	srand( time (NULL));

	for(int i = 0; i < n; i++)
	{	//przyjecie wartosci losowych przez wspolrzedne punktu
		x = a + ((double)rand()/(double)(RAND_MAX))*(b-a);
		y = a + ((double)rand()/(double)(RAND_MAX))*(b-a);

		if(In(x,y,r))
		{
			freq++;
		}
	}
	//obliczenie PI
	pi = 4*((double)freq/(double)n);
	cout<<pi;
}
/******************/
int main()
{
	//wywolanie funkcji
	PI_value();

	cin.get();
	cin.get();
	return 0;
}