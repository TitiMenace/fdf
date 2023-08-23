/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   includes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:47:29 by tschecro          #+#    #+#             */
/*   Updated: 2023/08/22 17:47:39 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDES_H
# define INCLUDES_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <math.h>

# define WIN_WIDTH 1923
# define WIN_HEIGHT 1080
# define OFFSET 10
# define RA_X 45
# define RA_Y 35.3644
# define RA_Z 0

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
# include <errno.h>
# include <stdint.h>

#endif
