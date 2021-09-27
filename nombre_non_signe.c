// Tp2 Haouche Achour Group A1
#include "nombre_non_signe.h"
#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>


unsigned bitCount(unsigned nombre){
    unsigned rsultat = 0;
    while(nombre>0){
        rsultat = (rsultat + (nombre & 1));
        nombre = nombre >> 1;
    }
    return rsultat;
}

// digit -> caractere
char forDigit(unsigned nombre){
    if(nombre > 9) return (char)(nombre+'A'-10);    
    else return (char)(nombre+'0');    
}

// caractere -> digit
unsigned digit(char caractere){
    if(caractere > '9') return (unsigned)(caractere-'A'+10);
    else
    return (unsigned)(caractere-'0');
}

// entier non signe -> chaine de caracteres hexadecimaux
void toHexString(unsigned nombre,char *res){
    int compteur = 0;
    for(compteur;compteur<8;compteur++){
        *res =(char)forDigit(nombre >> 28);
        nombre =(unsigned) nombre << 4;
        res++;
        }
        *res = (char)0;
}

// entier non signe -> chaine de caracteres binaires
void toBinaryString(unsigned nombre,char *res){
    int cpt = 0;
    for(cpt;cpt<32;cpt++){
        *res=(char)((nombre>>31)+'0');
        nombre =(unsigned) nombre << 1;
        res++;
    }
    *res=(char)0;
}

// entier non signe -> chaine de caracteres
void toUnsignedString(unsigned nombre,char *res,int base){
    unsigned nombre1 = nombre;
    //Taille de la chaine
    do{
        res++;
        nombre1=(unsigned)nombre1/base;
    }while(nombre1!=0);
    //Placerlecaracteredefin
    *res=(char)0;
    //Placer les caracteres depuis la fin
    do{
        res--;
        *res=(char)forDigit(nombre%base);
        nombre=(unsigned)nombre/base;
    }while(nombre!=0);

}

// chaine de caracteres -> entier non signé
unsigned parseUnsignedInt(char *chaine,i++aine))  ;
        chaine++;
        }
    return res ;
}