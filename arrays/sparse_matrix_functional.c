#include <stdio.h>
#define ROWS 4
#define COLS 4
/*This C program is used to check if a matrix is a sparse Matrix. If the number of zeros in a matrix exceeds (ROWS*COLS)/2, where ROWS, COLS is the dimension of the matrix, matrix is sparse matrix. Sparse matrix has more zero elements than nonzero elements.
 */
void findSparseMatrix(int matrix[ROWS][COLS]);

void initMatrix(int matrix[ROWS][COLS],
                int (*init)(int, int)) {
  for(int i = 0; i < ROWS; i++){
    for(int j = 0; j < COLS; j++){
      matrix[i][j] = (*init)(i, j);
    }
  }
}

int setZero(int i, int j) {
  return 0;
}

int setProduct(int i, int j) {
  return i * j;
}

int setDiagonal(int i, int j) {
  return i == j ? 1 : 0;
}

void printMatrix(int matrix[ROWS][COLS]) {
  printf("\n");
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      printf("%7d", matrix[i][j]);
    }
    printf("\n");
  }
}

int main(){
  int matrix[ROWS][COLS];

  initMatrix(matrix, setZero);
  printMatrix(matrix);
  
  initMatrix(matrix, setDiagonal);
  printMatrix(matrix);

  initMatrix(matrix, setProduct);
  printMatrix(matrix);
  
  /*for(int i = 0; i < ROWS; i++){
    for(int j = 0; j < COLS; j++){
      matrix[i][j] = i * j;
      // matrix[i][j] = 0;
       
    }
    }*/

  findSparseMatrix(matrix);
  return 0;
}

void findSparseMatrix(int matrix[ROWS][COLS]){
  int sparse_counter;
  for(int i = 0; i < ROWS; i++){
    for(int j = 0; j < COLS; j++){
      if (matrix[i][j] == 0){
        ++sparse_counter;      
      }
    }
  }
  if (sparse_counter > ((ROWS * COLS )/ 2))
    printf("The given matrix is sparse \n");
  else
    printf("The given matrix is not a Sparse Matrix \n"); 
  printf("There are %d number of zeros. \n", sparse_counter);
}
