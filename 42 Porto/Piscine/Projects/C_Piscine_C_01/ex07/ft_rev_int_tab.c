void	ft_rev_int_tab(int *tab, int size)
{
    int i;

    i = 0;
    int temp;
    while (i < size/2) 
    {
	    temp = tab[i];
	    tab[i] = tab[size - 1 - i];
	    tab[size - 1 - i] = temp;
	    i++;
    } 
}

/*
#include <stdio.h>

int main(void)
{
    int arr[] = {1, 2, 3, 4, 5};
    int i;
    ft_rev_int_tab(arr, 5);
    for (i = 0; i < 5; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}
*/

