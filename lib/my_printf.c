/*
** my_printf.c for my_printf in /home/david_h/rendu/PSU_2014_my_printf
** 
** Made by Sullivan David
** Login   <david_h@epitech.net>
** 
** Started on  Sun Nov 16 12:21:30 2014 david_h
** Last update Sun Nov 16 13:24:14 2014 david_h
*/

#include        <stdlib.h>
#include        <stdarg.h>
#include        "../include/my.h"

typedef         int (*flag)(va_list);

int             chk_fl(char *format, char *flag_tab, flag *func_tab, int i, va_list ap)
{
  int           j;

  j = 0;
  while ((format[i] != flag_tab[j]) && (flag_tab[j] != '\0'))
    j++;
  if (flag_tab[j] == '\0')
    {
      my_putchar('%');
      my_putchar(format[i]);
    }
  else
    func_tab[j](ap);
  return (i);
}

char            *tab(char *tab)
{
  tab = malloc(sizeof(char) * 11);

  tab[0] = 'd';
  tab[1] = 's';
  tab[2] = 'c';
  tab[3] = 'i';
  tab[4] = 'o';
  tab[5] = 'b';
  tab[6] = 'x';
  tab[7] = 'X';
  tab[8] = 'S';
  tab[9] = 'u';
  tab[10] = 'p';
  return (tab);
}

flag            *tab_func(flag *tab_func)
{
  tab_func = malloc(sizeof(flag) * 11);

  tab_func[0] = numput;
  tab_func[1] = str;
  tab_func[2] = charput;
  tab_func[3] = numput;
  tab_func[4] = unoctal;
  tab_func[5] = unbin;
  tab_func[6] = unexamin;
  tab_func[7] = unexamaj;
  tab_func[8] = stroctal;
  tab_func[9] = undec;
  tab_func[10] = exapoint;
  return (tab_func);
}

void             my_printf(char *fmt, ...)
{
  va_list       ap;
  flag          *func_tab;
  char          *flag_tab;
  int           i;

  va_start(ap, fmt);
  func_tab = tab_func(func_tab);
  flag_tab = tab(flag_tab);
  i = 0;
  while(fmt[i])
    {
      if (fmt[i] == '%')
        {
          i++;
          if (fmt[i] == '%')
            my_putchar('%');
          else
            chk_fl(fmt, flag_tab, func_tab, i, ap);
        }
      else
        my_putchar(fmt[i]);
      i++;
    }
}