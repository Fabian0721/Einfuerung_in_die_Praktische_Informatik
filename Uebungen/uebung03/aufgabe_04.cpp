#include "fccp.hh"

int potenz(int x, int exp)
{
	return print (fall1);
}
//Alle drei verschiedenen Faelle
int fall1(int x, int exp)
{
	return cond ( exp == 1, x, fall2(x,exp) );
}

int fall2(int x, int exp)
{
	return cond ( gerade(exp), quadrat(expo(x,(HalbExp(x,exp)))), fall3 )
}



int fall3(int exp)
{
	return 
}




//Prüft ob Gerade
bool gerade(int exp)
{
	return cond( exp % 2 == 0, true, false)
}


//Macht x2
int quadrat (int x)
{
	return x*x;
}

//Macht exp/2
int HalbExp (int x, int  exp)
{
	return exp/2;
}

//Soll x hoch exp2 machen
int expo (int x, int exp2)
{
	return cond ( 
}
