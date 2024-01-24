#include <iostream>

double PowerLoopLine(double x, int n);
double PowerLoopBin(double x, int n);

int main()
{
    
}

double PowerLoopLine(double x, int n)
{
    double result{ 1 };
    for (int i{}; i < n; i++)
        result *= x;
    return result;
}

double PowerLoopBin(double x, int n)
{
    double result{ 1 };

    while (n)
    {
        //if (n & 1)
        //{
        //    result *= x;
        //    n--;
        //}
        //else
        //{
        //    x *= x;
        //    n /= 2; // n >> 1;
        //}

        if (n & 1)
            result *= x;
        x *= x;
        n >>= 1;
        return result;
    }
}
