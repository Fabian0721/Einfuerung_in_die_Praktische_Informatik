#include "fcpp.hh"


//Die Ausgabe 404 sei von uns als Fehlermeldung festgelegt die ausgegeben wird wenn ungültige Werte eingegeben werden.
int bino(int n, int k)
{
	return print(
			cond( n >= 0,
				cond( k == 0 | k == n, 1,
					cond( k <= n, (bino(n - 1, k - 1) + bino(n - 1, k)), 404)
				),
			404));
}


int main()
{
	return bino(enter_int(), enter_int());
}


//Für die Werte n =; und k =; dauert die Berechnun Sekunden und damit länger als 10 Sekunden. 
