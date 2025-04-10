#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

int ft_putchar(int c)
{
    return (write(1, &c, 1));
}

int ft_putstr(char *str)
{
    int len = 0;
    int i = 0;

    while (str[i])
    {
        len += ft_putchar(str[i]);
        i++;
    }
    return len;
}

int ft_putnbr(int nb)
{
    long n = (long) nb;
    int len = 0;

    if (n < 0)
    {
        len += ft_putchar('-');
        n *= -1;
    }
    if (n < 10)
        len += ft_putchar(n + 48);
    else
    {
        len += ft_putnbr(n / 10);
        len += ft_putnbr(n % 10);
    }
    return (len);
}

int ft_check_print(va_list p, char c)
{
    if (c == 'c')
        return (ft_putchar(va_arg(p, int)));
    else if (c == 's')
        return (ft_putstr(va_arg(p, char *)));
    else if (c == 'd')
        return (ft_putnbr(va_arg(p, int)));
    return (0);
}

int ft_printf(char *str, ...)
{
    va_list p;
    int i, len;
    
    len = 0;
    i = 0;
    va_start(p, str);
    while (str[i])
    {
        if (str[i] == '%' && !str[i + 1])
            break;
        if (str[i] == '%' && str[i + 1])
        {
            len += ft_check_print(p, str[i + 1]);
            i++;
        }
        else 
            len += ft_putchar(str[i]);
        i++;
    }
    return (len);
}

int main(void)
{
    printf("%c", 'h');
    ft_printf("%c %d", 'h', 122);
    return 0;
}