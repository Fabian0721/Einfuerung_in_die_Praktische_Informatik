#include "fcpp.hh"

//---Aufgabe 2a---

//Die Ausgabe 404 sei als Fehlermeldung gesetzt, diese wird Ausgegeben falls n oder k ungültig sind.
int bino(int n, int k)
{
    return cond( n >= 0,
                cond( k == 0 | k == n, 1,
                    cond( k < n, (bino(n - 1, k - 1) + bino(n - 1, k)), 404)
                ),404);
}

int ausgeben(int n, int k)
{
	return print(bino(n, k));
}
//Für die Eingabe n = 33 und k = 16 beträgt die Laufzeit 14,3325 Sekunden und dauert damit länger als 10 Sekunden.
//Für die Eingabe n = 34 und k = 18 beträgt die Laufzeit 26,7865 Sekunden, dieser Laufzeitanstieg im Gegensatz zu n = 33 deutet auf eine hohe Komplexität hin.

//---Aufgabe 2b---

//Die Komplexität des Programms beträgt 2^n

//---Aufgabe 2c---

double fakultaet( int n )
{
  return cond( n <= 1, 1, n * fakultaet(n - 1) );
}

int binfast(int n, int k)
{
    return print ( fakultaet(n) / ( fakultaet(k) * fakultaet(n-k) ) );
}
//Die asymptotische Komplexität beträgt 1
//Bezüglich der Geschwindigkeit ist das Programm aus Aufgabe 2c deutlich schneller, da dessen Kompexität deutlich geringer ist. 

//---- Main Funktion für die Ausführung ----
int main()
{
    	ausgeben(enter_int(), enter_int());
        binfast(enter_int(), enter_int());
	return 0;
}




