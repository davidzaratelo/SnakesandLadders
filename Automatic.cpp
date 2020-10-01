#include <iostream>
using namespace std;
#include "Automatic.h"//Se incluye el archivo Automatic.h


Automatic::Automatic():Game(){//El Constructor recibe los atributos de la clase Game
}

void Automatic:: Move(int i,int ntiles, int npenalty,int nreward,int turnlimit){//Método que describe las acciones realizadas por el programa en el modo Automatic.
  int roll,move,extra,currpos,turncounter,update,finish,limit,turn;
  char position;
     roll=d1.Roll();//Se obtiene un numero aleatorio del dado del juego.
     move=roll+player[i].getTilePos();//La variable move almacena el movimiento que realiza el jugador en el turno
     position=tiles[move-1].getType();//Se obtiene la letra del tipo de casilla
     currpos=move-roll;//Posicion actual del jugador
     turn=player[i].CurrentTurn();//Turno actual del jugador
     //Si el movimiento del jugador es menor al numero de casillas total y no excede el limite de turnos, el juego sigue.
       if (move<ntiles && turnlimit>=turn){
            if (position=='N'){//Si la casilla es normal no recibe penalizacion y se muestra la informacion del jugador en el turno actual
           Turn t1(turn,player[i].getPlayerNum(),currpos,roll,position,player[i].UpdatePosition(roll,ntiles));//Se crea un objeto de clase turno para hacer la sobrecarga de <<
           cout<<t1<<endl;//Se utiliza la sobrecarga de <<
            }
           if (position=='S') {//Si la casilla es tipo serpiente recibe penalizacion y se muestra la informacion del jugador en el turno actual
           SnakeTile snake(npenalty);//Se crea un objeto con parametro inicial
           SnakeTile snake2; //Se crea un objeto sin parametros iniciales
           snake2=snake+move;//Se utiliza la sobrecarga del operador +
           move=move-ReceivePenalty(npenalty);
           Turn t2(turn,player[i].getPlayerNum(),currpos,roll,position,snake2.getPenalty()); //Se crea un objeto de clase turno para hacer la sobrecarga de <<
           cout<<t2<<endl; //Se utiliza la sobrecarga del operador <<
           }
           if (position=='L') {//Si la casilla es tipo escalera recibe recompensa y se muestra la informacion del jugador en el turno actual
           move=move+ReceiveReward(nreward);
           Turn t3(turn,player[i].getPlayerNum(),currpos,roll,position,player[i].UpdatePosition(roll+ReceiveReward(nreward),ntiles));//Se crea un objeto de clase turno para hacer la sobrecarga de <<
           cout<<t3<<endl;//Se utiliza la sobrecarga del operador <<
           }
       }
   if (move>=ntiles){//Si el movimiento total del jugador es mayor a la cantidad de casillas, el juego termina.
   CurrentPosition(i,ntiles);
   cout<<turn<<" "<<player[i].getPlayerNum()<<" "<<currpos<<" "<<roll<<" "<<" "<<" "<<player[i].UpdatePosition(roll,ntiles)<<endl;
   cout<<"Player number "<<player[i].getPlayerNum()<<" is the winner!! " <<endl;
   cout<<"GAME OVER"<<endl;
    }
    if (turnlimit<turn){//Si el turno actual es mayor a la cantidad limte de turnos, el juego termina.
    cout<<"The maximum number of turns has been reached.."<<endl;
    cout<<"GAME OVER"<<endl;
     }

}
