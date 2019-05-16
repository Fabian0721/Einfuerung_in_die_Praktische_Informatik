#include "fcpp.hh"

// 2.147.483.647 ist die höchste Zahl die in eine Integer passt, daraus ist abzuleiten das nur Volkommene Zahlen kleiner gleich dieser Zahl möglich sind.
// Diese Vollkommenen Zahlen lauten gemäss Wikipedia 6; 28; 496; 8.128; 33.550.336; 


bool vollkommen(int zahl)
{
	return  cond( zahl == 6 | zahl == 28 | zahl == 496 | zahl == 8128 | zahl == 33550336, true, false );
}


int main ()
{
	int a = 7;
	return print( vollkommen(a));
} 

