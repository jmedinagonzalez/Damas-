#include "Comun.h"

void convierteReina(string T[10][10]) {
    for (int y = 0; y < 10; y++) {
        if (T[0][y] == "0") {
            cout << "Se ha coronado una reina Para el equipo Blanco ." << endl;
            T[0][y] == "B";
        }
        if (T[9][y] == "1") {
            cout << "Se Ha coronado una reina para el equipo negro ." << endl;
            T[9][y] == "N";
        }
    }
}



bool puedecomerpiezanegra(string T[10][10], int x, int y) { // comprueba si hay una posicion que puede comer una pieza rival
    bool ok = false;
    if (T[x][y].compare("0")==0){
        if(x-2>=0 && y-2>=0){
        if (T[x - 1][y - 1].compare("1")==0 && T[x - 2][y - 2].compare(" ")==0 ) {
            ok = true;
        }
        }
    if(x-2>=0 && y+2<=9){
        if(T[x - 1][y + 1].compare("1") == 0 && T[x - 2][y + 2].compare(" ") == 0){
            
            ok = true;}
       } 
    }
    return ok;
}

bool EsunaReina(string T[10][10] , int x , int y )
{
    bool ok = false ;
    if(T[x][y].compare("N")==0)
        ok = true ;
    return ok;
}
void Llenarlo(string T[10][10]) {

    int i, j;
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {

            if (i < 3) {
                if (j % 2 == 0 && i % 2 == 0)
                    T[i][j] = "1";
                else
                    T[i][j] = " ";
                if (i % 2 != 0 && j % 2 != 0)
                    T[i][j] = "1";
            }
            if (i > 6) {
                if (j % 2 == 0 && i % 2 == 0)
                    T[i][j] = "0";
                else
                    T[i][j] = " ";
                if (i % 2 != 0 && j % 2 != 0)
                    T[i][j] = "0";
            }
            if (i > 2 and i < 7)
                T[i][j] = " ";

        }
           
    }

}


void Mostrar(string T[10][10]) {

    int i, j;

    for (i = 0; i < 10; i++) {

        for (j = 0; j < 10; j++) {

            cout << "[" << T[i][j] << "]";

        }

        cout << "   " << i << "   " << endl;
    }
    for (int m = 0; m < 10; m++) {
        cout << " " << m << " ";
    }
    cout << endl << endl << endl;
}


void SiNoComesTeComenParaBlancos(string T[10][10]) {
    for (int x = 0; x < 10; x++) {
        for (int y = 0; y < 10; y++) {
            if (T[x][y] == "0" && T[x - 1][y - 1] == "1" && T[x - 2][y - 2] == " ") {
                T[x - 1][y] = " ";
                T[x - 2][y - 2] = "0";
                T[x][y] = " ";
                cout << "TUVISTE LA OPORTUNIDAD DE COMER UNA PIEZA NEGRA " << endl<<endl;
                cout << "AL NO APROVECHAR SE HA PRODUCIDO UNA SOPLADITA ,QUE ES EL CASTIGO ,PERDER LA PIEZA, POR NO COMER ." << endl;
            }
        }
    }
}

void Contador(string T[10][10] , int &Uno , int &Dos){
int negras = 0 , blancas =0 ;
    for(int filas=0 ; filas < 10 ; filas++)
        for(int columnas=0 ; columnas < 10 ; columnas++){
            if(T[filas][columnas].compare("0")==0 || T[filas][columnas].compare("B")==0)
                blancas++;

            if(T[filas][columnas].compare("1")==0 || T[filas][columnas].compare("N")==0)
                negras++;
        }

Uno=blancas;
Dos=negras;
}
