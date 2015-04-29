#include<iostream>
#include<fstream>
#include<math.h>
#include<time.h>
#define MAX_V 100
using namespace std;
/***********************/
int NWD(int c, int m) //funkcja: wyznaczenie NWD
{
	int help;

	while(c)
	{
	help = m % c;
	m = c;
	c = help;
	}

	return m;
}
/***********************/
void first_factor(int T[], int m) //funkcja: rozk³ad na czynniki pierwsze
{
	int i, j = 0, value;

	value = (int)pow(m, 1/2.0);

	for(i = 2, j = 0 ; i <= value; i++, j++)
	{
		while (!(m % i))
       {
       m /= i; 
       T[j] = i;
       }
			
		if(m == 1)
		{
			break;
		}		
	}
}
/***********************/
void LCG(int *X, int n, int choose) //funkcja: realizacja dzia³ania generatora LCG
{
	int m, a = 2, c = 2, X_max = 0, T[MAX_V], i;
	ofstream output("LCG.txt");

	// #################### //
	// Wprowadzanie danych //
	while(X_max <= 0)
	{
		cout<<"Podaj maxymalna wartosc \n";
		cin>>X_max;
	};

		m = X_max + 1; // z za³o¿enia
	
	while((X[0] <= 0) || (X[0] > m))
	{
		cout<<"Podaj ziarno \n";
		cin>>X[0];
	};
	// ################### //
	cout<<endl;

	for(i = 0; i < MAX_V; i++)
	{
		T[i] = 0;
	}

				while((NWD(c,m)!=1)&&(c<m))
				{
					c++;
				}

	i = 0; 

	first_factor(T,m);

		while(T[i])
		{
			if(a<m)
			{
				if((20*T[i]%(a-1)==0)&&((a-1)%4==0))
				{
					break;
				}
				else
				{
					a++;
				}
			}
			else
			{
				a = rand() % m; //losowe a
				break;
			}

			i++;
		}

	cout<<"c: "<<c<<endl<<"a: "<<a<<endl;

			for(int j = 1; j <= n; j++)
			{
				X[j] = (a * X[j-1] + c) % m;

				if(choose == 1)
				{
				output<<X[j]<<endl;
				}
			}
}
/***********************/
void MLCG() //funkcja: realizacja dzia³ania generatora MLCG
{
	int n = -1, m, a = 2, X_max = 0, T[MAX_V], i;
	ofstream out("MLCG.txt");
	
	// #################### //
	// Wprowadzanie danych //
		while(n < 0)
	{
		cout<<"Podaj liczbe elementow losowych \n";
		cin>>n;
	};

	while(X_max <= 0)
	{
		cout<<"Podaj maxymalna wartosc \n";
		cin>>X_max;
	};

		m = X_max + 1; // z za³o¿enia

			int *X = new int [n+1];
			X[0] = 0;
	
	while((X[0] <= 0) || (X[0] > m))
	{
		cout<<"Podaj ziarno \n";
		cin>>X[0];
	};
	// ################### //
	cout<<endl;

				for(i = 0; i < MAX_V; i++)
				{
					T[i] = 0;
				}
	i = 0; 
			//rozklad na czynniki pierwsze
			first_factor(T,m);

	while(T[i])
	{
		if(a<m)
		{
			if((20*T[i]%(a-1)==0)&&((a-1)%4==0))
			{
				break;
			}
			else
			{
				a++;
			}
		}
		else
		{
			a = rand() % m; //losowe a
			break;
		}

		i++;
	}
					cout<<"a: "<<a<<endl;

					for(int j = 1; j <= n; j++)
					{
						X[j] = (a * X[j-1]) % m;
						out<<X[j]<<endl;
					}
}
/***********************/
void ALFG() //funkcja: realizacja dzia³ania generatora ALFG
{
	int n, m, r, s, i, *X, choose = 3;
	ofstream out("ALFG.txt");

			// ################ //
			// Wprowadzanie //
			do
			{
				cout<<"Podaj ilosc liczb losowych \n";
				cin>>n;
			}
			while(n<1);

			do
			{
				cout<<"Podaj ilosc elementow tablicy \n";
				cin>>r;
			}
			while((r<1)||(r>n));

			do
			{
				cout<<"Podaj wartosc modulu \n";
				cin>>m;
			}
			while(m<2);

			do
			{
				cout<<"Podaj wartosc s \n";
				cin>>s;
			}
			while((s<=1)||(s>r));
			// ################ //

					X = new int [r+1];
					X[0] = 0;
			LCG(X,r,choose);
			i = 0;
			while(n)
			{
				X[i] = (X[(r+i-s)%r] + X[i]) % m;
				out<<X[i]<<endl;
				i = (i+1)%r;
				n--;
			};

	//usuniecie
	delete [] X;
}
/***********************/
int main()
{
int choose;

do
{
cout<<"Wybierz generator liczb losowych:\n 1 - LCG,\n 2 - MLCG,\n 3 - ALFG.\n";
cin>>choose;
}
while((choose>3)||(choose<1));

	switch(choose)
	{
		case 1:
			{
				int n = 0, *X;
						while(n <= 0)
						{
							cout<<"Podaj liczbe elementow losowych \n";
							cin>>n;
						};

					X = new int [n+1];
					X[0] = 0;

				LCG(X,n,choose);
					//usuniecie
						delete [] X;
				break;
			}

		case 2:
			{
				MLCG();
				break;
			}

		case 3:
			{
				ALFG();
				break;
			}
	}

cin.get();
cin.get();
return 0;
}