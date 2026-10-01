#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h> 
#include <time.h>
#include <dirent.h>

#define Dossie "../test"
#define Fiche_tout "../test/TOUT.txt"
#define Fiche_non_valider "../test/non_valider.txt"
#define Fiche_valider "../test/valider.txt"

// -----------------color-----------------------
#define Mr "\033[0;35m"
#define MrT "\033[0;36m"
#define COLOR_END "\033[0m"
// -----------------color-----------------------


typedef struct cullsive{

int nb; 

}cullsive; 


// ------------------------------------------------------------------

void ecrire(const char* dossiT , const char* ficheT, int* EntiZ1 , int* EntiZ2 , int *EntiZ3); 

void lire(const char* dossiT , const char* ficheT);


// ------------------------ecrire 2-----------------------------
void ecrire2(const char* dossiT , const char* ficheT, int* EntiZ1 , int* EntiZ2 , int *EntiZ3);
// -----------------------------------------------------
// ------------------------------------------------------------------
