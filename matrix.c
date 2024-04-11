#include <stdio.h> //표준 입출력을 담당하고 있는 <stdio.h> 헤더파일 선언
#include <stdlib.h> //표준 라이브러리를 담당하고 있는 <stdlib.h> 헤더파일 선언
#include <time.h> //시간을 담당하고 있는 <time.h> 헤더파일 선언

void print_matrix(int **matrix, int ROW, int COLUMN); //행렬을 출력하는 함수 원형 선언
void addition_matrix(int **matrix_A, int **matrix_B, int ROW, int COLUMN); //행렬의 덧셈 함수 원형 선언
void subtraction_matrix(int **matrix_A, int **matrix_B, int ROW, int COLUMN); //행렬의 뺄셈 함수 원형 선언
void transpose_matrix(int **matrix, int ROW, int COLUMN); //행렬을 전치하는 함수 원형 선언
void multiply_matrix(int **matrix_A, int **matrix_B, int ROW_A, int COLUMN_A, int ROW_B, int COLUMN_B); //행렬의 곱셈 함수 원형 선언

int main(void) //main 함수 시작
{
    printf("[----- [배정민] [2023041088] -----]\n");

    int row; //int형의 row변수 선언
    int column; //int형의 column변수 선언

    scanf("%d %d", &row, &column); //row와 column값을 입력받기

    int **matrix_A = (int **)malloc(row * sizeof(int *)); //matrix_A를 이중포인터를 활용해 동적할당 받기
    int **matrix_B = (int **)malloc(row * sizeof(int *)); //matrix_B를 이중포인터를 활용해 동적할당 받기
    
    for (int i = 0; i < row; i++) //행의 크기만큼 for문 반복
    {
        matrix_A[i] = (int *)malloc(column * sizeof(int)); //matrix_A의 열을 동적할당 받기
        matrix_B[i] = (int *)malloc(column * sizeof(int)); //matrix_B의 열을 동적할당 받기
    }

    for(int j = 0; j < row; j++) //행의 크기만큼 for문 반복
    {
        for(int k = 0; k < column; k++) //열의 크기만큼 for문 반복
        {
            matrix_A[j][k] = (rand() % 100) + 1; //matrix_A 행렬의 요소에 랜덤값 넣기
            matrix_B[j][k] = (rand() % 100) + 1; //matrix_B 행렬의 요소에 랜덤값 넣기
        }
    }

    printf("Matrix A\n"); //Matrix A 출력
    print_matrix(matrix_A, row, column); //print_matrix함수 호출
    printf("\nMatrix B\n"); //Matrix B 출력
    print_matrix(matrix_B, row, column); //print_matrix함수 호출

    printf("\nMatrix A + Matrix B\n"); //Matrix A + Matrix B 출력
    addition_matrix(matrix_A, matrix_B, row, column); //addition_matrix함수 호출

    printf("\nMatrix A - Matrix B\n"); //Matrix A - Matrix B 출력
    subtraction_matrix(matrix_A, matrix_B, row, column); //subtraction_matrix함수 호출

    printf("\nTranspose Matrix A\n"); //Transpose Matrix A 출력
    transpose_matrix(matrix_A, row, column); //transpose_matrix함수 호출

    printf("\nTranspose Matrix B\n"); //Transpose Matrix B 출력
    transpose_matrix(matrix_B, row, column); //transpose_matrix함수 호출

    printf("\nMatrix A * Matrix B\n"); //Matrix A * Matrix B 출력
    multiply_matrix(matrix_A, matrix_B, row, column, row, column); //multiply_matrix함수 호출    

    for(int k = 0; k < row; k++) //행의 크기만큼 for문 반복
    {
        free(matrix_A[k]); //matrix_A 열의 메모리 해제
        free(matrix_B[k]); //matrix_B 열의 메모리 해제
    }
    free(matrix_A); //matrix_A 행의 메모리 해제
    free(matrix_B); //matrix_B 행의 메모리 해제

    return 0; //0값 반환
}

void print_matrix(int **matrix, int ROW, int COLUMN) //행렬을 출력하는 함수 정의
{
    for(int i = 0; i < ROW; i++) //행의 크기만큼 for문 반복
    {
        for(int j = 0; j < COLUMN; j++) //열의 크기만큼 for문 반복
        {
            printf("%d ", matrix[i][j]); //행렬의 요소 출력
        }
        printf("\n"); //줄바꿈
    }
}

void addition_matrix(int **matrix_A, int **matrix_B, int ROW, int COLUMN) //행렬의 덧셈 함수 정의
{
    int **matrix_C = (int **)malloc(ROW * sizeof(int *)); //matrix_C를 이중포인터를 활용해 동적할당 받기
    
    for (int i = 0; i < ROW; i++) //행의 크기만큼 for문 반복
    {
        matrix_C[i] = (int *)malloc(COLUMN * sizeof(int)); //matrix_C의 열을 동적할당 받기
    }

    for(int i = 0; i < ROW; i++) //행의 크기만큼 for문 반복
    {
        for(int j = 0; j < COLUMN; j++) //열의 크기만큼 for문 반복
        {
            matrix_C[i][j] = matrix_A[i][j] + matrix_B[i][j]; //matrix_C의 요소에 matrix_A의 요소와 matrix_B의 요소를 더한 값 넣기
        }
    }

    print_matrix(matrix_C, ROW, COLUMN); //print_matrix함수 호출

    free(matrix_C); //matrix_C 행렬 메모리 해제
}

void subtraction_matrix(int **matrix_A, int **matrix_B, int ROW, int COLUMN) //행렬의 뺄셈 함수 정의
{
    int **matrix_C = (int **)malloc(ROW * sizeof(int *)); //matrix_C를 이중포인터를 활용해 동적할당 받기
    for (int i = 0; i < ROW; i++) //행의 크기만큼 for문 반복
    {
        matrix_C[i] = (int *)malloc(COLUMN * sizeof(int)); //matrix_C의 열을 동적할당 받기
    }

    for(int i = 0; i < ROW; i++) //행의 크기만큼 for문 반복
    {
        for(int j = 0; j < COLUMN; j++) //열의 크기만큼 for문 반복
        {
            matrix_C[i][j] = matrix_A[i][j] - matrix_B[i][j]; //matrix_C의 요소에 matrix_A의 요소에서 matrix_B의 요소를 뺀 값 넣기
        }
    }

    print_matrix(matrix_C, ROW, COLUMN); //print_matrix함수 호출

    free(matrix_C); //matrix_C 행렬 메모리 해제
}

void transpose_matrix(int **matrix, int ROW, int COLUMN) //행렬을 전치하는 함수 정의
{
    int **matrix_C = (int **)malloc(COLUMN * sizeof(int *)); //matrix_C를 이중포인터를 활용해 동적할당 받기
    for (int i = 0; i < COLUMN; i++) //행의 크기만큼 for문 반복
    {
        matrix_C[i] = (int *)malloc(ROW * sizeof(int)); //matrix_C의 열을 동적할당 받기
    }

    for(int i = 0; i < ROW; i++) //행의 크기만큼 for문 반복
    {
        for(int j = 0; j < COLUMN; j++) //열의 크기만큼 for문 반복
        {
            matrix_C[j][i] = matrix[i][j]; //matrix_C의 요소에 matrix의 요소를 전치한 값 넣기
        }
    }

    print_matrix(matrix_C, COLUMN, ROW); //print_matrix함수 호출

    free(matrix_C); //matrix_C 행렬 메모리 해제
}

void multiply_matrix(int **matrix_A, int **matrix_B, int ROW_A, int COLUMN_A, int ROW_B, int COLUMN_B) //행렬의 곱셈 함수 정의
{

    int **matrix_C = (int **)malloc(ROW_A * sizeof(int *)); //matrix_C를 이중포인터를 활용해 동적할당 받기

    for (int i = 0; i < ROW_A; i++) //행의 크기만큼 for문 반복
    {
        matrix_C[i] = (int *)malloc(COLUMN_B * sizeof(int)); //matrix_C의 열을 동적할당 받기
    }

    for(int i = 0; i < ROW_A; i++) //행의 크기만큼 for문 반복
    {
        for(int j = 0; j < COLUMN_B; j++) //열의 크기만큼 for문 반복
        {
            matrix_C[i][j] = 0; //matrix_C의 요소를 0으로 초기화
            for(int k = 0; k < COLUMN_A; k++) //COLUMN_A의 크기만큼 for문 반복
            {
                matrix_C[i][j] += matrix_A[i][k] * matrix_B[k][j]; //matrix_C의 요소에 matrix_A의 요소와 matrix_B의 요소를 곱한 값 넣기
            }
        }
    }

    print_matrix(matrix_C, ROW_A, COLUMN_B); //print_matrix함수 호출

    free(matrix_C); //matrix_C 행렬 메모리 해제.
}