/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/05 20:04:30 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2018/08/12 23:53:51 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LIBFILLIT_H
# define LIBFILLIT_H
# include "libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct		s_sharp
{
	int				x;
	int				y;
}					t_sharp;

typedef struct		s_tetri
{
	t_sharp			sharp2;
	t_sharp			sharp3;
	t_sharp			sharp4;
	char			lettre;
	struct s_tetri	*next;
}					t_tetri;

int					ft_check(char *str);
char				**ft_tetrasplit(char const *s);
t_tetri				*ft_newtetri(void);
t_tetri				*ft_chartolist(char **strline);
char				**ft_makegrid(int size);
void				ft_resol(t_tetri *list);
int					ft_check_position(char **map, t_tetri *tetri, int a, int b);
int					ft_check_tetraminos(char **t, int x, int y);
int					ft_check_tetri(char **t, int x, int y);
int					ft_calcul_size_min(t_tetri *list);

#endif
