#include "code.h"


int main(void){

int nb_main = 6;
cullsive cull[nb_main];

srand(time(NULL) + getpid());

cull[0].nb = 0;   // min
cull[1].nb = 250; // max
cull[5].nb = 0;   // compteur

while (1) //ou //cull[5].nb < 10 ou plus ou moin comme 5
{
    // Generer les 3 nombres
    cull[2].nb = rand() % (cull[1].nb - cull[0].nb + 1) + cull[0].nb;
    cull[3].nb = rand() % (cull[1].nb - cull[0].nb + 1) + cull[0].nb;
    cull[4].nb = rand() % (cull[1].nb - cull[0].nb + 1) + cull[0].nb;

    // Ecrire dans Fiche_tout
    ecrire(Dossie, Fiche_tout, &cull[2].nb, &cull[3].nb, &cull[4].nb);

    // Incrementer le compteur
    cull[5].nb++;

    // Tout les 5 tours → lire le fichie
    if (cull[5].nb % 5 == 0)
    {
        printf("\n--- LECTURE APRES %d TOURS ---\n", cull[5].nb);
        lire(Dossie, Fiche_tout);
        printf("\n--- FIN LECTURE ---\n\n");
    }

    sleep(1);
}






printf("\n\n"); 
return 0; 
}
