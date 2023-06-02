#include <stdio.h>
#include <stdlib.h>
#include "truco.h"

int main(void) {
    unsigned int numa, numb;
    char chara, charb;
    fprintf(stdout,"A continuacion ingrese el numero y el palo de una carta valida\nDonde c es copa, b es basto, o es oro y e es espada\n");
    scanf("%u %c",&(numa), &(chara));
    fprintf(stdout,"Ahora ingrese otra carta\n");
    scanf("%u %c",&(numb), &(charb));
    truco_card a = truco_card_new(numa,chara);
    truco_card b = truco_card_new(numb, charb);
    if (truco_card_win(a,b))
    {
        fprintf(stdout,"El ganador es la carta:\n");
        truco_card_dump(a);
        fprintf(stdout,"El perdedor es la carta:\n");
        truco_card_dump(b);
    } else if (truco_card_win(b,a)) {
        fprintf(stdout,"El ganador es la carta:\n");
        truco_card_dump(b);
        fprintf(stdout,"El perdedor es la carta:\n");
        truco_card_dump(a);
    } else if (truco_card_tie(a,b)) {
        fprintf(stdout,"!La mano esta parda!\n");
        truco_card_dump(a);
        truco_card_dump(b);
    }

    a = truco_card_destroy(a);
    b = truco_card_destroy(b);
    
    return EXIT_SUCCESS;
}