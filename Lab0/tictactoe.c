// gcc -Wall -Wextra -Werror -pedantic -std=c99 -c tictactoe.c
// gcc -Wall -Wextra -Werror -pedantic -std=c99 tictactoe.o -o tictactoe
// ./tictactoe

#include <stdlib.h>  /* exit() y EXIT_FAILURE */
#include <stdio.h>   /* printf(), scanf()     */
#include <stdbool.h> /* Tipo bool             */

#include <assert.h>  /* assert() */

#define BOARD_SIZE 7

#define CELL_MAX (BOARD_SIZE * BOARD_SIZE - 1)

void print_sep(int length) {
    printf("\t ");
    for (int i=0; i < length;i++) printf("................");
    printf("\n");

}

void print_board(char board[BOARD_SIZE][BOARD_SIZE])
{
    int cell = 0;

    print_sep(BOARD_SIZE);
    for (int row = 0; row < BOARD_SIZE; ++row) {
        for (int column = 0; column < BOARD_SIZE; ++column) {
            printf("\t | %d: %c ", cell, board[row][column]);
            ++cell;
        }
        printf("\t | \n");
        print_sep(BOARD_SIZE);
    }
}

char get_winner(char board[BOARD_SIZE][BOARD_SIZE])
{   
    // Inicializamos en true variables booleanas 
    // que van a iterar BOARD_SIZE veces
    // sobre las filas y columnas de la matriz, 
    // por caso base de la conjuncion
    bool xWinner = true;        // Gana X horizontalmente
    bool oWinner = true;        // Gana O horizontalmente
    bool vxWinner = true;       // Gana X verticalmente
    bool voWinner = true;       // Gana O verticalmente
    bool diagonal_1_X = true;   // Gana X diagonalmente de izq a der
    bool diagonal_1_O = true;   // Gana O diagonalmente de izq a der
    bool diagonal_2_X = true;   // Gana X diagonalmente de der a izq
    bool diagonal_2_O = true;   // Gana O diagonalmente de der a izq

    // En caso de que ni X ni O ganen, winner es - (empate)
    char winner = '-';

    // Ciclo anidado que itera sobre Filas/Columnas (i) y Columnas/Filas (j)
    for (int i = 0; i < BOARD_SIZE; i++) {

        // Establecemos que siempre que se empiece este ciclo
        // al haber terminado de chequear si hay ganador en
        // las filas, diagonales o columnas correspondientes 
        // a i = 0, inicializamos denuevo los booleanos 
        // en true para comparar de a BOARD_SIZE cantidades 
        xWinner = true;
        oWinner = true;
        vxWinner = true;
        voWinner = true;


        // A partir de la fila/columna i, chequeamos si hay ganador
        for (unsigned int j = 0; j < BOARD_SIZE; j++) {

            xWinner = xWinner && (board[i][j] == 'X');
            oWinner = oWinner && (board[i][j] == 'O');

            vxWinner = vxWinner && (board[j][i] == 'X');
            voWinner = voWinner && (board[j][i] == 'O');
        }

        diagonal_1_X = diagonal_1_X && (board[i][i] == 'X');
        diagonal_1_O = diagonal_1_O && (board[i][i] == 'O');

        diagonal_2_X = diagonal_2_X && (board[abs(i-(BOARD_SIZE-1))][i] == 'X');
        diagonal_2_O = diagonal_2_O && (board[abs(i-(BOARD_SIZE-1))][i] == 'O');

        // Si ya se obtuvo al ganador,
        // lo devolvemos y detenemos la iteracion/funcion
        if (xWinner || vxWinner ) {
            winner = 'X';
            return winner;
        } else if (oWinner || voWinner) {
            winner = 'O';
            return winner;
        }   
    }

    if (diagonal_1_X || diagonal_2_X) {
        winner = 'X';
        return winner;
    } else if (diagonal_1_O || diagonal_2_O) {
        winner = 'O';
        return winner;
    }

    return winner;
}

bool has_free_cell(char board[BOARD_SIZE][BOARD_SIZE])
{
    // Caso base del existe
    bool free_cell=false;

    // Recorremos i filas y j columnas correspondientes
    for (unsigned int i = 0; i < BOARD_SIZE; i++) {
        for (unsigned int j = 0; j < BOARD_SIZE; j++) {
            free_cell = free_cell || (board[i][j] == '-');
        }

        // Luego de recorrer toda una fila,
        // si encontro una celda vacia, terminamos
        if (free_cell)
        {
            return free_cell;
        }
    }

    return free_cell;
}

int main(void)
{
    printf("\n\t |TicTacToe| \n");

    
    char board[BOARD_SIZE][BOARD_SIZE];


    // Inicializamos el tablero de tamanho BOARD_SIZE en '-'
    for (unsigned int i = 0; i < BOARD_SIZE; ++i)
    {
        for (unsigned int j = 0; j < BOARD_SIZE; ++j)
        {
            board[i][j] = '-';
        }
    }
    
    /*
    char board[BOARD_SIZE][BOARD_SIZE] = {
        { '-', '-','-', '-', '-' },
        { '-', '-','-', '-', '-' },
        { '-', '-','-', '-', '-' },
        { '-', '-','-', '-', '-' },
        { '-', '-', '-', '-','-' }
    };
    */

    char turn = 'X';
    char winner = '-';
    int cell = 0;
    while (winner == '-' && has_free_cell(board)) {
        print_board(board);
        printf("\nTurno %c - Elija posición (número del 0 al %d): ", turn,
               CELL_MAX);
        int scanf_result = scanf("%d", &cell);
        if (scanf_result <= 0) {
            printf("Error al leer un número desde teclado\n");
            exit(EXIT_FAILURE);
        }
        if (cell >= 0 && cell <= CELL_MAX) {
            int row = cell / BOARD_SIZE;
            int colum = cell % BOARD_SIZE;
            if (board[row][colum] == '-') {
                board[row][colum] = turn;
                turn = turn == 'X' ? 'O' : 'X';
                winner = get_winner(board);
            } else {
                printf("\nCelda ocupada!\n");
            }
        } else {
            printf("\nCelda inválida!\n");
        }
    }
    print_board(board);
    if (winner == '-') {
        printf("Empate!\n");
    } else {
        printf("Ganó %c\n", winner);
    }
    return 0;
}