#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


/* Miaow miaow ?? MIAOOOOOOW !!!*/

int reedMiaow(char *miaow){
    int i;
    int miaou = 0;
    for(i=5;i>=0;i--){
        if(miaow[i]<88 && miaow[i]>64){
            miaou+=pow(2,4-i);
        }
    }
    return miaou;
}

void creeateMiaow(char miaou, char *miaow){
    if(miaou==' ') {
        for(int i=0; i<5;i++){
            miaow[4-i]-=32;
            }
            
        return;
    }
    
        
    if(miaou>96 && miaou<123) miaou-=32; 
    miaou-=65;
    int i;
    char  binameow[6];
    for(i=0;i<5;i++){
        binameow[i]=(miaou%2)+48;
        miaou/=2;
    }

    
    for(i=0;i<5;i++){
        if(binameow[i]=='1'){
            miaow[4-i]-=32;
        }
    }
}
void miaowsentenceintoMiaow(char *sentence){
    char  miaow[6]="miaow";
    
    int i;
    for(i=0;i<strlen(sentence);i++){
        miaow[0]='m';
        miaow[1]='i';
        miaow[2]='a';
        miaow[3]='o';
        miaow[4]='w';
        miaow[5]='\0';

        creeateMiaow(sentence[i],miaow);
        printf("%s ",miaow);

    }
    printf("\n");

}
void Mioawtosentense(char *miaow){
    int i;
    char *sentence;
    char miaou[6]="miaow";
    int meow;
    for(i=0;i<strlen(miaow);i+=6){
        for(int j=0;j<5;j++){
            miaou[j]=miaow[i+j];
        }
        meow=reedMiaow(miaou);
        if(meow==31) printf(" ");
        else{
            printf("%c",meow+65);
        }
        
    }
}
int main(){
    char sentence[256];
    char miaow[6]="miaow";
    int i;
    int choice;
    
    printf("1 pour transformer en Miaow, 0 pour revenir logique MIAOW MIAOW\n");
    scanf("%d",&choice);
    FILE *fichier = NULL;
    fichier = fopen("miaow.txt", "r");
    if(fichier!=NULL){
        fgets(sentence,256,fichier);
        fclose(fichier);
    }
    else{
        printf(" MIAOW erreur ouverture fichier MIAOW\n");
    }
    if(choice==1){
        miaowsentenceintoMiaow(sentence);
    }
    else{
        Mioawtosentense(sentence);
    }
    return 0;
}