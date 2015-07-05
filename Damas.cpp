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

using namespace std;

int string2int(string texto) {
    int numero = -1;
    if (!texto.empty()) {
        numero = atoi(texto.c_str());
    }
    return numero;
}

vector<string> tokenizer(string texto) {
    vector<string> tokenes;
    if (!texto.empty()) {
        istringstream flujo(texto);
        string token;
        while (getline(flujo, token, ',')) {
            tokenes.push_back(token);
        }
    }
    return tokenes;
}

vector<int> numerizar(string texto) {
    vector<int> numeros;
    if (!texto.empty()) {
        istringstream flujo(texto);
        string token;
        while (getline(flujo, token, ',')) {
            int numero = string2int(token);
            numeros.push_back(numero);
        }
    }
    return numeros;
}

bool contiene(vector<string> arreglo, string elemento) {
    bool ok = false;
    if (find(arreglo.begin(), arreglo.end(), elemento) != arreglo.end()) {
        ok = true;
    }
    return ok;
}

void retornar(string T, int &x, int &y, string &h) {
    int L;
    char b[10];
    int i = 0;
    int asd[10];
    istringstream flujo(T);
    while (getline(flujo, T, ',')) {
        if (i < 2) {
            asd[i] = string2int(T);
        } else {
            h = T;
        }
        i++;
    }
    x = asd[0];
    y = asd[1];
}

bool SepuedeMover(string T[10][10], int x, int y) { // verifica si las  diagonales estan vacias para poder mover la pieza
    bool ok = false;
    if ((T[x - 1][y - 1]).compare(" ") == 0 || ((T[x - 1][y + 1]).compare(" ") == 0))
        ok = true;
    return ok;
}
bool movimientovalido(string T[10][10], int x, int y) { //comprueba la posicion "x,y" y sus diagonales 
    bool ok = false;
         if (((T[x][y]).compare("0") == 0)){
            if(y-1>=0 ){
            if ((T[x - 1][y - 1]).compare(" ") == 0 )
            ok = true;
        }
        if(y+1<=9){
        if((T[x - 1][y + 1]).compare(" ") == 0)
            ok=true;}
    }
    return ok;
}

bool movimientovalido2(string T[10][10], int x, int y) { //comprueba la posicion "x,y" y sus diagonales 
    bool ok = false;
    if (((T[x][y]).compare("1") == 0)){
            if(y-1>=0){
                        if ((T[x + 1][y - 1]).compare(" ") == 0 )
                            ok = true;}
            if(y+1<=9){
                        if((T[x + 1][y + 1]).compare(" ") == 0)
                            ok = true;}
        }
    return ok;
}
bool puedecomerpiezanegra(string T[10][10], int x, int y) { // comprueba si hay una posicion que puede comer una pieza rival
    bool ok = false;
    if (T[x][y].compare("0")==0){
        if(x-2>=0 && y-2>=0){
        if (T[x - 1][y - 1].compare("1")==0 && T[x - 2][y - 2].compare(" ")==0 ) {
            cout<<"La Maquina Comera A La Pieza En La Posicion : "<<x-1<<" , "<<y-1<<endl;
            ok = true;
        }
        }
    if(x-2>=0 && y+2<=9){
        if(T[x - 1][y + 1].compare("1") == 0 && T[x - 2][y + 2].compare(" ") == 0){
            cout<<"La Maquina Comera A La Pieza En La Posicion : "<<x-1<<" , "<<y+1<<endl;
            ok = true;}
       } 
    }
    return ok;
}
bool PuedecomerLaMaquina(string T[10][10]){
    bool ok=false;
    for(int fila=0 ;fila<10 ; fila++){
            for(int columna=0 ; columna <10 ; columna++){
                if (puedecomerpiezanegra(T,fila,columna)) {
                        ok=true;
            }
        }
    }
    return ok;
}


bool puedecomerpiezaBlanca(string T[10][10], int x, int y) { // comprueba si hay una posicion que puede comer una pieza rival
    bool ok = false;
    if (T[x][y].compare("1")==0){
        if(x+2<=9 && y-2>=0){
        if (T[x + 1][y - 1].compare("0")==0 && T[x + 2][y - 2].compare(" ")==0 ) {
            cout<<"Puedes Comer A La Pieza En La Posicion : "<<x+1<<" , "<<y-1<<endl<<endl<<endl;
            cout<<"Con La Pieza En La Posicion : "<<x<<","<<y<<endl<<endl;
            ok = true;
        }
        }
    if(x+2<=9 && y+2<=9){
        if(T[x + 1][y + 1].compare("0") == 0 && T[x + 2][y + 2].compare(" ") == 0){
            cout<<"Puedes Comer A La Pieza En La Posicion : "<<x+1<<" , "<<y+1<<endl<<endl;
            cout<<"Con La Pieza En  La Posicion : "<<x<<" , "<<y<<endl<<endl;
            ok = true;}
       } 
    }
    return ok;
}
bool Puedescomer(string T[10][10],int &x ,int &y){
    bool ok=false;
    for(int fila=0 ;fila<10 ; fila++){
            for(int columna=0 ; columna <10 ; columna++){
                if (puedecomerpiezaBlanca(T,fila,columna)) {
                        ok=true;
                        x=fila;
                        y=columna;
            }
        }
    }
    return ok,x,y ;
}

bool SepuedeMoverDer(string T[10][10], int x, int y) { // comprueba solo la diagonal derecha
    bool ok = false;
    if(y+1<=9){
    if (T[x][y].compare("0") == 0 && (T[x - 1][y - 1]).compare(" ") == 0) {
        cerr << "[" << x << "][" << y << "] = " << T[x][y] << endl;
        cerr << "[" << (x -1) << "][" << (y - 1) << "] = " << T[x -1][y -1] << endl;
        ok = true;
    }}
    return ok;
}

bool SepuedeMoverIzq(string T[10][10], int x, int y) { // comprueba solo la diagonal izquierda
    bool ok = false;
    if(y-1>=0){
    if (T[x][y].compare("0") == 0 && (T[x - 1][y + 1]).compare(" ") == 0) {
        cerr << "[" << x << "][" << y << "] = " << T[x][y] << endl;
        cerr << "[" << (x -1) << "][" << (y + 1) << "] = " << T[x-1][y+1] << endl;
        ok = true;
    }
}
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



void MoverPiezaCero(string T[10][10], int x, int y, string h) {// funcion utilizada por la maquina , que sirve para mover mediante movimientos validos 
    if(T[x][y].compare("0")== 1)
    if (movimientovalido(T, x, y) && h.compare("derecha")) { // si la funcion recibe x,y,'derecha'  eliminara la pieza en la pos x,y y situara un nueva en la diagonal derecha
        T[x - 1][y - 1] = "0";
        T[x][y] = " ";
      
        cout<<"La Maquina Ha Movido A la derecha Desde : "<<x<<" , "<<y<<"  Hacia : "<<x-1<<" , "<<y-1<<endl<<endl;
        Mostrar(T);
    }
    if(T[x][y].compare("0")==1)
    if (movimientovalido(T, x, y) && h.compare("izquierda")) { // si recibe "x,y,izquierda" , eliminara la figura en la pos x,y y situara una nueva en la diagonal izquierda
        T[x - 1][y + 1] = "0";
        T[x][y] = " ";
        cout<<"La Maquina Ha Movido A la izquierda Desde : "<<x<<" , "<<y<<"  Hacia : "<<x-1<<" , "<<y+1<<endl<<endl;
        Mostrar(T);
    }
}

void MoverPiezaUno(string T[10][10], int x, int y, string h) { // realiza lo mismo que la funcion anterior , solo que es con entrada por teclado 
    if(y-1>=0)
    if (movimientovalido2(T,x,y) && h.compare("derecha")) {
        T[x + 1][y - 1] = "1";
        T[x][y] = " ";
        Mostrar(T);
    }
     if(y+1<=9)
     if(movimientovalido2(T,x,y) && h.compare("izquierda")){
        T[x + 1][y + 1] = "1";
        T[x][y] = " ";
        Mostrar(T);
    }
} 

void QueMuevaLaMaquina(string T[10][10], int &a, int &b) { // utilizando gran parte de las funciones antes definidas , la maquina comprueba la cant de mov validos , y ejecuta uno 
    int i, j, z = 0, x[10], y[10];
    for (i = 0; i < 10; i++)
        for (j = 0; j < 10; j++) {
            if (movimientovalido(T, i, j)) {
                x[z] = i;
                y[z] = j;
                z++;
            }
        }
    int hora = time(NULL);
    srand(hora);
    int alazar = rand() % z;
    a = x[alazar];
    b = y[alazar];
    if (z > 0) {

        if (SepuedeMover(T, a, b)) {
            if (SepuedeMoverDer(T, a, b)) {
                MoverPiezaCero(T, a, b, "derecha");
            }

            if (SepuedeMoverIzq(T, a, b)) {
                MoverPiezaCero(T, a, b, "izquierda");
            }
        }
        else
        QueMuevaLaMaquina(T,a,b); 
    }
}
void convierteReina(string T[10][10]) {
    for (int y = 0; y < 10; y++) {
        if (T[0][y] == "0") {
            cout << "Se ha coronado una reina Para el equipo Blanco ." << endl;
            T[0][y] == "RB";
        }
        if (T[9][y] == "1") {
            cout << "Se Ha coronado una reina para el equipo negro ." << endl;
            T[9][y] == "RN";
        }
    }
}
void comerpiezanegra(string T[10][10], int x, int y) { // segun lo comprobado por la funcion anterior , se procede a utilizar esta funcion para comer dicha pieza

    if (T[x][y] == "0" && T[x - 1][y + 1] == "1" && T[x - 2][y + 2] == " ") {
        T[x - 1][y + 1] = " ";
        T[x - 2][y + 2] = "0";
        T[x][y] = " ";
        Mostrar(T);

    }
    if (T[x][y] == "0" && T[x - 1][y - 1] == "1" && T[x - 2][y - 2] == " ") {
        T[x - 1][y - 1] = " ";
        T[x - 2][y - 2] = "0";
        T[x][y] = " ";
        Mostrar(T);
    }
}
void LamaquinaCome(string T[10][10]){

    for(int fila=0 ;fila<10 ; fila++){
            for(int columna=0 ; columna <10 ; columna++){
                if (puedecomerpiezanegra(T,fila,columna)) 
                    comerpiezanegra(T,fila,columna);
                    
                        
            }
        }
    }


void SiNoComesTeComenParaBlancos(string T[10][10]) {
    for (int x = 0; x < 10; x++) {
        for (int y = 0; y < 10; y++) {
            if (T[x][y] == "0" && T[x - 1][y - 1] == "1" && T[x - 2][y - 2] == " ") {
                T[x - 1][y] = " ";
                T[x - 2][y - 2] = "0";
                T[x][y] = " ";
                cout << "TUVISTE LA OPORTUNIDAD DE COMER UNA PIEZA NEGRA " << endl;
                cout << "AL NO APROVECHAR SE HA PRODUCIDO UNA SOPLADITA QUE ES EL CASTIGO ,PERDER LA PIEZA, POR NO COMER ." << endl;
            }
        }
    }
}


void comerpiezablanca(string T[10][10], int x, int y) { // come pieza , segun por lo que le indican por teclado 
    if (T[x][y] == "1" && T[x + 1][y + 1] == "0" && T[x + 2][y + 2] == " ") {
        T[x + 1][y + 1] = " ";
        T[x + 2][y + 2] = "1";
        T[x][y] = " ";

    }
    if (T[x][y] == "1" && T[x + 1][y - 1] == "0" && T[x + 2][y - 2] == " ") {
        T[x + 1][y - 1] = " ";
        T[x + 2][y - 2] = "1";
        T[x][y] = " ";
    }
}
bool comerpiezablancaDere(string T[10][10],int x , int y){
    bool ok=false;
    if (T[x][y] == "1" && T[x + 1][y - 1] == "0" && T[x + 2][y - 2] == " ") {
        cout<<"Puede Comer Pieza Blanca santando a la derecha  "<<endl;
        ok = true;
    }
    return ok ;
}
bool comerpiezablancaIzqu(string T[10][10],int x , int y){
    bool ok=false;
    if (T[x][y] == "1" && T[x + 1][y + 1] == "0" && T[x + 2][y + 2] == " ") {
        cout<<"Puede Comer Pieza Blanca Saltando A la izquierda  "<<endl;
        ok=true;
    }
    return ok ;
}
void comerpiezablancaDer(string T[10][10],int x , int y){
    if (comerpiezablancaDere(T,x,y)) {
        T[x + 1][y - 1] = " ";
        T[x + 2][y - 2] = "1";
        T[x][y] = " ";
    }
}
void comerpiezablancaIzq(string T[10][10],int x , int y){
    if (comerpiezablancaIzqu(T,x,y)) {
        T[x + 1][y + 1] = " ";
        T[x + 2][y + 2] = "1";
        T[x][y] = " ";

    }
}
int main() {
    string A;
    string B,C;
    int x = 0, y = 0, i = 0, z = 0, piezas = 10;
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
                                if(comerpiezablancaIzqu(T,i,z))
                                    comerpiezablancaIzq(T,i,z);
                                        if(comerpiezablancaDere(T,i,z))
                                            comerpiezablancaDer(T,i,z);
                                
                                convierteReina(T);}
                                    if(C.compare("no")==0)
                                            {   
                                        cout << "Ingrese Movimiento Para Pieza Negra :" << endl;
                                        cin>>A;
                                        if (A.compare("exit") == 0)
                                            break;
                                            retornar(A, x, y, B);
                                            MoverPiezaUno(T, x, y, B);
                                            convierteReina(T);}
                                        }
                                            else
                                            cout<<"Opcion No Valida , Ud Pierde El Movimiento ."<<endl;
                                    }
            

            else{

                            cout << "Ingrese Movimiento Para Pieza Negra :" << endl;
                            cin>>A;
                            if (A.compare("exit") == 0)
                                break;
                            retornar(A, x, y, B);
                            MoverPiezaUno(T, x, y, B);
                            convierteReina(T);
        }

        cout << "La Maquina Esta pensando el movimiento ..." << endl;
        //sleep(2);
        if(PuedecomerLaMaquina(T))
                  LamaquinaCome(T);
          
            else
            QueMuevaLaMaquina(T, a, b);
        piezas--;
    } while (piezas > 0);
    
    // Resetamos a la salida original
    cerr.rdbuf(estandar);
    
    return 0;
}