#include<iostream>
#include<math.h>
#include<time.h>
#include<random.h>
using namespace std;
/******************/
//funkcja: sprawdza czy punkt lezy pod wykresem funkcji
bool Under(double x, double y, int *X, int n)
{
	double value = 0;
	for(int i = n; i>=0; i--)
	{
		value += X[i]*pow(x,i);
	}

	if(y <= value)
	{
		return true;
	}
	else
	{
		return false;
	}
	//value = 0;
}
/******************/
// funkcja: wprowadza dane do programu
void enter(int &n, int &a, int &b)
{
	do
	{
	cout<<"Podaj najwiekszy stopien wielomianu\n";
	cin>>n;
	}
	while((n<0)||(n>10));

	do
	{
	cout<<"Podaj poczatek przedzialu calkowania\n";
	cin>>a;
	}
	while((a<-1000)||(a>1000));

	do
	{
	cout<<"Podaj koniec przedzialu calkowania\n";
	cin>>b;
	}
	while((a>b)||(b>1000));
}
/******************/
void integral()
{
	int i, k, n, a, b, hit_points = 0;
	const int all_points = 10000;
	double steep = 0, value = 0, j, max_v = 0, min_v = 0, x, y; 
	long double integral, area;

	enter(n,a,b);

		int *X = new int [n+1];

	for(i = n; i>=0; i--)
	{
		cout<<"Podaj wspolczynnik przy x o potedze "<<i<<endl;
		cin>>X[i];
	}
			//obliczanie kroku - by wyliczyc wartosc max i min funkcji
			steep = ((double)b - (double)a) / 1000.0;

		//wyszukiwanie max i min (najwiekszej i najmniejszej wartosci ktora przyjmuje funkcja w przedziale <a;b> )
		for(j = (double)a; j <= (double)b; j += steep)
		{
			for(i = n; i >= 0; i--)
			{
				value += X[i]*pow(j,i);
			}
	
				if(  value > max_v)
				{
					max_v = value;
				}
					value = 0;
		}

					srand( time (NULL));

					for(k = 0; k < all_points; k++)
					{
						x = a + ((double)rand() / ((double)RAND_MAX+1)) * (b - a);
						y = min_v + ((double)rand() / ((double)RAND_MAX+1)) * (max_v - min_v);

							if(Under(x,y,X,n))
							{
							hit_points++; //punkty bedace pod wykresem funkcji
							}
					}

	//obliczanie pola calkowitego
	area = (double)max_v * ((double)b - (double)a);

	//obliczenie wartosci ca³ki
	integral = area * ((double)hit_points / (double)all_points);

	cout<<"\n\nWartosc calki: "<<integral<<endl;

delete [] X;
}
/******************/
int main()
{
	integral();

	cin.get();
	cin.get();
	return 0;
}
/*********************/
