#include <stdio.h>

      int tablero[8][8] = {0};
      int heuristica[8][8] = {22,22,22,22,22,22,22,22,
                              22,24,24,24,24,24,24,22,
                              22,24,26,26,26,26,24,22,
                              22,24,26,28,28,26,24,22,
                              22,24,26,28,28,26,24,22,
                              22,24,26,26,26,26,24,22,
                              22,24,24,24,24,24,24,22,
                              22,22,22,22,22,22,22,22 };
      
      int filaActual = 0;
      int columnaActual = 0;
      int reina = 0;
      int mejor = 30;
      int horizontal, vertical;
      int vertical_positivo, vertical_negativo;// variables para la diagonal //
      int casillas = 0; //variable para comprobar si está todo el tablero ocupado //
      
      while (casillas < 64)
      {
          casillas = 0;
          // revisa todo el tablero para ver la mejor posibilidad (se podría hacer función) //
            for(filaActual = 0; filaActual < 8; filaActual++)
            {
               for(columnaActual = 0; columnaActual < 8; columnaActual++)
               {
                    if( tablero[filaActual][columnaActual] == 0)
                    {
                        if( heuristica[filaActual][columnaActual] < mejor)
                        {
                            mejor = heuristica[filaActual][columnaActual];
                            horizontal = filaActual;
                            vertical = columnaActual;
                        }
                    }
               }
            }
            // fin revisar tablero //
            
            tablero[horizontal][vertical] = 5; // situa la reina en el tablero //
            
            for(columnaActual = 0; columnaActual < 8; columnaActual++)// marca el ataque horizontal de la reina actual (deja las casillas//
            {   
                if(tablero[horizontal][columnaActual] != 5 )
                {                                                     // horizontales ocupadas) //
                   tablero[horizontal][columnaActual] = 1;
                }
            }
            
            for(filaActual = 0; filaActual < 8; filaActual++) // marca el ataque vertical de la reina actual (deja las casillas verticales ocupadas) //
            {
                if ( tablero[filaActual][vertical] != 5 )
                {
                tablero[filaActual][vertical] = 1;
                }
            }
            
            // marca el ataque diagonal de la reina actual (deja las diagonales ocupadas //
           vertical_positivo = vertical;
           vertical_negativo = vertical;
           for(filaActual = horizontal - 1; filaActual >= 0; filaActual--)
            {
              vertical_positivo++;
              vertical_negativo--;
              if (vertical_positivo <= 7 && tablero[filaActual][vertical_positivo] != 5)
              {
                 tablero[filaActual][vertical_positivo] = 1;
              }
              if (vertical_negativo >= 0 && tablero[filaActual][vertical_negativo] != 5)
              {
                 tablero[filaActual][vertical_negativo] = 1;
              }  
            }
            
           vertical_positivo = vertical;
           vertical_negativo = vertical;
           for(filaActual = horizontal + 1; filaActual <= 7; filaActual++)
            {
              vertical_positivo++;
              vertical_negativo--;
              if (vertical_positivo <= 7 && tablero[filaActual][vertical_positivo] != 5)
              {
                 tablero[filaActual][vertical_positivo] = 1;
              }
              if (vertical_negativo >= 0 && tablero[filaActual][vertical_negativo] != 5)
              {
                 tablero[filaActual][vertical_negativo] = 1;
              }  
            }
            // fin ataque diagonal //
            
            // ajustar heuristica//
            
          for(filaActual = 0; filaActual < 8; filaActual++)
          {
            for(columnaActual = 0; columnaActual < 8; columnaActual++)
            {
               heuristica[filaActual][columnaActual] = 0;
            }
          }
            
            for (horizontal = 0; horizontal <= 7; horizontal++)
            {
                for(vertical = 0; vertical <= 7; vertical++)
                {
                   if (tablero[horizontal][vertical] != 1 && tablero[horizontal][vertical] != 5)
                   {
                        for(columnaActual = 0; columnaActual < 8; columnaActual++)// marca el ataque horizontal de la reina actual (deja las casillas horizontales ocupadas) //
                        {   
                            if(tablero[horizontal][columnaActual] != 5 && tablero[horizontal][columnaActual] != 1 )
                            {                                                     
                               heuristica[horizontal][vertical]++;
                            }
                        }
                        
                        for(filaActual = 0; filaActual < 8; filaActual++) // marca el ataque vertical de la reina actual (deja las casillas verticales ocupadas) //
                        {
                            if ( tablero[filaActual][vertical] != 5 && tablero[filaActual][vertical] != 1 )
                            {
                              heuristica[horizontal][vertical]++;
                            }
                        }
                        
                        // marca el ataque diagonal de la reina actual (deja las diagonales ocupadas //
                       vertical_positivo = vertical;
                       vertical_negativo = vertical;
                       for(filaActual = horizontal - 1; filaActual >= 0; filaActual--)
                        {
                          vertical_positivo++;
                          vertical_negativo--;
                          if (vertical_positivo <= 7 && tablero[filaActual][vertical_positivo] != 5 && tablero[filaActual][vertical_positivo] != 1)
                          {
                             heuristica[horizontal][vertical]++;
                          }
                          if (vertical_negativo >= 0 && tablero[filaActual][vertical_negativo] != 5 && tablero[filaActual][vertical_negativo] != 1)
                          {
                             heuristica[horizontal][vertical]++;
                          }  
                        }
                        
                       vertical_positivo = vertical;
                       vertical_negativo = vertical;
                       for(filaActual = horizontal + 1; filaActual <= 7; filaActual++)
                        {
                          vertical_positivo++;
                          vertical_negativo--;
                          if (vertical_positivo <= 7 && tablero[filaActual][vertical_positivo] != 5 && tablero[filaActual][vertical_positivo] != 1)
                          {
                             heuristica[horizontal][vertical]++;
                          }
                          if (vertical_negativo >= 0 && tablero[filaActual][vertical_negativo] != 5 && tablero[filaActual][vertical_negativo] != 1)
                          {
                             heuristica[horizontal][vertical]++;
                          }  
                        }
                        // fin ataque diagonal //
                   } 
                             
                }
            } // fin ajustar heuristica //
            
            
            mejor = 30; // reinicia 'mejor' para una nueva reina //
            reina++;
            // revisa el tablero para ver si estan todas las casillas ocupadas //
            for(filaActual = 0; filaActual < 8; filaActual++)
            {
               for(columnaActual = 0; columnaActual < 8; columnaActual++)
               {
                  if (tablero[filaActual][columnaActual] != 0)
                     casillas++;
               }
            } // fin revisar tablero//
            
      }
      // muestra el tablero //
      for(filaActual = 0; filaActual < 8; filaActual++)
      {
        for(columnaActual = 0; columnaActual < 8; columnaActual++)
        {
           printf("%d ",tablero[filaActual][columnaActual] );
        }
        printf("\n");
      }
      
      // muestra la heuristica //
      printf("\n");
      
      for(filaActual = 0; filaActual < 8; filaActual++)
      {
        for(columnaActual = 0; columnaActual < 8; columnaActual++)
        {
           printf("%2d ",heuristica[filaActual][columnaActual] );
        }
        printf("\n");
      }
      

