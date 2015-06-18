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

            if (i < 3 ){
                if(j%2==0 && i%2==0)
                T[i][j] = "1";
                else
                    T[i][j]= " ";
                 if(i%2 != 0 && j%2 != 0)
                T[i][j]= "1";
             }
            if (i > 6 ){
                  if(j%2==0 && i%2==0)
                T[i][j] = "0";
                else
                    T[i][j]= " ";
                 if(i%2 != 0 && j%2 != 0)
                T[i][j] = "0";}
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
    if (T[x][y]=="1" && T[x+1][y-1] == " " && h.compare("derecha")) {
        T[x+1][y-1] = "1";
        T[x][y] = " ";
        Mostrar(T);}
    
   if (T[x][y]=="1" && T[x+1][y+1]==" " && h.compare("izquierda")) {
        T[x+1][y+1] = "1";
        T[x][y] = " ";
        Mostrar(T);}
}

void SiNoComesTeComenParaBlancos(string T[10][10]){
    for(int x=0 ; x<10 ; x++){
    for(int y=0 ; y<10 ; y++){
    if(T[x][y]=="0"&& T[x-1][y-1]=="1"&& T[x-2][y-2]==" "){
       T[x-1][y] = " ";
       T[x-2][y-2] = "0";
       T[x][y] = " ";
       cout<<"TUVISTE LA OPORTUNIDAD DE COMER UNA PIEZA NEGRA "<<endl;
       cout<<"AL NO APROVECHAR SE HA PRODUCIDO UNA SOPLADITA QUE ES EL CASTIGO ,PERDER LA PIEZA, POR NO COMER ."<<endl;
    }
}}}
 bool puedecomerpiezanegra(string T[10][10],int x , int y ){
 bool ok = false;
  if((x-1>=0 )&& (x+1<=9) && (y-1>=0) && (y+1<10))
  if((T[x][y]).compare("0")==0 && (((T[x-1][y-1]).compare("1")==0 && (T[x-2][y-2]).compare(" ")==0 )|| T[x-1][y+1].compare("1")==0 && T[x-2][y+2].compare(" ")==0)){
       ok = true;
  }
  return ok;
}
void comerpiezanegra(string T[10][10],int x ,int y){

  if(T[x][y]=="0" && T[x-1][y+1]=="1"&& T[x-2][y+2]==" "){
       T[x-1][y+1] = " ";
       T[x-2][y+2] = "0";
       T[x][y] = " ";

}
if(T[x][y]=="0" && T[x+1][y-1]=="1"&& T[x+2][y-2]==" "){
       T[x-1][y-1] = " ";
       T[x-2][y-2] = "0";
       T[x][y] = " ";}
}
void comerpiezablanca(string T[10][10],int x , int y){
    if(T[x][y]=="1" && T[x+1][y+1]=="0"&& T[x+2][y+2]==" "){
       T[x+1][y+1] = " ";
       T[x+2][y+2] = "1";
       T[x][y] = " ";

}
if(T[x][y]=="1" && T[x+1][y-1]=="0"&& T[x+2][y-2]==" "){
       T[x+1][y-1] = " ";
       T[x+2][y-2] = "1";
       T[x][y] = " ";}}

bool SepuedeMover(string T[10][10],int x, int y){
  bool ok= false;
  if((T[x-1][y-1]).compare(" ")==0 || ((T[x-1][y+1]).compare(" ")==0) )
    ok=true;
  return ok;
}
bool SepuedeMoverDer(string T[10][10],int x,int y){
  bool ok=false;
  if((T[x-1][y-1]).compare(" ")==0)
    ok = true;
  return ok;
}
bool SepuedeMoverIzq(string T[10][10] , int x , int y){
  bool ok = false;
  if((T[x-1][y+1]).compare(" ")==0)
    ok = true;
  return ok;
}
bool movimientovalido(string T[10][10], int x, int y) {
    bool ok = false;
    if((x-1>=0 )&& (x+1<=9) && (y-1>=0) && (y+1<10))
    if (((T[x][y]).compare("0") == 0 ) && ((T[x - 1][y - 1]).compare(" ") == 0 || (T[x - 1][y + 1]).compare(" ") == 0)) {
        ok = true;
    }
    return ok;
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
int alazar =rand()%z;
a=x[alazar]; b=y[alazar];
if(z>0){
  cout<<z<<endl;
  if(SepuedeMover(T,a,b)){
            cout<<"entro ."<<endl;
            if(SepuedeMoverDer(T,a,b)){
              cout<<"entro Derecha."<<endl;
              MoverPiezaCero(T,a,b,"derecha");}
        
            if(SepuedeMoverIzq(T,a,b)){
              cout<<"entro Izquierda."<<endl;
            MoverPiezaCero(T,a,b,"izquierda");}
    }
    else {
      cout<<"no entro ."<<endl;
      QueMuevaLaMaquina(T,a,b);}
           }
}
void convierteReina(string T[10][10]){
    for(int y=0 ;y<10 ; y++){
    if(T[0][y]=="0"){
        cout<<"Se ha coronado una reina Para el equipo Blanco ."<<endl;
         T[0][y]=="RB";
    }
    if(T[9][y]=="1"){
    cout<<"Se Ha coronado una reina para el equipo negro ."<<endl;
    T[9][y]=="RN";
    }
}
}

int main() {
    string A;
    string B;
    int x=0, y=0, i=0,z=0,piezas=10;
    string T[10][10],puede;
    int asd[10],a,b;
    int hora=time(NULL);
    srand(hora);
    int alazar =rand()%2;
    Llenarlo(T);
    Mostrar(T);
 do{
    cout << "Ingrese Movimiento Para Pieza Negra :" << endl;
    cin>>A;
    if(A.compare("exit")==0){
      break;}else{
     if(A.compare("comerpiezablanca")==0){
            cout << "Ingrese Posicion Pieza que come :" << endl;
            cin>>A;
            retornar(A,x,y,B);
        comerpiezablanca(T,x,y);}
    else{
    retornar(A,x,y,B);
    MoverPiezaUno(T,x,y,B);
     convierteReina(T);
     SiNoComesTeComenParaBlancos(T);}}
    

 cout<<"La Maquina Esta pensando el movimiento ..."<<endl;  
 sleep(3);
if(puede.compare("SI")==0){
  cout<<a<<","<<b<<endl;
  puede="NO";
  Mostrar(T);
  comerpiezanegra(T,a,b);}
else{
QueMuevaLaMaquina(T,a,b);
   for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
              if(puedecomerpiezanegra(T,i,j)){
                a=i;
                b=j;
                 puede="SI";}}}}
 
piezas--;
}while(piezas>0);
    return 0;
}