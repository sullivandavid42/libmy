/*
** flag_s.c for my_printf in /home/david_h/rendu/PSU_2014_my_printf
** 
** Made by Sullivan David
** Login   <david_h@epitech.net>
** 
** Started on  Sun Nov 16 12:35:37 2014 david_h
** Last update Sun Nov 16 12:44:00 2014 david_h
*/

#include        "../include/my.h"
#include        <stdarg.h>

typedef         int (*flag)(va_list);

int             unexamin(va_list list)
{
  unsigned int  nb;
  int           nb2;
  char          *base;

  nb2 = va_arg(list, int);
  base = "0123456789abcdef";
  if (nb2 < 0)
    {
      my_putstr("ffffffff");
      return (0);
    }
  nb = nb2;
  my_putnbr_base(nb, base);
}

int             unbin(va_list list)
{
  unsigned int  nb;
  char          *base;

  nb = va_arg(list, unsigned int);
  base = "01";
  my_putnbr_base(nb, base);
}

int             unoctal(va_list list)
{
  unsigned int  nb;
  char          *base;

  nb = va_arg(list, unsigned int);
  base = "01234567";
  my_putnbr_base(nb, base);
}

int             undec(va_list list)
{
  unsigned int  nb;
  char          *base;

  nb = va_arg(list, unsigned int);
  my_put_nbr(nb);
}

int             exapoint(va_list list)
{
  void          *format;
  char          *base;

  base = "0123456789abcdef";
  format = va_arg(list, void *);
  my_putstr("0x");
  my_putnbr_base(format, base);
}
