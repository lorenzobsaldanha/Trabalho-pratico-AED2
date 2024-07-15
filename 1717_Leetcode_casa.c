int maximumGain ( char* s, int x, int y ) {
     int total = 0, i, j,  tam, cont = 0, verifica, tamCopia;
    char *copia, *fim;
   
    
    for( i=0; s[i]; i++ ){
		if( s[i] == 'b' )
		cont++;
    }
    tam = i;
   
    copia = ( char* ) malloc ( sizeof( char ) *tam + 1 );
    fim = ( char* ) malloc ( sizeof ( char ) *tam + 1 );
   
    for( i = 0 ; s[i]; i++ ){
		copia[i] = s[i];
	}
tamCopia = i;

 if( x >= y ){//remove todos ab antes dos ba
     
     verifica = 0;
     while( verifica < cont ) {
		 j = 0;
		 
      for( i = 0; i < tamCopia; i++ ){
   
      
        if( copia[i] == 'a' && copia[ i + 1 ] == 'b' ){
            total = total + x;
         
         copia[i] = '1';
          copia[ i + 1 ] ='1';  // o '1'anula a letra pra nao repetir a soma no ultimo ab
           i += 2;// PULA o b
         }
           if( copia[i] != '1' ){
          fim[j] = copia[i];
          j++;
        }
        
      } 
      free( copia );
      copia = ( char* ) malloc ( sizeof( char ) * tam + 1 );
 for( i = 0; i < j; i++ ){
	 copia[i] = fim[i];
 }
tamCopia = i;
  verifica ++;
   } // fim do while aqui                  
    
     cont = 0;     //diminui a repeticao do while()
         for( i = 0; i < tamCopia; i++ ){    
		if( copia[i] == 'a' )
		cont ++;
    }
  
       verifica = 0;                
 while( verifica < cont ){    
	 j = 0;
      for( i = 0; i < tamCopia; i++ ){
      
        if( copia[i] == 'b' && copia[i + 1] == 'a' ){
            total = total + y;
            
      
           copia[i] = '1';
           copia[i + 1] = '1';
           i += 2;
        }
          if( copia[i] != '1' ){
          fim[j] = copia[i];
          j ++;
        }
      }
     
      for( i = 0; i < j; i++ ){
		  copia[i] = fim[i];
	  }

    verifica ++;
     } // fim do while aqui
    } //fim do (x>=y)
    



	 //comeca o x<y aqui
    if( x < y ){//remove todos ba antes dos ab
     verifica = 0;
    while( verifica < cont ){
		j = 0;
       
      for( i = 0; i < tamCopia; i++ ){
     
        if( copia[i] == 'b' && copia[i + 1] == 'a' ){
            total = total + y;
            
      
           copia[i] = '1';
            copia[i + 1] = '1';
           i += 2;
        }
          if( copia[i] != '1' ){
          fim[j] = copia[i];
          j ++;
        }
      }
 free( copia );
      copia = ( char* ) malloc ( sizeof( char ) * tam + 1 );
     for( i = 0; i < j; i++ ){
		 copia[i] = fim[i];
	 }
     tamCopia = i;
 verifica ++; 
     } // fim do while aqui
     cont = 0;  //diminui a repeticao do while
              for( i = 0; i < tamCopia; i++ ){    
		if( copia[i] == 'a' )
		cont ++;
    }
      verifica = 0;
 while( verifica < cont ){
	 j = 0;
      for( i = 0; i < tamCopia; i++ ){
       
        if( copia[i] == 'a' && copia[i + 1] == 'b' ){
            total = total + x;
            
      
           copia[i] = '1';
            copia[i + 1] = '1';
           i += 2;
        }
        if( copia[i] != '1' ){
          fim[j] = copia[i];
          j ++;
        }
      }
  
      for( i = 0; i < j; i++ ){
		  copia[i] = fim[i];
	  }
    verifica ++; 
     } // fim do while aqui

    }

    return( total );
}