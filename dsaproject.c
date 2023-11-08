#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>

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

// Function to create a new node
Node* createNode(int row, int col, int value) {
Node* newNode = (Node*)malloc(sizeof(Node));
newNode->row = row;
newNode->col = col;
newNode->value = value;
newNode->next = NULL;
return newNode;
}

// Function to create a sparse matrix
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

// Function to insert an element into the sparse matrix
void insertElement(SparseMatrix* matrix, int row, int col, int value) {
if (row < 0 || row >= matrix->rows || col < 0 || col >= matrix->cols) {
printf("Invalid row or column index\n");
return;
}
Node* newNode = createNode(row, col, value);
newNode->next = matrix->rows_array[row];
matrix->rows_array[row] = newNode;
}

// Function to print the game board
void GameBoard(SparseMatrix* matrix, int** revealed, int board[4][4]) {
for (int i = 0; i < matrix->rows; i++) {
for (int j = 0; j < matrix->cols; j++) {
if (revealed[i][j] == 1) {
Node* curr = matrix->rows_array[i];
while (curr != NULL) {
if (curr->col == j) {
printf("%d", curr->value);
break;
}
curr = curr->next;
}
printf("%d ", board[i][j]);
} else {
printf(" # ");
}
}
printf("\n\n\n");
}
}

// Function to check if the game is won
int isGameWon(int** revealed, int rows, int cols) {
for (int i = 0; i < rows; i++) {
for (int j = 0; j < cols; j++) {
if (revealed[i][j] == 0) {
return 0;
}
}
}
return 1;
}

int main() {
int rows = 4;
int cols = 4;

srand(time(NULL));

// Define 10 different matrices
int matrices[10][4][4] = {
{{1, 2, 3, 0}, {4, 5, 7, 0}, {1, 2, 3, 6}, {4, 5, 7, 6}},
{{2, 4, 6, 0}, {3, 5, 8, 0}, {2, 4, 6, 7}, {3, 5, 8, 7}},
{{0, 1, 2, 0}, {3, 4, 6, 0}, {0, 1, 2, 5}, {3, 4, 6, 5}},
{{7, 8, 9, 0}, {2, 3, 5, 0}, {7, 8, 9, 4}, {2, 3, 5, 4}},
{{5, 6, 8, 0}, {1, 2, 4, 0}, {5, 6, 8, 3}, {1, 2, 4, 3}},
{{9, 8, 7, 0}, {6, 5, 3, 0}, {9, 8, 7, 2}, {6, 5, 3, 2}},
{{4, 3, 2, 0}, {9, 8, 6, 0}, {4, 3, 2, 1}, {9, 8, 6, 1}},
{{2, 1, 0, 0}, {7, 6, 4, 0}, {2, 1, 0, 9}, {7, 6, 4, 9}},
{{6, 7, 9, 0}, {5, 6, 8, 0}, {6, 7, 9, 2}, {5, 6, 8, 2}},
{{3, 4, 5, 0}, {8, 9, 1, 0}, {3, 4, 5, 8}, {8, 9, 1, 8}},
// Define other matrices here
// ...
};

// Randomly select a matrix for the game
int randomIndex = rand() % 10;
int** selectedMatrix = matrices[randomIndex];

// Create the sparse matrix for the selected game board
SparseMatrix* matrix = createSparseMatrix(rows, cols);
for (int i = 0; i < rows; i++) {
for (int j = 0; j < cols; j++) {
if (selectedMatrix[i][j] != 0) {
insertElement(matrix, i, j, selectedMatrix[i][j]);
}
}
}

// Allocate memory for the revealed matrix
int** revealed = (int**)malloc(rows * sizeof(int*));
if (!revealed) {
printf("Memory allocation failed");
return 1;
}

for (int i = 0; i < rows; i++) {
revealed[i] = (int*)malloc(cols * sizeof(int));
if (!revealed[i]) {
printf("Memory allocation failed");
return 1;
}
for (int j = 0; j < cols; j++) {
revealed[i][j] = 0;
}
}

int totalPairs = (rows * cols) / 2;
int pairsmatched = 0;

while (1) {
printf("Memory Game\n");
GameBoard(matrix, revealed, selectedMatrix);

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
GameBoard(matrix, revealed, selectedMatrix);

printf("Enter the coordinates of the second card (row col): ");
scanf("%d %d", &row2, &col2);
if (row2 < 0 || row2 >= rows || col2 < 0 || col2 >= cols || revealed[row2][col2] == 1) {
printf("Invalid input. Please try again.\n");
revealed[row1][col1] = 0;
continue;
}

revealed[row2][col2] = 1;
GameBoard(matrix, revealed, selectedMatrix);

if (selectedMatrix[row1][col1] == selectedMatrix[row2][col2]) {
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

// Free allocated memory
for (int i = 0; i < rows; i++) {
free(revealed[i]);
}
free(revealed);

return 0;
}
