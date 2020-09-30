//AUTOR: DAVID ZÁRATE LÓPEZ
//A01329785


#include "Game.cpp"//Se incluye el archivo Game.cpp, archivo donde se encuentra la Clase padre Game
#include "Automatic.cpp"//Se incluye el archivo Automatic.cpp, donde se encuentra la clase hija de Game
#include "Manual.cpp"//Se incluye el archivo Manual.cpp, donde se encuentra la clase hija de Game
#include <iostream>//Se incluye la biblioteca iostream
#include<vector>//Se incluye la biblioteca de vectores, los cuales son utilizados en el programa
#include <cstdlib>//Se incluye la biblioteca para utilizar numeros aleatorios
using namespace std;
int main(){
  Game *Game[2];//se crea un arreglo de la clase Game, las cuales serán los modos Automatic y Manual
  Game[0]= new Automatic();//Se crea un objeto de la clase Automatic
  Game[1]= new Manual();// Se crea un objeto de la clase Manual
  //A continuación se declaran diferentes variables para obtener la información que nos proporcione el usuario para establecer el juego
  char gamestyle;
  int cont,playnum,nsnake,nladder,i,ntiles,npenalty,nreward,turnlimit;
  int turns=0;
  int j;
  cont=1;
  i=0;

  //Se arroja el primer mensaje a la terminal.
  cout<<"Welcome to Snakes and Ladders"<<endl;
  try{
    //El usuario elige la cantidad de jugadores dentro del juego
    cout<<"How many players would you like to stablish?"<<endl;
    cin>>playnum;
    if (playnum<1) {
      throw "Invalid player value ";
    }
  }catch (const char* msg) {
       cerr << msg <<playnum<< endl;
       return 1;
  }

try{
  //El usuario elige la cantidad de casillas en el tablero del juego
  cout<<"How many Tiles would you like to have?"<<endl;
  cin>>ntiles;
  if (ntiles<5) {
    throw "Invalid tiles value ";
  }
}catch (const char* msg) {
     cerr << msg <<ntiles<< endl;
     return 1;
}
try{
  //El usuario elige la cantidad de casillas de serpientes en el tablero de juego
  cout<<"How many Snake tiles would you like to have?"<<endl;
  cin>>nsnake;
  if (nsnake<1 || nsnake>ntiles || nsnake==ntiles) {
    throw "Invalid snake tiles value ";
  }
}
catch (const char* msg) {
     cerr << msg <<nsnake<< endl;
     return 1;
}
try{
  //EL usuario elige la cantidad de casillas de escaleras en el tablero de juego
  cout<<"How many Ladder tiles would you like to have?"<<endl;
  cin>>nladder;
  if (nladder>ntiles || nladder<1 ||nladder==ntiles) {
    throw "Invalid ladder tiles value ";
  }
}
  catch (const char* msg) {
       cerr << msg <<nladder<< endl;
       return 1;
  }

  try{
    //Se selecciona el valor de penalizacion de las casillas de serpientes
    cout<<"How many spaces would you like for a Penalty?"<<endl;
    cin>>npenalty;
    if (npenalty<1) {
      throw "Invalid penalty value ";
    }
  }
    catch (const char* msg) {
         cerr << msg <<npenalty<< endl;
         return 1;
    }

  try{
    //Se selecciona el valor de recompensa de las casillas de escaleras
    cout<<"How many spaces would you like for a Reward?"<<endl;
    cin>>nreward;
    if (nreward<1) {
      throw "Invalid reward value ";
    }
  }
    catch (const char* msg) {
         cerr << msg <<nreward<< endl;
         return 1;
    }

  try{
    //Se selecciona el limite de turnos por jugador
    cout<<"How many turns would you like to have?"<<endl;
    cin>>turnlimit;
    if (turnlimit<1) {
      throw "Invalid turn limit value ";
    }
  }
    catch (const char* msg) {
         cerr << msg <<turnlimit<< endl;
         return 1;
    }


  //Se elige el estilo de juego; Automatic o Manual
  cout<<"The game styles are:"<<endl;
  cout<<"-Manual, where you'll be able to control each turn"<<endl;
  cout<<"-Automatic, in which the game will run without supervision"<<endl<<endl;
  //Si el usuario elige una opcion que no sea ni A ni M, esta pregunta se repetirá hasta que escriba una de estas.

      try {
        cout<<"Would you like the game to be Manual or Automatic?, Press A for Automatic and M for Manual"<<endl;
        cin>>gamestyle;
          if (gamestyle!='A' && gamestyle!='M') {
            throw "Invalid mode ";
          }
      }
      catch (const char* msg) {
           cerr << msg <<gamestyle<< endl;
           return 1;
      }


  //Si el estilo de juego es Automático, se utilizará el objeto de la clase Automatic.
  if (gamestyle=='A') {
    j=0;
  }
  //Si el estilo de juego es Manual, se utilizará el objeto de la clase Manual.
  if (gamestyle=='M') {
    j=1;
  }
  //Una vez elegido el modo de juego, se inicializan los metodos de establecer jugadores, turnos, penalizacion, recompensa y tablero.
  //Estos metodos reciben como parámetro los valores del usuario
  Game[j]->StablishPlayers(playnum);
  Game[j]->setTurnlimit(turnlimit);
  Game[j]->ReceivePenalty(npenalty);
  Game[j]->ReceiveReward(nreward);
  Game[j]->StablishBoard(ntiles,npenalty,nsnake,nladder,nreward);

  if (j==1) {//Si el modo es Manual, el siguiente mensaje se mostrará al usuario, por única vez
  cout<<"Press C to continue next turn, or E to end the game:"<<endl;
  }

  while (cont==1){// Ciclo while, el cual se utiliza para que se muestre la información de progresion del juego
    //Además hace posible que se muestre el turno por cada jugador.
        Game[j]->Move(i,ntiles,npenalty,nreward,turnlimit);//Se manda la información del usuario al metodo Move, la variable j denota si es Automatico a Manual
        if(Game[j]->CurrentPosition(i,ntiles)>=ntiles){ //En caso de que la posicion sea mayor a la capacidad de casillas del tablero se finaliza el juego
        cont=Game[j]->FinishGame();
        }
        if (Game[j]->TurnCheck(i)>turnlimit) {//En caso de que los turnos sean mayores a la capacidad de turnos del juego se finaliza el juego
          cont=Game[j]->FinishGame();
        }
        if(i<playnum){//En este condicional se establece que si el numero de jugador actual es menor al limite de jugadores, se pasará al siguiente jugador
          i++;
        }
        if (i>=playnum){//En este condicional se establece que si el numero de jugador actual es mayor al limite de jugadores, se pasará al primer jugador, para la siguiente ronda de turnos.
          i=0;
        }
      }

  return 0;


}
