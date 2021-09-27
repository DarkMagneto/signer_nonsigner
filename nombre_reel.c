// Didier Teifreto - Octobre 2020
#include <stdio.h>
//#include <stdlib.h>
#include <math.h>
// Macro conversion de type reel <-> representation mémoire
#define  FLOAT_TO_INT_BITS(f) ( *(unsigned*)&(f) )
#define  INT_BITS_TO_FLOAT(i) ( *(float*)&(i) )

void testNbrDenormalise(){
        int c; float f,f1;
        c = (0.25+0.5== 0.75);printf("%d, ",c);
        c = (0.2+0.1== 0.3); printf("%d, ",c);
        c = (0.2+0.1-0.3==0);printf("%d, ",c);
		c = (0.2+0.1-0.3< 0.0000000001); printf("%d\n",c);
        f = 1.0/0.0;printf("%f, ",f);
        f = f+1;printf("%f, ",f);
        f1 = -1.0/0.0;printf("%f, ",f1);
        f1 = f + f1;printf("%f, ",f1);
        f = sqrt(-1.0); printf("%f, ",f);
        f = f + 1.0/0.0; printf("%f\n",f);
}

unsigned getSigne(float reel){
    return  FLOAT_TO_INT_BITS(reel);
}

unsigned getExposant(float reel){
    return FLOAT_TO_INT_BITS(reel);
}
unsigned getMantisse(float reel){
    return FLOAT_TO_INT_BITS(reel);
}
float setSigne(float reel,unsigned signe){
    unsigned bits;
    bits = FLOAT_TO_INT_BITS(reel);
    // A écrire
    reel = INT_BITS_TO_FLOAT(bits);
    return reel;
}
float setExposant(float reel,unsigned exposant){
    unsigned bits;
    bits = FLOAT_TO_INT_BITS(reel);
    // A écrire
    reel = INT_BITS_TO_FLOAT(bits);
    return reel;
}
float setMantisse(float reel,unsigned mantisse){
    unsigned bits;
    bits = FLOAT_TO_INT_BITS(reel);
    // A écrire
    reel = INT_BITS_TO_FLOAT(bits);
    return reel;
}
float maximumFloat(){
    float res = 1;
    //while(res+...!=res+1){
        res = res + 1;
    //}
    return res+1;
}
int main() {
    float N1=125.25f,N2=-0.375f,N3=-0.1f,f=0;
    printf("---- Valeurs mémoires de N1 n2 et N3 ----\n");
    printf("%x, , ",FLOAT_TO_INT_BITS(N1));
    printf("%x ",FLOAT_TO_INT_BITS(N2));
    printf("%x\n",FLOAT_TO_INT_BITS(N3));

    printf("---- Signe/Exposant/Mantisse de 125.25 ----\n");
    printf("%d, ",getSigne(N1));
    printf("%d, ",getExposant(N1));
    printf("%x\n",getMantisse(N1));

    printf("---- Signe/Exposant/Mantisse de -0.375 ----\n");
    printf("%d, ",getSigne(N2));
    printf("%d, ",getExposant(N2));
    printf("%x\n",getMantisse(N2));

    printf("---- Signe/Exposant/Mantisse de 0.1 ----\n");
    printf("%d, ",getSigne(N3));
    printf("%d, ",getExposant(N3));
    printf("%x\n",getMantisse(N3));


    printf("---- testNbrDenormalise ----\n");
    testNbrDenormalise();
    
    f=setSigne(f,0); f=setExposant(f,6); f=setMantisse(f,0xFA8000);

    printf("---- Valeur mémoire de  125.25 ----\n");
    printf("%f\n",f);

    f = maximumFloat();
    printf("---- Signe/Exposant/Mantisse de Max-1 ----\n");    
	printf("%f\n",f);
}
