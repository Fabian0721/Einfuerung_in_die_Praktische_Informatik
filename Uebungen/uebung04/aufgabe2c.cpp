#include "fcpp.hh"

int fakultaet(int h)
{
	return cond( h == 0 | h == 1, 1, h * fakultaet( h - 1 ) );
	//Fakultaetsberechnung funktioniert nicht määäääääää
}

int main()
{
	int n = enter_int();
	int k = enter_int();

	return print ( fakultaet( n ) ) / ( fakultaet( k ) * fakultaet( n - k ));
}
