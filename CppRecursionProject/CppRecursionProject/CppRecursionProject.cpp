#include <iostream>

double Power(double x, int n)
{
    double result{ 1 };
    for (int i{}; i < n; i++)
        result *= x;
    return result;
}

double PowerRec(double x, int n)
{
    if (n == 0) return 1;
    return PowerRec(x, n - 1) * x;
}

double PowerRecBin(double x, int n)
{
    if (n == 0) return 1;
    if (n & 1)
        return PowerRecBin(x, n - 1) * x;
    else
    {
        int temp = PowerRecBin(x, n / 2);
        return temp * temp;
    }
}

void BinNumber(int n)
{
    if (n >= 2)
        BinNumber(n / 2);
    std::cout << n % 2;
}

double CircleArea(double radius)
{
    return 3.14 * Power(radius, 2);
}

int main()
{
    std::cout << Power(5, 3) << "\n";
    std::cout << PowerRec(5, 3) << "\n";

    BinNumber(37);
}
