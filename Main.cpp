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
using namespace std;
void LamaquinaCome(string T[10][10]){

    for(int fila=0 ;fila<10 ; fila++){
            for(int columna=0 ; columna <10 ; columna++){
                if (puedecomerpiezanegra(T,fila,columna)) 
                    comerpiezanegra(T,fila,columna);
                    
                        
            }
        }
    }


int main() {
    string A;
    string B,C;
    int x = 0, y = 0, i = 0, z = 0, blancas , negras;
    string T[10][10];
    int asd[10], a, b;
    Llenarlo(T);
    Mostrar(T);
    
    // Creamos un archivo para el log, es un archivo de texto sencillo.
    ofstream archivo("salida.log", ofstream::out);
    // Obtenemos el buffer original
    streambuf *estandar = cerr.rdbuf();
    // Redireccionamos la salida de errores (cerr) al archivo de texto salida.log
    cerr.rdbuf(archivo.rdbuf());
    
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
                            if(HayUnaReinaNegra(T))
                                MoverReina(T,x,y);
        }

        cout << "La Maquina Esta pensando el movimiento ..." << endl;
        sleep(2);
        if(PuedecomerLaMaquina(T))
                  LamaquinaCome(T);
          
            else
            QueMuevaLaMaquina(T, a, b);
    
    } while (ContarPiezas(T,blancas,negras) );
    if(blancas == 0)
    {   cout<<endl<<endl<<endl<<endl<< "Victoria !" <<endl<<endl<<endl<<endl;
            cout<< " ¡¡¡Felicidades Ha Ganado El Juego Contra La Maquina !!!!"<<endl;
        }
        if(negras == 0 )
        {
            cout<<endl<<endl<<endl<<endl<< " ¡ Derrota ! "<<endl<<endl<<endl<<endl;
            cout<<" Ha Ganado la Maquina , Puede volver a intenarlo"<<endl;
    }
    // Resetamos a la salida original
    cerr.rdbuf(estandar);
    
    return 0;
}