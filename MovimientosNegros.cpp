#include "Comun.h"

bool EstaLibre(string T[10][10],int x ,int y,int aumentado , string h)//La Funcion Estalibre verifica las diagonales 
//con los if dentro de los while pretendo que me retorne si la cant de espacios que intenta moverse la dama esta libre
{
    bool ok = false ;
    if(h.compare("AD")==0)//ABD = diagonal superior derecha
    {

    while(aumentado>0){
        if( T[x+aumentado][y+aumentado].compare(" ")==0){
            
            ok = true;
        }
       aumentado--;   
    }

    }
    if(h.compare("ABD")==0)//AD diagonal inferior derecha
    {

    while(aumentado>0){
        if( T[x-aumentado][y+aumentado].compare(" ")==0)
        {
            
            ok = true;
        }
       aumentado--;   
    }

}
    if(h.compare("ABI")==0)//diagonal inferior izquierda
    {

    while(aumentado>0){
        if( T[x-aumentado][y-aumentado].compare(" ")==0){
            
            ok = true;
        }
       aumentado--;   
    }

}
if(h.compare("AI")==0)//diagonal superior izquierda
{

    while(aumentado>0){
        if( T[x+aumentado][y-aumentado].compare(" ")==0)
        {
            ok = true;
        }
       aumentado--;   
    }

}
return ok ;

}

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
bool validar(string j){
    bool ok=false;
for(int asdf=0 ; asdf<j.size();asdf++)
    {
        if(j[asdf]==',')
            ok=true;
    }
    return ok;
}
void retornar(string T, int &x, int &y, string &h) {
    int L;
    char b[10];
    int i = 0;
    int asd[10];
    if(validar(T)){
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
                    y = asd[1];}
                    else
                        cout<<"Movimiento no permitido"<<endl;
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

void MoverPiezaUno(string T[10][10], int x, int y, string h) { // realiza lo mismo que la funcion anterior , solo que es con entrada por teclado 
    
        if(h.compare("izquierda")==0 ){
            if(T[x+1][y-1].compare(" ")==0){
                if(x+1<10){
                    if(y-1>=0){
            if (movimientovalido2(T,x,y)) {
            T[x + 1][y - 1] = "1";
            T[x][y] = " ";
            Mostrar(T);}
            }
            else{
                cout<<endl<<endl<<"¡Aviso!"<<endl<<endl<<endl;
                cout<<"Estas intentando hacer un movimiento no permitido para la ocasion"<<endl<<endl;
                cout<<"Movimiento anualado , pierdes la jugada"<<endl<<endl;}
        }
            else{
                cout<<endl<<endl<<"¡Aviso!"<<endl<<endl<<endl;
                cout<<"Estas intentando hacer un movimiento no permitido para la ocasion"<<endl;
                cout<<"Movimiento anualado , pierdes la jugada"<<endl<<endl;}
        }
            else{
                cout<<endl<<endl<<"¡Aviso!"<<endl<<endl<<endl;
                cout<<"Estas intentando hacer un movimiento no permitido para la ocasion"<<endl;
                cout<<"Movimiento anualado , pierdes la jugada"<<endl<<endl;}
    
}
     
        if(h.compare("derecha")==0 ){
        if(T[x+1][y+1].compare(" ")==0){
            if(x+1<10){
                if(y+1<10){
            if(movimientovalido2(T,x,y)){
            T[x + 1][y + 1] = "1";
            T[x][y] = " ";
            Mostrar(T);}
            }
            else{
                cout<<endl<<endl<<"¡Aviso!"<<endl<<endl<<endl;
                cout<<"Estas intentando hacer un movimiento no permitido para la ocasion"<<endl<<endl;
                
                cout<<"Movimiento anualado , pierdes la jugada"<<endl<<endl;}
    }
            else{
                cout<<endl<<endl<<"¡Aviso!"<<endl<<endl<<endl;
                cout<<"Estas intentando hacer un movimiento no permitido para la ocasion"<<endl<<endl;
                cout<<"Movimiento anualado , pierdes la jugada"<<endl;}            }
            else{
                cout<<endl<<endl<<"¡Aviso!"<<endl<<endl<<endl;
                cout<<"Estas intentando hacer un movimiento no permitido para la ocasion"<<endl<<endl;
                cout<<"Movimiento anualado , pierdes la jugada"<<endl<<endl;}

} 
}
void MoverReina(string T[10][10],int fila , int columna ){
    /* para Usar a la reina hay que posicionarse en ella 
     luego preguntara donde deseas moverte y se debe poner arriba,derecha,4
    eso significa 4 espacios en la diagonal superior derecha */
 string h,A,B;
 string k[3];
 int i=0,x;
            if(T[fila][columna].compare("N")==0)
            {
                cout<<"¿Hacia donde desea mover a la reina ?"<<endl;
                cin>>h;
                istringstream flujo(h);
                   while (getline(flujo, h, ',')){
                            if (i < 2) {
                                k[i] = h;} 
                            else
                            x = string2int(h);
                            i++;}
                            A = k[0];
                            B = k[1];
                }

              
/*
Para poder comer se debe colocar a la reina en la posicion de la pieza que se desea comer 
la funcion sola va a colocar a la reina atras y comera a la pieza */

        
        if(A.compare("arriba")==0 )//primmero compara si mueve hacia arriba o hacia abajo , luego compara izq o derecha 
        {   
            
            if(B.compare("izquierda")==0){
               
            if(T[fila-x][columna-x]== " ")
                if(fila-x>=0)
                    if(columna-x>=0){ 
            if(EstaLibre(T,fila,columna,x,"AI")==0)//este if lo que pretende es que si esta la diagonal completa libre , que se mueva solamente hacia ella 
            {
                            T[fila][columna] = " ";
                            T[fila-x][columna-x] = "N";
                            Mostrar(T);}}

                                        else
                                            cout<<"Movimiento Invalido "<<endl;
                                                        
            if(T[fila-x][columna-x]== "0" )
                if(fila-x-1>=0)
                    if(columna-x-1>=0){
            if(T[fila-x-1][columna-x-1]== " ")
            if(EstaLibre(T,fila,columna,x-1,"AI"))                                                              //este if , es para comprobar si la reina puede comer 
                                                                                                                // ya que para comer con la reina se debe posicionar sobre la pieza a comer
                                                                                                                //si esta la diagonal libre (excluyendo la pieza) y el espacio detras de la pieza esta libre la reina se comera la pieza        
            {
                        if(fila-x-1>=0 && columna-x-1>=0){
                            T[fila-x-1][columna-x-1] = "N";
                            T[fila-x][columna-x] = " ";
                            T[fila][columna] = " ";
                            Mostrar(T);}}

                            else
                                cout<<"Movimiento Invalido "<<endl;
        }
        }
        if(B.compare("derecha")==0){

            if(T[fila-x][columna+x]== " ")
                    if(fila-x>=0)
                                if(columna+x<10){
                    if(EstaLibre(T,fila,columna,x,"AD") ){
                     T[fila][columna]= " ";
                     T[fila-x][columna+x]= "N";
                     Mostrar(T);}
                 }

                                else
                                    cout<<"Movimiento Invalido "<<endl;


                if(T[fila-x][columna-x]== "0" )
                if(fila-x-1>=0)
                    if(columna+x+1<10){
                            if(T[fila-x-1][columna+x+1]== " ")
                            if(EstaLibre(T,fila,columna,x-1,"AD")){
                            T[fila-x-1][columna-x+1] = "N";
                            T[fila-x][columna+x] = " ";
                            T[fila][columna] = " ";
                            Mostrar(T);}}

                            else
                                cout<<"Movimiento Invalido "<<endl;
            
        }   
    
}
        if(A.compare("abajo")==0){
                if(B.compare("derecha")==0){
                    if(T[fila+x][columna+x]== " " )
                        if(fila+x<10)
                            if(columna+x<10){
                    if(EstaLibre(T,fila,columna,x,"ABD")==0)
                    {
                            T[fila][columna]= " ";
                            T[fila+x][columna+x] = "N";
                            Mostrar(T);
                    }
            }
                            else

                                cout<<"Movimiento Invalido "<<endl;

                if(T[fila+x][columna+x]== "0" )
                    if(fila+x+1<10)
                        if(columna+x+1<10){
                if(T[fila+x+1][columna+x+1]== " " )
                if(EstaLibre(T,fila,columna,x-1,"ABD")==0) {
                            T[fila+x+1][columna+x+1] = "N";
                            T[fila+x][columna+x] = " ";
                            T[fila][columna] = " ";
                            Mostrar(T);
                    }   
                    }
                    else 
                            cout<<"Movimiento Invalido ."<<endl;    
            }
            if(B.compare("izquierda")==0){
                        if(T[fila+x][columna-x]== " " )
                            if(fila+x<10)
                                if(columna>=0){
                        if(EstaLibre(T,fila,columna,x,"ABI")==0){
                        T[fila][columna] = " ";
                        T[fila+x][columna-x] = "N";
                        Mostrar(T);}
                    }
                    else
                        cout<<"Movimiento Invalido "<<endl;

            if(T[fila+x][columna-x]== "0")
            if(fila+x+1<10)
                if(columna-x-1>=0){ 
            if(T[fila+x+1][columna-x-1]== " ")
            if(EstaLibre(T,fila,columna,x-1,"ABI")==0){
                                T[fila+x+1][columna-x-1] = "N";
                                T[fila+x][columna-x] = " ";
                                T[fila][columna] = " ";
                                Mostrar(T);
                            }}

                                else
                                    cout<<"Movimiento Invalido "<<endl;
        } 
        }
}



bool HayUnaReinaNegra(string T[10][10]){
    bool ok = false ;
    for(int fila =0 ;fila<10 ;fila++){
        for(int columna =0 ; columna<10 ; columna++){
            if(T[fila][columna].compare("N")==0){
                ok = true;
            }
        }
    }
    return ok;
}



bool comerpiezablancaDere(string T[10][10],int x , int y){
    bool ok=false;
    if (T[x][y] == "1" && T[x + 1][y - 1] == "0" && T[x + 2][y - 2] == " ") {
        
        ok = true;
    }
    return ok ;
}
bool comerpiezablancaIzqu(string T[10][10],int x , int y){
    bool ok=false;
    if (T[x][y] == "1" && T[x + 1][y + 1] == "0" && T[x + 2][y + 2] == " ") {
       
        ok=true;
    }
    return ok ;
}
void comerpiezablancaDer(string T[10][10],int x , int y){
    if (comerpiezablancaDere(T,x,y)) {
        cout<<"Se Comerá una Pieza Blanca santando a la derecha  "<<endl;
        T[x + 1][y - 1] = " ";
        T[x + 2][y - 2] = "1";
        T[x][y] = " ";
        Mostrar(T);
    }
}
void comerpiezablancaIzq(string T[10][10],int x , int y){
    if (comerpiezablancaIzqu(T,x,y)) {
         cout<<"Se Comerá Una Pieza Blanca Saltando A la izquierda  "<<endl;
        T[x + 1][y + 1] = " ";
        T[x + 2][y + 2] = "1";
        T[x][y] = " ";
        Mostrar(T);

    }
}

void comerpiezablanca(string T[10][10], int x, int y) { // come pieza , segun por lo que le indican por teclado 
    if (T[x][y] == "1" && T[x + 1][y + 1] == "0" && T[x + 2][y + 2] == " ") {
        T[x + 1][y + 1] = " ";
        T[x + 2][y + 2] = "1";
        T[x][y] = " ";
        Mostrar(T);

    }
    if (T[x][y] == "1" && T[x + 1][y - 1] == "0" && T[x + 2][y - 2] == " ") {
        T[x + 1][y - 1] = " ";
        T[x + 2][y - 2] = "1";
        T[x][y] = " ";
        Mostrar(T);
    }
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