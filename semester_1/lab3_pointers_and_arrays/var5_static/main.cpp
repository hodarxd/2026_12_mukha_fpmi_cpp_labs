#include <iostream>
#include <random>

const int MAX_SIZE = 1000000;

int input_array(int *arr, int n)
{
    std::cout << "Input elements of array" << std::endl;
    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }
    return arr[n];
}

int input_array_random(int *arr, int n)
{
    int a, b;
    std::cout << "Input range from a to b" << std::endl;
    std::cin >> a >> b;
    std::mt19937 gen(45218965);
    std::uniform_int_distribution<int> dist(a, b);
    for (int i = 0; i < n; i++)
    {
        arr[i] = dist(gen);
    }
    return arr[n];
}

void output_array(int *arr, int length)
{
    std::cout << "Array: ";
    for (int i = 0; i < length; i++)
    {
        std::cout << arr[i] << '\t';
    }
}

int var_5(int *arr, int length, int t)
{
    int count = length - 1;
    for (int i = 0; i < length; i++)
    {
        if (arr[i] == t)
        {
            arr[i] = 0;
            int y = i;
            while (i != count)
            {
                int emp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = emp;
                i++;
            }
            i = y - 1;
            count--;
        }
    }
    return arr[length];
}

int main()
{
    int n, t;
    int arr[MAX_SIZE];
    std::cout << "Input size of array and t" << std::endl;
    std::cin >> n >> t;
    std::cout << "How you want input array: 1 - by hands, 2 - random" << std::endl;
    int choise;
    std::cin >> choise;
    if (choise == 1)
    {
        arr[n] = input_array(arr, n);
    }
    else if (choise == 2)
    {
        arr[n] = input_array_random(arr, n);
    }
    else
    {
        std::cout << "Try 1 or 2" << std::endl;
    }
    output_array(arr, n);
    arr[n] = var_5(arr, n, t);
    output_array(arr, n);
}