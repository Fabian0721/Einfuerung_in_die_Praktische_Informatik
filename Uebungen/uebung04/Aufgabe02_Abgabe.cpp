#include "fcpp.hh"

//---Aufgabe 2a---

//Die Ausgabe 404 sei als Fehlermeldung gesetzt, diese wird Ausgegeben falls n oder k ung�ltig sind.
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
//F�r die Eingabe n = 33 und k = 16 betr�gt die Laufzeit 14,3325 Sekunden und dauert damit l�nger als 10 Sekunden.
//F�r die Eingabe n = 34 und k = 18 betr�gt die Laufzeit 26,7865 Sekunden, dieser Laufzeitanstieg im Gegensatz zu n = 33 deutet auf eine hohe Komplexit�t hin.

//---Aufgabe 2b---

//Die Komplexit�t des Programms betr�gt 2^n

//---Aufgabe 2c---

double fakultaet( int n )
{
  return cond( n <= 1, 1, n * fakultaet(n - 1) );
}

int binfast(int n, int k)
{
    return print ( fakultaet(n) / ( fakultaet(k) * fakultaet(n-k) ) );
}
//Die asymptotische Komplexit�t betr�gt 1
//Bez�glich der Geschwindigkeit ist das Programm aus Aufgabe 2c deutlich schneller, da dessen Kompexit�t deutlich geringer ist. 

//---- Main Funktion f�r die Ausf�hrung ----
int main()
{
    	ausgeben(enter_int(), enter_int());
        binfast(enter_int(), enter_int());
	return 0;
}




