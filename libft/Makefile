
NAME = libft.a
FLAGS = -Wall -Wextra -Werror
LIBFT = libft.h

SRCS = ft_atoi.c \
	  ft_bzero.c \
	  ft_isalnum.c \
	  ft_isalpha.c \
	  ft_isascii.c \
	  ft_isdigit.c \
	  ft_isprint.c \
	  ft_memchr.c \
	  ft_memcmp.c \
	  ft_memcpy.c \
	  ft_memset.c \
	  ft_putchar_fd.c \
	  ft_strlcat.c \
	  ft_strchr.c \
	  ft_strlcpy.c \
	  ft_strlen.c \
	  ft_strrchr.c \
	  ft_strnstr.c \
	  ft_strncmp.c \
	  ft_strdup.c \
	  ft_calloc.c \
	  ft_tolower.c \
	  ft_toupper.c \
	  ft_memmove.c \
	  ft_substr.c \
	  ft_strjoin.c \
	  ft_strtrim.c \
	  ft_striteri.c \
	  ft_itoa.c \
	  ft_putstr_fd.c \
	  ft_strmapi.c \
	  ft_putendl_fd.c \
	  ft_putnbr_fd.c \
	  ft_strcpy.c \
	  ft_strcat.c \
	  ft_strncat.c \
	  ft_strcmp.c \
	  ft_split.c \
	#   $(wildcard printf/*.c) \
	#   $(wildcard GNL/*.c)

SRCSBONUS = ft_lstnew.c \
	  ft_lstsize.c \
	  ft_lstlast.c \
	  ft_lstadd_back.c \
	  ft_lstadd_front.c \
	  ft_lstdelone.c \
	  ft_lstclear.c \
	  ft_lstiter.c \
	  ft_lstmap.c \

OBJS = $(SRCS:.c=.o)

OBJSBONUS = $(SRCSBONUS:.c=.o)

.PHONY: all clean fclean re bonus

all: $(NAME) bonus

$(NAME): $(OBJS) $(OBJSBONUS)
		ar rcs $(NAME) $(OBJS) $(OBJSBONUS)

bonus:	$(OBJSBONUS)
		ar r $(NAME) $(OBJSBONUS)

$(OBJSBONUS): %.o: %.c
		cc $(FLAGS) -c $< -o $@

$(OBJS): %.o: %.c $(LIBFT)
		cc $(FLAGS) -c $< -o $@

clean:
		/bin/rm -f $(OBJS) $(OBJSBONUS)

fclean:	clean
		/bin/rm -f $(NAME)

re:		fclean all