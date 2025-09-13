/* ft_find_next_prime.c */
int ft_is_prime(int nb); /* protótipo */

int ft_find_next_prime(int nb)
{
    if (nb <= 2)
        return (2);
    while (nb > 2)
    {
        if (ft_is_prime(nb))
            return (nb);
        nb++;
    }
    return (2); /* fallback (não deverá acontecer) */
}
