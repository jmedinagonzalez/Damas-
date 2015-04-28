#include <cstring>
#include <stdlib.h>
#include <iostream>
using namespace std;
void Llenarlo(string T[10][10]){

    int i,j ;
    for ( i=0 ; i<10 ; i++){
        for(j=0 ; j<10 ;j++){
            
            if (i<3)
             T[i][j]="1";  
            if (i>6)
             T[i][j]="0"; 
            if(i>2 and i<7)
             T[i][j]=" ";
            
                 }

    }   
}
void retornar(string T ,int &x,int &y){
char L[1];char b[10];int z; char F[T.size()],Asd[1];

for(int i=0;i<T.size();i++){
L[0]=T[i];
if(strcmp(L,",")!=0)
cout<<L[0]<<endl;
cout<<"la Diferencia es : "<<strcmp(L,",")<<endl;
}}
void Mostrar(string T[10][10]){

    int i,j ;
    for ( i=0 ; i<10 ; i++){
        for(j=0 ; j<10 ;j++){
            
          cout<<"["<<T[i][j]<<"]";
                 }

            cout<<endl;

    }   
}

void MoverPieza (string T[10][10],int x, int y){
  
         if(T[x][y]!= " " && T[x+1][y]!= "1" )
         {
          T[x+1][y]= "1";
           T[x][y]=" ";
           Mostrar(T);
         }
          else
          cout<<"Movimiento Invalido Intente Otro"<<endl<<endl<<endl;     

}
int main()
{
    string A,b,c;
    int x,y,i,e;
    string T[10][10];
    int asd[10][10];
    Llenarlo(T);
    cout<<"ingrese movimiento :"<<endl;
    cin>>A;b=A[0];c=A[2];
    //x=atoi(b.c_str());
    //y=atoi(c.c_str());
   // MoverPieza(T,x-1,y-1);
   retornar(A,i,e);    
    return 0;
}



