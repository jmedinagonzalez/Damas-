#include "Comun.h"


bool HayUnaReinablanca(string T[10][10]){
    bool ok = false ;
    for(int fila =0 ;fila<9 ;fila++){
        for(int columna =0 ; columna<9 ; columna++){
            if(T[fila][columna].compare("B")==0){
                ok = true;
            }
        }
    }
    return ok;
}

bool SepuedeMover(string T[10][10], int x, int y) { // verifica si las  diagonales estan vacias para poder mover la pieza
    bool ok = false;
 	
    if ((T[x - 1][y - 1]).compare(" ") == 0 ){
    	
        ok = true;}
   
    if ((T[x - 1][y + 1]).compare(" ") == 0 ){
    
    	ok = true;
}
    return ok;
}

bool SepuedeMoverDer(string T[10][10], int x, int y) { // comprueba solo la diagonal derecha
    bool ok = false;
    if (((T[x][y]).compare("0") == 0)){
            if(y-1>=0 ){
            if ((T[x - 1][y - 1]).compare(" ") == 0 )
            ok = true;
        }
}
    return ok;
}

bool SepuedeMoverIzq(string T[10][10], int x, int y) { // comprueba solo la diagonal izquierda
    bool ok = false;
    if (((T[x][y]).compare("0") == 0)){
    if(y+1<=9){
        if((T[x - 1][y + 1]).compare(" ") == 0)
            ok=true;
    }
}
    return ok;
}

bool movimientovalido(string T[10][10], int x, int y) { //comprueba la posicion "x,y" y sus diagonales 
    bool ok = false;
         if (((T[x][y]).compare("0") == 0)){
            if(y-1>=0 ){
            if ((T[x - 1][y - 1]).compare(" ") == 0 && (T[x - 1][y - 1]).compare("0") != 0)
            ok = true;
        }
        if(y+1<=9){
        if((T[x - 1][y + 1]).compare(" ") == 0 && (T[x - 1][y + 1]).compare("0") != 0 )
            ok=true;}
        }
        if(T[x][y].compare("B")==0)
            ok = true;
    return ok;
}
void MoverPiezaCero(string T[10][10], int x, int y, string h) {// funcion utilizada por la maquina , que sirve para mover mediante movimientos validos 
    
    if (movimientovalido(T, x, y) && h.compare("derecha")) { // si la funcion recibe x,y,'derecha'  eliminara la pieza en la pos x,y y situara un nueva en la diagonal derecha
        T[x - 1][y - 1] = "0";
        T[x][y] = " ";
      
        cout<<"La Maquina Ha Movido A la derecha Desde : "<<x<<" , "<<y<<"  Hacia : "<<x-1<<" , "<<y-1<<endl<<endl;
        Mostrar(T);
    }
   		
    if (movimientovalido(T, x, y) && h.compare("izquierda")) { // si recibe "x,y,izquierda" , eliminara la figura en la pos x,y y situara una nueva en la diagonal izquierda
        T[x - 1][y + 1] = "0";
        T[x][y] = " ";
        cout<<"La Maquina Ha Movido A la izquierda Desde : "<<x<<" , "<<y<<"  Hacia : "<<x-1<<" , "<<y+1<<endl<<endl;
        Mostrar(T);
    }
}

void comer(string T[10][10],int x , int y){
    if(T[x + 1][y + 1].compare("1")==0 && T[x + 2][y + 2].compare(" ")==0)
        if(x + 2 <= 9 && y + 2 <= 9){
        T[x][y]=" ";
        T[x+2][y+2]="B";}

        if(T[x + 1][y - 1].compare("1")==0 && T[x + 2][y - 2].compare(" ")==0)
            if(x + 2 <= 9 && y - 2 >= 0){
                T[ x ][ y ]= " ";
                T[x + 2][y - 2]="B";}

                if( T[x - 1][y - 1].compare("1")==0 && T[x - 2][y - 2].compare(" ")==0)
                    if(x - 2 >= 0 && y - 2 >= 0){
                        T[x][y] = " ";
                        T[x - 2][y - 2] = "B";
                    }

                        if( T[x - 1][y + 1].compare("1")==0 && T[x - 2][y + 2].compare(" ")==0)
                            if(x - 2 >= 0 && y + 2 <= 9){
                            T[x][y]=" ";
                            T[x-2][y+2]="B";}



}
void movimientovalidoDamas(string T[10][10], int x , int y){

int i=1,a=0,q,w;
int mov[100],muv[100];

    if (T[x][y].compare("B") == 0){

        if(x+i <=9 && y-i >= 0)
        while(T[x+i][y-i].compare(" ")==0){
            comer(T,x+i,y-i);
            mov[a]=x+i;
            muv[a]=y-i;
            i++;
            a++;
        }
        i=1;
        if(x + i <= 9 && y + i <= 9 )
        while(T[x+i][y+i].compare(" ")==0){
            comer(T,x+i,y+i);
            mov[a]=x+i;
            muv[a]=y+i;
            i++;
            a++;
        }
        i=1;
        if( x - i >= 0 && y - i >= 0)
        while(T[x-i][y-i].compare(" ")==0){
            comer(T,x-i,y-i);
            mov[a]=x+i;
            muv[a]=y+i;
            i++; 
            a++;
        }
        i=1;
        if( x - i >= 0 && y + i <= 9)
        while(T[x-i][y+i].compare(" ")==0){
            comer(T,x-i,y+i);
            mov[a]=x+i;
            muv[a]=y+i;
            i++;
            a++;
        }
     i=1;
    int hora = time(NULL);
    srand(hora);
    int alazar = rand() % a;
    q = mov[alazar];
    w = muv[alazar];

    T[x][y]= " ";
    T[q][w]= "B";
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

        if(T[a][b].compare("B")==0){
            movimientovalidoDamas(T,a,b);}
            else{

        if(b==9 || b==0){
        	if(b==9)
        		MoverPiezaCero(T,a,b,"izquierda");
        	if(b==0)
        		MoverPiezaCero(T,a,b,"derecha");
        }
        else{
        if (SepuedeMoverDer(T, a, b) && SepuedeMoverIzq(T,a,b)) {
            if (SepuedeMoverDer(T, a, b)) {
            	
                MoverPiezaCero(T, a, b, "derecha");
            }

            if(SepuedeMoverIzq(T, a, b)) {
            	
                MoverPiezaCero(T, a, b, "izquierda");
            }
    
    	}
    	if(SepuedeMoverDer(T,a,b)){
    		MoverPiezaCero(T, a, b, "derecha");
    	}
    	if(SepuedeMoverIzq(T,a,b)){
    		MoverPiezaCero(T, a, b, "izquierda");
    	}
}
}
}
void comerpiezanegra(string T[10][10], int x, int y) { // segun lo comprobado por la funcion anterior , se procede a utilizar esta funcion para comer dicha pieza

    if (T[x][y] == "0" && T[x - 1][y + 1] == "1" && T[x - 2][y + 2] == " ") {
        T[x - 1][y + 1] = " ";
        T[x - 2][y + 2] = "0";
        T[x][y] = " ";
         cout<<"La jugador2 Ha Comido A La Pieza En La Posicion " <<x-1<<" , "<<y+1<<endl;
         cout<<"Desde la pieza en La posicion " <<x<<" , "<<y<<endl;
        Mostrar(T);

    }
    if (T[x][y] == "0" && T[x - 1][y - 1] == "1" && T[x - 2][y - 2] == " ") {
        T[x - 1][y - 1] = " ";
        T[x - 2][y - 2] = "0";
        T[x][y] = " ";
        cout<<"La Jugador 2 Ha Comido A La Pieza En La Posicion " <<x-1<<" , "<<y-1<<endl;
        cout<<"Desde la pieza en la posicion " <<x<<" , "<<y<<endl;
        Mostrar(T);
    }
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
void LamaquinaCome(string T[10][10]){

    for(int fila=0 ;fila<10 ; fila++){
            for(int columna=0 ; columna <10 ; columna++){
                if (puedecomerpiezanegra(T,fila,columna)) 
                    comerpiezanegra(T,fila,columna);
                    
                        
            }
        }
    }


