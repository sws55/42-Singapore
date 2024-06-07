# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sebwong <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/26 19:17:17 by sebwong           #+#    #+#              #
#    Updated: 2024/05/26 19:17:19 by sebwong          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(NAME): $(OBJS)
	$(ARFLAGS) $(NAME) $(OBJS)

bonus: $(OBJS) $(OBJS_BONUS)
	$(ARFLAGS) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
