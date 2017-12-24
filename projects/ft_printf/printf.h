/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giabanji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 15:35:18 by giabanji          #+#    #+#             */
/*   Updated: 2017/12/22 20:17:22 by giabanji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include "libft/libft.h"

int				g_size;
int				ft_printf(char *format, ...);
int				ft_isdisc(char s);
//int				ft_validformat(char *format);
int				ft_validstruct(char *s, int n);
void			print_str(va_list ap);
void			ft_readformat(char *s, va_list ap);
void			print_d(va_list ap);
void			print_u(va_list ap);
void			print_x(va_list ap);
void			print_o(va_list ap);
void			print_c(va_list ap);
void			print_s(va_list ap);
void			upper(char **str);
void			lower(char **str);
void			ft_nullstr(void);
int				ft_validflag(char *s, int n);
int				ft_validlength(char *s, int n);
int				ft_validacc(char *s, int n);
int				ft_validmod(char *s, int n);
void			workinstruct(void);
int				val_jz(char c);
void			print_cifer(char *s);
void			print_left_cif(char *s, int char_l);
void			print_wright_cif(char *s);
void			pr_d_c(char *s, int n);
void			print_ch(int c);

typedef struct	s_date
{
	int			defis;
	int			plus;
	int			space;
	int			hash;
	int			zero;
	int			length;
	int			accuracy;
	int			mod;
	int			h;
	int			hh;
	int			l;
	int			ll;
	int			j;
	int			z;
	int			convers;
}				t_data;

t_data			g_data;

#endif
