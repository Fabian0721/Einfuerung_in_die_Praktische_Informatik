#include "fcpp.hh"
#include "save_image.hh"
#include <cmath>

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
  t.real = re;
  t.imag = im;
  return t;
}

// Syntaktischer Zucker
float real( Complex q ) { return q.real; }
float imag( Complex q ) { return q.imag; }

// Summiert zwei komplexe Zahlen p und q und schreibt das Ergebnis in p
void add_complex( Complex p, Complex q )
{
  p.real = p.real + q.real;
  p.imag = p.imag + q.imag;
}

// Multipliziert zwei komplexe Zahlen p und q und schreibt das Ergebnis in p
void multiply_complex( Complex p, Complex q )
{
  float speicher = p.real;

  p.real = (real(q) * real(p)) - (imag(q) * imag(p));
  p.imag = (speicher * imag(q)) + (imag(p) * real(q));
}

// Berechnet einen Schritt der Mandelbrot-Folge fuer die komplexe Zahl
// c, gegeben dem aktuellen Folgenelement z und schreibt das Ergebnis in z
void schritt( Complex z, Complex c )
{
  multiply_complex( z, z );
  add_complex( z, c );
}

// Betrag einer komplexen Zahl
float betrag(Complex z) {
  return std::sqrt((z.real * z.real)+(z.imag * z.imag));
}

// Betrag des n-ten Elements der Mandelbrot-Folge  zu c
float trajektorie( Complex c, int n )
{
  Complex z;
  z.real = 0;
  z.imag = 0;
  for (int i = 0; i < n; i++) {
    schritt(z, c);
  }
  return betrag(z);
}

//// Teil b)

// Datentyp fuer Bilder der Hoehe H und Breite W
struct Image {
  int H, W;
  float* pixel;
};

// Erzeugt ein neues Bild der Hoehe H und Breite W
Image create_image(int H, int W) {
  // TODO Erzeugen Sie ein Bild der entsprechenden Hoehe und Breite und
  // allokieren Sie den benoetigten Speicherplatz fuer die Pixel dynamisch
  Image bild;
  bild.H = H;
  bild.W = W;
  bild.pixel = new float;
}

// Wert eines Bildes I in der i-ten Zeile und j-ten Spalte
float get_pixel( Image bild, int i, int j) {
  int pixelzahl = 0;
  int ii = 0;
  int jj = 0;
  while(ii != i && jj != j) {
    ii = ii + 1;
    if (ii == bild.W) {
      ii = 0;
    }
    jj = jj + 1;
    pixelzahl = pixelzahl + 1;
  }
  return pixelzahl;
}

// Setzt den Wert von Bild I in der i-ten Zeile und j-ten Spalte auf den
// Wert value
void set_pixel( Image bild, int i, int j, float value) {
  get_pixel(bild, i, j);
}

//// Teil c)

// Initialisiert die Werte zweier Bilder x_coords und y_coords, so dass die
// Pixel den x und y Koordinaten eines Gitters (x_min, x_max, y_min, y_max)
// entsprechen. D.h. links oben entspricht (x_min, y_min), rechts oben
// (x_max, y_min), links unten (x_min, y_max) und rechts unten (x_max,
// y_max)
void init_grid(/* TODO typ x_coords, typ y_coords */,
                float x_min, float x_max,
                float y_min, float y_max) {
  // TODO Iterieren Sie ueber Zeilen und Spalten und nutzen Sie obige
  // set_pixel Funktion
}

// Reduziert Hoehe und Breite eines Bildes I um einen Faktor 2.
void downsample(/* TODO typ I */) {
  // TODO Skalieren Sie das Bild und achten Sie darauf Speicherplatz
  // effizient zu nutzen, d.h. nach der Operation soll kein ungenutzer
  // Speicherplatz mehr reserviert sein.
}

int main()
{
  int H = 256;
  int W = 256;
  int N = 100;
  float xmin = -1.5,
        xmax =  0.5,
        ymin = -1.0,
        ymax =  1.0;

  // TODO b) Erzeugen und initialisieren Sie x_coords und y_coords
  // TODO c) Erzeugen Sie ein Bild bild, welches den Betrag des N-ten
  //         Elements der Mandelbrot Folge visualisiert

  save_image("bild.png", bild.pixel, bild.W, bild.H);
  // TODO d) Nutzen Sie downsample um das Bild bild herunterzuskalieren
  save_image("bild_klein.png", bild.pixel, bild.W, bild.H);
}
