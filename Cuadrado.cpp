#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cassert>

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

void MoverPiezaUno(string T[10][10], int x, int y,string h) {

    if (T[x][y] != " " && T[x + 1][y] != "1" && h.compare("derecha")==0) {
        T[x + 1][y+1] = "1";
        T[x][y] = " ";
        Mostrar(T);
    } 
   if (T[x][y] != " " && T[x + 1][y] != "1" && h.compare("izquierda")==0) {
        T[x+1][y-1] = "1";
        T[x][y] = " ";
        Mostrar(T);}

}
void MoverPiezaCero(string T[10][10], int x, int y , string h) {

    if (T[x][y] != " " && T[x - 1][y] == "0" && h.compare("izquierda")) {
        T[x - 1][y-1] = "0";
        T[x][y] = " ";
        Mostrar(T);
    } if (T[x][y] != " " && T[x - 1][y] == "0" && h.compare("derecha")) {
        T[x - 1][y+1] = "0";
        T[x][y] = " ";
        Mostrar(T);
    }

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
}
else{
cout<<"No Existe Una Pieza Para Comer ."<<endl;}}
void comerpiezablanca(string T[10][10],int x , int y){
    if(T[x][y]=="1"&& T[x+1][y]=="0"&& T[x+2][y]==" "){
       T[x+1][y] = " ";
       T[x+2][y] = "0";
       T[x][y] = " ";
}
else{cout<<"No Existe Pieza Para Comer ."<<endl;}}
int main() {
    string A;
    string B;
    int x=0, y=0, i=0,z=0;
    string T[10][10];
    int asd[10];
    Llenarlo(T);
     do{
    cout << "Ingrese Movimiento Para Pieza Negra :" << endl;
    cin>>A;
     if(A.compare("comerpiezablanca")==0){
            cout << "Ingrese Posicion Pieza que come :" << endl;
            cin>>A;
            retornar(A,x,y,B);
        comerpiezablanca(T,x,y);
    }
    else{
    retornar(A,x,y,B);
    MoverPiezaUno(T,x-1,y,B);}
    cout<< " Ingrese Movimiento Para Piezas Blancas : "<<endl;
    cin>>A;
    if(A.compare("comerpiezanegra")==0){
             cout << "Ingrese Posicion Pieza que come :" << endl;
            cin>>A;
            retornar(A,x,y,B);
        comerpiezanegra(T,x,y);   
    }
    retornar(A,x,y,B);
    MoverPiezaCero(T,x-1,y,B);
    SiNoComesTeComenParaBlancos(T);
   
    }while(A.compare("exit")!= 0);
   
    
    return 0;
}