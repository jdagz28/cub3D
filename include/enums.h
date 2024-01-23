/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enums.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 20:51:52 by gmarchal          #+#    #+#             */
/*   Updated: 2024/01/23 19:24:58 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUMS_H
# define ENUMS_H

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

enum e_directions {
	NORTH,
	SOUTH,
	EAST,
	WEST
};

#endif
