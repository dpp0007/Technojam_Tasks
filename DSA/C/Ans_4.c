#include <stdio.h>

int compress(char *chars, int size)
{
    int indices = 0;
    int i = 0;
    while (i < size)
    {
        char current = chars[i];
        int count = 0;
        while (i < size && chars[i] == current)
        {
            count++;
            i++;
        }
        chars[indices] = current;
        indices++;
        if (count > 1)
        {
            int start = indices;
            while (count > 0)
            {
                chars[indices++] = (count % 10) + '0';
                count /= 10;
            }
            for (int j = start, k = indices - 1; j < k; j++, k--)
            {
                char temp = chars[j];
                chars[j] = chars[k];
                chars[k] = temp;
            }
        }

       
    }
    return indices;
}

int main()
{
    char chars[] = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    int size = sizeof(chars) / sizeof(chars[0]);
    int newSize = compress(chars, size);
    printf("New length: %d\n", newSize);
    for (int i = 0; i < newSize; i++)
    {
        printf("%c ", chars[i]);
    }
    printf("\n");
    return 0;
}