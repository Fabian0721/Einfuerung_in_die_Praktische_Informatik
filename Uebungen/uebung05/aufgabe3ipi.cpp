#include "fcpp.hh"

//Funktion prüft ob ein Tupel gültig ist:
bool tupelcheck(int n, int x, int y)
{
    return ((x * x) + (y * y)) <= (n * n);
}

// Funktion Sucher geht durch das Feld:
double sucher(int n, int x, int y, int a)
{
    return cond((x==0) && (y==1),
                a+1,
                cond(x==0,
                  sucher(n, n, y-1, a+1),
                  cond(tupelcheck(n, x, y),
                    sucher(n, x-1, y, a+1),
                    sucher(n,x-1,y,a))));
}

//Funktion die Pi aus dem dem Flächeninhalt berechnet:
double pi(double su, double n)
{
  return su/(n*n);
}

//Funktion imkreis ruft den Sucher mit 4 Variablen auf
int imkreis( int n )
{
    return (4*sucher(n,n,n,0))+1;
}

int main()
{
    //Eingabe:
    double n = enter_int();
    //Anzahl der Punkte:
    print(imkreis(n));
    //Pi daraus berechnet:
    print(pi(imkreis(n), n));
}

//Eine Annäherung an Pi lässt sich folgerndermaßen berechnen:
//A = pi * (r * r)
//< = >
//pi = A / (r * r);
