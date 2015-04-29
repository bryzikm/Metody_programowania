#include<iostream>
#include<fstream>
#include<string>
using namespace std;

/******************/
ifstream dane("dane.txt"), nazwa("nazwy.txt"); //zmienne plikowe globalne
/******************/
void pr_plecakowy(int **P, int **Q, int n, int m_max, int *m, int *c);
/******************/
void wypis(int **P, int **Q, int n, int m_max, int *m, int *c, string *N);
/******************/

int main()
{
	int i, n, m_max;

dane>>n>>m_max; //wczytanie wartoœci z pliku

	string *N = new string [n+1];

	for(i=1; i<=n; i++)
	{
		nazwa >> N[i];
	}
	//zarezerwowanie miejsca dla dynamicznej tablicy dwuwymiarowej
	int **P = new int *[n+1];
		for(i=0; i<=n; i++)
			P[i] = new int [m_max+1];

	int **Q = new int *[n+1];
		for(i=0; i<=n; i++)
			Q[i] = new int [m_max+1];
	//tablice jednowymiarowe dynamiczne
	int *m = new int [n+1];

	int *c = new int [n+1];

pr_plecakowy(P,Q,n,m_max,m,c);
wypis(P,Q,n,m_max,m,c,N);

	cin.get();
	cin.get();
	return 0;
}

/************************/
void pr_plecakowy(int **P, int **Q, int n, int m_max, int *m, int *c)
{
int i, j;

	for(j=1; j<=m_max; j++)
		{
			P[0][j] = 0;
			Q[0][j] = 0;
		}

		for(i=1; i<=n; i++)
		{
			P[i][0] = 0;
			Q[i][0] = 0;
		}

			for(i=1; i<=n; i++)
			{
				dane>>c[i]>>m[i];

					for(j=1; j<=m_max; j++)
					{
						if((j>=m[i])&&(P[i-1][j]<(P[i][j-m[i]]+c[i])))
						{
							P[i][j] = P[i][j-m[i]] + c[i];
							Q[i][j] = i;
						}
						else
						{
							P[i][j] = P[i-1][j];
							Q[i][j] = Q[i-1][j];
						}
					}
			}
}
/************************/
void wypis(int **P, int **Q, int n, int m_max, int *m, int *c, string *N)
{
	int i, j;
	
			cout<<"Tablica wartosci: "<<endl;
			for(i=1; i<=n; i++)
			{
				for(j=1; j<=m_max; j++)
				{
					cout<<P[i][j]<<" ";
				}
				cout<<endl;
			}
			cout<<endl;

			cout<<"Tablica Q: "<<endl;
			for(i=1; i<=n; i++)
			{
				for(j=1; j<=m_max; j++)
				{
					cout<<Q[i][j]<<" ";
				}
				cout<<endl;
			}
cout<<endl;
    //wypisanie co jest spakowane
    
    while(m_max > 0)
    {
        cout << N[ Q[n][m_max]] <<": "<< c[Q[n][m_max]] << endl;
        m_max -= m[ Q[n][m_max]];
    };

		//zwolnienie dynamicznej tablicy wskaŸników
		for(i=0; i<=n; i++)
			delete [] P[i];
		delete [] P;

		for(j=0; i<=n; i++)
			delete [] Q[i];
		delete [] Q;

		delete [] m;

		delete [] c;
}
/************************/
