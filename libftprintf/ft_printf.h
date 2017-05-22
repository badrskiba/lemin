/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bskiba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 15:46:59 by bskiba            #+#    #+#             */
/*   Updated: 2017/02/10 02:42:51 by bskiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft.h"
# include <wchar.h>
# include <stdio.h>
# include <stdarg.h>

typedef struct			s_format
{
	const char			*string;
	size_t				pos;
	size_t				count;
}						t_format;

typedef struct			s_flags
{
	int		plus;
	int		minus;
	int		space;
	int		hashtag;
	int		zero;
}						t_flags;

typedef enum			e_lenght
{
	Default, hh, h, l, ll, j, z
}						t_lenght;

typedef enum			e_type
{
	rien, s_deci, us_deci, chr, hex_upper,
	hex_lower, octal, str, pointer, pourc
}						t_type;

typedef struct			s_handler
{
	t_flags				flags;
	unsigned int		width;
	unsigned int		precision;
	t_lenght			lenght;
	t_type				type;
	int					n;
	int					prec;
}						t_handler;

int						ft_printf(const char *format, ...);
void					read_string(t_format *format, va_list arg);
void					read_format(t_format *format, va_list arg);
void					handle_flags(t_format *format, t_handler *handler);
int						cheek_flags(char a, t_handler *handler);
int						cheek_flags_next(char a, t_handler *handler);
void					handle_width(t_format *format, t_handler *handler);
void					handle_precision(t_format *format, t_handler *handler);
void					handle_length(t_format *format, t_handler *handler);
void					handle_type(t_format *format, t_handler *handler);
int						valid_type(char a, t_handler *handler);
void					cheek_capital(char a, t_handler *handler);
void					print_int(t_format *format,
											t_handler *handler, va_list arg);
void					print_signed_int(t_format *format,
											t_handler *handler, va_list arg);
void					print_signed_int_next(t_format *format,
											t_handler *handler, intmax_t n);
void					print_unsigned_int(t_format *format,
											t_handler *handler, va_list arg);
char					*ft_itoa_intmax(intmax_t n);
void					n_neg(intmax_t *n, int *neg);
void					print_int_endwidth(t_format *format,
									t_handler *handler, intmax_t n, int nbn);
int						put_precision(t_format *format,
											t_handler *handler, char *str);
int						put_firstflag(t_format *format,
									t_handler *handler, intmax_t n, int nbn);
void					put_width(t_format *format,
										t_handler *handler, char c, int i);
void					print_int_frontwidth(t_format *format,
									t_handler *handler, intmax_t n, int nbn);
void					put_precision_diff(t_format *format,
								t_handler *handler, char *string);
void					print_chr(t_format *format,
											t_handler *handler, va_list arg);
void					print_char(char c, t_format *format,
														t_handler *handler);
void					print_char_next(char c, t_format *format,
														t_handler *handler);
void					print_hex(t_format *format,
											t_handler *handler, va_list arg);
char					*printf_strlower(char *str);
char					*printf_strupper(char *str);
void					print_octal(t_format *format,
											t_handler *handler, va_list arg);
char					*printf_itoa_base_octal(uintmax_t n, int base);
void					print_str(t_format *format,
											t_handler *handler, va_list arg);
void					print_normal_str(t_format *format,
												t_handler *handler, char *str);
void					print_pourcent(t_format *format, t_handler *handler);
void					print_widestr(t_format *format,
										t_handler *handler, wchar_t *string);
void					print_uint_endwidth(t_format *format,
									t_handler *handler, uintmax_t n);
int						put_ufirstflag(t_format *format,
									t_handler *handler);
void					print_uint_frontwidth(t_format *format,
									t_handler *handler, uintmax_t n, int nbn);
char					*ft_itoa_uintmax(uintmax_t n);
unsigned int			max_bytes(wchar_t *string,
														t_handler *handler);
void					count_bytes(unsigned int *count, wint_t wint);
void					print_wint(wint_t wint, t_format *format);
void					print_hex_frontwidth(char *string, t_format *format,
											t_handler *handler, char fill);
int						zero_x_print(t_format *format, t_handler *handler);
void					put_precision_hex(char *string, t_format *format,
														t_handler *handler);
void					print_hex_endwidth(char *string, t_format *format,
												t_handler *handler, char fill);
char					*printf_itoa_base(uintmax_t n, int base);
char					*printf_strupper(char *str);
void					print_octal_frontwidth(char *string, t_format *format,
											t_handler *handler, char fill);
int						put_precision_octal(char *string, t_format *format,
												t_handler *handler, int i);
int						zero_print(t_format *format);
#endif
