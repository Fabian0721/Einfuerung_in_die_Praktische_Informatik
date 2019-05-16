#include "fcpp.hh"

float determinanteflo(float a, float b, float c, float d)
{
	return (a*d)-(b*c);
}

//Float hat nur 32 Bit zu verfügung dementsprechend wird die Rundung füher vorgenommen und damit
//ist das Ergebnis anderst exakt 10000. 

double determinantedou(double a, double b, double c, double d)
{
	return (a*d)-(b*c);
}

//Double hat 64 Bit zur verfügung demenstsprechend wird die Rundung später bzw. garnicht vorgenommen 
//und es kommt das exakte Ergebnis raus 10000.0001.

int main() 
{
	print(determinanteflo(100,0.01,-0.01,100));
	print(determinantedou(100,0.01,-0.01,100));
	return 0;
}
