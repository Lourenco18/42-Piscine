char *ft_strcpy(char *dest, char *src){
    int i;

    i = 0;
    while (src[i] != '\0'){
        dest[i] = src[i];
        i++;
    }
    return (dest);
}
/*
#include <stdio.h>
int main(void)
{
    char src[] = "42 porto";
    char dest[50];

    ft_strcpy(dest, src);
    printf("src: %s\n", src);
    printf("dest: %s\n", dest);
    return (0);
}
    */