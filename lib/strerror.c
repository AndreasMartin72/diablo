/*  $Revision: 1.1.1.2 $
**
**  Only <errno.h> is needed; the others are just to get the right sprintf()
**  declaration, sigh.
*/

#include "defs.h"

#if USE_STRERROR

/*
**  Return a string representation of errno.
*/
char *
strerror(int e)
{
    extern int	sys_nerr;
    extern char	*sys_errlist[];
    static char	buff[30];

    if (e >= 0 && e < sys_nerr)
	return sys_errlist[e];
    (void)sprintf(buff, "Error code %d\n", e);
    return buff;
}

#endif

