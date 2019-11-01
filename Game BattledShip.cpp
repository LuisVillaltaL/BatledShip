/*	=======================================================================
--	Juego BattledShip Algoritmos <Author,LV>
--  Fecha de creacion <Create DAte,,> '2019-10-06'
--  Fecha de Modificacion <Create DAte,,> '2019-10-30', Agregar Ataque
	=======================================================================
*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

using namespace std;
//	==================
//	Variables Globales 
typedef int vida;
int op, x, y, i;
char **a=NULL,**b=NULL,**ta=NULL,**tb=NULL;
vida jugador2 = 5, jugador1 = 5;
//	=======================
// 	LLamada a las Funciones
char** inicio();
void mover(char **p);
void liberar(char **p);
void tablero(char **p);
void turno(int i);
void msj_ganador();
vida cont_vidas(char **p);
void ingresar(char **p,int i);
void atacar(char **p,char **pos,vida barcos,vida enemigo);
void juego(char **p,char **enemigo,char **posienemigo,vida vbarcos,vida venemigo);
void jugar(char **a,char **b,char **ta,char **tb,vida jugador2,vida jugador1);
void PrintBarco();

//	=======================================
//	Menu Principal llama a la funcion Jugar 
int main(){
	PrintBarco();
	cin >> op;
	 b = inicio();
	 a = inicio();
	ta = inicio();
	tb = inicio();

	system("cls");
	switch(op){
		case 1:
			jugar (a,b,ta,tb,jugador2, jugador1);
		break;
	}
	
	liberar(a);
	liberar(b);
	liberar(ta);
	liberar(tb);

}
//	=========================
// Funcion para dos jugadores
void jugar(char **a,char **b,char **ta,char **tb,vida jugador2,vida jugador1){
	turno(1);
	tablero(a);
	for(i = 0; i <= 4; i++){
		ingresar(a,i);
		tablero(a);
	}
	
	turno(2);
	tablero(b);
	for(i = 0; i <= 4; i++){
		ingresar(b,i);
		tablero(b);
	}
	system("cls");
	
	for(i = 1; jugador1 > 0 && jugador2 > 0;i++){
		turno(i);
		
		if(i%2==0)juego(a,tb,b,jugador1,jugador2);
		else juego(b,ta,a,jugador2,jugador1);
		
		jugador1 = cont_vidas(a);
		jugador2 = cont_vidas(b);	
	}
	
	getchar();
	system("cls");
}
//	==================================
//	Funcion Imprimir Tablero del Juego
void tablero(char **p){
	int i,j;
	for(i = 0; i <= 20; i++)p[0][i];
	for(i = 0; i <= 20;i++)p[i][0];
	for(i = 0; i <= 20;i++){
		printf("\n\t\t\t\t");
		for(j = 0; j <= 20;j++)
			printf(" %c",p[i][j]);
	}
}
char** inicio(){
	char **p=NULL;
	int i,j;
	
	p=(char**)malloc(20*sizeof(char*));
	for(i = 0; i <= 20; i++)
		p[i]=(char*)malloc(20*sizeof(char));
		
	for(j = 0; j <= 20; j++)
		for(i = 0; i <= 20;i++)
			p[j][i]='_';	
			
	return p;
}
void liberar(char **p){
	int i;
	for(i=0;i<=20;i++)free(p[i]);
	free(p);
}
//	=================================================
//	Funcion para Imprimir Mensaje de Turno de Jugador
void turno(int i){
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\t\t\t\t");
	Sleep(60*10);
	if(i%2==0){
		printf("Turno de Jugador 2");
		Sleep(60*30);
		
	}
	else{
		printf("Turno del Jugador 1");
		Sleep(60*30);
		
	}
	for(i=0;i<20;i++)putchar('\n');
	
	system("cls");	
}

vida cont_vidas(char **p){
	int i,j;
	vida cont = 0;
	for(i = 0; i < 20; i++)
		for(j = 0; j < 20;j++){
			if(p[i][j]>='A' && p[i][j]<='K')
			cont++;
		}
	return cont;
}
//	=======================================================
//	Funcion Generar tablero para realizar ataque a oponente
void juego(char **p,char **enemigo,char **posienemigo,vida vbarcos,vida venemigo){
	int op;
	system("cls");
	cout << "\n\t Tienes "<<vbarcos << " Municiones ";
	tablero(p);
	printf("\n\t\t\t 1. Atacar\n\t\t\t ");
	printf("\n\t\t\t 2. Turno del Oponente\n\t\t\t ");
	scanf("%d",&op);
	
	switch(op){
		case 1:atacar(enemigo,posienemigo,vbarcos,venemigo);break;
		case 2: exit;
	}
	fflush(stdin);
}
//	===================================
//	Funcion Atacar posiciones de Barcos
void atacar(char **p,char **pos,vida barcos,vida enemigo){
	int i,x=0,y=0;
	for(i=0;i<barcos && enemigo>0;i++){
		system("cls");
		system("color 0B");
		printf("\t\t\t Ingresa la posicion que desea Atacar\n");
		tablero(p);
		x=0;
		do{
			if(x!=0)printf("\n\t\t Posicion ya Fue Atacada");
			
			printf("\n\t\t\tx: ");
			scanf("%d",&x);
			printf("\t\t\tY: ");
			scanf("%d",&y);
			
		}while(pos[y][x]=='#' || pos[y][x]=='-');
		
		if(pos[y][x]>='A' && pos[y][x]<='K'){
			enemigo--;
			pos[y][x]=p[y][x]='#';
			printf("\a");
		}
		else pos[y][x]=p[y][x]='-';
	}
	if(enemigo==0)msj_ganador();
}

//	=============================================
// 	Funciona Ingresa las coordenadas de las Naves
void ingresar(char **p,int i){
	int x=0,y=0;
	printf("\n\t\t\t Ingresa las cordenadas de tu barco %d\n",i+1);
	do{
		if(x!=0)printf("\n\t\t\t\tYA EXISTE ESTE BARCO!!\n");
		printf("\t\t\tx: ");
		scanf("%d",&x);
		printf("\t\t\ty: ");
		scanf("%d",&y);
		
	}while(p[y][x]>='A' && p[y][x]<='K');
	
	system("cls");
	p[y][x]='A'+i;
}
//	=====================================================
//	funcion muestra mensaje si destruye la flota completa
void msj_ganador(){
	int i;
	system("cls");
	system("color fd");
	printf("\n\n\n\n\n\n\n\n\t\t    ");
	Sleep(60*10);
	char cad[]={"Has Destruido la Flota Enemiga"};
	for(i=0;i<cad[i]!='\0';i++){
		putchar(cad[i]);
		Sleep(30);
	}
	Sleep(60*60);
	printf("\n\n\t\t    <ENTER>");
	getchar();
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
