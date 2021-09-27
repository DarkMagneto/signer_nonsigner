// Didier Teifreto - Septembre 2020
#include <stdio.h> // Utilisation de  putchar et getchar SEULEMENT
#include <string.h> // pour les macros de test 
#include "nombre_signe.h"


// Macros de test des fonctions 
char tab[30];

// Macros de test des fonctions 
#define testEQ(ok,res) sprintf(tab,"%d",res); printString("E:"); printString(tab); sprintf(tab,"%d",ok); printString(", F:"); printString(tab);\
                         if (ok==res){ printString("->OK\n");resOK++;} else {printString("->Erreur\n");resErreur++;}

#define testSTREQ(ok,res) printString("E:\"");printString(res);printString("\" ,F:\"");printString(ok);printString("\"");\
                         if (strcmp(ok,res)==0){ printString("->OK\n");resOK++;} else {printString("->Erreur\n");resErreur++;}

#define testEQ2(var1,var11,var2,var22) sprintf(tab,"%d,%d",var1,var2); printString("E:"); printString(tab);printString(", F:"); \
                        sprintf(tab,"%d,%d",var11,var22);printString(tab);\
                         if ((var1==var11)&&(var2==var22)) { printString("->OK\n");resOK++;}  else {printString("->Erreur\n");resErreur++;}

//entrees et sorties de chaine de caracteres 
void printString(char *s){
    while(*s!=(char)0){
        putchar(*s);
        s++;
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
    int N1=0x42FA8001; // base 10 = 1 123 713 025
    int N2=0xBEC01234; // base 10 = -1 094 708 684
    int N3=0xFFFFFFFF; // base 10 = -1
    int N4=0x7FFFFFFF; // base 10 = 2 147 483 647 
    int N5=0x80000000; // base 10 = -2 147 483 648 
    char res[33];
    int entier,resultat;

    printString("---- bitCount -----\n");
    entier = bitCount(N1);testEQ(entier,10);
    entier = bitCount(N2);testEQ(entier,13);
    entier = bitCount(N3);testEQ(entier,32);
    entier = bitCount(N4);testEQ(entier,31);
    entier = bitCount(N5);testEQ(entier,1);
    entier = bitCount(0);testEQ(entier,0);
	
    printString("---- forDigit -----\n");
	*(res+1)=(char)0;
    *res = forDigit(7,17);printString("erreur base - ");testEQ(*res,'\0');
	*res = forDigit(11,10);printString("erreur digit - ");testEQ(*res,'\0');
	*res = forDigit(7,16);testEQ(*res,'7');
	*res = forDigit(12,16);testEQ(*res,'C');
	
    printString("---- digit -----\n");
    entier = digit('3',17);printString("erreur base - ");testEQ(entier,-1);
    entier = digit('A',10);printString("erreur caractere base - ");testEQ(entier,-1);	
    entier = digit('a',10);printString("erreur caractere base - ");testEQ(entier,-1);			
    entier = digit('g',16);printString("erreur caractere minuscule - ");testEQ(entier,-1);	
    entier = digit('G',16);printString("erreur caractere majuscule - ");testEQ(entier,-1);	
    entier = digit(' ',16);printString("erreur caractere - ");testEQ(entier,-1);
    entier = digit('7',16);testEQ(entier,7);
    entier = digit('A',16);testEQ(entier,10);
    entier = digit('a',16);testEQ(entier,10);						
			


    printString("---- toString -----\n");
    *res=(char)0;
    entier = toString(N1,res,17);printString("erreur base - ");testEQ(entier,1);
    entier = toString(N1,res,16);printString("pas erreur base - ");testEQ(entier,0);
    entier = toString(N2,res,10);testSTREQ(res,"-1094708684");
    entier = toString(N3,res,10);testSTREQ(res,"-1");
    entier = toString(N4,res,10);testSTREQ(res,"2147483647");
    entier = toString(N5,res,10);testSTREQ(res,"-2147483648");
    entier = toString(123,res,10);testSTREQ(res,"123");
    entier = toString(0,res,10);testSTREQ(res,"0");


    printString("---- parseInt correct ----\n");
    entier = parseInt("1123713025",&resultat,10);testEQ2(resultat,1123713025,entier,0);
    entier = parseInt("+1123713025",&resultat,10);testEQ2(resultat,1123713025,entier,0);
    entier = parseInt("-1094708684",&resultat,10);;testEQ2(resultat,-1094708684,entier,0);
    entier = parseInt("2147483647",&resultat,10);testEQ2(resultat,2147483647,entier,0);
    entier = parseInt("-2147483648",&resultat,10);testEQ2(resultat,(int)-2147483648,entier,0);
    entier = parseInt("123",&resultat,10);testEQ2(resultat,123,entier,0);
    entier = parseInt("0",&resultat,10);testEQ2(resultat,0,entier,0);


    printString("---- parseInt erreur ----\n");
    entier = parseInt("2147483648",&resultat,10);printString("2147483648");testEQ(entier,1);
    entier = parseInt("-2147483649",&resultat,10);printString("-2147483649");testEQ(entier,1);
    entier = parseInt("-214748364999",&resultat,10);printString("-214748364999");testEQ(entier,1);
    entier = parseInt("-214748364999",&resultat,10);printString("-214748364999");testEQ(entier,1);

    printString("----- resultat test ----\n");
    printf("resultat OK = %d\n",resOK);
    printf("résultat FAUX = %d\n",resErreur);
    return resErreur;
}
int main(){
    return test();
}