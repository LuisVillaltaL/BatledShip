#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>

using namespace std;

void PrintBarco();
void jugar();

//	================== 
// 	Variables globales
typedef int vida;
int jugador1[20][20], jugador2[20][20], puntajejugador1 = 0, puntajejugador2 = 0, i, j, k, opcion1, opcion2, rojo, azul,menu, salir;


//	==========================================
//	Inicia programa Menu y llamada a funciones
int main()
{
	do{
		PrintBarco();
		cin >>menu;
		
		switch(menu)
		{
			case 1: 
				jugar(); 
			break;
			case 2:
				system ("cls");
				cout << "Confirme que desea salir " << endl;
				cout << "1. Si" << endl;
				cout << "2. No, Regresa a Menu? " <<endl;
				cin >>salir;
				if(salir == 1){
					return 0;
				}else{
					return main();
				}
				
				system ("pause");
				system ("cls");
			break;
		}
	}while(menu !=3);
	
	return 0;
}

//	===========================================
//	Funcion imprime mensaje de turno de jugador
void mensaje_turno(int i){
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\t\t\t\t");
	Sleep(60*10);
	if(i%2==0){
		
		printf("Turno Jugador 2");
		Sleep(60*30);
		system("color b");
	}
	else{

		printf("Turno Jugador 1");
		Sleep(60*30);
		system("color c");
	}
	for(i=1;i<5;i++)putchar('\n');
	
	system("cls");	
}
void imprimir(char **p){
	int i,j;
	for(i=0;i<10;i++)p[0][i]='0'+i;
	for(i=0;i<10;i++)p[i][0]='0'+i;
	for(i=0;i<10;i++){
		printf("\n\t\t\t\t");
		for(j=0;j<10;j++)
			printf(" %c",p[i][j]);
	}
}
//	=======================================
// 	Funcion que imprime el tablero de juego
void tablero() {   
    // tablero del jugador
    for(i = 1; i <= 20;i++) // Imprime el tablero del jugador
    {
        printf("\t");
        for(j = 1; j <= 20;j++)
        {
            if(jugador1[i][j]==3)
            {
                printf("  #");
            }
            else
            {
                if(jugador1[i][j]==2) // Imprime 'X' si vale 2 || 'O' si vale 1
                {
                    printf("  X");
                }
                else
                {
                    if(jugador1[i][j]==1)
                    {
                        printf("  O");
                    }
                    else
                    {
                        printf("  -");
                    }
                }
            }                                    
        }
 
    cout << "\n";  
}

}
// ================================================
// funcion llenado de Tablero
void iniciar(){ 
	system("cls");
    for( k = 1; k <= 5; k++) // Distribuye los barcos
    {
        imprimir(char **p);

        jugador1[i][j]=1; // La posicion de los barcos valdra 1
                       
		cout << "\n\n Ingrese sus coordenadas\n\n";
        printf("\n\tX%d = ",k);
        scanf("%d", &opcion2);
                         
        printf("\n\tY%d = ", k);
        scanf("%d", &opcion1);
       
        jugador1[opcion1][opcion2]=1;
                  	    
    system("cls");
                                                         
    }  
     
}

// Funcion turno de jugadores
void jugar(){
	system ("cls");
	mensaje_turno(1);
	for(i = 0; i <= 4; i++){
		iniciar();

	}
	
	mensaje_turno(2);
	for(i = 0; i <= 4; i++){
		iniciar();
		
	}
	system("pause");
	system("cls");
}

//	=====================================
// 	Funcion para Imprimir Barco en Menu
void PrintBarco(){
	system("color 09");
	cout <<"\t                                    BATTLESHIP"<< endl <<endl;
	cout <<"\t                                        |__"<< endl;
	cout <<"\t                                       |\\/"<< endl;
	cout <<"\t                                       ---"<< endl;
	cout <<"\t                                       / | ["<< endl;
	cout <<"\t                               !       | |||"<< endl;
	cout <<"\t                             _/|      _/|-++'"<< endl;
	cout <<"\t                         +  +--| \\   |--|--|_ |-"<< endl;
	cout <<"\t                      { /|__|  |/\\ __|  |--- |||__/"<< endl;
	cout <<"\t                     +---------------___[}-_===_.'____                /\\"<< endl;
	cout <<"\t                 ____`-' ||___-{]_| _[}-  |     |_[___\\ ==--          \\/   _"<< endl;
	cout <<"\t  __..._____--==/___]_|__|_____________________________[___\\==--___,-----' .7"<< endl;
	cout <<"\t |                                                                   LV-90/"<< endl;
	cout <<"\t  \\                                                                   	/__"<< endl;
	cout <<"\t   \\________________________________________________________________________|"<< endl;
	cout <<"\t ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< endl <<endl;
	cout << "\t 1. Jugar" << endl;
	cout << "\t 2. Salir " << endl;

}
