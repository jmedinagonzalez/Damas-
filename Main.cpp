#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cassert>
#include <unistd.h>
#include <stdlib.h>
#include "Comun.h"
#include <time.h>
#include<fstream>
using namespace std;



int main() {
    clock_t t_ini, t_fin;
    double secs;
    string A;
    string B,C;
    int x = 0, y = 0, i = 0, z = 0, blancas=1 , negras=1;
    string T[10][10];
    int asd[10], a, b;
    Llenarlo(T);
    Mostrar(T);
    
    ofstream myfile;
    myfile.open("Reglas.txt");

    myfile<<"Estas son las reglas del juego : "<<endl;
    myfile<<"-1: las fichas se mueven solo diagonalmente y solo 1 espacio"<<endl;
    myfile<<"-2: Para comer una pieza , debe tener un espacio en blanco detras de la pieza que se desea comer ( diagonalmente )"<<endl;
    myfile<<"-3  Las damas ( o reinas ) pueden saltar por mas de un espacio  "<<endl;
    myfile<<"-4  Si Ud realiza un movimiento invalido perdera su turno automaticamente "<<endl;
    myfile<<"-5  Si Ud desea terminar el juego antes de ganar o perder , solo desea tipear 'exit' y el juego terminara "<<endl;
    myfile<<"-6  Para mover la reina , primero debe situarse en la posicion de la reina por ejemplo  : "<<endl;
    myfile<<"    si la reina esta en el espacio (4,8) ud debe teclear 4,8 y luego interactuara con el juego  "<<endl;
    myfile<<"    la forma de mover a la reina es : diagonal , cantidad de espacios . Por ejemplo : arriba,derecha,1 "<<endl;
    myfile<<"    el cual le preguntara los movimientos a realizar con la reina , para comer una pieza ud debe situarse encima de aquella pieza "<<endl;
    myfile<<"    siempre y cuando cumpla con la regla establecida previamente para poder comer "<<endl;
    myfile<<"-7 La regla mas importante :   ¡¡¡ Diviertase !!!  "<<endl;

    myfile.close();
    t_ini = clock();
     do {
        
            

            if (Puedescomer(T,i,z)){
                     cout<<"¿ Desea Comer Pieza ? "<<endl;
                     cin>>C;
                     
                     cout<<C<<endl;
                             if(C.compare("si")==0 || C.compare("no")==0){
                                if(C.compare("si")==0){
                                    if(comerpiezablancaIzqu(T,i,z)&&comerpiezablancaDere(T,i,z)){

                                        cout<<"¿Hacia donde desea Comer ? "<<endl;
                                        cin>>C;
                                                if(C.compare("derecha")==0)
                                                    comerpiezablancaDer(T,i,z);
                                                    if(C.compare("izquierda")==0)
                                                            comerpiezablancaIzq(T,i,z);
                                    }
                                if(comerpiezablancaIzqu(T,i,z)){
                                    comerpiezablancaIzq(T,i,z);}
                                        if(comerpiezablancaDere(T,i,z)){
                                            comerpiezablancaDer(T,i,z);} 
                                                convierteReina(T);}
                                    if(C.compare("no")==0)
                                            {   
                                        cout << "Ingrese Movimiento Para Pieza Negra :" << endl;
                                        cin>>A;
                                        if (A.compare("exit") == 0)
                                            break;

                                            retornar(A, x, y, B);
                                             SiNoComesTeComenParaBlancos(T);
                                            if(EsunaReina(T,x,y)){
                                                MoverReina(T,x,y);
                                                
                                            }
                                            else{
                                            MoverPiezaUno(T, x, y, B);
                                            convierteReina(T);}
                                        }
                                        }
                                            else
                                            cout<<"Opcion No Valida , Ud Pierde El Movimiento ."<<endl;

                                        i=0; z=0;
                                    }
            

            else{

                            cout << "Ingrese Movimiento Para Pieza Negra :" << endl;
                            cin>>A;
                            if (A.compare("exit") == 0)
                                break;
                            retornar(A, x, y, B);       
                            MoverPiezaUno(T, x, y, B);
                            convierteReina(T);

                            if(HayUnaReinaNegra(T)){
                                MoverReina(T,x,y);
                                
                           }
        }

        cout << "La Maquina Esta pensando el movimiento ..." << endl;
        sleep(2);
        if(PuedecomerLaMaquina(T))
                  LamaquinaCome(T);
          
            else
                QueMuevaLaMaquina(T, a, b);            

    Contador(T,negras,blancas);
   
    } while (negras > 0 && blancas > 0);
    if(blancas == 0)
    {   cout<<endl<<endl<<endl<<endl<< "Victoria !" <<endl<<endl<<endl<<endl;
            cout<< " ¡¡¡Felicidades Ha Ganado El Juego Contra La Maquina !!!!"<<endl;
                Mostrar(T);
        }
        /*if(negras == 0 )
        {
            cout<<endl<<endl<<endl<<endl<< " ¡ Derrota ! "<<endl<<endl<<endl<<endl;
            cout<<" Ha Ganado la Maquina , Puede volver a intenarlo"<<endl;
            Mostrar(T);

    }*/
    t_fin = clock();    
    secs = (double)(t_fin - t_ini) / CLOCKS_PER_SEC;
    printf("%.16g milisegundos\n", secs * 1000.0);
    return 0;
}