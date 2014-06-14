
#include <stdlib.h> 
#include <stdio.h>
#include <string.h>
#include <unistd.h>

void creditos(void){
	printf ("García Pérez Eduardo Ismael\n");
	printf ("Hernandez Camacho Marcos Uriel 113281\n");

	printf ("Ingenieria Desarrollo Software");
	printf ("\n24 de Mayo 2014");
	printf ("\nPractica Numero Uno");
	printf ("\nJuan Carlos López Pimentel");
	

	printf("\n______________\n\n");
	return;
}

int main(int argc, char const *argv[])
{
	int bandera = 0;
	int opcion = 0;



	while (bandera == 0){
		printf("\nOpciones : \n");
		printf("1-Decifrar Archivo\n");
		printf("2-Encriptar\n");
		printf("3-Creditos\n");
		printf("4-salir\n");

		printf("\nOpcion : ");
		scanf("%d", &opcion);
	
		if (opcion == 4 )
			bandera = 1;
		
		else if(opcion == 1){
			system("clear");
			
			char Archivo[80]; 
			char comandoPermisos[80] = "chmod 777 ";
			char comando[80]="gpg ";

			printf ("Coolocar el nombre del Archivo: ");
			scanf ("%s", Archivo); 
			strcat(comandoPermisos, Archivo);
			strcat(comando, Archivo);

			system(comandoPermisos);
			system(comando);

			FILE *fichero;
			char mensaje[4050];

			fichero =fopen("ArchivoF.txt", "r");
			
			if (fichero==NULL){
				
			}else{
				while(!feof(fichero)){
					fgets (mensaje,4050,fichero);
					if(feof(fichero)){
						printf("\n\n\nEl Archivo volvera a Encriptarse\n");
					}else{
						fputs(mensaje,stdout);
					}
				}
				fclose(fichero);
			}
			
			//remove("ArchivoF.txt");
			
			char comandoPermisosFuera[80] = "chmod 000 ";
			strcat(comandoPermisosFuera, Archivo);
			system(comandoPermisosFuera);
			
		}else if(opcion == 2){
			system("clear");
			char fichero[80]; 
			char comando[80] = "gpg -c ";
			

			printf ("Coolocar el nombre del fichero: ");
			scanf ("%s", fichero); 
			strcat(comando, fichero);
			system(comando);
			remove(fichero);

		}

		else if(opcion == 3){
			system("clear");
			creditos();
		}

	}
	return 0;
}
//gcc -o program -c program.c