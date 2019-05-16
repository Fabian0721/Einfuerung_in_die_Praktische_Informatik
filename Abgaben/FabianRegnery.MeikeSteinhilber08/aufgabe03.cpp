#include "fcpp.hh"
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

struct BaumElement {
  int zahl;
  char variable;
  char zeichen;
  BaumElement* links;
  BaumElement* rechts;
};
//Globaler Array
BaumElement baum[100];

//Drucken des Baums in infix Notation
std::string print_in(BaumElement* be) {
  std::string output;
    if (be->zeichen==0) {
      if (be->zahl!=0) {
        output = output + convert_int_to_str(be->zahl);
      } else {
        output = output + be->variable;
      }
      return output;
    }
    //Reckursiver wiederverwendbare Aufruf
    output = output + print_in(be->links);
    output = output + be->zeichen;
    output = output + print_in(be->rechts);
  return output;
}
//Drucken des Baums in prefix Notation
std::string print_pre(BaumElement* be) {
  std::string output;
  if (be->zeichen==0) {
    if (be->zahl!=0) {
      output = output + convert_int_to_str(be->zahl);
    } else {
      output = output + be->variable;
    }
    return output;
  }
  //Reckursiver wiederverwendbare Aufruf
  output = output + be->zeichen;
  output = output + print_pre(be->links);
  output = output + print_pre(be->rechts);
return output;
}
//Drucken des Baums in postfix Notation
std::string print_post(BaumElement* be) {
  std::string output;
  if (be->zeichen==0) {
    if (be->zahl!=0) {
      output = output + convert_int_to_str(be->zahl);
    } else {
      output = output + be->variable;
    }
    return output;
  }
  //Reckursiver wiederverwendbare Aufruf
  output = output + print_post(be->links);
  output = output + print_post(be->rechts);
  output = output + be->zeichen;
return output;
}

BaumElement* insert(BaumElement* expr, char var, BaumElement* subexpr) {
  return 0;
}

// Stack Implementation zum Baum generieren
struct Stack
{
  BaumElement* value[100];
  int top;
};

Stack stack;

void init_stack() {
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

bool empty() {
  return stack.top == 0;
}

BaumElement* create_tree(const char* ausdruck) {
  //Globale Variable wird zurück gesetzt.
  BaumElement reseter;
  reseter.zahl = NULL;
  reseter.zeichen = NULL;
  reseter.variable = NULL;
  reseter.links = NULL;
  reseter.rechts = NULL;
  for (int i = 0; i<100; i++) {
    baum[i] = reseter;
  }
  //Stack initialisieren
  init_stack();

  bool vorzahl = false; //Gibt an ob davor eine Zahl war
  int zahl = 0;
  std::string worter = ausdruck;
  //Lesen der Eingabe und setzen der Zeiger mit hilfe des Stacks
  for (int i = 0; i < worter.size(); i++) {
    if (worter[i] > 47 && worter[i] < 58) {
      if (vorzahl) {
        zahl = (zahl * 10) + (worter[i] - 48); //Zusammenbauen der Ziffern
      } else {
        zahl = worter[i] - 48;
        vorzahl = true;
      }
    } else {
      if (worter[i]=='+'||worter[i]=='-'||worter[i]=='*'||worter[i]=='/') { //Operatoren
        baum[i].zeichen = worter[i];
        baum[i].rechts = pop();
        baum[i].links = pop();
        push(&baum[i]);
      }
      if (zahl != 0) { //Zahlen
        baum[i].zahl = zahl;
        baum[i].rechts = nullptr;
        baum[i].links = nullptr;
        push(&baum[i]);
        zahl = 0;
      }
      if ((worter[i]>='A' && worter[i]<='Z') || (worter[i]>='a' && worter[i]<='z')){ //Variablen
        baum[i].variable = worter[i];
        push(&baum[i]);
      }
      vorzahl = false;
    }
  } //Ausgabe der Eingabe
  std::cout << "Ihre Eingabe lautete: " << '\n' << worter << '\n';
  return pop();
}

int main (int argc, char* argv[])
{
  const char* ausdruck1 = "67 55 - 54 6 / + 2 *";
  BaumElement* baum1 = create_tree(ausdruck1);

  if(baum1) {
    std::cout << "Praefix: \n" << print_pre(baum1) << std::endl;
    std::cout << "Infix: \n" << print_in(baum1) << std::endl;
    std::cout << "Postfix: \n" << print_post(baum1) << std::endl;
  }

  const char* ausdruck2 = "X 1 - X 1 + *";
  BaumElement* baum2 = create_tree(ausdruck2);

  if(baum2) {
    std::cout << "Praefix: \n" << print_pre(baum2) << std::endl;
    std::cout << "Infix: \n" << print_in(baum2) << std::endl;
    std::cout << "Postfix: \n" << print_post(baum2) << std::endl;
  }

  baum2 = insert(baum2, 'X', baum1);

  if(baum2) {
    std::cout << "Praefix: \n" << print_pre(baum2) << std::endl;
    std::cout << "Infix: \n" << print_in(baum2) << std::endl;
    std::cout << "Postfix: \n" << print_post(baum2) << std::endl;
  }

  return 0;
}
