#include "../fcpp.hh"
#include <string>  // std::string
#include <cstring> // strlen




// zur Unterscheidung von Elementen mit Operatoren und Variablen
char EMPTY_CHAR = ' ';

// zum Zusammenbauen von Strings
std::string convert_int_to_str(int zahl)
{
  char result[16];
  sprintf ( result, "%d", zahl );
  return result;
}

// zum Zusammenbauen von Strings
std::string convert_char_to_str(char zeichen)
{
  return std::string(1, zeichen);
}

struct BaumElement
{
  int zahl;
  char variable;
  char zeichen;
  BaumElement* links;
  BaumElement* rechts;
};

BaumElement  Ast[100];							//Globale Variable zum Speichern der Baumelemente (Sorry)

std::string print_in(BaumElement* be)
{
  std::string String="";						//String am Anfang leer



  if(be->zeichen!=0||be->variable!=0)						//Ist Aktuelles Element kein Operator?
  {
  		if(be->links->zahl!=0||be->links->variable!=0)		//linker Ast eine Variable/Zahl => zum String hinzufügen
  		{
  			if(be->links->zahl!=0)
  			{
  				String=String+convert_int_to_str(be->links->zahl);
  			}
  			else
  			{
  				String=String+convert_char_to_str(be->links->variable);
  			}
  		}
  		else												//linker Ast ein Operator => Behandel wie den Anfang
  		{
  			String=String+(print_in(be->links));
  		}

  		String=String+(be->zeichen);						//Der Operator kommt in die Mitte (d.h. Infix)

  		if(be->rechts->zahl!=0||be->rechts->variable!=0)	//rechter Ast analog zum Linken
  		{
  			if(be->rechts->zahl!=0)
  			{
  				String=String+convert_int_to_str(be->rechts->zahl);
  			}
  			else
  			{
  				String=String+convert_char_to_str(be->rechts->variable);
  			}
  		}
  		else
  		{
  			String=String+(print_in(be->rechts));
  		}
  }


  return String;			//Gefüllter string zurückgegeben
}

std::string print_pre(BaumElement* be)
{
  std::string String="";


  if(be->zeichen!=0)		//BaumElement ist ein Operator
  {
  	String=String+" "+convert_char_to_str(be->zeichen); 	//d.h. Operator anhängen + linker Ast + rechter Ast
  	String=String+print_pre(be->links);
  	String=String+print_pre(be->rechts);
  }
  else						//BaumElement ist eine Variable/Zeichen => Dranhängen
  {
  	if(be->zahl!=0)
  	{
  		String=String+" "+convert_int_to_str(be->zahl);
  	}
  	else
  	{
  		String=String+" "+convert_char_to_str(be->variable);
  	}
  }

  return String;
}

std::string print_post(BaumElement* be)
{
  /*std::string String="";
  std::string Speicher;

  Speicher=print_pre(be);
  for(int i=0;i<Speicher.size();++i)
  {
  	String=String+Speicher[Speicher.size()-i];
  }
  return String;*/
  std::string String="";						//String am Anfang leer



  if(be->zeichen!=0||be->variable!=0)						//Ist Aktuelles Element kein Operator?
  {
  		if(be->links->zahl!=0||be->links->variable!=0)		//linker Ast eine Variable/Zahl => zum String hinzufügen
  		{
  			if(be->links->zahl!=0)
  			{
  				String=String+convert_int_to_str(be->links->zahl);
  			}
  			else
  			{
  				String=String+convert_char_to_str(be->links->variable);
  			}
  		}
  		else												//linker Ast ein Operator => Behandel wie den Anfang
  		{
  			String=String+(print_post(be->links));
  		}



  		if(be->rechts->zahl!=0||be->rechts->variable!=0)	//rechter Ast analog zum Linken
  		{
  			if(be->rechts->zahl!=0)
  			{
  				String=String+convert_int_to_str(be->rechts->zahl);
  			}
  			else
  			{
  				String=String+convert_char_to_str(be->rechts->variable);
  			}
  		}
  		else
  		{
  			String=String+(print_post(be->rechts));
  		}
  		String=String+(be->zeichen);						//Der Operator kommt in die Mitte (d.h. Infix)
  }


  return String;
}



BaumElement* insert(BaumElement* expr, char var, BaumElement* subexpr) 		//Nicht bearbeitet
{

}

// Stack Implementation zum Baum generieren
struct Stack
{
  BaumElement* value[100];
  int top;
};

Stack stack;

void init_stack()
{
  stack.top = 0;
}

void push(BaumElement* element)
{
  stack.value[stack.top] = element;
  stack.top++;
}

BaumElement* pop()
{
  stack.top--;
  return stack.value[stack.top];
}

BaumElement* create_tree(const char* ausdruck)
{
  init_stack();

  int zahl=0;				//Variable um charverkettungen zu int konvertieren
 std::string davor;		//Speichert ob der char davor operator, zahl oder variable war
  int n=0;					//Zählt das array mit BaumElementen ab
  int i=0;					//Zählt die Schleife und damit ausdruck durch
  while(i<strlen(ausdruck))
  {


  	if(ausdruck[i]>='0'&&ausdruck[i]<='9')
  	{
  		davor="zahl";
  		zahl=(zahl*10)+(ausdruck[i]-'0');		//rechnet char in int und hängt sie hinten dran
  	}
  	else if(ausdruck[i]=='+'||ausdruck[i]=='-'||ausdruck[i]=='*'||ausdruck[i]=='/')
  	{
  		davor="op";
  		Ast[n].zeichen=ausdruck[i];			//Zeichen wird eingelesen
		Ast[n].links=pop();					//Bekommt die im stack gespeicherten Pointer zugewiesen
  		Ast[n].rechts=pop();
  		push(&Ast[n]);						//und Pusht sich dann selbst
  		n++;								//Beim nächsten mal wird array+1 angesprochen
  	}
  	else if(ausdruck[i]==EMPTY_CHAR)
  	{
  		if(davor=="zahl")					//nur wenn vorher eine zahl gestanden hat
  		{

	  		Ast[n].zahl=zahl;				//s.o.
	  		Ast[n].variable=0;
	  		Ast[n].links=nullptr;
	  		Ast[n].rechts=nullptr;
	  		push(&Ast[n]);
	  		zahl=0;							//zahl wird zurückgesetzt
  			n++;
  		}

  	}
  	else if(ausdruck[i]>='A'&&ausdruck[i]<='Z'||ausdruck[i]>='a'&&ausdruck[i]<='z')
  	{
  		davor="var";						//s.o.
  		Ast[n].variable=ausdruck[i];
  		Ast[n].zahl=0;						//zahl wird zum vergleichen in print_pre und co null gesetzt
  		Ast[n].links=nullptr;
  		Ast[n].rechts=nullptr;
  		push(&Ast[n]);
  		++n;
  	}
  	else									//Kein gültiges zeichen wurde erkannt
  	{
  		throw std::runtime_error("Ungültiges Zeichen");
  	}
  	++i;
  }

  	BaumElement* ast =&Ast[n-1];			//Bei return &Ast giebt er ein warning aus
  	return ast;
}

int main (int argc, char* argv[])
{
  const char* ausdruck1 = "67 55 - 54 6 / + 2 *";
  BaumElement* baum1 = create_tree(ausdruck1);

  if(baum1)
  {
   std::cout << "Praefix: \n" << print_pre(baum1) << std::endl;
  	std::cout << "Infix: \n" << print_in(baum1) << std::endl;
   std::cout << "Postfix: \n" << print_post(baum1) << std::endl;
  }

  const char* ausdruck2 = "X 1 - X 1 + *";
  BaumElement* baum2 = create_tree(ausdruck2);

  if(baum2)
  {
    std::cout << "Praefix: \n" << print_pre(baum2) << std::endl;
    std::cout << "Infix: \n" << print_in(baum2) << std::endl;
    std::cout << "Postfix: \n" << print_post(baum2) << std::endl;
  }

  /*
  baum2 = insert(baum2, 'X', baum1);
  if(baum2)
  {
    std::cout << "Praefix: \n" << print_pre(baum2) << std::endl;
    std::cout << "Infix: \n" << print_in(baum2) << std::endl;
    std::cout << "Postfix: \n" << print_post(baum2) << std::endl;
  }
	*/
  return 0;
}
