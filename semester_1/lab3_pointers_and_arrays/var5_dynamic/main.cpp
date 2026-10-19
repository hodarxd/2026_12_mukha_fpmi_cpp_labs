#include <iostream>
#include <random>

void input_array(double *arr, int n)
{
    std::cout << "Input elements of array" << std::endl;
    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }
}

void input_array_random(double *arr, int n)
{
    double a, b;
    std::cout << "Input range from a to b" << std::endl;
    std::cin >> a >> b;
    std::mt19937 gen(45218965);
    std::uniform_real_distribution<double> dist(a, b);
    for (int i = 0; i < n; i++)
    {
        arr[i] = dist(gen);
    }
}

void output_array(double *arr, int length)
{
    std::cout << "Array: ";
    for (int i = 0; i < length; i++)
    {
        std::cout << arr[i] << '\t';
    }
    std::cout << std::endl;
}

bool var_7(double *arr, int length)
{
    int counter = 0;
    for (int i = 0; i < length; i++)
    {
        int num = static_cast<int>(arr[i]);
        if (num >= 0 && num <= 10)
        {
            counter++;
        }
    }
    
    if (counter > ((length + 1) / 2))
    {
        std::cout << "Cant solve" << std::endl;
        return false;
    }

    int target_idx = 0;
    for (int i = 0; i < length; i++)
    {
        int num = static_cast<int>(arr[i]);
        if (num >= 0 && num <= 10)
        {
            int target_pos = target_idx * 2;
            if (target_pos < i) {
                double temp = arr[i];
                for (int k = i; k > target_pos; k--) {
                    arr[k] = arr[k - 1];
                }
                arr[target_pos] = temp;
            }
            target_idx++;
        }
    }
    return true;
}

int main()
{
    int n;
    std::cout << "Input size of array" << std::endl;
    std::cin >> n;
    
    if (n <= 0) {
        std::cout << "Invalid size!" << std::endl;
        return 1;
    }

    double *arr = new double[n];
    
    std::cout << "How you want input array: 1 - by hands, 2 - random" << std::endl;
    int choise;
    std::cin >> choise;
    
    if (choise == 1)
    {
        input_array(arr, n);
    }
    else if (choise == 2)
    {
        input_array_random(arr, n);
    }
    else
    {
        std::cout << "Try 1 or 2" << std::endl;
        delete[] arr;
        return 1;
    }

    std::cout << "\nBefore ";
    output_array(arr, n);

    bool success = var_7(arr, n);

    if (success)
    {
        std::cout << "After ";
        output_array(arr, n);
    }

    delete[] arr;
    return 0;
}