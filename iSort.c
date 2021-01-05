#include <stdio.h>
#include <stdbool.h>
int shift_element(int *arr, int i);
int insertion_sort(int *arr, int len);

int shift_element(int *arr, int i)
{
    int j;
    int temp = *arr;
    int temp1 = 0;
    for (j = 0; j < i; j++)
    {
        temp1 = *(arr + j + 1);
        *(arr + j + 1) = temp;
        temp = temp1;
    }
    return 0;
}

int insertion_sort(int *arr, int len)
{
    int i;
    for (i = 1; i < len; i++)
    {
        if (*(arr + i) < *(arr + i - 1))
        {
            int j = 1;

            while (i - (j + 1) >= 0)
            {
                if (*(arr + i) < *(arr + (i - j - 1)))
                {
                    j++;
                }
                else
                {
                    break;
                }
            }
            int temp = *(arr + i);
            shift_element(arr + i - j, j);
            *(arr + i - j) = temp;
        }
    }
    return 0;
}
int main()
{

    int array[50];
    int i;
    printf("Please enter 50 integers\n");
    int number;
    for (i = 0; i < 50; i++)
    {
        scanf(" %d", &number);
        *(array + i) = number;
    }
    insertion_sort(array, 50);
    for (i = 0; i < 49; i++)
    {
        printf("%d,", *(array + i));
    }
    printf("%d", *(array + 49));

    return 0;
}
