// TP2 PINSELLO Valentin
#include "nombre_signe.h"
#include <stdio.h>

#define srl(a,b) (int)((unsigned)a >> (unsigned)b);

unsigned bitCount(int nombre)
{
    unsigned res = 0;
    
    while(nombre != 0)
    {
        res += nombre&1;
        nombre = srl(nombre,1);
    }
    
    return res;
}

char forDigit(int nombre,int base)
{
	if((base < 2 || base > 16) || (nombre%base != nombre))
	{
		return (char)0;
	}
	else
	{
		char tab[16]="0123456789ABCDEF";
    	return tab[nombre%base];
	}
}

int digit(char caractere,int base)
{
	if(base < 2 || base > 16){return -1;}
	
	if(caractere > '9')
    {
    	if(caractere >= 'a' && caractere <= 'f')
    	{
    		if(((int)caractere - 'a' + 10)%base != ((int)caractere - 'a' + 10)){return -1;}
    		else return (int)caractere - 'a' + 10;
    	}
        else if(caractere >= 'A' && caractere <= 'F')
        {
        	if(((int)caractere - 'A' + 10)%base != ((int)caractere - 'A' + 10)){return -1;}
    		else return (int)caractere - 'A' + 10;
        }
        else
        {
        	return -1;
        }
    }
    else
    {
    	if(((int)caractere - '0')%base != ((int)caractere - '0')){return -1;}
    	else return (int)caractere - '0';
    }
}

int toString(int nombre,char *res,int base)
{
	if(base < 2 || base > 16){return 1;}

    int nombreCpy = nombre;
    
    if(nombre < 0)
    {
    	*res = '-';
    	res++;

    	do
	    {
	        nombreCpy /= base;
	        res++;
	    }
	    while (nombreCpy != 0);
	    
	    *res = (char)0;
	    
	    do
	    {
	        res--;
	        *res = forDigit(-nombre%base & 0xF,base);
	        nombre /= base;
	    }
	    while(nombre != 0);
    }
    else
    {
    	do
	    {
	        nombreCpy /= base;
	        res++;
	    }
	    while (nombreCpy != 0);
	    
	    *res = (char)0;
	    
	    do
	    {
	        res--;
	        *res = forDigit(nombre%base,base);
	        nombre /= base;
	    }
	    while(nombre != 0);
    }
    
    return 0;
}

int parseInt(char *chaine,int *resultat,int base)
{
	if(base < 2 || base > 16){return 1;}

	if(*chaine == '-')
	{
		*chaine++;
		*resultat = 0;

		if(*chaine == '0')
		{
			return 0;
		}

	    while(*chaine != (char)0)
	    {
	    	int res = digit((char)*chaine,base);

	    	if(res == -1){return 1;}
	    	else
	    	{
	    		int previousResultat = *resultat;
	    		*resultat = *resultat * base + res;
	    		if(previousResultat < *resultat){chaine++;}
	    		else{return 1;}
	    	}
	    }

	    *resultat = -*resultat;
	}
	else
	{
		if(*chaine == '+'){*chaine++;}

		*resultat = 0;

		if(*chaine == '0')
		{
			return 0;
		}

	    while(*chaine != (char)0)
	    {
	    	int res = digit((char)*chaine,base);

	        if(res == -1){return 1;}
	    	else
	    	{
	    		int previousResultat = *resultat;
	    		*resultat = *resultat * base + res;
	    		if(previousResultat < *resultat){chaine++;}
	    		else{return 1;}
	    	}
	    }

	    if(*resultat == -2147483648){return 1;}
	}

    return 0;
}
