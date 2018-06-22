#include <stdio.h>

#define MAXLEN 1000
#define BUFFSIZE 100

int getch(void);
void ungetch(int c);
int getfloat(int *pn);

int main(void)
{
    
    return 0;
}

int bufp = 0;
int buf[BUFFSIZE];

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if(bufp >= BUFFSIZE)
    {
        printf("ungetch: too many characters\n");
    }
    else
    {
        buf[bufp++] = c;
    }
}

int getfloat(int *pn)
{
    int c, sign;

    while(isspace(c = getch()));

    if(!isdigit(c) && c != EOF && c != '+' && c != '-')
    {
        ungetch(c);
        return 0;
    }

    sign = (c == '-') ? -1 : 1;

    if(c == '+' || c == '-')
    {
        if(!isdigit(c = getch()))
        {
            ungetch(c);
            ungetch(sign == 1 ? '+' : '-');
            return 0;
        }
    }

    for(*pn = 0; isdigit(c); c = getch())
    {
        *pn = 10 * *pn + (c - '0');
    }

    *pn = *pn * sign;

    if(c != EOF)
    {
        ungetch(c);
    }

    return c;
}

// Exercise page: 111

// OBS: Silence is golden.