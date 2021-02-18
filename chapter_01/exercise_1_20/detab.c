#include <stdio.h>

#define TAB_WIDTH 8

int main(void)
{
  int c;
  int line_pos = 0;
  char nr_of_spaces;

  while ((c = getchar()) != EOF)
  {
    if (c == '\t')
    {
      nr_of_spaces = TAB_WIDTH - line_pos % TAB_WIDTH;
      line_pos += nr_of_spaces;

      while (nr_of_spaces)
      {
        putchar(' ');
        --nr_of_spaces;
      }
    }
    else
    {
      putchar(c);

      if (c == '\n')
      {
        line_pos = 0;
      }
      else
      {
        ++line_pos;
      }
    }
  }

  return 0;
}
