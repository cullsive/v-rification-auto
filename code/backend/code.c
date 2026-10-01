#include "code.h"


//--------------------------Ecrire-----------------------------------------


void ecrire(const char* dossiT , const char* ficheT, int* EntiZ1 , int* EntiZ2 , int *EntiZ3){

DIR* dossie = opendir(dossiT); 

if(!dossie){
    perror("opendir_ecrire"); 
    exit(1); 
}



FILE* fiche = fopen(ficheT , "a"); 

if(!fiche){
    printf("non valider_ecrire"); 
    closedir(dossie); 
    return; 
}


fprintf(fiche,"%d %d %d : \n",*EntiZ1 ,*EntiZ2,*EntiZ3); 
printf(Mr"LT+ \033[0;m:\033[0;36m %d %d %d\n"COLOR_END,*EntiZ1 ,*EntiZ2,*EntiZ3);
fclose(fiche); 

closedir(dossie);
}



// --------------------------ecrire 2--------------------------------------



void ecrire2(const char* dossiT , const char* ficheT, int* EntiZ1 , int* EntiZ2 , int *EntiZ3){

DIR* dossie = opendir(dossiT); 

if(!dossie){
    perror("opendir_ecrire"); 
    exit(1); 
}



FILE* fiche = fopen(ficheT , "a"); 

if(!fiche){
    printf("non valider_ecrire"); 
    closedir(dossie); 
    return; 
}


fprintf(fiche,"{ %d , %d , %d }\n",*EntiZ1 ,*EntiZ2,*EntiZ3); 
fclose(fiche); 

closedir(dossie);
}




//---------------------------Lire-----------------------------------------



long position_lecture = 0;   // position dans le fichier

void lire(const char* dossiT , const char* ficheT)
{
    DIR* dossie = opendir(dossiT);
    if(!dossie){
        perror("opendir_lire");
        exit(1);
    }

    FILE* fiche = fopen(ficheT , "r");
    if(!fiche){
        printf("non valider_lire");
        closedir(dossie);
        return;
    }

    // 🔥 Aller à la dernière position connue
    fseek(fiche, position_lecture, SEEK_SET);

    char ligne[1024];
    int a, b, c;

    while (fgets(ligne, sizeof(ligne), fiche) != NULL)
    {
        if (sscanf(ligne, "%d %d %d", &a, &b, &c) == 3)
        {
            if (a < b && b < c && c > a)
                ecrire2(Dossie, Fiche_valider, &a , &b, &c);
            else
                ecrire2(Dossie, Fiche_non_valider, &a , &b, &c);
        }
        sleep(1);
    }

    // 🔥 Sauvegarder la nouvelle position
    position_lecture = ftell(fiche);

    fclose(fiche);
    closedir(dossie);
}
