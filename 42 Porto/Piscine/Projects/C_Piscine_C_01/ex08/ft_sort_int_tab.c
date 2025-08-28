

void ft_sort_int_tab(int *tab, int size)
{
    int i;
    int j;
    int temp;

    i = 0;
    while (i < size - 1)
    {
        j = 0;
        while (j < size - 1 - i)
        {
            if (tab[j] > tab[j + 1])
            {
                temp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = temp;
            }
            j++;
        }
        i++;
    }
}

/*
#include <stdio.h>

int main(void)
{
    int arr[] = {5, 3, 4, 1, 2};
    int i;
    ft_sort_int_tab(arr, 5);
    for (i = 0; i < 5; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}
*/


