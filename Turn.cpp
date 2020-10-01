#include <iostream> //Biblioteca iostream
#include "Turn.h" //incluye el archivo Turn.h
using namespace std;

Turn:: Turn(){ //CONSTRUCTOR, no recibe parametros

}

Turn:: Turn(int tur,int num,int curr,int roll,char tilety,int final){ //CONSTRUCTOR, el cual recibe los parametros de cada turno de cada jugador, inicializa las variables.
  playernumber=num;
  turn=tur;
  currposition=curr;
  rolldice=roll;
  tiletype=tilety;
  finalpos=final;
}
