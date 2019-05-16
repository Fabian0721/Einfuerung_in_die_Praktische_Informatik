#include "fcpp.hh"
//Aufgabe 2
float rechnen(float a, float b, float c)
{
	return (a+b)+c;
}

float rechnen2(float a, float b, float c)
{
	return a+(b+c);
}

float quadrat(int n)
{
	return cond(n==1, 10, 10 * quadrat(n-1));
}

float quadratne(int n)
{
	return cond(n==1, -10, -10 * quadrat(n-1));
}

float quadratbruch(int n)
{
	return cond(n==1, 1/10, 1/quadrat(n));
}

int main()
{
	int n = 4;
	print(rechnen(quadrat(n),quadratne(n),quadratbruch(n)));
	print(rechnen2(quadrat(n),quadratne(n),quadratbruch(n)));
    
    
    //Test der Funktionen
	//print(quadrat(enter_int()));
    //print(quadratne(enter_int()));
    //print(quadratbruch(enter_int()));
    
	return 0;
}

//Ergebnisse Funktionale Programmierung:
//
//          rechnen                             rechnen2                        gleich?
//  6       9.999999974752427e-07               0                                <--- NO --->
//  7       1.000000011686097e-07               0                               
//  8       9.99999993922529e-09                0
//  9       9.999999717180685e-10               0
//  10      1.000000013351432e-10               0
//  11      9.999999960041972e-12               0
//  12      9.999999960041972e-13               0
//  13      1.000000050214306e-13               0
//  14      9.9999998245167e-15                 0
//
//Die Gleichungen sind nie wirklich Assoziativ, wobei bei je größer n wird desto eher lässt sich der unterschied //vernachlässigen. 
