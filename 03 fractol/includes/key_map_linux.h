/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   key_map_linux.h                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/20 08:26:41 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2018/05/08 16:26:34 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef KEY_MAP_LINUX_H
# define KEY_MAP_LINUX_H

# define K_A			0x0061
# define K_B			0x0062
# define K_C			0x0063
# define K_D			0x0064
# define K_E			0x0065
# define K_F			0x0066
# define K_G			0x0067
# define K_H			0x0068
# define K_I			0x0069
# define K_J			0x006A
# define K_K			0x006B
# define K_L			0x006C
# define K_M			0x006D
# define K_N			0x006E
# define K_O			0x006F
# define K_P			0x0070
# define K_Q			0x0071
# define K_R			0x0072
# define K_S			0x0073
# define K_T			0x0074
# define K_U			0x0075
# define K_V			0x0076
# define K_W			0x0077
# define K_X			0x0078
# define K_Y			0x0079
# define K_Z			0x007A

# define K_1			0x0026
# define K_2			0x00E9
# define K_3			0x0022
# define K_4			0x0027
# define K_5			0x0028
# define K_6			0x002D
# define K_7			0x00E8
# define K_8			0x005F
# define K_9			0x00E7
# define K_0			0x00E0

# define K_UP 			0xFF52
# define K_DOWN			0xFF54
# define K_LEFT			0xFF51
# define K_RIGHT		0xFF53

# define K_PAD_PLUS		0xFFAB
# define K_PAD_MINUS	0xFFAD
# define K_PAD_VERRNUM	0xFF7F
# define K_PAD_ENTER	0xFF8D
# define K_PAD_SLASH	0xFFAF
# define K_PAD_STAR		0xFFAA
# define K_PAD_DOT		0xFF9F

# define K_PAD_0		0xFFE9
# define K_PAD_1		0xFF9C
# define K_PAD_2		0xFF99
# define K_PAD_3		0xFF9B
# define K_PAD_4		0xFF96
# define K_PAD_5		0xFF9D
# define K_PAD_6		0xFF98
# define K_PAD_7		0xFF95
# define K_PAD_8		0xFF97
# define K_PAD_9		0xFF9A

# define K_MINUS 27
# define K_EQUAL 24
# define K_ESC 			0xFF1B
# define K_TAB 48
# define K_SPACE		0x0020
# define K_ENTER		0xFF0D
# define K_BACKSPACE 51
# define K_SCREENSHOT 105
# define K_BACKSLASH 42
# define K_SLASH 44

# define K_DOT 65
# define K_COMA 43
# define K_SEMICOLON 41
# define K_SIMPLEQUOTE 39
# define K_ACCENT 50
# define K_OPEN_BRACK 33
# define K_CLOSE_BRACK 30

# define K_INSERT 114
# define K_END 119
# define K_DELETE 117
# define K_PAGEUP 116
# define K_PAGEDOWN 121
# define K_HOME 115

# define K_F1			0xFFBE
# define K_F2			0xFFBF
# define K_F3			0xFFC0
# define K_F4			0xFFC1
# define K_F5			0xFFC2
# define K_F6			0xFFC3
# define K_F7			0xFFC4
# define K_F8			0xFFC5
# define K_F9			0xFFC6
# define K_F10			0xFFC7
# define K_F11			0xFFC8
# define K_F12			0xFFC9

# define MOD_CAPSLOCK	0xFFE5
# define MOD_LSHIFT 257
# define MOD_RSHIFT 258
# define MOD_LCTRL 256
# define MOD_RCTRL 269
# define MOD_CMD 259
# define MOD_LALT 261
# define MOD_RALT 262

# define MAX_KEYS 512

# define M_NONE 0
# define M_LCLICK 1
# define M_RCLICK 2
# define M_WHEELCLICK 3
# define M_WHEELUP 4
# define M_WHEELDOWN 5
# define MAX_MBUTTON 6

#endif
