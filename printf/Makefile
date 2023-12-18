SRCS	=	ft_strlen.c \
			ft_memset.c \
			ft_calloc.c \
			ft_strdup.c \
			ft_tolower.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_c_char.c \
			ft_s_char.c \
			ft_itoa.c \
			ft_convertbase16.c \
			ft_p_voidp.c \
			ft_di_int.c \
			ft_putcount.c \
			ft_put_identifer.c \
			ft_printf.c \
			ft_u_ull.c \
			ft_xlx_ui.c \
			ft_output.c

NAME	=	libftprintf.a

OBJS	=	$(SRCS:%.c=%.o)

CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror

all:		${NAME}

${NAME}:	${OBJS}
			ar rcs $@ $^

%.o:		%.c
			${CC} ${CFLAGS} -c $< -o $@

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re