# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arafeeq <arafeeq@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/19 11:59:12 by arafeeq           #+#    #+#              #
#    Updated: 2022/11/30 19:29:04 by arafeeq          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS =	ft_isalpha ft_isdigit ft_isalnum ft_isascii ft_isprint\
		ft_strlen ft_memset ft_bzero ft_memcpy ft_memmove\
		ft_strlcpy ft_strlcat ft_toupper ft_tolower ft_strchr\
		ft_strrchr ft_strncmp ft_memchr ft_memcmp ft_strnstr\
		ft_atoi ft_calloc ft_strdup ft_substr ft_strjoin\
		ft_strtrim ft_split ft_itoa ft_strmapi ft_striteri\
		ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_putnbr_fd\
		ft_lstnew ft_lstadd_front ft_lstsize ft_lstlast\
		ft_lstadd_back ft_lstdelone ft_lstclear ft_lstiter ft_lstmap

OBJDIR = libft_objects

OBJS = $(addprefix $(OBJDIR)/, $(addsuffix .o, $(SRCS)))

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

AR = ar rcs

$(OBJDIR)/%.o : %.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS) 

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all