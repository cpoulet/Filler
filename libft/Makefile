# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpoulet <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/03 09:22:13 by cpoulet           #+#    #+#              #
#    Updated: 2017/01/26 19:09:23 by cpoulet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC =	ft_putchar.c\
		ft_strlcpy.c\
		ft_putchar_fd.c\
		ft_strlen.c\
		ft_wstrlen.c\
		ft_putendl.c\
		ft_strmap.c\
		ft_putendl_fd.c\
		ft_strmapi.c\
		ft_atoi.c\
		ft_approx.c\
		ft_atoi_skip.c\
		ft_putnbr.c\
		ft_strncat.c\
		ft_bzero.c\
		ft_putnbr_fd.c\
		ft_strncmp.c\
		ft_putstr.c\
		ft_strncpy.c\
		ft_first_word.c\
		ft_putstr_fd.c\
		ft_strnequ.c\
		ft_isalnum.c\
		ft_strcat.c\
		ft_strnew.c\
		ft_rangenew.c\
		ft_tabnew.c\
		ft_tab_i_new.c\
		ft_wcharnew.c\
		ft_wcharnew_c.c\
		ft_isalpha.c\
		ft_ishexa.c\
		ft_get_hexa.c\
		ft_get_nb_b.c\
		ft_memalloc.c\
		ft_strchr.c\
		ft_strnstr.c\
		ft_isascii.c\
		ft_memccpy.c\
		ft_strclr.c\
		ft_strrchr.c\
		ft_isdigit.c\
		ft_isblank.c\
		ft_memchr.c\
		ft_strcmp.c\
		ft_strsplit.c\
		ft_isprint.c\
		ft_memcmp.c\
		ft_strcpy.c\
		ft_strstr.c\
		ft_strredim.c\
		ft_itoa.c\
		ft_itoa_base.c\
		ft_memcpy.c\
		ft_strdel.c\
		ft_strsub.c\
		ft_memdel.c\
		ft_strdup.c\
		ft_strtrim.c\
		ft_memmove.c\
		ft_strequ.c\
		ft_tolower.c\
		ft_strtolow.c\
		ft_strtoup.c\
		ft_memset.c\
		ft_striter.c\
		ft_toupper.c\
		ft_nblen.c\
		ft_u_nblen.c\
		ft_nblen_b.c\
		ft_striteri.c\
		ft_nbword.c\
		ft_strjoin.c\
		ft_power.c\
		ft_u_power.c\
		ft_strlcat.c\
		ft_lstnew.c\
		ft_lstadd.c\
		ft_lstaddend.c\
		ft_lstdel.c\
		ft_lstdelone.c\
		ft_lstiter.c\
		ft_lstmap.c\
		ft_tabdel.c\
		ft_tab_to_lst.c\
		ft_is_char.c\
		ft_max.c\
		ft_min.c\
		get_next_line.c\
		ft_printf.c\
		buffer.c\
		format.c\
		fwp_bin.c\
		fwp_int.c\
		fwp_hex.c\
		fwp_ptr.c\
		fwp_wstr.c\
		fwp_u_int.c\
		fwp_char.c\
		fwp_oct.c\
		fwp_wchar.c\
		parser.c\
		cast_mod.c\
		lst_arg.c\
		str_field.c\
		num_field.c\

OBJ = $(SRC:.c=.o)

HEADER = includes/

FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJ)
	@ar rc $@ $(OBJ)
	@ranlib $@

%.o: %.c
	@gcc -o $@ -c $< $(FLAGS) -I $(HEADER)

.PHONY : clean

clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)

re : fclean all
