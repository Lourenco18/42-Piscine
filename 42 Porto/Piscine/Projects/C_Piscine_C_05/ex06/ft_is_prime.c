/* ft_is_prime.c */
int ft_is_prime(int nb)
{
    int i;
    int limit;

    if (nb <= 1)
        return (0);
    if (nb == 2)
        return (1);
    if (nb % 2 == 0)
        return (0);
    i = 3;
    limit = nb / i; /* usado apenas como aproximação em loop */
    while (i <= nb / i)
    {
        if (nb % i == 0)
            return (0);
        i += 2;
    }
    return (1);
}
