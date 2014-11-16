/*
** flag_f.c for printf in /home/david_h/rendu/PSU_2014_my_printf
** 
** Made by Sullivan David
** Login   <david_h@epitech.net>
** 
** Started on  Sun Nov 16 12:34:46 2014 david_h
** Last update Sun Nov 16 13:17:53 2014 david_h
*/

#include        <stdarg.h>
#include        "../include/my.h"

typedef         int (*flag)(va_list);

int             str(va_list list)
{
  char          *format;

  format = va_arg(list, char *);
  my_putstr(format);
}

int             charput(va_list list)
{
  char          c;

  c = va_arg(list, int);
  my_putchar(c);
}

int             numput(va_list list)
{
  int           nb;

  nb = va_arg(list, int);
  my_put_nbr(nb);
}

int             stroctal(va_list list)
{
  char          *format;
  char          *base;
  int           i;

  format = va_arg(list, char *);
  i = 0;
  base = "01234567";
  while (format[i])
    {
      if (format[i] < 7)
        {
          my_putstr("\\00");
          my_putnbr_base(format[i], base);
        }
      else if ((format[i] > 7 && format[i] < 32) || format[i] >= 127)
        {
          my_putstr("\\0");
          my_putnbr_base(format[i], base);
        }
      else
        my_putchar(format[i]);
      i++;
    }
}

int             unexamaj(va_list list)
{
  int           nb;
  unsigned int  nb2;
  char          *base;

  nb = va_arg(list, int);
  base = "0123456789ABCDEF";
  if (nb < 0)
    {
      my_putstr("FFFFFFFF");
      return (0);
    }
  nb2 = nb;
  my_putnbr_base(nb2, base);
}
