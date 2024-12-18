/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enums.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 20:51:52 by gmarchal          #+#    #+#             */
/*   Updated: 2024/01/23 19:22:10 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUMS_H
# define ENUMS_H

# ifdef LINUX

enum {
	K_ESC = 65307,
	K_UP = 65362,
	K_DOWN = 65364,
	K_LEFT = 65361,
	K_RIGHT = 65363,
	K_NUM_0 = 65438,
	K_NUM_1 = 65436,
	K_NUM_2 = 65433,
	K_NUM_3 = 65435,
	K_NUM_4 = 65430,
	K_NUM_5 = 65437,
	K_NUM_6 = 65432,
	K_NUM_7 = 65429,
	K_NUM_8 = 65431,
	K_NUM_9 = 65434,
	K_NUM_PERIOD = 65439,
	K_NUM_SLASH = 65455,
	K_NUM_ASTERISK = 65450,
	K_NUM_MINUS = 65453,
	K_NUM_PLUS = 65451,
	K_NUM_ENTER = 65421,
	K_W = 119,
	K_A = 97,
	K_S = 115,
	K_D = 100,
	K_E = 101
};

# else

enum {
	K_ESC = 53,
	K_UP = 126,
	K_DOWN = 125,
	K_LEFT = 123,
	K_RIGHT = 124,
	K_NUM_MINUS = 78,
	K_NUM_PLUS = 69,
	K_NUM_0 = 82,
	K_NUM_1 = 83,
	K_NUM_2 = 84,
	K_NUM_3 = 85,
	K_NUM_4 = 86,
	K_NUM_5 = 87,
	K_NUM_6 = 88,
	K_NUM_7 = 89,
	K_NUM_8 = 91,
	K_NUM_9 = 92,
	K_NUM_PERIOD = 65,
	K_NUM_SLASH = 75,
	K_NUM_ASTERISK = 67,
	K_NUM_ENTER = 76,
	K_W = 13,
	K_A = 0,
	K_S = 1,
	K_D = 2,
	K_E = 14
};

# endif

enum e_directions {
	NORTH,
	SOUTH,
	EAST,
	WEST
};

#endif
