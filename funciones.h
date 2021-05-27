#include <stdio.h>

int validarfech(int A, int B, int C);


int validarfech(int A, int B, int C)
{
	if(C>=1999 && C<=2021)
	{
		if(B>=1&&B<=12){
			switch(B){
				case 1:
				case 3:
				case 5:
				case 7:
				case 8:
				case 12: if(A>=1&&A<=31)
							return 0;
						else{
							printf("Fecha incorrecta\n");
							return (1);
						}
				break;
				case 4:
				case 6:
				case 9:
				case 11: if(A>=1&&A<=30)
							return 0;
						else{
							printf("Fecha incorrecta\n");
							return 1;
						}				
				break;
				case 2: if(C%4==0&&C%100 != 0 || C%400==0)
							return 1;
							if(A>=1&&A<=29)
								return 1;
						else{
							printf("Fecha incorrecta\n");
							return 1;
						}			
				
				
				
			}
			
		}
		else{
			printf("Fecha incorrecta\n");
			return 1;
		}
	}else{
		printf("Fecha incorrecta, el año tiene que ser mayor a 1999 y menor a 2021\n");
		return 1;
		
		
	}
	
	return 0;
	
	
}
