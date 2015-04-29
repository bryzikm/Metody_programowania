#include <iostream>
#include <fstream>
using namespace std;

ifstream plik("dane.txt");
/*************************************/
struct tree {
	tree *root, *left, *right;
	char sign;
	int frequency;
};
/*************************************/	
void read_and_sort(char *C, int *F, int q);
/*************************************/
void tree_road(tree * p, char *code, int temp)
{
  if(!(p->left))
  {
    cout << p->sign << " : ";
    for(int i = 0; i < temp; i++) 
	{
			cout << code[i];
	}
    cout << endl;
  }
  else
  {
    code[temp] = '0'; 
	tree_road(p->left, code, temp + 1);
    code[temp] = '1'; 
	tree_road(p->right, code, temp + 1);    
  }
}
/*************************************/
int main()
{
	char *C, *code;
	int *F, n;
	
	plik >> n;
	C = new char [n];
	code = new char [n];
	F = new int [n];

	read_and_sort(C,F,n);
    
    tree *p, *p1, *p2;
    
    // pierwszy wezel, ktory zostal stworzony + zapisanie wartosci
    p = new tree;
    p->root = p->left = p->right = NULL;
    p->sign = C[0];
    p->frequency = F[0];
    
    for ( int i = 1 ; i < n ; i++ )
    {

        p1 = new tree;
        p1->left = p1->right = NULL;
        p1->sign = C[i];
        p1->frequency = F[i];
        // dla kazdego elementu tworzymy drzewo majace jedynie korzen
        p2 = new tree;
        p2->root = NULL;
        
        // do korzenia dolaczamy wezly p1 i p2
        p->root = p1->root = p2;
        
        if(F[i] <= F[i+1])
        {
         p2->left = p1; 
         p2->right = p;   
        }
        else
        {
         p2->left = p; 
         p2->right = p1;
        }               
        // p staje sie nowym korzeniem drzewa
        p = p2;
    }
    
    tree_road(p, code, 0);    

	//zwolnienie dynamicznych tablic
	delete [] C;
	delete [] F;
	delete [] code;

	cin.get();
	cin.get();
	return 0;
}
/*************************************/
void read_and_sort(char *C, int *F, int n) //funkcja wczytujaca z pliku i sortujaca
{
	for(int i = 0; i < n; i++)
	{
		plik>>C[i]>>F[i];
	}
                       
	for(int j = 0; j < n - 1; j++)
	{
		for (int i = 0; i < n - 1; i++)
        {
            if (F[i] > F[i + 1])
            {
                swap(F[i], F[i + 1]);
                swap(C[i], C[i + 1]);
            }
        }
	}
}/*
void find2min(tree * &p1, tree * &p2)
    {
      TlistElement * p;

      p1 = front; p2 = front->next;
      if(p1->F[i] > p2->key)
      {
        TlistElement * x;
        x = p1; p1 = p2; p2 = x;
      }
      p = front->next->next;
      while(p)
      {
        if(p->key < p2->key)
        {
          p2 = p;
          if(p1->F[i] > p2->key)
          {
            TlistElement * x;
            x = p1; p1 = p2; p2 = x;
          }      
        }
        p = p->next;
      }     
    }  */  