#include <iostream>

void MinVars();

void ArrayInit(int array[], int size)
{
    for (int i{}; i < size; i++)
        array[i] = rand() % 100;
}

void ArrayPrint(int array[], int size)
{
    for (int i{}; i < size; i++)
        std::cout << array[i] << " ";
    std::cout << "\n";
}

void ArrayInitPrint(int array[], int size)
{
    ArrayInit(array, size);
    ArrayPrint(array, size);
}

int ArrayAmount(int array[], int size)
{
    int amount{};
    for (int i{}; i < size; i++)
        amount += array[i];
    return amount;
}

bool FirstMin(int a, int b)
{
    return a < b;
}

int ArrayMinValue(int array[], int size)
{
    int min{ array[0] };
    for (int i{ 1 }; i < size; i++)
        if (min > array[i])
            min = array[i];
    return min;
}

int ArrayMinIndex(int array[], int size)
{
    int minIndex{};
    for (int i{ 1 }; i < size; i++)
        if (array[minIndex] > array[i])
            minIndex = i;
    return minIndex;
}

void ArrayReverse(int array[], int size)
{
    int temp;
    for (int i{}; i < size / 2; i++)
    {
        temp = array[i];
        array[i] = array[size - i - 1];
        array[size - i - 1] = temp;
    }
}

int main()
{
    srand(time(nullptr));

    const int size{ 10 };
    int array[size];

    ArrayInit(array, size);
    ArrayPrint(array, size);

    std::cout << "Min index: " << ArrayMinIndex(array, size)
        << " Min value: " << ArrayMinValue(array, size) << "\n";

    ArrayReverse(array, size);
    ArrayPrint(array, size);

    int steps{ 123 };
    //steps = steps % size;
    steps %= size;


    for (int s{}; s < steps; s++)
    {
        int temp = array[0];
        for (int i{}; i < size - 1; i++)
            array[i] = array[i + 1];
        array[size - 1] = temp;
    }

    ArrayPrint(array, size);
}   


void MinVars()
{
    int a, b, c, d;
    std::cout << "input 4 numbers: ";
    std::cin >> a >> b >> c >> d;

    int min = a;

    if (min > b)
        min = b;
    if (min > c)
        min = c;
    if (min > d)
        min = d;
    std::cout << min << "\n";
}