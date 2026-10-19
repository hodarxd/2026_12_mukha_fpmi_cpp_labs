#include <iostream>
#include <random>
void AllocateMatrix(int **&matrix, int m, int n)
{
    matrix = new int *[m];
    for (int i = 0; i < m; i++)
    {
        matrix[i] = new int[n]{};
    }
}

void PrintMatrix(int **matrix, int m, int n)
{
    for (int row = 0; row < m; row++)
    {
        for (int col = 0; col < n; col++)
        {
            std::cout << matrix[row][col] << " ";
        }
        std::cout << std::endl;
    }
}

void InputMatrix(int **matrix, int m, int n)
{
    std::cout << "Input matrix:" << std::endl;
    for (int row = 0; row < m; row++)
    {
        for (int col = 0; col < n; col++)
        {
            std::cin >> matrix[row][col];
        }
    }
}

void DeleteMatrix(int **matrix, int m)
{
    for (int i = 0; i < m; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void arr_sum(int** arr, int rows, int cols, int* sum){
    for(int i = 0; i < rows; i++){
        sum[i] = 0;
        for(int j = 0; j < cols; j++){
            sum[i] += arr[i][j];
        }
    }
}
void sort_select(int* arr, int* idx, int length){
    for (int i = 0; i < length - 1; i++) {
    int minIndex = i;
    for (int j = i + 1; j < length; j++) {
      if (arr[j] < arr[minIndex])
        minIndex = j;
    }
    if (minIndex != i) {
      int temp = arr[i];
      arr[i] = arr[minIndex];
      arr[minIndex] = temp;

      int tempIdx = idx[i];
        idx[i] = idx[minIndex];
        idx[minIndex] = tempIdx;
    }
  }
}

void input_matrix_random(int **matrix, int n, int m){
    double a, b;
    std::cout << "Input range from a to b" << std::endl;
    std::cin >> a >> b;
    std::mt19937 gen(45218965);
    std::uniform_real_distribution<double> dist(a, b);
    for (int row = 0; row < m; row++)
    {
        for (int col = 0; col < n; col++)
        {
            matrix[row][col] = dist(gen);
        }
    }
    
}

int main()
{
    int m, n;
    std::cout << "Input m and n" << std::endl;
    std::cin >> m >> n;
    int **matrix_a;
    int* arr = new int[m];
    int* idx = new int[m];
    for (int i = 0; i < m; i++) {
        idx[i] = i;
    }
    AllocateMatrix(matrix_a, m, n);
    std::cout << "How you want input array: 1 - by hands, 2 - random" << std::endl;
    int choise;
    std::cin >> choise;
    switch (choise)
    {
    case 1:
        InputMatrix(matrix_a, m,n);
    case 2:
        input_matrix_random(matrix_a, m,n);
    default:
        std::cout<<"Try 1 or 2"<<std::endl;
    }
    arr_sum(matrix_a, m, n, arr);
    sort_select(arr, idx, m);
    for (int row = 0; row < m; row++)
    {
        for (int col = 0; col < n; col++)
        {
            std::cout << matrix_a[idx[row]][col] << " ";
        }
        std::cout << std::endl;
    }
    DeleteMatrix(matrix_a, m);
    delete[] arr;
}