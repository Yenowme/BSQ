
#include "bsq.h"

void one_print(char c)
{
	write(1, &c, 1);
	write(1, "\n", 1);
}

void printerror(void)
{
	write(STDERR, MAPERROR, ft_strlen(MAPERROR));
}
