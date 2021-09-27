// Didier Teifreto - Septembre 2020
#include <stdio.h> // 
#include <string.h> // pour les macros de test
#include "nombre_non_signe.h"

char tab[30];

// Macros de test des fonctions 

#define testEQ(ok,res) sprintf(tab,"%u",res); printString("E:"); printString(tab); sprintf(tab,"%u",ok); printString(", F:"); printString(tab);\
                         if (ok==res){ printString("->OK\n");resOK++;} else {printString("->Erreur\n");resErreur++;}



#define testSTREQ(ok,res) printString("E:\"");printString(res);printString("\" ,F:\"");printString(ok);\
                        printString("\"");if (strcmp(ok,res)==0){ printString("->OK\n");resOK++;} \
                         else {printString("->Erreur\n");resErreur++;}

//entrees et sorties de chaine de caracteres 
void printString(char *s){
    char c;
    c=*s;
    while(c!=(char)0){
        putchar(c);
        s++;
        c=*s;
    }
}
void readString(char *res){
    char c;
    do{
        c=getchar();
        *res=c;
        res++;
    }while(c!='\n');
    *(res-1)=(char)0;
}
int test() {
    int resOK=0,resErreur=0;
    unsigned N1=0x42FA8001; // en base 10 = 1 123 713 025
    unsigned N2=0xBEC01234; // en base 10 = 3 200 258 612
    unsigned N3=0xFFFFFFFF; // en base 10 = 4 294 967 295
    char res[33];
    unsigned entier;

    printString("---- bitCount -----\n");
    entier = bitCount(N1);testEQ(entier,10);
    entier = bitCount(N2);testEQ(entier,13);
    entier = bitCount(N3);testEQ(entier,32);
    entier = bitCount(123);testEQ(entier,6);
    entier = bitCount(0);testEQ(entier,0);

    printString("---- forDigit ----\n");
    *(res+1)=(char)0;
    *res=forDigit(6);testEQ(*res,'6');
    *res=forDigit(8);testEQ(*res,'8');
    *res=forDigit(9);testEQ(*res,'9');
    *res=forDigit(0xA);testEQ(*res,'A');
    *res=forDigit(0xB);testEQ(*res,'B');

    printString("---- digit ----\n");
    *(res+1)=(char)0;    
    entier = digit('7');testEQ(entier,7); 
    entier = digit('9');testEQ(entier,9);
    entier = digit('A');testEQ(entier,0xA); 
    entier = digit('C');testEQ(entier,0xC);


    printString("---- toHexString ----\n");
    toHexString(N1,res);testSTREQ(res,"42FA8001");
    toHexString(N2,res);testSTREQ(res,"BEC01234");
    toHexString(N3,res);testSTREQ(res,"FFFFFFFF");
    toHexString(123,res);testSTREQ(res,"0000007B");
    toHexString(0,res);testSTREQ(res,"00000000");

    printString("---- toBinaryString ----\n");
    toBinaryString(N1,res);testSTREQ(res,"01000010111110101000000000000001");
    toBinaryString(N2,res);testSTREQ(res,"10111110110000000001001000110100");
    toBinaryString(N3,res);testSTREQ(res,"11111111111111111111111111111111");
    toBinaryString(123,res);testSTREQ(res,"00000000000000000000000001111011");
    toBinaryString(0,res);testSTREQ(res,"00000000000000000000000000000000");

    
    printString("---- toUnsignedString -----\n");
    toUnsignedString(N1,res,10);testSTREQ(res,"1123713025");
    toUnsignedString(N2,res,16);testSTREQ(res,"BEC01234");
    toUnsignedString(N3,res,10);testSTREQ(res,"4294967295");
    toUnsignedString(123,res,10);testSTREQ(res,"123");
    toUnsignedString(0,res,10);testSTREQ(res,"0");


    printString("---- parseUnsignedInt ----\n");
    entier = parseUnsignedInt("1123713025",10);testEQ(entier,1123713025);
    entier = parseUnsignedInt("BEC01234",16);testEQ(entier,(unsigned)3200258612);
    entier = parseUnsignedInt("4294967295",10);testEQ(entier,(unsigned)4294967295);
    entier = parseUnsignedInt("123",10);testEQ(entier,123);
    entier = parseUnsignedInt("0",10);testEQ(entier,0);    


    printString("----- resultat test ----\n");
    printf("résultat(s) correct(s)=%u\n",resOK);
    printf("résultat(s) inexact(s) %u\n",resErreur);
    return resErreur;
}
int main(){
    return test();
}
