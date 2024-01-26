#include <iostream>

void MinVars();
void ArrayInit(int array[], int size);
void ArrayPrint(int array[], int size);
void ArrayInitPrint(int array[], int size);
int ArrayAmount(int array[], int size);
bool FirstMin(int a, int b);
int ArrayMinValue(int array[], int size);
int ArrayMinIndex(int array[], int size);
void ArrayReverse(int array[], int size);
void ArrayShiftLeft(int array[], int size, int steps);

void ArraySortSelect(int array[], int size);
void ArraySortBubble(int array[], int size);
void ArraySortShacker(int array[], int size);
void ArraySortInsert(int array[], int size);

void ArraySortQuickRec(int array[], int begin, int end);
void ArraySortQuick(int array[], int size);

int ArraySearchLine(int array[], int size, int key);
int ArraySearchBin(int array[], int size, int key);

int main()
{
    srand(time(nullptr));

    const int size{ 20 };
    int array[size];

    ArrayInit(array, size);
    ArrayPrint(array, size);
    //ArraySortShacker(array, size);
    ArraySortQuick(array, size);
    ArrayPrint(array, size);

    int key;
    std::cout << "Input key of search: ";
    std::cin >> key;

    int index = ArraySearchLine(array, size, key);
    if (index >= 0)
        std::cout << "Found. Index = " << index << "\n";
    else
        std::cout << "Not found\n";

    index = ArraySearchBin(array, size, key);
    if (index >= 0)
        std::cout << "Found. Index = " << index << "\n";
    else
        std::cout << "Not found\n";

    /*
    std::cout << "Min index: " << ArrayMinIndex(array, size)
        << " Min value: " << ArrayMinValue(array, size) << "\n";

    ArrayReverse(array, size);
    ArrayPrint(array, size);

    //int steps{ 123 };
    //steps = steps % size;

    ArraySortInsert(array, size);
    ArrayPrint(array, size);
    */
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

void ArrayShiftLeft(int array[], int size, int steps)
{
    steps %= size;

    for (int s{}; s < steps; s++)
    {
        int temp = array[0];
        for (int i{}; i < size - 1; i++)
            array[i] = array[i + 1];
        array[size - 1] = temp;
    }
}

void ArraySortSelect(int array[], int size)
{
    int indexMin;
    int temp;

    for (int i{}; i < size - 1; i++) // left array's border
    {
        indexMin = i;
        for (int j{ i + 1 }; j < size; j++) // search min index
            if (array[indexMin] > array[j])
                indexMin = j;
        temp = array[i]; // swap
        array[i] = array[indexMin];
        array[indexMin] = temp;
    }
}

void ArraySortBubble(int array[], int size)
{
    int temp;
    bool isSort;

    for (int i{}; i < size - 1; i++)
    {
        isSort = true;
        for (int j{ size - 1 }; j > i; j--)
            if (array[j] < array[j - 1])
            {
                temp = array[j];
                array[j] = array[j - 1];
                array[j - 1] = temp;
                isSort = false;
            }
        if (isSort)
            break;
    }
}

void ArraySortShacker(int array[], int size)
{
    int top{ 0 };
    int bottom{ size - 1 };

    int temp;
    bool isSort;

    while (top < bottom)
    {
        isSort = true;
        for (int i{ bottom }; i > top; i--)
        {
            if (array[i] < array[i - 1])
            {
                temp = array[i];
                array[i] = array[i - 1];
                array[i - 1] = temp;
                isSort = false;
            }
        }
        if (isSort)
            break;
        top++;

        isSort = true;
        for (int i{ top }; i < bottom; i++)
        {
            if (array[i] > array[i + 1])
            {
                temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                isSort = false;
            }
        }
        if (isSort)
            break;
        bottom--;
    }
}

void ArraySortInsert(int array[], int size)
{
    int temp;
    int j;
    for (int i{ 1 }; i < size; i++)
    {
        temp = array[i];
        for (j = i; j > 0; j--)
            if (array[j - 1] > temp)
                array[j] = array[j - 1];
            else
                break;
        array[j] = temp;
    }
}



int ArraySearchLine(int array[], int size, int key)
{
    for (int i{}; i < size; i++)
        if (array[i] == key)
            return i;
    return -1;
}

int ArraySearchBin(int array[], int size, int key)
{
    int left{ 0 };
    int right{ size - 1 };
    int middle;

    while (left <= right)
    {
        middle = (left + right) / 2;
        if (key == array[middle])
            return middle;
        if (key > array[middle])
            left = middle + 1;
        else
            right = middle - 1;
    }

    return -1;
}

void ArraySortQuick(int array[], int size)
{
    ArraySortQuickRec(array, 0, size - 1);
}

void ArraySortQuickRec(int array[], int begin, int end)
{
    int pivot{ array[(begin + end) / 2] };
    int left{ begin };
    int right{ end };

    int temp;

    do
    {
        while (array[left] < pivot) left++;
        while (array[right] > pivot) right--;

        if (left <= right)
        {
            temp = array[left];
            array[left] = array[right];
            array[right] = temp;
            left++;
            right--;
        }
    } while (left <= right);

    if (begin < right)
        ArraySortQuickRec(array, begin, right);
    if (left < end)
        ArraySortQuickRec(array, left, end);
}