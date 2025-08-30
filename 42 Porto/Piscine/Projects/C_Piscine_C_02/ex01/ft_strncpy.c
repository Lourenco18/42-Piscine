char *ft_strncpy(char *dest, char *src, unsigned int n){
    unsigned int i;
    dest[n] = '\0';
    i = 0;
    while (i < n && src[i] != '\0'){
        dest[i] = src[i];
        i++;
    }
      while (i < n){
        dest[i] = '\0';
        i++;
    }

    return (dest);
}
/*
#include <stdio.h>
int main(void)
{
    char src[] = "42 portoadsadasdas";
    char dest[50];

    ft_strncpy(dest, src, 10);
    printf("src: %s\n", src);
    printf("dest: %s\n", dest);
    return (0);
}
    */
