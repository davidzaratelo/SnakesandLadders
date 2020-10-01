#include "Dice.h" //Se incluye el archivo Dice.h
#include <iostream> //Biblioteca iostream
#include <stdlib.h> //Biblioteca que permite usar la funcion rand()
using namespace std;
//Se obtienen los espacios
int Dice::getSpaces(){
  return spaces;
}
//Constructor, no recibe parametros
Dice::Dice(){
  spaces=0;
}

//Se "tira" el dado
int Dice::Roll(){
spaces=(rand() % 6) + 1;
return spaces;
}
//Imprime la cantidad de espacios a avanzar
void Dice::print(){
  cout<<spaces;
}
