# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaleassa <aaleassa@learner.42.tech>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/21 12:29:16 by aabtah            #+#    #+#              #
#    Updated: 2026/02/23 14:08:20 by aaleassa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc -Wall -Wextra -Werror
CFLAGS =  -I. -Ift_printf
SRCS = main.c \
       adaptive_sort.c \
       bench.c \
       complex_alg.c \
       compute_disorder.c \
       ft_reverse_split.c \
       helper_fun_1.c \
       helper_fun_free.c \
       helper_fun_libft.c \
       helper_fun_main.c \
       index.c \
       medium_algorithem.c \
       push.c \
       reverse_rotate.c \
       rotate.c \
       selection_sort.c \
       sort_small.c \
       swap.c \
       ft_printf/ft_printf.c \
       ft_printf/ft_printf_hex.c \
       ft_printf/ft_printf_numbers.c \
	   ft_printf/ft_putfloat.c \
       ft_printf/ft_printf_utils.c
OBJS = $(SRCS:.c=.o)

HEADER = push_swap.h

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
