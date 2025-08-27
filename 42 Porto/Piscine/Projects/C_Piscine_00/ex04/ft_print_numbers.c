#include <unistd.h>

void ft_is_negative(int n)
{
 if(n<0){
    write(1, "N\n", 2);
 } else if(n>=0) {
    write(1, "P\n", 2);
 } 
}

int main(void)
{
    ft_is_negative(5 );
    ft_is_negative(-5);
    ft_is_negative(0);
    return 0;
}


