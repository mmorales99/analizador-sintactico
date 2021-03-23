#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
//******************************************************************************
/*

Archivo de guardado y amplicion de datos :: data.txt

*/
//******************************************************************************

//******************************************************************************
/***************************Declaraciones**************************************/
//******************************************************************************

char str[99999];
char *tok[99999];
int numTok=0;

void help();
void add();
void games();
void after_command();
void marcianitos();

//******************************************************************************
/***************************Funcion principal**********************************/
//******************************************************************************    

int main(){
    int salir;
    FILE *myProg;
//******************************************************************************
//******************************************************************************    
    myProg = fopen("data.txt","r");
    if(myProg==0){
        system("MKDIR Analizador_Sintactico");
        system("MOVE /-Y Analizador_Sintactico");
        myProg = fopen("data.txt","w+");
        system("START analizadorSintactico.exe");
        return 0;
    }
//******************************************************************************
//******************************************************************************    
    printf("\n\n\n\n\n\n\n\t\tBIENVENIDO/A AL ANALIZADOR SINTACTICO\n\n\n\n\n\n\tEste progama necesita que le des una frase u oracion\n\n\n\n\n\t            Pulsa intro para continuar\n\n\t\t\t\t\t\t");
    getchar();
    system("cls");
    fflush(stdin);
    printf("\n\n\n\tRecuerda que esto es un progrma realizado por una persona,\n\tpuede que contenga errores.\n\tSi es asi, escribe \" !!add \" delante para anyadir y corregir lo errores.\n\n");
    printf("\tUsa el comando \" !!help \" para conocer todos los comandos\n\ty sus funciones.\n");
    printf("\tPulsa intro para continuar, o usa \" !!salir \" , \n\ttambien puedes consultar los comandos.\n\n\tPulsa intro para limpiar la pantalla.");
    printf("\n");
    while(1){
        numTok=0;
        printf("\n\tIntroduce tu frase, oracion o comando(help) :\n\t");
        printf("\n\t>>");
        gets(str);
        if(str==NULL || strcmp(str,"")==0){
			system("cls");
			continue;	
		}
	    tok[numTok] = strtok(str, " \t\n\r");
	    numTok++;
	    while((tok[numTok] = strtok(NULL, " \t\n\r")) != NULL ){
	        numTok++;
		}
	        
	    if(strcmp(tok[0], "!!salir") == 0){
	        return 0;
  		}else if(strcmp(tok[0], "!!help")== 0){
	    	help();
		}else if(strcmp(tok[0], "!!add")== 0){
	    	add();
		}else if(strcmp(tok[0], "!!games")== 0){
			games();
		}
		system("cls");
    }
//****************************************************************************** 
//******************************************************************************
    printf("\n\n");
    return 0;
}

//******************************************************************************
    
 
 
//******************************************************************************

void after_command(){
	printf("\n\n");
	Sleep(300);
	getch();
	return;
	}

void help(){
    if(strcmp(str, "!!help")== 0){
		system("cls");
		printf("\n\t>>!!help\n\n");
		printf("\tPulsa intro o escribe 'clear' para vaciar la ventana.\n");
        printf("\n\tLos comandos disponibles son :\n");
        printf("\n\tadd [Sintagma] : [clasificacion o funcion]\n");
        printf("\n\tgames [marcianitos/]\n");
        after_command();
    }
}
    
void add(){
    if(strcmp(str, "!!add")== 0){
        printf("\n\tFaltan argumentos.\n\tUSA :\t");
        printf("add [Sintagma] : [clasificacion o funcion]");
    }else if(tok[1]== NULL){
        printf("\n\tFaltan argumentos.\n\t");
        printf("add [Sintagma] : [clasificacion o funcion]");
    }
	after_command();		
}												
                          
void games(){
	int escoge(){
		if(strcmp(tok[1],"marcianitos")==0){
			marcianitos();
		}else if(strcmp(tok[1],"pong")<0){
			printf("\n\tNO HAY MAS JUEGOS EN MEMORIA");
			Sleep(1500);
			return 0;
		}else{
			printf("\tFaltan argumentos.\n\tLos juegos actualmente disponibles son: \n\t\t-marcianitos\n\t\t");
			Sleep(1000);
			return 0;	
		}
	}
	escoge();
	after_command();
}

//***********************COMPLEMENTOS 1: JUEGOS*********************************
    
void marcianitos(){
	system("cls");
	void pantalla_completa(){
		keybd_event(VK_MENU,
	                0x38,
	                0,
	                0);
	    keybd_event(VK_RETURN,
	                0x1c,
	                0,
	                0);
	    keybd_event(VK_RETURN,
	                0x1c,
	                KEYEVENTF_KEYUP,
	                0);
	    keybd_event(VK_MENU,
	                0x38,
	                KEYEVENTF_KEYUP,
	                0);
	    return;
		}
		
	void juego()
	{
		int pantalla;
	    int sizey = 23;
	    int sizex = 40;
	    int x, y, yi;
	    char world[sizey][sizex];
	    char player = 'A';
	    char playerLaser = 158;
	    char enemy = 197;
	    char enemyShielded = 206;
	    char enemyLaser = 179;
	    char explosion = 'X';
	    int score = 0;
	    int victory = 1;
	    int laserReady = 1;
	    int enemyReady = 0;
		int bonus=0;
		char *aprovacion;
		
	    srand(time(NULL));
	
	    /*welcome screen*/
	    printf("\n\n\n\n\n\t\t\tDOS COSAS ANTES DE EMPEZAR\n\n\n\n\n");
	    Sleep(2000);
	    system("cls");
	    printf("BE AWARE ALL PHOTOSENSITIVE PEOPLE OR EPILEPTIC PEOPLE \nBECAUSE THE EXISTENCE OF SCRAMBLING SCREEN.\n\n");
	    printf("SE ADVIERTE A TODA PERSONA EPILEPTICA O FOTOSENSIBLE DE LA APARICION\nDE PANTALLA PARPADEANTES DE ALTA FRECUENCIA.\n\n");
		printf("IF YOU MAKE USAGE OF THIS SOFTWARE YOU BECAME RESPONSIBLE ABOUT \nANY POSIBLE HARM YOU CAN CAUSE TO YOUSELF.\n\n");
		printf("SI ACEPTA HACER USO DE ESTE SOFWARE, USTED SERA RESPONSABLE DE LO QUE PUEDA\nSUCEDER.\n\n");
		printf("SI / NO || YES / NO :");    
	    fflush(stdin);
	    gets(aprovacion);
	    fflush(stdin);
	    if(strcmp(aprovacion, "NO")== 0){
			return;
		}
		if(strcmp(aprovacion, "N")== 0){
			return;
		}
		if(strcmp(aprovacion, "No")== 0){
			return;
		}
		if(strcmp(aprovacion, "n")== 0){
			return;
		}
		if(strcmp(aprovacion, "nO")== 0){
			return;
		}
		if(strcmp(aprovacion, "no")== 0){
			return;
		}
		Sleep(100);
		system("cls");
		char *tipoPantalla[3];
		printf("\n\n\n\tQUIERES JUGAR A PANTALLA COMPLETA? ");
		printf("\n\tSI / NO || YES / NO :");    
	    gets(tipoPantalla);
	    if(strcmp(tipoPantalla, "NO")== 0){
			pantalla=0;
		}
		if(strcmp(tipoPantalla, "N")== 0){
			pantalla=0;
		}
		if(strcmp(tipoPantalla, "No")== 0){
			pantalla=0;
		}
		if(strcmp(tipoPantalla, "n")== 0){
			pantalla=0;
		}
		if(strcmp(tipoPantalla, "nO")== 0){
			pantalla=0;
		}
		if(strcmp(tipoPantalla, "no")== 0){
			pantalla=0;
		}else{
		pantalla=1;
		}
		if(pantalla==1){
			pantalla_completa();
		}
		Sleep(100);
	    system("cls");
	    Sleep(800);
	    printf("\n \n  Welcome novice! \n \n \n \n");
	    Sleep(1000);
	    printf("  You have been called to arms, in order to beat the great NAZI virus. \n \n \n \n");
	    Sleep(1000);
	    printf("  Your operating system is depending upon you. \n \n \n \n");
	    Sleep(2500);
	    printf("  Good luck, litle duck.");
	    Sleep(1000);
	    printf("\n \n \n \n \tPress any key to start.");
	    fflush(stdin);
		getch();
	    fflush(stdin);
		system("CLS");
		printf("\n\n\n\tUSE [A] TO MOVE LEFT, [D] TO MOVE RIGHT. \n\tUSE [M] TO SHOOT. YOU CAN PAUSE THE GAME USING TAB.\n\n\n\n\n\t\t\tHERE YOU ARE:\n\n\n\t\t\t      A\n\n\n\t\t    THIS IS YOUR CHARACTER");
		Sleep(1500);
		printf("\n\n\n\t   Press any key to continue.\n\n");
		fflush(stdin);
		getch();
		fflush(stdin);	
		system("cls");
		while(1){
			
	    /*initialise world*/
	    int totalEnemies = 0;
	    for (x = 0; x < sizex; x ++) {
	        for (y = 0; y < sizey; y ++) {
	            if ((y+1) % 2 == 0 && y < 7 && x > 4 && x < sizex - 5 && x % 2 ==0) {
	                world[y][x] = enemy;
	                totalEnemies ++;
	            }
	            else if ((y+1) % 2 == 0 && y >= 7 && y < 9 && x > 4 && x < sizex - 5 && x % 2 ==0){
	                world[y][x] = enemyShielded;
	                totalEnemies = totalEnemies + 2;
	            }
	            else {
	                world[y][x] = ' ';
	            }
	        }
	    }
	    world[sizey - 1][sizex / 2] = player;
	    int i = 1;
	    char direction = 'l';
	    char keyPress;
	    int currentEnemies = totalEnemies;
	    while(currentEnemies > 0 && victory) {
	        int drop = 0;
	        int enemySpeed = 1 + 10 * currentEnemies / totalEnemies;
	        laserReady ++;
	
	        /*display world*/
	        system("cls");
	        printf("     SCORE:    %d", score);
	        printf("\n");
	            for (y = 0; y < sizey; y ++) {
	            printf("|");
	                for (x = 0; x < sizex; x ++) {
	                    printf("%c",world[y][x]);
	                }
	            printf("|");
	            printf("\n");
	            }
	
	        /*laser time*/
	        for (x = 0; x < sizex; x ++) {
	            for (y = sizey-1; y >= 0; y --) {
	                if (i%2 == 0 && world[y][x] == enemyLaser && (world[y+1][x] != enemy & world[y+1][x] != enemyShielded)){
	                world[y+1][x] = enemyLaser;
	                world[y][x] = ' ';
	                }
	                else if (i%2 == 0 && world[y][x] == enemyLaser && (world[y+1][x] == enemy | world[y+1][x] == enemyShielded)){
	                    world[y][x] = ' ';
	                }
	            }
	        }
	        for (x = 0; x < sizex; x ++) {
	            for (y = 0; y < sizey; y ++) {
	                if ((i % 5) == 0 && (world[y][x] == enemyShielded | world[y][x] == enemy) && (rand() % 15) > 13 && world[y+1][x] != playerLaser){
	                    for (yi = y+1; yi < sizey; yi ++) {
	                        if (world[yi][x] == enemy | world[yi][x] == enemyShielded) {
	                            enemyReady = 0;
	                            break;
	                        }
	                        enemyReady = 1;
	                    }
	                    if (enemyReady) {
	                        world[y+1][x] = enemyLaser;
	                    }
	                }
	                if (world[y][x] == playerLaser && world[y-1][x] == enemy) {
	                    world[y][x] = ' ';
	                    world[y-1][x] = explosion;
	                    currentEnemies --;
	                    score = score + 50;
	                }
	                else if (world[y][x] == playerLaser && world[y-1][x] == enemyShielded) {
	                    world[y][x] = ' ';
	                    world[y-1][x] = enemy;
	                    currentEnemies --;
	                    score = score + 50;
	                }
	                else if (world[y][x] == playerLaser && world[y-1][x] == enemyLaser) {
	                    world[y][x] = ' ';
	                }
	                else if (world[y][x] == explosion) {
	                    world[y][x] = ' ';
	                }
	                else if ((i+1) % 2 == 0 && world[y][x] == enemyLaser && world[y+1][x] == player) {
	                    world[y+1][x] = explosion;
	                    world[y][x] = ' ';
	                    victory = 0;
	                }
	                else if (world[y][x] == playerLaser && world[y-1][x] != enemyLaser) {
	                        world[y][x] = ' ';
	                        world[y-1][x] = playerLaser;
	                }
	            }
	        }
	
	        /*update enemy direction*/
	        for (y = 0; y < sizey; y ++) {
	            if (world[y][0] == enemy) {
	                direction = 'r';
	                drop = 1;
	                break;
	            }
	            if (world[y][sizex-1] == enemy){
	                direction = 'l';
	                drop = 1;
	                break;
	            }
	        }
	
	        /*update board*/
	        if (i % enemySpeed == 0) {
	            if (direction == 'l') {
	                for (x = 0; x < sizex - 1; x ++) {
	                    for (y = 0; y < sizey; y ++) {
	                        if (drop && (world[y-1][x+1] == enemy || world[y-1][x+1] == enemyShielded)){
	                            world[y][x] = world[y-1][x+1];
	                            world[y-1][x+1] = ' ';
	                        }
	                        else if (!drop && (world[y][x+1] == enemy || world[y][x+1] == enemyShielded)) {
	                            world[y][x] = world[y][x+1];
	                            world[y][x+1] = ' ';
	                        }
	                    }
	                }
	            }
	            else {
	                for (x = sizex; x > 0; x --) {
	                    for (y = 0; y < sizey; y ++) {
	                        if (drop && (world[y-1][x-1] == enemy || world[y-1][x-1] == enemyShielded)) {
	                            world[y][x] = world[y-1][x-1];
	                            world[y-1][x-1] = ' ';
	                        }
	                        else if (!drop && (world[y][x-1] == enemy || world[y][x-1] == enemyShielded)) {
	                            world[y][x] = world[y][x-1];
	                            world[y][x-1] = ' ';
	                        }
	                    }
	                }
	            }
	            for (x = 0; x < sizex; x ++) {
	                if (world[sizey - 1][x] == enemy) {
	                    victory = 0;
	                }
	            }
	        }
	
	        /*control player*/
	        if(kbhit()){
	            keyPress = getch();
	        }
	        else {
	            keyPress = ' ';
	        }
	        if (keyPress == 'a') {
	            for (x = 0; x < sizex; x = x+1) {
	                if ( world[sizey-1][x+1] == player) {
	                    world[sizey-1][x] = player;
	                    world[sizey-1][x+1] = ' ';
	                }
	            }
	        }
	
	        if (keyPress == 'd') {
	            for (x = sizex - 1; x > 0; x = x-1) {
	                if ( world[sizey-1][x-1] == player) {
	                    world[sizey-1][x] = player;
	                    world[sizey-1][x-1] = ' ';
	                }
	            }
	        }
	        if (keyPress == 'm' && laserReady > 2) {
	            for (x = 0; x < sizex; x = x+1) {
	                if ( world[sizey-1][x] == player) {
	                    world[sizey - 2][x] = playerLaser;
	                    laserReady = 0;
	                }
	            }
	        }
	        
			if (keyPress == '	') {
	            Sleep(150);
	            fflush(stdin);
				system("cls");
				printf("     SCORE :   %d\n",score);
				printf("|                                         |\n"); 
				printf("|                                         |\n");
				printf("|                                         |\n");
				printf("|       %c %c    %c %c    %c      %c            |\n",enemy,enemy,enemy,enemy,enemy,enemy);
				printf("|       %c %c %c %c       %c      %c            |\n",enemy,enemy,enemy,enemy,enemy,enemy);
				printf("|       %c %c %c %c    %c %c  %c   |\n");
				printf("|                                         |\n");
				printf("|                P A U S E                |\n");
				printf("|                                         |\n");
				printf("|           %c             %c       %c       |\n",enemy,enemy,enemy);
				printf("|                    %c                    |\n",enemyLaser);
				printf("|                                         |\n");
				printf("|                                         |\n");
				printf("|                                         |\n");
				printf("|                                         |\n");
				printf("|                                         |\n");
				printf("|                                         |\n");
				printf("|                                         |\n");
				printf("|                                         |\n");
				printf("|       %c                          %c      |\n",enemyLaser,enemyLaser);
				printf("|                   %c*                    |\n",enemyLaser);
				printf("|            %c                            |\n",enemyLaser);
				printf("|                    A           %c        |\n",enemyLaser);
				getch();																	                                                                           
				system("cls");		
	        }
			        
	        i ++;
	        Sleep(60);
	    }
	    system("cls");
	        printf("     SCORE :   %d", score);
	        printf("\n");
	            for (y = 0; y < sizey; y ++) {
	            printf("|");
	                for (x = 0; x < sizex; x ++) {
	                    printf("%c",world[y][x]);
	                }
	            printf("|");
	            printf("\n");
	            }
	    Sleep(1000);
	    system("cls");
	    if (victory != 0) {
	        printf("\n \n \n \n \n \n               CONGRATULATIONS! \n \n \n \n \n");
	        Sleep(1000);
	        printf("\n \n               Score: %d", score);
	        Sleep(1000);
	        bonus = totalEnemies*20 - i;
	        printf("\n \n               Bonus: %d", bonus);
	        Sleep(1000);
	        printf("\n \n               Total Score: %d", score + bonus);
	        printf("\n \n \n \n               Well done");
	        Sleep(1000);
	        printf(", Hero.");
	        Sleep(1000);
	        fflush(stdin);
			getch();
	        fflush(stdin);
	    }
	    else {
			bonus = ( totalEnemies - currentEnemies )*20 - i;
	        printf("\n \n \n \n \n \n               You have failed.");
	        Sleep(1000);
	        printf("\n \n \n \n \n \n               Windows is doomed.");
	        Sleep(1000);
	        if(bonus<0){
				bonus=0;
				}
	        printf("\n \n \n	       Your Max Bonus : %d", bonus);
	        printf("\n \n \n               Final Score    : %d\n\n", score);
	        fflush(stdin);
			getch();
	        fflush(stdin);
	    }
	    system("cls");
	    char *wanto;
	    printf("\n\n\t\tDo you want to play again?");
	    printf("\t[ YES / NO] :\t");
	    fflush(stdin);
		gets(wanto);
	    fflush(stdin);
		if(strcmp(wanto,"no")==0){
			return;
			}
		if(strcmp(wanto,"No")==0){
			return;
			}
		if(strcmp(wanto,"nO")==0){
			return;
			}
		if(strcmp(wanto,"NO")==0){
			return;
			}
		if(strcmp(wanto,"n")==0){
			return;
			}
		if(strcmp(wanto,"N")==0){
			return;
			}
		i=0;
		x=0;
		y=0;
		yi=0;
		int drop=0;
		int enemySpeed=0;
		currentEnemies=0;
		totalEnemies=0;
	    score = 0;
	    victory = 1;
	    laserReady = 1;
	    enemyReady = 0;
		}
	}
	
	juego();
}

 
//******************************************************************************
