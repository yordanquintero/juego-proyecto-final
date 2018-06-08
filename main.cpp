#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <conio.h>



void gotoxy(int x,int y){
    HANDLE hcon=GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwpos;
    dwpos.X=x;
    dwpos.Y=y;
    SetConsoleCursorPosition(hcon, dwpos);
}

void cuadro(){
	int i;
	//Horizontales
	for(i = 1; i < 50; i++){
		gotoxy(i, 1); printf("%c", 205); //Horizontales Superiores
		gotoxy(i, 20); printf("%c", 205);//Horizontales Inferiores
	}
	//Verticales
	for(i = 2; i < 20; i++){
		gotoxy(1, i); printf("%c", 186); //Verticales Izquierda
		gotoxy(50, i); printf("%c", 186);//Verticales Derecha
	}
	//Esquinas
	gotoxy(1, 1); printf("%c", 201);
	gotoxy(1, 20); printf("%c", 200);
	gotoxy(50, 1); printf("%c", 187);
	gotoxy(50, 20); printf("%c", 188);
}
void cuadro2(){
	int i;
	//Horizontales
	for(i = 1; i < 111; i++){
		gotoxy(i, 0); printf("%c", 205); //Horizontales Superiores
		gotoxy(i, 25); printf("%c", 205);//Horizontales Inferiores
	}
	//Verticales
	for(i = 1; i < 25; i++){
		gotoxy(0, i); printf("%c", 186); //Verticales Izquierda
		gotoxy(111, i); printf("%c", 186);//Verticales Derecha
	}
	//Esquinas
	gotoxy(0, 0); printf("%c", 201);
	gotoxy(0, 25); printf("%c", 200);
	gotoxy(111,0); printf("%c", 187);
	gotoxy(111, 25); printf("%c", 188);
}
void imprimir();
void imprimir_nivel2();
void imprimir_nivel3();
void borrar(int,int );
void iniciar();
void iniciar_nivel2();
void iniciar_nivel3();
void wait(int );
void menu();
void intro();
void batalla();
void batalla_nivel2();
void batalla_nivel3();
void guardar();
FILE *archivo;

int  i, j, k, jugador[100][100], oponente[100][100],opcion, opcion1, opcion2, puntajeoponente=0,auxiliar,destruidosoponentes=0,destruidosjugador,destruidosoponentes_nivel2=0,destruidosjugador_nivel2,probabilidad,nivel=1;
float dificultad=0.5;

struct jugadores{
char nombre[30];
int puntajejugador=0;

}jugadorr;

int main(){

system("color 0A");
intro();
menu();



    return 0;
}
void menu(){



do{
printf("                                                                                \n");
printf(" ...............................................................................\n");
printf(" ...............................................-::+++*:........................\n");
printf(" ...................*.....*-......=-...-::.....:+.....-*........................\n");
printf(" ...................*----:*:......*:++**=*.....-#==**++*........................\n");
printf(" ...................*.....::......*......*.....-*......*........................\n");
printf(" ...................*.....::......*......*......*......=..-.....................\n");
printf(" ................-:+=*=======*=*=******++::-......:+-.......*...................\n");
printf(" ................=...:++++-........++*++-.......:++:++......*...................\n");
printf(" ................=...*:..++.......-+-..+*.......++..-++.....*...................\n");
printf(" ................=...++..++........++.-++.......:+++++......*-..................\n");
printf(" ................#....++++..........:++-...----:::*=++++++++=+:+++++*+++++**=**+\n");
printf(" .--:++*+*+***++:-.----::----.................................................:+\n");
printf(" .=..........................................................................::.\n");
printf(" .-+...............----------:::++++++:::++++*************+++*****+++::----.*-..\n");
printf(" ..+:......................................................................=....\n");
printf(" ...*....................................................................-*.....\n");
printf(" ....*..................................................................-+......\n");
printf(" ....-*................................................................+:.......\n");
printf(" .....:+.............................................................-*.........\n");
printf(" ......:+...........................................................*:..........\n");
printf(" .......-*........................................................:*............\n");
printf(" .........++...................................................-**..............\n");
printf(" ...........-+*==*****+***+*********+++++************+**+***+:..................\n");
printf(" ...............................................................................\n");
printf("                                                                                \n");

cuadro2();
gotoxy(89,1); printf("BATALLA NAVAL\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");


 gotoxy(89,3); printf("1.JUGAR");
 gotoxy(89,5);   printf("2.SALIR\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
 gotoxy(89,7); printf("dame una opcion: ");
 scanf("%d",&opcion);

    system("cls");
    switch(opcion){
    case 1:iniciar();
            break;
    case 2:exit(0);
            break;
   default: gotoxy(20,10); printf("OPCION INCORRECTA\n\n");
   system("pause");
   system("cls");










    }


}while(opcion!=0);

system("cls");


}
void intro(){

printf(" _______  _______  _______  _______  ___      ___      _______    __    _  _______  __   __  _______  ___     \n");
printf("|  _    ||   _   ||       ||   _   ||   |    |   |    |   _   |  |  |  | ||   _   ||  | |  ||   _   ||   |    \n");
printf("| |_|   ||  |_|  ||_     _||  |_|  ||   |    |   |    |  |_|  |  |   |_| ||  |_|  ||  |_|  ||  |_|  ||   |    \n");
printf("|       ||       |  |   |  |       ||   |    |   |    |       |  |       ||       ||       ||       ||   |    \n");
printf("|  _   | |       |  |   |  |       ||   |___ |   |___ |       |  |  _    ||       ||       ||       ||   |___ \n");
printf("| |_|   ||   _   |  |   |  |   _   ||       ||       ||   _   |  | | |   ||   _   | |     | |   _   ||       |\n");
printf("|_______||__| |__|  |___|  |__| |__||_______||_______||__| |__|  |_|  |__||__| |__|  |___|  |__| |__||_______|\n");

printf("\n\t    \n\n\t\t#\n\t\t#|\n\t\t#|#\n\t\t#|##\n\t\t#|###\n\t\t#|####");
printf("\n\t\t#|#####\n\t\t#|######\n\t#########################\n\t _______________________");
printf("\n\t  ####/)###############\n\t   ###(/##############\n\t    #################\n\t     ###############");
 wait(4);
 system("cls");
}

void imprimir (){
    printf("\t\t\tBATALLA");
    printf("\n\n");

  for(i=1;i<=5;i++){ // Imprime tablero del oponente
        printf("\n\t\t");
        for(j=1;j<=9;j++){
            if(oponente[i][j]==1){
                printf(" #");
            }else{
                if(oponente[i][j]==2){// Imprime 'X' si vale 2

                    printf(" x");
                }else{
                    printf(" -");
                }
            }
        }

    }

        printf("\n\t\t____________________\n");
        gotoxy(38,4);  printf("OPONENTE ");
        printf("\n\n\n\n\n");
   for(i=1;i<=5;i++){ // Imprime el tablero del jugador

        printf("\n\t\t");
        for(j=1;j<=9;j++){
            if(jugador[i][j]==3){
                printf(" #");

            }
            else{
                if(jugador[i][j]==2){ // Imprime 'X' si vale 2 || 'O' si vale 1

                    printf(" x");
                }
                else{
                    if(jugador[i][j]==1){

                        printf(" O");
                    }
                    else{
                        printf(" -");
                    }
                }
            }
        }

    }

    printf("\n\n");
gotoxy(38,11); printf("JUGADOR ");

 gotoxy(54,12); printf("PUNTOS: %d",jugadorr.puntajejugador);
 gotoxy(54,4); printf("PUNTOS: %d",puntajeoponente);


    }

void borrar(int x,int y){
    gotoxy(x,y); printf("  ");
}





void iniciar(){// Rellena con '0' el arreglo y coloca los barcos
        destruidosjugador=0;
        destruidosoponentes=0;
       jugadorr.puntajejugador=0;
       puntajeoponente=0;
            cuadro();
    gotoxy(8,4);printf("ingresa tu nombre: ");
                fflush(stdin);
                fgets(jugadorr.nombre,30,stdin);
            system("cls");

    gotoxy(8,5); printf(" ingresa las cordenadas de tus barcos \n\n");
    printf("\t\t\t%s",jugadorr.nombre);
            cuadro();
            wait(4);

    system("cls");
    for(i=1;i<=5;i++){ // Llena todo con '0'
        for(j=1;j<=9;j++){
            jugador[i][j]=0;
            oponente[i][j]=0;

        }
    }

    srand(time(0));

    for(k=1;k<=5;k++){ // Distribuye los barcos
        imprimir();

        cuadro();

        i=1+rand()%5; // Distribuye los barcos oponentes
        j=1+rand()%9;
        while(oponente[i][j]==1){
            i=1+rand()%5; j=1+rand()%9;
        }
                oponente[i][j]=1; // La posicion de los barcos valdra 1

            gotoxy(2,17); printf("dame las cordenadas de tus 5 barcos x%d=   y%d=   \n\n\n",k,k);
            gotoxy(41,17); scanf("%d",&opcion2);
            gotoxy(47,17); scanf("%d",&opcion1);

        while(opcion2<1 || opcion2>9){
            printf("    Escoje un valor valido ( 1 a 9 )\n\tX%d", k);
            borrar(41,17);
            cuadro();
             gotoxy(41,17); scanf("%d", &opcion2);

        }


            gotoxy(2,17); printf("dame las cordenadas de tus 5 barcos x%d=   y%d=   \n\n\n",k,k);


        while(opcion1<1 || opcion1>5){

            printf("\n    Escoje un valor valido ( 1 a 5 )\n\tY%d", k);
            borrar(47,17);
            gotoxy(47,17); scanf("%d", &opcion1);

        }

        if(jugador[opcion1][opcion2]==1){
            gotoxy(2,18);  printf("Ese valor ya existe...\n");
            system("pause");
            k=k-1;
            oponente[i][j]=oponente[i][j]-1;
        }
         jugador[opcion1][opcion2]=1;

        system("cls");


    }
        imprimir();

        cuadro();

        printf("\n\n\n");
         batalla();

}
void wait(int seconds){ // Funcion 'clock' para el tiempo de juego

    clock_t endwait;
    endwait = clock() + seconds * CLOCKS_PER_SEC;
    while( clock() < endwait )
    {}
}


void batalla(){

        system("cls");
        cuadro();
gotoxy(14,5); printf(" Preparado para la batalla?\n\n");
           wait(2);
           printf("\n\t\t\tAHORA!!!");
           wait(1);
           system("cls");
            imprimir();
            cuadro();


                do{
                    system("cls");
                    imprimir();
                    cuadro();

          gotoxy(2,17);  printf("ataca! dame la posicion que quieres atacar\n");
          gotoxy(2,18); printf("X= ");
            scanf("%d",&opcion2);
            while(opcion2<1 || opcion2>9){
              gotoxy(2,19);  printf("escoje un valor valido (1 a 9)");
                borrar(5,18);
               gotoxy(5,18); scanf("%d",&opcion2);
            }
              gotoxy(8,18); printf("Y= ");
              scanf("%d",&opcion1);
              while(opcion1<1||opcion1>5){
                 gotoxy(2,19);  printf("escoje un valor valido (1 a 5)");
                   borrar(11,18);
                gotoxy(8,18); printf("Y= ");
                gotoxy(11,18); scanf("%d",&opcion1);
              }


                auxiliar=oponente[opcion1][opcion2];
                oponente[opcion1][opcion2]=3;
                system("cls");
                imprimir();
                cuadro();
                printf("\n");
                system("pause");
                oponente[opcion1][opcion2]=auxiliar;

                if(oponente[opcion1][opcion2]==1){
                    destruidosoponentes=destruidosoponentes+1;
                    oponente[opcion1][opcion2]=2;
                    jugadorr.puntajejugador=jugadorr.puntajejugador+300;
                    system("cls");
                    imprimir();
                    cuadro();
                   gotoxy(3,19); printf("haz acertado!!\n\n\n");
                }else{
                     system("cls");
                    imprimir();
                    cuadro();
                    gotoxy(3,19); printf("haz fallado...\n\n\n");
                }

                system("pause");


                if(destruidosoponentes==5){
                system("cls");
                cuadro();
                gotoxy(20,10);  printf("HAZ GANADO!!\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
                wait(4);
                iniciar_nivel2();
                }


                system("cls");
                imprimir();
                cuadro();
              gotoxy(2,17); printf("turno del oponente         \n");
               wait(2);


        dificultad=dificultad+0;
               srand(time(0));
               probabilidad=rand()%5;


               if(probabilidad>dificultad){
                   i=1+rand()%5;
                   j=1+rand()%9;
                   while(jugador[i][j]==2){
                       i=1+rand()%5; j=1+rand()%9;
                   }
                   auxiliar=jugador[i][j];
               }else{
                   while(jugador[i][j]==2 || jugador[i][j]!=1){
                       i=1+rand()%5; j=1+rand()%9;
                   }
                   auxiliar=jugador[i][j];
               }
                jugador[i][j]=3;
               opcion1=i;
               opcion2=j;
               system("cls");
               imprimir();
               jugador[opcion1][opcion2]=auxiliar;

               if(jugador[opcion1][opcion2]==1){


                   jugador[opcion1][opcion2]=2;
                   destruidosjugador=destruidosjugador+1;
                   puntajeoponente=puntajeoponente+300;
                    system("cls");
                    imprimir();
                    cuadro();
               gotoxy(3,19); printf("El oponente ha acertado!!\n\n\n");
               system("pause");


            }else{

                    cuadro();
                  gotoxy(3,19);  printf("El oponente ha fallado...                     \n\n");
                    system("pause");
                    system("cls");
               }
                if(destruidosjugador==5){
                system("cls");
                cuadro();
                gotoxy(20,10);  printf("HAZ PERDIDO :c \n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
                wait(4);
                guardar();
                exit(0);
                }



                }while(destruidosoponentes<5||destruidosjugador<5);


}


void guardar(){
    char direccion[]="D:\\archivo\\batalla_naval.txt";
   archivo=fopen(direccion,"w");
   if(archivo==NULL){
    printf("no se pudo guardar el archivo");
   }else{
       printf("se guardo el archivo\n");
       printf("ubicacion: %s\n",direccion);
   }

    fprintf(archivo,"nombre: %s",jugadorr.nombre);
    fprintf(archivo,"puntaje: %d\n",jugadorr.puntajejugador);
    fprintf(archivo,"------------------ nivel: %d\n",nivel);
    fprintf(archivo,"oponente\n");
    fprintf(archivo,"puntaje: %d",puntajeoponente);

    fclose(archivo);


}
void iniciar_nivel2(){// Rellena con '0' el arreglo y coloca los barcos
        destruidosjugador_nivel2=0;
        destruidosoponentes_nivel2=0;
        puntajeoponente=0;
       jugadorr.puntajejugador=0;
       nivel=2;
            cuadro();

            system("cls");

gotoxy(23,4);printf("NIVEL 2");
cuadro();
        wait(3);

    system("cls");
    for(i=1;i<=6;i++){ // Llena todo con '0'
        for(j=1;j<=10;j++){
            jugador[i][j]=0;
            oponente[i][j]=0;

        }
    }

    srand(time(NULL));

    for(k=1;k<=8;k++){ // Distribuye los barcos
        imprimir_nivel2();

        cuadro();

        i=1+rand()%6; // Distribuye los barcos oponentes
        j=1+rand()%10;
        while(oponente[i][j]==1){
            i=1+rand()%6; j=1+rand()%10;
        }
                oponente[i][j]=1; // La posicion de los barcos valdra 1

            gotoxy(2,17); printf("dame las cordenadas de tus 8 barcos x%d=   y%d=   \n\n\n",k,k);
            gotoxy(41,17); scanf("%d",&opcion2);
            gotoxy(47,17); scanf("%d",&opcion1);

        while(opcion2<1 || opcion2>10){
            printf("    Escoje un valor valido ( 1 a 10 )\n\tX%d", k);
            borrar(41,17);
            cuadro();
             gotoxy(41,17); scanf("%d", &opcion2);

        }


            gotoxy(2,17); printf("dame las cordenadas de tus 8 barcos x%d=   y%d=   \n\n\n",k,k);


        while(opcion1<1 || opcion1>6){

            printf("\n    Escoje un valor valido ( 1 a 6 )\n\tY%d", k);
            borrar(47,17);
            gotoxy(47,17); scanf("%d", &opcion1);

        }

        if(jugador[opcion1][opcion2]==1){
            gotoxy(2,18);  printf("Ese valor ya existe...\n");
            system("pause");
            k=k-1;
            oponente[i][j]=oponente[i][j]-1;
        }
         jugador[opcion1][opcion2]=1;

        system("cls");


    }
        imprimir_nivel2();

        cuadro();

        printf("\n\n\n");
         batalla_nivel2();

}
void batalla_nivel2(){

        system("cls");
        cuadro();
gotoxy(14,5); printf(" Preparado para la batalla?\n\n");
           wait(2);
           printf("\n\t\t\tAHORA!!!");
           wait(1);
           system("cls");
            imprimir_nivel2();
            cuadro();


                do{
                    system("cls");
                    imprimir_nivel2();
                    cuadro();

          gotoxy(2,17);  printf("ataca! dame la posicion que quieres atacar\n");
          gotoxy(2,18); printf("X= ");
            scanf("%d",&opcion2);
            while(opcion2<1 || opcion2>10){
              gotoxy(2,19);  printf("escoje un valor valido (1 a 10)");
                borrar(5,18);
               gotoxy(5,18); scanf("%d",&opcion2);
            }
              gotoxy(8,18); printf("Y= ");
              scanf("%d",&opcion1);
              while(opcion1<1||opcion1>6){
                 gotoxy(2,19);  printf("escoje un valor valido (1 a 6)");
                   borrar(11,18);
                gotoxy(8,18); printf("Y= ");
                gotoxy(11,18); scanf("%d",&opcion1);
              }


                auxiliar=oponente[opcion1][opcion2];
                oponente[opcion1][opcion2]=3;
                system("cls");
                imprimir_nivel2();
                cuadro();
                printf("\n");
                system("pause");
                oponente[opcion1][opcion2]=auxiliar;

                if(oponente[opcion1][opcion2]==1){
                    destruidosoponentes_nivel2=destruidosoponentes_nivel2+1;
                    oponente[opcion1][opcion2]=2;
                    jugadorr.puntajejugador=jugadorr.puntajejugador+300;
                    system("cls");
                    imprimir_nivel2();
                    cuadro();
                   gotoxy(3,19); printf("haz acertado!!\n\n\n");
                }else{
                     system("cls");
                    imprimir_nivel2();
                    cuadro();
                    gotoxy(3,19); printf("haz fallado...\n\n\n");
                }

                system("pause");


                if(destruidosoponentes_nivel2==8){
                system("cls");
                cuadro();
                gotoxy(20,10);  printf("HAZ GANADO!!\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
                wait(4);
                iniciar_nivel3();
                }
                system("cls");
                imprimir_nivel2();
                cuadro();
              gotoxy(2,17); printf("turno del oponente         \n");
               wait(2);


        dificultad=dificultad+0;
               srand(time(0));
               probabilidad=rand()%8;


               if(probabilidad>dificultad){
                   i=1+rand()%6;
                   j=1+rand()%10;
                   while(jugador[i][j]==2){
                       i=1+rand()%6; j=1+rand()%10;
                   }
                   auxiliar=jugador[i][j];
               }else{
                   while(jugador[i][j]==2 || jugador[i][j]!=1){
                       i=1+rand()%6; j=1+rand()%10;
                   }
                   auxiliar=jugador[i][j];
               }
                jugador[i][j]=3;
               opcion1=i;
               opcion2=j;
               system("cls");
               imprimir_nivel2();
               jugador[opcion1][opcion2]=auxiliar;

               if(jugador[opcion1][opcion2]==1){


                   jugador[opcion1][opcion2]=2;
                   destruidosjugador_nivel2=destruidosjugador_nivel2+1;
                   puntajeoponente=puntajeoponente+300;
                    system("cls");
                    imprimir_nivel2();
                    cuadro();
               gotoxy(3,19); printf("El oponente ha acertado!!\n\n\n");
               system("pause");


            }else{

                    cuadro();
                  gotoxy(3,19);  printf("El oponente ha fallado...                     \n\n");
                    system("pause");
                    system("cls");
               }
                if(destruidosjugador_nivel2==8){
                system("cls");
                cuadro();
                gotoxy(20,10);  printf("HAZ PERDIDO :c \n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
                guardar();
                wait(4);
                exit(0);
                }



                }while(destruidosoponentes_nivel2<8||destruidosjugador_nivel2<8);


}
void imprimir_nivel2 (){
    printf("\t\t\tBATALLA");

    gotoxy(3,3); printf("NIVEL 2");

  for(i=1;i<=6;i++){ // Imprime tablero del oponente
        printf("\n\t\t");
        for(j=1;j<=10;j++){
            if(oponente[i][j]==1){
                printf(" #");
            }else{
                if(oponente[i][j]==2){// Imprime 'X' si vale 2

                    printf(" x");
                }else{
                    printf(" -");
                }
            }
        }


    }

        printf("\n\t\t_______________________\n");
        gotoxy(40,4);  printf("OPONENTE ");
        printf("\n\n\n\n\n\n");
   for(i=1;i<=6;i++){ // Imprime el tablero del jugador

        printf("\n\t\t");
        for(j=1;j<=10;j++){
            if(jugador[i][j]==3){
                printf(" #");

            }
            else{
                if(jugador[i][j]==2){ // Imprime 'X' si vale 2 || 'O' si vale 1

                    printf(" x");
                }
                else{
                    if(jugador[i][j]==1){

                        printf(" O");
                    }
                    else{
                        printf(" -");
                    }
                }
            }
        }

    }

    printf("\n\n");
gotoxy(40,13); printf("JUGADOR ");

 gotoxy(54,12); printf("PUNTOS: %d",jugadorr.puntajejugador);
 gotoxy(54,4); printf("PUNTOS: %d",puntajeoponente);


    }



 /// nivel 3
    void imprimir_nivel3 (){
    printf("\t\t\tBATALLA");
    printf("\n\n");
gotoxy(3,3); printf("NIVEL 3");
  for(i=1;i<=7;i++){ // Imprime tablero del oponente
        printf("\n\t\t");
        for(j=1;j<=11;j++){
            if(oponente[i][j]==1){
                printf(" #");
            }else{
                if(oponente[i][j]==2){// Imprime 'X' si vale 2

                    printf(" x");
                }else{
                    printf(" -");
                }
            }
        }


    }

        printf("\n\t\t_______________________\n\n");

        gotoxy(40,6);  printf("OPONENTE ");
        printf("\n\n\n\n\n");
   for(i=1;i<=7;i++){ // Imprime el tablero del jugador

        printf("\n\t\t");
        for(j=1;j<=11;j++){
            if(jugador[i][j]==3){
                printf(" #");

            }
            else{
                if(jugador[i][j]==2){ // Imprime 'X' si vale 2 || 'O' si vale 1

                    printf(" x");
                }
                else{
                    if(jugador[i][j]==1){

                        printf(" O");
                    }
                    else{
                        printf(" -");
                    }
                }
            }
        }

    }


gotoxy(40,13); printf("JUGADOR ");

 gotoxy(54,12); printf("PUNTOS: %d",jugadorr.puntajejugador);
 gotoxy(54,4); printf("PUNTOS: %d",puntajeoponente);


    }

void iniciar_nivel3(){// Rellena con '0' el arreglo y coloca los barcos
        nivel=3;
        destruidosjugador=0;
        destruidosoponentes=0;
        puntajeoponente=0;
       jugadorr.puntajejugador=0;
            cuadro();
    gotoxy(23,4);printf("NIVEL 3");
        wait(3);

            system("cls");



    system("cls");
    for(i=1;i<=7;i++){ // Llena todo con '0'
        for(j=1;j<=11;j++){
            jugador[i][j]=0;
            oponente[i][j]=0;

        }
    }

    srand(time(NULL));

    for(k=1;k<=11;k++){ // Distribuye los barcos
        imprimir_nivel3();

        cuadro();

        i=1+rand()%7; // Distribuye los barcos oponentes
        j=1+rand()%11;
        while(oponente[i][j]==1){
            i=1+rand()%7; j=1+rand()%11;
        }
                oponente[i][j]=1; // La posicion de los barcos valdra 1

            gotoxy(2,21); printf("dame las cordenadas de tus 5 barcos x%d=   y%d=   \n\n\n",k,k);
            gotoxy(41,21); scanf("%d",&opcion2);
            gotoxy(47,21); scanf("%d",&opcion1);

        while(opcion2<1 || opcion2>11){
            printf("    Escoje un valor valido ( 1 a 11 )\n\tX%d", k);
            borrar(41,21);
            cuadro();
             gotoxy(41,21); scanf("%d", &opcion2);

        }


            gotoxy(2,21); printf("dame las cordenadas de tus 11 barcos x%d=   y%d=   \n\n\n",k,k);


        while(opcion1<1 || opcion1>7){

            printf("\n    Escoje un valor valido ( 1 a 7 )\n\tY%d", k);
            borrar(47,21);
            gotoxy(47,21); scanf("%d", &opcion1);

        }

        if(jugador[opcion1][opcion2]==1){
            gotoxy(2,22);  printf("Ese valor ya existe...\n");
            system("pause");
            k=k-1;
            oponente[i][j]=oponente[i][j]-1;
        }
         jugador[opcion1][opcion2]=1;

        system("cls");


    }
        imprimir_nivel3();

        cuadro();

        printf("\n\n\n");
         batalla_nivel3();

}


void batalla_nivel3(){

        system("cls");
        cuadro();
gotoxy(14,5); printf(" Preparado para la batalla?\n\n");
           wait(2);
           printf("\n\t\t\tAHORA!!!");
           wait(1);
           system("cls");
            imprimir_nivel3();
            cuadro();


                do{
                    system("cls");
                    imprimir_nivel3();
                    cuadro();

          gotoxy(2,21);  printf("ataca! dame la posicion que quieres atacar\n");
          gotoxy(2,22); printf("X= ");
            scanf("%d",&opcion2);
            while(opcion2<1 || opcion2>11){
              gotoxy(2,21);  printf("escoje un valor valido (1 a 11)");
                borrar(5,21);
               gotoxy(5,21); scanf("%d",&opcion2);
            }
              gotoxy(8,22); printf("Y= ");
              scanf("%d",&opcion1);
              while(opcion1<1||opcion1>7){
                 gotoxy(2,21);  printf("escoje un valor valido (1 a 7)");
                   borrar(11,21);
                gotoxy(8,21); printf("Y= ");
                gotoxy(11,21); scanf("%d",&opcion1);
              }


                auxiliar=oponente[opcion1][opcion2];
                oponente[opcion1][opcion2]=3;
                system("cls");
                imprimir_nivel3();
                cuadro();
                printf("\n");
                system("pause");
                oponente[opcion1][opcion2]=auxiliar;

                if(oponente[opcion1][opcion2]==1){
                    destruidosoponentes=destruidosoponentes+1;
                    oponente[opcion1][opcion2]=2;
                    jugadorr.puntajejugador=jugadorr.puntajejugador+300;
                    system("cls");
                    imprimir_nivel3();
                    cuadro();
                   gotoxy(3,21); printf("haz acertado!!\n\n\n");
                }else{
                     system("cls");
                    imprimir_nivel3();
                    cuadro();
                    gotoxy(3,21); printf("haz fallado...\n\n\n");
                }

                system("pause");


                if(destruidosoponentes==11){
                system("cls");
                cuadro();
                gotoxy(20,10);  printf("HAZ GANADO!!\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
                wait(4);
                guardar();
                exit(0);
                }
                system("cls");
                imprimir_nivel3();
                cuadro();
              gotoxy(2,21); printf("turno del oponente         \n");
               wait(2);


        dificultad=dificultad+0.5;
               srand(time(0));
               probabilidad=rand()%5;


               if(probabilidad>dificultad){
                   i=1+rand()%7;
                   j=1+rand()%11;
                   while(jugador[i][j]==2){
                       i=1+rand()%7; j=1+rand()%11;
                   }
                   auxiliar=jugador[i][j];
               }else{
                   while(jugador[i][j]==2 || jugador[i][j]!=1){
                       i=1+rand()%7; j=1+rand()%11;
                   }
                   auxiliar=jugador[i][j];
               }
                jugador[i][j]=3;
               opcion1=i;
               opcion2=j;
               system("cls");
               imprimir_nivel3();
               jugador[opcion1][opcion2]=auxiliar;

               if(jugador[opcion1][opcion2]==1){


                   jugador[opcion1][opcion2]=2;
                   destruidosjugador=destruidosjugador+1;
                   puntajeoponente=puntajeoponente+300;
                    system("cls");
                    imprimir_nivel3();
                    cuadro();
               gotoxy(3,21); printf("El oponente ha acertado!!\n\n\n");
               system("pause");


            }else{

                    cuadro();
                  gotoxy(3,21);  printf("El oponente ha fallado...                     \n\n");
                    system("pause");
                    system("cls");
               }
                if(destruidosjugador==11){
                system("cls");
                cuadro();
                gotoxy(20,10);  printf("HAZ PERDIDO :c \n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
                wait(4);
                guardar();
                exit(0);
                }



                }while(destruidosoponentes<11||destruidosjugador<11);


}



