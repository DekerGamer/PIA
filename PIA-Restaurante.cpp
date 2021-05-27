//struct con el pedido, costo, platillo, tipo de pago,comer aqui o recoger, tipo de envio(RAPPI, DIDI FOOD)
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "funciones.h"

typedef struct{
	int numero_orden;
	int platillo; //tipo de platillo
	char pago; //tarjeta o efectivo
	float costo; //costo total sin envio
	int tipoenvio; //tipo de envio (1= rappi, 2=didi etc.)
	float totalenvio; //costo total con envio
	int D; 
	int M;
	int A;
}ordenes;

int i;
float lista_precios[]={50,60,40,55,45,0}; //Precios de los platillos
float envio[]={30,35,40,0,0,0}; //Precios de envios


void llenar(ordenes o[5]);
int menu();
void ordenar(ordenes o[5], int i);
void suma(ordenes o[5], int i);
void mes(ordenes o[5], int i);
void dia(ordenes o[5], int i);
void anio(ordenes o[5], int i);

int main(){	
	ordenes o[5];
	llenar(o);
	int opcion;
	
	do{


    opcion=menu();

        switch ( opcion )
        {
            case 1:
				ordenar(o,i);
			break;
				
			case 2:
				dia(o,i);
			break;
			
			case 3:
				mes(o,i);
			break;	
			
			case 4:
				anio(o,i);
			break;
			
			case 5:
				suma(o,i);
			break;
			
			case 6:
				llenar(o);
			break;	

         }
	}while(opcion != 7);
	
	
}


void llenar(ordenes o[5]){
	int j=0,k=0,r,z,q;
	system("cls");
	do{
		printf("\n\tAntojitos Gomez\n\n");

		do
		{
			do
			{
				printf("Dar el numero de orden: ");
				scanf("%d",&o[i].numero_orden);
				z=0;
				for(j=0;j<i;j++)
					if(o[i].numero_orden==o[j].numero_orden)
						{
							printf("La orden ya existe. \n");
							z=1;
						}

			}while(z==1);
		}while(o[i].numero_orden<1 || o[i].numero_orden>100);
		
		do{
		
			do
			{
				int h;
				printf("\nSeleccione el platillo\n0 = orden de enchiladas\t$50\n1 = orden de tacos\t$60\n2 = sopes\t\t$40\n3 = orden de empanadas\t$55\n4 = orden de flaustas\t$45\n5 = n enchiladas\t$10c/u\n6 = n tacos\t\t$12c/u\n7 = n sopes\t\t$8c/u\n8 = n empanadas\t\t$11c/u\n9 = n flaustas\t\t$9c/u\n");
				fflush(stdin);
				scanf("%d",&o[i].platillo);
				
				
				
				if(o[i].platillo==5)
				{					
					printf("Cuantas enchiladas desea agregar? ");
					scanf("%d",&h);
					int p = (h*10);
					o[i].costo+=p;
				}
				else if(o[i].platillo==6)
				{
					printf("Cuantos tacos desea agregar? ");
					scanf("%d",&h);
					int p = (h*12);
					o[i].costo+=p;
				}
				else if(o[i].platillo==7)
				{
					printf("Cuantos sopes desea agregar? ");
					scanf("%d",&h);
					int p = (h*8);
					o[i].costo+=p;
				}
				
				else if(o[i].platillo==8)
				{
					printf("Cuantas empanadas desea agregar? ");
					scanf("%d",&h);
					int p = (h*11);
					o[i].costo+=p;
				}
				
				else if(o[i].platillo==9)
				{
					printf("Cuantas flautas desea agregar? ");
					scanf("%d",&h);
					int p = (h*9);
					o[i].costo+=p;
				}
				else if(o[i].platillo==0 || o[i].platillo==1 || o[i].platillo==2 || o[i].platillo==3 || o[i].platillo==4){
					o[i].costo+=lista_precios[o[i].platillo];
				}								
								

			}while(o[i].platillo != 0 && o[i].platillo != 1 &&  o[i].platillo !=2 && o[i].platillo !=3 && o[i].platillo !=4 && o[i].platillo !=5 && o[i].platillo !=6 && o[i].platillo !=7 && o[i].platillo !=8 && o[i].platillo !=9);
		printf("\nDesea agregar otro platillo?  (1=si, otro=no) \n");
		scanf("%d",&q);
		
		}while(q==1);

		do
		{
			o[i].totalenvio = o[i].costo;
			printf("\nSeleccione el tipo de envio\n0 = Rappi\t\t$30\n1 = Didi food\t\t$35\n2 = Uber Eats\t\t$40\n3 = Comer en local\t$0\n4 = Pasar a recoger\t$0\n");
			fflush(stdin);
			scanf("%d",&o[i].tipoenvio);
			o[i].tipoenvio = toupper(o[i].tipoenvio);

			o[i].totalenvio+=envio[o[i].tipoenvio];
		}while(o[i].tipoenvio != 0 && o[i].tipoenvio != 1 &&  o[i].tipoenvio !=2 && o[i].tipoenvio !=3 && o[i].tipoenvio !=4);		

		do{
			printf("Formato de pago (E = efectivo, T = tarjeta): ");
			fflush(stdin);
			scanf("%c",&o[i].pago);
			o[i].pago=toupper(o[i].pago);
		}while(o[i].pago != 'E' && o[i].pago !='T');	


		do
		{
			printf("Dar la fecha de la orden (dd/mm/aaaa):  ");
			scanf("%d/%d/%d",&o[i].D, &o[i].M, &o[i].A);

		}while(validarfech(o[i].D,o[i].M,o[i].A)==1 );

	

		printf("\nDesea ingresar otra orden? (1=si, otro=no)\n");
		scanf("%d",&r);
		i++;

	}while(r==1);
	system("cls");
					
	ordenes aux;
	
	for(int k=0;k<5;k++){
	
		
		
		if(o[k].pago=='e' or o[k].pago=='E'){
					
			printf("\n\tTicket %d\n\n",(k+1));
			printf("No de orden: %d\n",o[k].numero_orden);
			printf("El pago se hizo en: Efectivo\n");
			printf("Fecha: %d/%d/%d\n",o[k].D,o[k].M,o[k].A);
			printf("Costo: $%.2f\n",o[k].costo);
			printf("Costo total con envio: $%.2f\n",o[k].totalenvio);
			printf("\n--------------------------------------------------\n");		
		}
		else if(o[k].pago=='t' or o[k].pago=='T'){
			
			printf("\n\tTicket %d\n\n",(k+1));
			printf("No de orden: %d\n",o[k].numero_orden);
			printf("El pago se hizo por: Tarjeta\n");
			printf("Fecha: %d/%d/%d\n",o[k].D,o[k].M,o[k].A);
			printf("Costo: $%.2f\n",o[k].costo);
			printf("Costo total con envio: $%.2f\n",o[k].totalenvio);
			printf("\n--------------------------------------------------\n");
		}		
	
			
	}
	
	FILE*f;
	f=fopen("Ordenes.txt","w");
	if (f==NULL){
		printf("No se ha podido abrir.\n");
	}
	
	for(int k=0;k<5;k++){	
				
		if(o[k].pago=='e' or o[k].pago=='E'){
					
			fprintf(f,"\n\tTicket %d\n\n",(k+1));
			fprintf(f,"No de orden: %d\n",o[k].numero_orden);
			fprintf(f,"El pago se hizo en: Efectivo\n");
			fprintf(f,"Fecha: %d/%d/%d\n",o[k].D,o[k].M,o[k].A);
			fprintf(f,"Costo: $%.2f\n",o[k].costo);
			fprintf(f,"Costo total con envio: $%.2f\n",o[k].totalenvio);
			fprintf(f,"\n--------------------------------------------------\n");		
		}
		else if(o[k].pago=='t' or o[k].pago=='T'){
			
			fprintf(f,"\n\tTicket %d\n\n",(k+1));
			fprintf(f,"No de orden: %d\n",o[k].numero_orden);
			fprintf(f,"El pago se hizo por: Tarjeta\n");
			fprintf(f,"Fecha: %d/%d/%d\n",o[k].D,o[k].M,o[k].A);
			fprintf(f,"Costo: $%.2f\n",o[k].costo);
			fprintf(f,"Costo total con envio: $%.2f\n",o[k].totalenvio);
			fprintf(f,"\n--------------------------------------------------\n");
		}		
	
			
	}	
	

	
	fclose(f);
		
	
}


int menu(){
    int opcion;

    do
    {
	    printf("\n\tAntojitos Gomez");
		printf("\n1. Mostrar todas las ordenes");
		printf("\n2. Mostrar el monto de ventas por dia");
		printf("\n3. Mostrar el monto de ventas por mes");
		printf("\n4. Mostrar el monto de ventas por anio");
		printf("\n5. Mostrar ganancias totales");
		printf("\n6. Agregar otra orden");
		printf("\n7. Terminar");
		printf("\nOpcion: ");
        scanf( "%d", &opcion );

	}while(opcion<1 || opcion>7);

	return opcion;

}



void ordenar(ordenes o[5], int i)
{
system("cls");
printf("\n\tTODAS LAS ORDENES\n\n");
	
	for(int k=0;k<5;k++){
	
		
		
		if(o[k].pago=='e' or o[k].pago=='E'){
					
			printf("No de orden: %d\n",o[k].numero_orden);
			printf("El pago se hizo en: Efectivo\n");
			printf("Fecha: %d/%d/%d\n",o[k].D,o[k].M,o[k].A);
			printf("Costo: $%.2f\n",o[k].costo);
			printf("Costo total con envio: $%.2f",o[k].totalenvio);
			printf("\n--------------------------------------------------\n");		
		}
		else if(o[k].pago=='t' or o[k].pago=='T'){
			
			printf("No de orden: %d\n",o[k].numero_orden);
			printf("El pago se hizo por: Tarjeta\n");
			printf("Fecha: %d/%d/%d\n",o[k].D,o[k].M,o[k].A);
			printf("Costo: $%.2f\n",o[k].costo);
			printf("Costo total con envio: $%.2f",o[k].totalenvio);
			printf("\n--------------------------------------------------\n");
		}		
				
	}

}


void suma(ordenes o[5], int i){
	int k;
	float x=0;
	float y=0;
	if(1==1){
		
		for(k=0;k<i;k++){
			
			y+=o[k].totalenvio;
			x+=o[k].costo;
			
		}
	system("cls");
	printf("\n\tGANANCIAS TOTALES\n\n");		
	printf("\nGanancia total con envios: $%.2f",y);
	printf("\nGanancia total sin envios: $%.2f\n",x);
	printf("\n--------------------------------------------------\n");	
	}
}


void mes(ordenes o[5], int i)
{
	int k;
	float x=0;
	float y=0;	
	int mes,anio;
	printf("Ingrese el mes: ");
	scanf("%d",&mes);
	printf("Ingrese el anio: ");
	scanf("%d",&anio);
	
	FILE*f;
	f=fopen("mes.txt","w");
	if (f==NULL){
		printf("No se ha podido abrir.\n");
	}	
	
	if(1==1){
		for(i=0;i<5;i++)
		{
			if(mes==o[i].M)
			{
				if(anio==o[i].A){
					y+=o[i].totalenvio;
					x+=o[i].costo;
				}
	
			}
		}
		system("cls");
		printf("\n\tGANANCIAS POR MES\n\n");		
		printf("\nGanancia total con envios: $%.2f",y);
		printf("\nGanancia total sin envios: $%.2f\n",x);
		printf("\n--------------------------------------------------\n");
		fprintf(f,"\n\tGANANCIAS POR MES\n\n");		
		fprintf(f,"\nGanancia total con envios: $%.2f",y);
		fprintf(f,"\nGanancia total sin envios: $%.2f\n",x);
		fprintf(f,"\n--------------------------------------------------\n");					
	}
	
	fclose(f);		
	
	return;
}

void dia(ordenes o[5], int i)
{
	int k;
	float x=0;
	float y=0;	
	int dia,mes,anio;
	printf("Ingrese el dia: ");
	scanf("%d",&dia);
	printf("Ingrese el mes: ");
	scanf("%d",&mes);
	printf("Ingrese el anio: ");
	scanf("%d",&anio);
	
	FILE*f;
	f=fopen("dia.txt","w");
	if (f==NULL){
		printf("No se ha podido abrir.\n");
	}	
	
	
	if(1==1){
		for(i=0;i<5;i++)
		{
			if(dia==o[i].D)
			{						
				if(mes==o[i].M)
				{
					if(anio==o[i].A){
						y+=o[i].totalenvio;
						x+=o[i].costo;
					}
		
				}
			}
		}
		system("cls");
		printf("\n\tGANANCIAS POR DIA\n\n");		
		printf("\nGanancia total con envios: $%.2f",y);
		printf("\nGanancia total sin envios: $%.2f\n",x);
		printf("\n--------------------------------------------------\n");
		fprintf(f,"\n\tGANANCIAS POR DIA\n\n");		
		fprintf(f,"\nGanancia total con envios: $%.2f",y);
		fprintf(f,"\nGanancia total sin envios: $%.2f\n",x);
		fprintf(f,"\n--------------------------------------------------\n");				
			
	}
	
	fclose(f);
	return;
}



void anio(ordenes o[5], int i)
{
	int k;
	float x=0;
	float y=0;	
	int anio;

	printf("Ingrese el anio: ");
	scanf("%d",&anio);
	
	FILE*f;
	f=fopen("anio.txt","w");
	if (f==NULL){
		printf("No se ha podido abrir.\n");
	}	
	
	if(1==1){
		for(i=0;i<5;i++)
		{

			if(anio==o[i].A){
				y+=o[i].totalenvio;
				x+=o[i].costo;
			}
	
			
		}
		system("cls");
		printf("\n\tGANANCIAS POR ANIO\n\n");
		printf("\nGanancia total con envios: $%.2f",y);
		printf("\nGanancia total sin envios: $%.2f\n",x);
		printf("\n--------------------------------------------------\n");
		fprintf(f,"\n\tGANANCIAS POR ANIO\n\n");
		fprintf(f,"\nGanancia total con envios: $%.2f",y);
		fprintf(f,"\nGanancia total sin envios: $%.2f\n",x);
		fprintf(f,"\n--------------------------------------------------\n");			
	}
	
	fclose(f);
	return;
}


