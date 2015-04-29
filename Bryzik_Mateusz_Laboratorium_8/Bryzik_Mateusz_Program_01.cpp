#include<iostream>
#include<fstream>
using namespace std;
/**********************/ //funckaj pakujaca rzeczy do plecaka
void plecak(int i1, int i2, int *p, int *w, double *s, int &maxprofit, int maxW, int n, int profit, int weight, int *node);
/**********************/
void sortowanie(int n, int *p, int *w, double *s); //funkcja sortujaca nierosnaco wedlug s[]
/**********************/
int main()
{
	ifstream plik("dane.txt"); //plik z danymi
	int *p, *w, *node, maxW, n, profit = 0, maxprofit = 0, weight = 0, i1=0, i2=0; //zmienne: cena, waga, wezel, maxymalna waga, ilosc rzeczy, profit..
											//...maxymalny profit, obliczana waga rzeczy, indeksy i1 i i2 (obrazujacy ktory wezel rozpatrujemy)
	double *s; //stosunek: p[]/w[]

	plik>>n>>maxW; //wczytanie danych z pliku
	//utworzenie tablic dynamicznych przechowywujacych dane dla odpowiedniego i
	p = new int [n+1];
	w = new int [n+1];
	s = new double [n+1];
	node = new int [n+1];
	//wczytanie danych do tablic
	for(int i=1; i<=n; i++)
	{
		plik>>p[i]>>w[i]>>s[i];
		node[i] = 0;
	}

sortowanie(n,p,w,s); //wywolanie funkcji sortujacej wczytane dane nierosnaco (wg s[])
	//przypisanie wartosci skrajnym elementom tablic
    p[0] = 0;
    w[0] = 0;
    p[n+1] = 0;
    w[n+1] = maxW;
    node[0] = 0;

plecak(i1, i2, p, w, s, maxprofit, maxW, n, profit, weight, node); //wywolanie funkcji rozpatrujacej poszczegolne wezly

cout<<"maxprofit = "<<maxprofit<<endl; //wypisanie maxymalnego profitu w plecaku

	cin.get();
	cin.get();
	return 0;
}
/*******************/
void sortowanie(int n, int *p, int *w, double *s)
{
	    for(int i=1; i < n; i++)
		{
			for(int j=1; j < n; j++)
			{
				if(s[j] < s[j+1]) //sprawdzenie warunku
					{	//zamiana danych miêdzy sob¹
						swap(s[j],s[j+1]);
						swap(w[j],w[j+1]);
						swap(p[j],p[j+1]);
					}
			}
		}
}
/*******************/
void plecak(int i1, int i2, int *p, int *w, double *s, int &maxprofit, int maxW, int n, int profit, int weight, int *node)
{
	    int k, totweight, bound; //zmienne: indeks, waga calkowita, granica

    cout << "wezel(" << i1 << ", " << i2 << ")\n";

    if(i2%2!=0) //sprawdzenie warunku indeksu 2
    {
        cout << "Wybieramy przedmiot " << i1 << "\n";
        profit+=p[i1]; //zwiekszenie wartosci profitu o cene przedmiotu i1
        weight+=w[i1]; //zwiekszenie wagi
    }
	else
	{
	 cout << "Nie wybieramy przedmiotu " << i1 << "\n";
	}
    cout << "profit=" << profit << "\n"; //wypisanie profitu oraz wagi
    cout << "weight=" << weight << "\n\n";

    if(weight >= maxW) //sprawdzenie warunku
	{
		cout << "Wezel nieobiecujacy\n\n";
	}
	else
    {
        if(profit>maxprofit) //sprawdzenie drugiego warunku
        {
            maxprofit=profit;
            cout <<"maxprofit=" << maxprofit << "\n";
        }
        k=i1; //za k podstaw indeks i1
		int t1 = weight; //zmienna pomocnicza przechowywujaca wage
        while(t1<=maxW) 
		{
			t1+=w[++k]; //obliczanie zmiennej w petli
		}
        cout << "k=" << k << "\n";

        totweight=weight; //przypisanie zmiennym wartosci
        bound=profit;

        for(int i=i1+1; i<k; i++) //obliczanie total weight i granicy
        {
            totweight+=w[i];
            bound+=p[i];
        }

			bound+=s[k]*(maxW-totweight); //obliczenie granicy ze wzoru
		//wypisanie danych
        cout << "bound=" << bound << "\n";
        cout << "totweight=" << totweight << "\n";

        if(bound<=maxprofit) //sprawdzenie warunku
		{	
			cout << "Wezel nieobiecujacy\n\n";
		}
		else
        {
           cout << "Wezel obiecujacy\n\n";

            if(i1<n)
			{
			if(node[i1+1]%2==0)
			++node[i1+1];
			}
            plecak(i1+1, node[i1+1], p, w, s, maxprofit, maxW, n, profit, weight, node); //rekurencja (idziemy do dziecka w drzewie)
        }
    }

    cout << "POWROT\n\n"; //w przypadku wykorzystania wszystkich mo¿liwoœci
    if(i2%2!=0 && i1>0)
	{	//cofamy sie do wez³a poprzedniego, zmniejszamy dane
		plecak(i1, ++node[i1], p, w, s, maxprofit, maxW, n, profit-p[i1], weight-w[i1], node);
	}
}
//(int i1, int i2, int *p, int *w, double *s, int &maxprofit, int maxW, int n, int profit, int weight, int *node)