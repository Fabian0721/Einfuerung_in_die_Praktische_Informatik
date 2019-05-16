#include "fcpp.hh"
#include "save_image.hh"
#include <cmath> // wegen abs Funktion

//// Teil a)

// Datentyp fuer komplexe Zahlen bestehend aus Real- und Imaginaerteil
struct Complex
{
  float real;
  float imag;
};

// Erzeuge eine komplexe Zahl mit Realteil re und Imaginaerteil im
Complex erzeuge_complex( float re, float im )
{
  Complex t;
  t.real = re; t.imag = im;
  return t;
}

// Syntaktischer Zucker
float real( Complex q ) { return q.real; }
float imag( Complex q ) { return q.imag; }

// Summiert zwei komplexe Zahlen p und q und schreibt das Ergebnis in p
void add_complex( Complex &p, Complex &q)
{
  p.real = p.real + q.real; //realer Teil der berechneten Komplexenzahl
  p.imag = p.imag + q.imag; //imaginärer Teil der berechneten Komplexenzahl
}

// Multipliziert zwei komplexe Zahlen p und q und schreibt das Ergebnis in p
void multiply_complex( Complex &p, Complex &q)
{
  float real = p.real * q.real - p.imag * q.imag; //Zwischenspeicher für das Ergebnis p.real
  p.imag = p.real * q.imag + p.imag * q.real;
  p.real = real;
}

void schritt( Complex &z, Complex &c )
{
  if(z.real == 0 && z.imag == 0) //Festlegung der ersten Folgenschritts
	{
		z.real = c.real;
		z.imag = c.imag;
	}
  else
	{
		multiply_complex(z,z); //berechnet Z²
		add_complex(z,c); // addiert Z² und Komplexezahl
	}
	
}

// Betrag einer komplexen Zahl
float betrag(Complex z) 
{
  float betrag = std::sqrt(z.real * z.real + z.imag * z.imag);
  return betrag;
}

// Betrag des n-ten Elements der Mandelbrot-Folge  zu c
float trajektorie( Complex c, int n )
{
  Complex z; //Erzeuge komplexe Zahl
  z.real = 0;
  z.imag = 0;
  
  for(int i = 1; i <=n ; i++) //wiederhole Schritt bis das Nte Element gefunden ist
  {
	schritt(z,c);
  }
  return betrag(z); // gebe als Ergebnis den Betrag zurück
}

//// Teil b)

// Datentyp fuer Bilder der Hoehe H und Breite W
struct Image
{
  int H = 0;
  int W = 0;
  float* pixel;
};

// Erzeugt ein neues Bild der Hoehe H und Breite W
Image create_image(int H, int W) 
{
  
 Image Bild;
 Bild.H = H;
 Bild.W = W;
      
  Bild.pixel = new float[H*W]; //erzeuge den Speicher für die Pixel
  return Bild;
}

// Wert eines Bildes I in der i-ten Zeile und j-ten Spalte
float get_pixel( Image Bild, int i, int j) 
{	
	int PixelNr = i * Bild.W + j;
	
	return Bild.pixel[PixelNr];
}

// Setzt den Wert von Bild I in der i-ten Zeile und j-ten Spalte auf den
// Wert value
void set_pixel( Image &Bild, int i, int j, float value) 
{
   	int PixelNr = i * Bild.W + j;
   
	Bild.pixel[PixelNr] = value;
	
}

//// Teil c)

// Initialisiert die Werte zweier Bilder x_coords und y_coords, so dass die
// Pixel den x und y Koordinaten eines Gitters (x_min, x_max, y_min, y_max)
// entsprechen. D.h. links oben entspricht (x_min, y_min), rechts oben
// (x_max, y_min), links unten (x_min, y_max) und rechts unten (x_max,
// y_max)
void init_grid(Image &x_coords, Image &y_coords, float xmin, float xmax, float ymin, float ymax)
{
  // erzeuge Steps für die Achsen
  float xstep = std::abs(xmin - xmax)/ x_coords.W; 
  float ystep = std::abs(ymin - ymax)/ y_coords.W;
  //std::cout << "ystep  = " << ystep << std::endl;
	long i = 0;
	
	//erzeuge Werte der XAchse
	float value = xmin;	
	for(i = 0;  i < x_coords.H; i++)
	{
		value = xmin;	
		for(int j = 0; j < x_coords.W; j++) 
		{
			set_pixel( x_coords, i, j, value);	
			value = value + xstep;		
			//std::cout << get_pixel(x_coords, i, j) << " ";
		}			
	}
	//erzeuge Werte der YAchse
	value = ymin;	
	for(i = 0;  i < y_coords.H; i++)
	{
		for(int j = 0; j < y_coords.W; j++) 
		{
			set_pixel( y_coords, i, j, value);	
			//std::cout << get_pixel(y_coords, i, j) << " ";		
		}
		value = value + ystep;	
	}
  }

void downsample(Image &Bild) 
{
int i = 0;
float zwischenSpeicher[Bild.H/2*Bild.W/2]; //erzeugt halbierten Zwischenspeicher

  for(long Zeile = 0;  Zeile < Bild.H; Zeile++)
	{
			for(long  Spalte = 0; Spalte < Bild.W; Spalte++) 
			{			
				if(Spalte % 2 == 0 && Zeile % 2 == 0)
				{
					zwischenSpeicher[i] = get_pixel(Bild, Zeile, Spalte);
					i++;					
				}		
			}				
	}
	
  delete[] Bild.pixel;
  Bild.pixel = zwischenSpeicher;	
  Bild.W = Bild.W/2;
  Bild.H = Bild.H/2;
}

int main()
{
  int H = 800;
  int W = 800;
  int N = 100;
  
  float xmin = -1.5,
        xmax = 1.5,
        ymin = -2.0,
        ymax = 2.0;
  
  /*float s = 1.0/(10*10*10*10),
		xmin = -0.7453 - s,
        xmax = -0.7453 + s,
        ymin = 0.1127 - s,
        ymax = 0.1127 + s;*/

  // TODO b) Erzeugen und initialisieren Sie x_coords und y_coords
  Image x_coords = create_image(H,W);
  Image y_coords = create_image(H,W);
  Image Bild = create_image(H,W);
  init_grid(x_coords, y_coords, xmin, xmax, ymin, ymax);
  // TODO c) Erzeugen Sie ein Bild bild, welches den Betrag des N-ten
  //         Elements der Mandelbrot Folge visualisiert


	for(long Zeile = 0;  Zeile < H; Zeile++)
	{
		for(long  Spalte = 0; Spalte < W; Spalte++) 
		{
			float realerTeil = get_pixel(x_coords, Zeile, Spalte); //hole realerTeil aus dem Bild c_coords
			float imagTeil = get_pixel(y_coords, Zeile, Spalte); // hole imagTeil aus dem Bild y_coords

			Complex ComplexeZahl = erzeuge_complex(realerTeil, imagTeil); //erzeuge die Komplexe Zahl
			float BetragNteComplexeZahl = trajektorie( ComplexeZahl, N ); //geht bis zur N-ten Zahl in der Folge und gibt Betrag aus
						
			set_pixel(Bild, Zeile, Spalte, BetragNteComplexeZahl);	//erstellt das Bild der Mandelbrotmenge	
		}
		
	}

  save_image("bild.png", Bild.pixel, Bild.W, Bild.H); // Aenderung der Funktion in Zeile 13:  "delete[] tmp;" wegen Fehlermeldung
  save_image("x_coords.png", x_coords.pixel, x_coords.W, x_coords.H);
  save_image("y_coords.png", y_coords.pixel, y_coords.W, y_coords.H);
  // TODO d) Nutzen Sie downsample um das Bild bild herunterzuskalieren
  downsample(Bild);
  save_image("bild_klein.png", Bild.pixel, Bild.W, Bild.H);
}




