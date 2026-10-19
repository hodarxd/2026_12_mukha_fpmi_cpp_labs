#include <iostream>
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

int main()
{
    int m, n, p;
    std::cout << "Input m and n and p" << std::endl;
    std::cin >> m >> n >> p;
    int **matrix_a;
    int **matrix_b;
    int **matrix_c;
    AllocateMatrix(matrix_a, m, n);
    InputMatrix(matrix_a, m, n);
    AllocateMatrix(matrix_b, n, p);
    InputMatrix(matrix_b, n, p);
    AllocateMatrix(matrix_c, m, p);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < p; j++)
        {
            int k = 0;
            while (k < n)
            {
                matrix_c[i][j] += matrix_a[i][k] * matrix_b[k][j];
                k++;
            }
        }
    }
    PrintMatrix(matrix_c, m, p);
    DeleteMatrix(matrix_a, m);
    DeleteMatrix(matrix_b, n);
    DeleteMatrix(matrix_c, m);
}