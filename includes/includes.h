
#ifndef INCLUDES_H
# define INCLUDES_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <math.h>

# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080
# define OFFSET 1
# define RA_X (35.26 * M_PI / 180)
# define RA_Y 0
# define RA_Z (M_PI / 4)

# include "fdf.h"
# include <stdio.h>
# include <stdbool.h>
# define XK_MISCELLANY
# define XK_LATIN1
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <limits.h>
# include <X11/keysymdef.h>
# include <stdlib.h>
# include <X11/X.h>

#endif
