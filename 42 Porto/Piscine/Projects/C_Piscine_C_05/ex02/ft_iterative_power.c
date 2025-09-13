/* ft_iterative_power.c */
int ft_iterative_power(int nb, int power)
{
    int res;
    int i;

    if (power < 0)
        return (0);
    if (power == 0)
        return (1); /* inclui 0^0 -> 1 conforme enunciado */
    res = 1;
    i = 0;
    while (i < power)
    {
        res *= nb;
        i++;
    }
    return (res);
}
