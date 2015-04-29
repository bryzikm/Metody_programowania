#include<iostream>
using namespace std;
/*************************/
void Hanoi(char A, char B, char C, int n) //funkcja Hanoi 
	{
		if(n==1) //sprawdzenie warunku
		{
			cout<<A<<"->"<<C<<endl;
		}
		else
		{
			Hanoi(A, C, B, n-1); //rekursja - wywolanie funkcji w funckji przy zmniejszonym n
			cout<<A<<"->"<<C<<endl;
			Hanoi(B, A, C, n-1);
		}
	}

int main()
{
char A = 'A', B = 'B', C = 'C';
int n=0;

		while(n<2) //podanie ilosci elementow wie¿y
		{
			cout<<"Podaj n"<<endl;
			cin>>n;
		}

		Hanoi(A, B, C, n); //wywolanie funkcji Hanoi

	cin.get();
	cin.get();
	return 0;
}