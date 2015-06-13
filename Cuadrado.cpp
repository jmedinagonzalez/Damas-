#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cassert>
#include <unistd.h>

using namespace std;
char blanco = 178;
char negro = 177; 
int contador = 1;
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

void Llenarlo(string T[10][10]) {

    int i, j;
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {

            if (i < 3)
                T[i][j] = "1";
            if (i > 6)
                T[i][j] = "0";
            if (i > 2 and i < 7)
                T[i][j] = " ";

        }

    }
}

void retornar(string T,int &x ,int &y, string &h) {
    int L;
    char b[10];
    int i=0;
    int asd[10];
    istringstream flujo(T);
    while(getline(flujo,T,',')){ 
        if(i<2){
        asd[i]=string2int(T);
         }
        else{
        h=T;}
        i++;
    }
x=asd[0]; y=asd[1];
}

void Mostrar(string T[10][10]) {

    int i, j;
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {

            cout << "[" << T[i][j] << "]";
        }

        cout << endl;

    }
    cout<<endl<<endl<<endl;
}


void MoverPiezaCero(string T[10][10], int x, int y,string h) {
    if (T[x][y]=="0" && T[x-1][y-1] == " " && h.compare("derecha")) {
        T[x-1][y-1] = "0";
        T[x][y] = " ";
        Mostrar(T);}
    
   if (T[x][y] == "0" && T[x-1][y+1] == " " && h.compare("izquierda")) {
        T[x-1][y+1] = "0";
        T[x][y] = " ";
        Mostrar(T);}
}

void MoverPiezaUno(string T[10][10], int x, int y,string h) {
    if (T[x][y]=="1" && T[x+1][y-1] == " " && h.compare("derecha") && y-1>0) {
        T[x+1][y-1] = "1";
        T[x][y] = " ";
        Mostrar(T);}
    
   if (T[x][y] == "1" && T[x+1][y+1] == " " && h.compare("izquierda") && y+1<10) {
        T[x+1][y+1] = "1";
        T[x][y] = " ";
        Mostrar(T);}
}
void moverpiezaceroDerecha(string T[10][10], int x, int y ) {
        T[x-1][y-1] = "0";
        T[x][y] = " ";
       }
void MoverPiezaCeroIzquierda(string T[10][10],int x,int y){
        T[x-1][y+1] = "0";
        T[x][y] = " ";
}
void SiNoComesTeComenParaBlancos(string T[10][10]){
    for(int x=0 ; x<10 ; x++){
    for(int y=0 ; y<10 ; y++){
    if(T[x][y]=="0"&& T[x-1][y]=="1"&& T[x-2][y]==" "){
       T[x-1][y] = " ";
       T[x-2][y] = "0";
       T[x][y] = " ";
    }
}}}
 void comerpiezanegra(string T[10][10],int x , int y){
    if(T[x][y]=="0"&& T[x-1][y]=="1"&& T[x-2][y]==" "){
       T[x-1][y] = " ";
       T[x-2][y] = "0";
       T[x][y] = " ";
}}
void comerpiezablanca(string T[10][10],int x , int y){
    if(T[x][y]=="1" && T[x+1][y]=="0"&& T[x+2][y]==" "){
       T[x+1][y] = " ";
       T[x+2][y] = "0";
       T[x][y] = " ";
}}



bool movimientovalido (string T[10][10],int x ,int y){
    
    if(T[x][y].compare("0")==0 && (T[x-1][y-1].compare("0")!=0) && (T[x-1][y+1].compare("0")!=0) && y+1<10){
    return true;}
}

void QueMuevaLaMaquina(string T[10][10] ,int &a , int &b){
int i,j,z=0,x[10],y[10];
for(i=0 ; i<10 ; i++)
    for(j=0 ; j<10 ; j++){
     if(movimientovalido(T,i,j)){
         x[z]=i;
         y[z]=j;
         z++;
         }
}
int hora=time(NULL);
srand(hora);
int alazar =rand()%10;
a=x[alazar]; b=y[alazar];

/*
if (movimientovalido(T,a[alazar],b[alazar]) && (alazar%2!=0)){
    MoverPiezaCeroIzquierda(T,a[alazar],b[alazar]);}
if(movimientovalido(T,a[alazar],b[alazar])== false){
   z=0;
   cout<<"No Quedan Movimientos a realizar ."<<endl;
}*/
}




int main() {
    string A;
    string B;
    int x=0, y=0, i=0,z=0;
    string T[10][10];
    int asd[10],a,b;
    int hora=time(NULL);
    srand(hora);
    int alazar =rand()%10;
    Llenarlo(T);
    Mostrar(T);
    do{
    cout << "Ingrese Movimiento Para Pieza Negra :" << endl;
    cin>>A;
     if(A.compare("comerpiezablanca")==0){
            cout << "Ingrese Posicion Pieza que come :" << endl;
            cin>>A;
            retornar(A,x,y,B);
        comerpiezablanca(T,x,y);}
    else{
    retornar(A,x,y,B);
    MoverPiezaUno(T,x,y,B);}
 cout<<"La Maquina Esta pensando el movimiento ..."<<endl;  
 sleep(3);
QueMuevaLaMaquina(T,a,b);
if(alazar%2==0){
    comerpiezanegra(T,a,b);
MoverPiezaCero(T,a,b,"derecha");}
else{
    comerpiezanegra(T,a,b);
    MoverPiezaCero(T,a,b,"izquierda");}
}while(A.compare("exit")!= 0);
    return 0;
}