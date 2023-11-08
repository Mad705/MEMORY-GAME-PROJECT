#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
typedef struct Node {
    int row;
    int col;
     int value;
    struct Node* next;
} Node;

typedef struct SparseMatrix {
    int rows;
    int cols;
    Node** rows_array; 
} SparseMatrix;

Node* createNode(int row, int col, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->row = row;
    newNode->col = col;
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

SparseMatrix* createSparseMatrix(int rows, int cols) {
    SparseMatrix* matrix = (SparseMatrix*)malloc(sizeof(SparseMatrix));
    matrix->rows = rows;
    matrix->cols = cols;
    matrix->rows_array = (Node**)malloc(rows * sizeof(Node*));
    for (int i = 0; i < rows; i++) {
        matrix->rows_array[i] = NULL;
    }
    return matrix;
}

void insertElement(SparseMatrix* matrix, int row, int col, int value) {
     
    Node* newNode = createNode(row, col, value);
    newNode->next = matrix->rows_array[row];
    matrix->rows_array[row] = newNode;
}

void printSparseMatrix(SparseMatrix* matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        Node* curr = matrix->rows_array[i];
        while (curr != NULL) {
            printf("%d \n", curr->value);
            curr = curr->next;
        }
    }
}
void GameBoard(struct SparseMatrix* matrix, int** revealed, int board[4][4]) {
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            if (revealed[i][j] == 1) {
                struct Node* curr = matrix->rows_array[i];
                 printf("   %d   ",board[i][j]);                
            }
            else {
                printf("   #   ");
            }
        }
        printf("\n\n\n");
    }
}

int main() {
    int rows = 4;
    int cols = 4;

    struct SparseMatrix* matrix = createSparseMatrix(rows, cols);

    int board[4][4] = {
        {1, 2, 3, 0},
        {4, 5, 7, 0},
        {1, 2, 3, 6}, 
        {4, 5, 7, 6}
    };

    int** revealed = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        revealed[i] = (int*)malloc(cols * sizeof(int));
        if (!revealed[i]) {
            return 0; 
        }
        for (int j = 0; j < cols; j++) {
            revealed[i][j] = 0;  
        }
    }

    int totalPairs = (rows*cols)/2;
    int pairsmatched = 0;

    while (1) {

        printf("Memory Game\n");
        GameBoard(matrix,revealed,board);

        if (pairsmatched == totalPairs) {
            printf("You won the game!\n");
            break;
        }

        int row1, col1, row2, col2;

        printf("Enter the coordinates of the first card (row col): ");
        scanf("%d %d", &row1, &col1);
        if (row1 < 0 || row1 >= rows || col1 < 0 || col1 >= cols || revealed[row1][col1] == 1) {
            printf("Invalid input. Please try again.\n");
            continue;
        }

        revealed[row1][col1] = 1;
        GameBoard(matrix,revealed,board);

        printf("Enter the coordinates of the second card (row col): ");
        scanf("%d %d", &row2, &col2);
        if (row2 < 0 || row2 >= rows || col2 < 0 || col2 >= cols || revealed[row2][col2] == 1) {
            printf("Invalid input. Please try again.\n");
            revealed[row1][col1] = 0; 
            continue;
        }

        revealed[row2][col2] = 1;
        GameBoard(matrix,revealed,board);

        if (board[row1][col1] == board[row2][col2]) {
            printf("You've found a pair!\n");
            pairsmatched++;
        } else {
            printf("Try again.\n");
            revealed[row1][col1] = 0;
            revealed[row2][col2] = 0;
            Sleep(3000);
            system("cls");
            printf("Try again.\n");
        }
    }

    for (int i = 0; i < rows; i++) {
        free(revealed[i]);
    }
    free(revealed);

    return 0;
}