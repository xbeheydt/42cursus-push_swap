/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .test_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbeheydt <xbeheydt@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 11:05:43 by xbeheydt          #+#    #+#             */
/*   Updated: 2022/03/09 11:48:48 by xbeheydt         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include <.tests.h>

/* define unit test functions HERE */
/* libft */
int	test_ft_atoi(void *);
int	test_ft_bzero(void *);
int	test_ft_calloc(void *);
int	test_ft_isalnum(void *);
int	test_ft_isalpha(void *);
int	test_ft_isascii(void *);
int	test_ft_isdigit(void *);
int	test_ft_islower(void *);
int	test_ft_isprint(void *);
int	test_ft_isspace(void *);
int	test_ft_isupper(void *);
int	test_ft_itoa(void *);
int	test_ft_lstadd_back(void *);
int	test_ft_lstadd_front(void *);
int	test_ft_lstclear(void *);
int	test_ft_lstdelone(void *);
int	test_ft_lstiter(void *);
int	test_ft_lstlast(void *);
int	test_ft_lstmap(void *);
int	test_ft_lstnew(void *);
int	test_ft_lstsize(void *);
int	test_ft_lstpop_front(void *);
int	test_ft_lstpop_back(void *);
int	test_ft_memchr(void *);
int	test_ft_memcmp(void *);
int	test_ft_memcpy(void *);
int	test_ft_memmove(void *);
int	test_ft_memset(void *);
int	test_ft_putchar_fd(void *);
int	test_ft_putendl_fd(void *);
int	test_ft_puthnbr_fd(void *);
int	test_ft_putnbr_fd(void *);
int	test_ft_putstr_fd(void *);
int	test_ft_putunbr_fd(void *);
int	test_ft_split(void *);
int	test_ft_strchr(void *);
int	test_ft_strdup(void *);
int	test_ft_striteri(void *);
int	test_ft_strjoin(void *);
int	test_ft_strlcat(void *);
int	test_ft_strlcpy(void *);
int	test_ft_strlen(void *);
int	test_ft_strmapi(void *);
/* TODO : make strcmp */
int	test_ft_strncmp(void *);
int	test_ft_strnstr(void *);
int	test_ft_strrchr(void *);
int	test_ft_strtrim(void *);
int	test_ft_substr(void *);
int	test_ft_tolower(void *);
int	test_ft_toupper(void *);
/* get_next_line */
int	test_gnl_get_buffer(void *);
int	test_gnl_clear_buffer(void *);
int	test_gnl_get_line1(void *);
int	test_gnl_get_line2(void *);
int	test_gnl_get_line3(void *);
int	test_gnl_line_realloc(void *);
int	test_gnl_small_line_nonl(void *args);
int	test_gnl_big_text_nl(void *args);
int	test_gnl_big_text_alt_nl(void *args);
int	test_gnl_one_nl(void *args);
int	test_gnl_empty(void *args);
int	test_gnl_fake_fd(void *args);
/* ft_printf */
int	test_ft_printf_percent(void *args);
int	test_ft_printf_c(void *args);
int	test_ft_printf_s(void *args);
int	test_ft_printf_u(void *args);
int	test_ft_printf_i(void *args);
int	test_ft_printf_d(void *args);
int	test_ft_printf_x(void *args);
int	test_ft_printf_X(void *args);
int	test_ft_printf_p(void *args);
int	test_ft_printf_minus(void *args);
int	test_ft_printf_plus(void *args);
int	test_ft_printf_zero(void *args);
int	test_ft_printf_sharp(void *args);
int	test_ft_printf_dot(void *args);
int	test_ft_printf_space(void *args);
int	test_ft_printf_bonus_percent(void *args);
int	test_ft_printf_bonus_s(void *args);
int	test_ft_printf_bonus_d(void *args);
int	test_ft_printf_bonus_i(void *args);
int	test_ft_printf_bonus_u(void *args);
int	test_ft_printf_bonus_x(void *args);
int	test_ft_printf_bonus_X(void *args);

static unit_t	tests[] = {
	/* libft */
	{ TEST_FCN(test_ft_atoi), NULL, NULL, RUN },
	{ TEST_FCN(test_ft_bzero), NULL, NULL, RUN },
	{ TEST_FCN(test_ft_calloc), NULL, NULL, RUN },
	{ TEST_FCN(test_ft_isalnum), NULL, NULL, RUN },
	{ TEST_FCN(test_ft_isalpha), NULL, NULL, RUN },
	{ TEST_FCN(test_ft_isascii), NULL, NULL, RUN },
	{ TEST_FCN(test_ft_isdigit), NULL, NULL, RUN },
	{ TEST_FCN(test_ft_islower), NULL, NULL, RUN },
	{ TEST_FCN(test_ft_isprint), NULL, NULL, RUN },
	{ TEST_FCN(test_ft_isspace), NULL, NULL, RUN },
	{ TEST_FCN(test_ft_isupper), NULL, NULL, RUN },
	{ TEST_FCN(test_ft_itoa), NULL, NULL, RUN },
	{ TEST_FCN(test_ft_lstadd_back), NULL, NULL, RUN },
	{ TEST_FCN(test_ft_lstadd_front), NULL, NULL, RUN },
	{ TEST_FCN(test_ft_lstclear), NULL, NULL, RUN },
	{ TEST_FCN(test_ft_lstdelone), NULL, NULL, RUN },
	{ TEST_FCN(test_ft_lstiter), NULL, NULL, RUN },
	{ TEST_FCN(test_ft_lstlast), NULL, NULL, RUN },
	{ TEST_FCN(test_ft_lstmap), NULL, NULL, RUN },
	{ TEST_FCN(test_ft_lstnew), NULL, NULL, RUN },
	{ TEST_FCN(test_ft_lstsize), NULL, NULL, RUN },
	{ TEST_FCN(test_ft_lstpop_front), NULL, NULL, RUN },
	{ TEST_FCN(test_ft_lstpop_back), NULL, NULL, RUN },
	{ TEST_FCN(test_ft_memchr), NULL, NULL, RUN },
	{ TEST_FCN(test_ft_memcmp), NULL, NULL, RUN },
	{ TEST_FCN(test_ft_memcpy), NULL, NULL, RUN },
	{ TEST_FCN(test_ft_memmove), NULL, NULL, RUN },
	{ TEST_FCN(test_ft_memset), NULL, NULL, RUN },
	{ TEST_FCN(test_ft_putchar_fd), NULL, NULL, RUN },
	{ TEST_FCN(test_ft_putendl_fd), NULL, NULL, RUN },
	{ TEST_FCN(test_ft_puthnbr_fd), NULL, NULL, RUN },
	{ TEST_FCN(test_ft_putnbr_fd), NULL, NULL, RUN },
	{ TEST_FCN(test_ft_putstr_fd), NULL, NULL, RUN },
	{ TEST_FCN(test_ft_putunbr_fd), NULL, NULL, RUN },
	{ TEST_FCN(test_ft_split), NULL, NULL, RUN },
	{ TEST_FCN(test_ft_strchr), NULL, NULL, RUN },
	{ TEST_FCN(test_ft_strdup), NULL, NULL, RUN },
	{ TEST_FCN(test_ft_striteri), NULL, NULL, RUN },
	{ TEST_FCN(test_ft_strjoin), NULL, NULL, RUN },
	{ TEST_FCN(test_ft_strlcat), NULL, NULL, RUN },
	{ TEST_FCN(test_ft_strlcpy), NULL, NULL, RUN },
	{ TEST_FCN(test_ft_strlen), NULL, NULL, RUN },
	{ TEST_FCN(test_ft_strmapi), NULL, NULL, RUN },
	{ TEST_FCN(test_ft_strncmp), NULL, NULL, RUN },
	{ TEST_FCN(test_ft_strnstr), NULL, NULL, RUN },
	{ TEST_FCN(test_ft_strrchr), NULL, NULL, RUN },
	{ TEST_FCN(test_ft_strtrim), NULL, NULL, RUN },
	{ TEST_FCN(test_ft_substr), NULL, NULL, RUN },
	{ TEST_FCN(test_ft_tolower), NULL, NULL, RUN },
	{ TEST_FCN(test_ft_toupper), NULL, NULL, RUN },
	/* get_next_line */
	{ TEST_FCN(test_gnl_get_buffer), NULL, NULL, RUN },
	{ TEST_FCN(test_gnl_clear_buffer), NULL, NULL, RUN },
	{ TEST_FCN(test_gnl_get_line1), NULL, NULL, RUN },
	{ TEST_FCN(test_gnl_get_line2), NULL, NULL, RUN },
	{ TEST_FCN(test_gnl_get_line3), NULL, NULL, RUN },
	{ TEST_FCN(test_gnl_line_realloc), NULL, NULL, RUN },
	{ TEST_FCN(test_gnl_small_line_nonl), NULL, NULL, RUN },
	{ TEST_FCN(test_gnl_big_text_nl), NULL, NULL, RUN },
	{ TEST_FCN(test_gnl_big_text_alt_nl), NULL, NULL, RUN },
	{ TEST_FCN(test_gnl_one_nl), NULL, NULL, RUN },
	{ TEST_FCN(test_gnl_empty), NULL, NULL, RUN },
	{ TEST_FCN(test_gnl_fake_fd), NULL, NULL, RUN },
	/* ft_printf */
	{ TEST_FCN(test_ft_printf_percent), NULL, NULL, RUN },
	{ TEST_FCN(test_ft_printf_c), NULL, NULL, RUN },
	{ TEST_FCN(test_ft_printf_s), NULL, NULL, RUN },
	{ TEST_FCN(test_ft_printf_u), NULL, NULL, RUN },
	{ TEST_FCN(test_ft_printf_i), NULL, NULL, RUN },
	{ TEST_FCN(test_ft_printf_d), NULL, NULL, RUN },
	{ TEST_FCN(test_ft_printf_x), NULL, NULL, RUN },
	{ TEST_FCN(test_ft_printf_X), NULL, NULL, RUN },
	{ TEST_FCN(test_ft_printf_p), NULL, NULL, RUN },
	{ TEST_FCN(test_ft_printf_minus), NULL, NULL, RUN },
	{ TEST_FCN(test_ft_printf_plus), NULL, NULL, RUN },
	{ TEST_FCN(test_ft_printf_zero), NULL, NULL, RUN },
	{ TEST_FCN(test_ft_printf_sharp), NULL, NULL, RUN },
	{ TEST_FCN(test_ft_printf_dot), NULL, NULL, RUN },
	{ TEST_FCN(test_ft_printf_space), NULL, NULL, RUN },
	{ TEST_FCN(test_ft_printf_bonus_percent), NULL, NULL, RUN },
	{ TEST_FCN(test_ft_printf_bonus_s), NULL, NULL, RUN },
	{ TEST_FCN(test_ft_printf_bonus_d), NULL, NULL, RUN },
	{ TEST_FCN(test_ft_printf_bonus_i), NULL, NULL, RUN },
	{ TEST_FCN(test_ft_printf_bonus_u), NULL, NULL, RUN },
	{ TEST_FCN(test_ft_printf_bonus_x), NULL, NULL, RUN },
	{ TEST_FCN(test_ft_printf_bonus_X), NULL, NULL, RUN },
	TEST_END
};

int	main(int argc, const char *argv[])
{
	return (__main(argc, argv, tests));
}
