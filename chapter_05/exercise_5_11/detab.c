#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define DEFAULT_TAB_LENGTH 8

int is_str_uint(char *str);
int is_tab_stop_arg_list_valid(int argc, char *argv[]);

int main(int argc, char *argv[])
{
  if (!is_tab_stop_arg_list_valid(argc, argv))
  {
    puts("ERROR: Invalid tab stop list.\n");
    return EXIT_FAILURE;
  }

  int c;
  int tab_stop = DEFAULT_TAB_LENGTH;
  int arg_pos = 1;
  int line_pos = 0;
  int nr_of_spaces;
  int nr_of_tab_stops = argc - 1;

  while ((c = getchar()) != EOF)
  {
    if (c == '\t')
    {
      if (nr_of_tab_stops)
      {
        tab_stop = atoi(argv[arg_pos++]);
        --nr_of_tab_stops;
      }
      else if (argc > 1)
      {
        tab_stop = 1;
      }

      nr_of_spaces = tab_stop - line_pos % tab_stop;

      while (nr_of_spaces)
      {
        putchar(' ');
        ++line_pos;
        --nr_of_spaces;
      }
    }
    else
    {
      putchar(c);
      ++line_pos;

      if (c == '\n')
      {
        arg_pos = 1;
        line_pos = 0;
        nr_of_tab_stops = argc - 1;
      }
    }
  }

  return EXIT_SUCCESS;
}

int is_str_uint(char *str)
{
  for (unsigned int i = 0; i < strlen(str); ++i)
  {
    if (!isdigit(str[i]))
    {
      return 0;
    }
  }
  return 1;
}

int is_tab_stop_arg_list_valid(int argc, char *argv[])
{
  for (unsigned int i = 1; i < argc; ++i)
  {
    if (!is_str_uint(argv[i]) || (i > 1 && atoi(argv[i - 1]) > atoi(argv[i])))
    {
      return 0;
    }
  }
  return 1;
}

// NOTE: The current program works in a similar fashion as expand.
// run: ./detab 4 8 12 16 < file_tabs.txt > file_spaces.txt
