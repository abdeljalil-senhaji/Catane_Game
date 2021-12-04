#include <iostream>
using namespace std;
int main()
{
    int tab[10];
    int indice;
    for (int i = 0; i<10; i++)
        {
            cout << "ecrir un nombre : ";
            cin >> tab[i];
        }
    for (int i=1; i<10; i++)
    {
        if (tab[indice]< tab[i])
            indice = i;
    }

    cout << "l'indice de plus grande élément est : " << indice <<endl; 
    return 0;
}