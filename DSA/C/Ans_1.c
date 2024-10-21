#include <stdio.h>

// ncr=n!/r!(n-r)!
int factorial(int n)
{
    for (int i = n; i >= 0; i--)
    {
        if (i == 1 || i == 0)
        {
            return 1;
        }
        else
        {
            return factorial(n - 1) * n;
        }
    }
}

void generatePascalTriangle(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            printf(" ");
        }
        for (int k = 0; k <= i; k++)
        {
            printf("%lld ", factorial(i) / (factorial(k) * factorial(i - k))); // Binomial expanission
        }
        printf("\n");
    }
}

int main()
{
    int n = 5;
    generatePascalTriangle(n);
    return 0;
}