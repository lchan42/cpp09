# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lchan <lchan@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/16 15:50:50 by lchan             #+#    #+#              #
#    Updated: 2023/04/22 12:16:29 by lchan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	PmergeMe
SRCS	=	main.cpp PmergeMe.cpp
HEADER	=	PmergeMe.hpp
OBJS	=	$(SRCS:.cpp=.o)
COMPIL	=	c++
FLAGS	=	-std=c++98 -Wall -Wextra  -Wno-unused -g3

#-Werror

# $< = dependances | $@ = regles -> .o

%.o:	%.cpp
	$(COMPIL) $(FLAGS) -c $< -o $@

all:	$(NAME)

$(NAME): $(OBJS) $(HEADER)
	$(COMPIL) $(FLAGS) $(OBJS) -o $@

clean:
	rm -rf $(OBJS)

fclean:	clean
	rm -rf $(NAME)

re: fclean all

# 5: make re && ./PmergeMe `shuf -i 1-100000 -n 5000 | tr "\n" " "`

.PHONY: all clean fclean re
