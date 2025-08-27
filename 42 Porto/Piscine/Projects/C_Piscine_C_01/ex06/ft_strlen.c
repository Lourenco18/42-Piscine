int ft_strlen(char *str){
    int num = 0;
    while (*str) {
        num++;
        str++;
    }
    return num;
}