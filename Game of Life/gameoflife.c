#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** copy_board(char **board, int size){
    char **copy;
    copy = (char **)malloc(size * sizeof(char *));
    for(int i = 0; i < size; i++){
        copy[i] = (char *)malloc(size * sizeof(char));
        for(int j = 0; j < size; j++){
            copy[i][j] = board[i][j];
        }
    }
    return copy;
}
void change_status(char **board, int row, int column, int live_neighbors){
    if(board[row][column] == 'x'){
        if(live_neighbors < 2 || live_neighbors >3){
            board[row][column] = '.';
        }
        else{
            board[row][column] = 'x';
        }
    }
    else if(board[row][column] == '.'){
        if(live_neighbors == 3){
            board[row][column] = 'x';
        }
        else{
            board[row][column] = '.';
        }
    }
}

void check_neighbors(char **board, char **copy, int row, int column, int size){
    int neighbors[8][2] = {{-1,-1}, {0,-1}, {1,-1}, {1,0}, {1,1}, {0,1}, {-1,1}, {-1,0}};
    int live_neighbors = 0;

    for(int i = 0; i < 8; i++){
        if(copy[(row + neighbors[i][0]+size) % size][(column+neighbors[i][1]+size)%size] == 'x'){
            live_neighbors++;
        }
    }

    change_status(board, row, column, live_neighbors);
}
void play_game(char **board, int ticks, int size){
    for(int i = 0; i < ticks; i++){
        char **copy = copy_board(board, size);
        for(int rows = 0; rows < size; rows++){
            for(int columns = 0; columns < size; columns++){
                check_neighbors(board, copy, rows, columns, size);
            }
        }
    }
}
void print_board(char **board, int size){
    int i, j;
    for(i = 0; i < size; i++){
        for(j = 0; j<size; j++){
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
}


int main(int argc, char *argv[]){
    /* check input */
    if(argc != 3){
        printf("\n INVALID INPUT");
        printf("Usage: %s <seed_file> <ticks>\n", argv[0]);
        exit(0);
    }

    /* open file of name argv[1] */
    FILE *file=fopen(argv[1], "r");
    if(file == NULL){
        printf("\n INVALID FILE: can't open file %s", argv[1]);
        exit(0);
    }

    int ticks = atoi(argv[2]);
    char line[1000];
    int size, i, j;
    char **board;

    /* get size n from the first line*/
    if (fgets(line, sizeof(line), file) != NULL)
        size = strlen((const char *)line) -1;

    board = (char **)malloc(size * sizeof(char *));
    for (i=0; i<size; i++) {
        board[i] = (char *)malloc(size * sizeof(char));
        for (j=0; j<size; j++) {
            board[i][j] = line[j];
        }
        /* get next line */
        if (i < size-1 && fgets(line, sizeof(line), file) == NULL) {
            exit(0);
        }
    }

    play_game(board, ticks, size);
    print_board(board, size);

}
