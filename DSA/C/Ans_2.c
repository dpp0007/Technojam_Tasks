#include <stdio.h>

int climbStairs(int n) {
    int num1=1,num2=1,temp;
    for (int i = 0; i < n-1; i++)
    {
        temp=num1;
        num1=num1+num2;
        num2=temp;
    }
    return num1;
}

int main() {
    int n = 5;
    printf("%d\n", climbStairs(n));
    return 0;
}
