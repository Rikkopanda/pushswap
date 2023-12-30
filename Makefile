
LIBFTA = libft/libft.a

INCL = -I./libft -I./include
CFLAGS = -Wall -Werror -Wextra $(INCL) -g
PS_DIR = pushswap_src/
PS_MAINSRC = $(PS_DIR)pushswap.c
PS_SRCS = 	$(PS_DIR)make_stack_a.c	\
		$(PS_DIR)sorting.c \
		$(PS_DIR)clear_stack.c \
		$(PS_DIR)pushing_nodes.c \
		$(PS_DIR)sorting_init.c \
		$(PS_DIR)sorting_tools.c \
		$(PS_DIR)set_targets.c \
		$(PS_DIR)parsing_args.c \
		$(PS_DIR)general_tools.c \
		$(PS_DIR)commands/push.c \
		$(PS_DIR)commands/rotate.c \
		$(PS_DIR)commands/swap.c \
		$(PS_DIR)commands/reverserotate.c
#$(PS_DIR)debug.c
PS_OBJS = $(PS_SRCS:.c=.o)
PS_MAINOBJ = $(PS_MAINSRC:.c=.o)
PS_EXE = push_swap
PS_A = push_swap.a

CHKR_DIR = checker_src/
GNL_DIR = libft/get_next_line/
CHKR_MAINSRCS = $(CHKR_DIR)checker.c \
				$(CHKR_DIR)read_stdin.c \
				$(GNL_DIR)get_next_line.c \
				$(GNL_DIR)get_next_line_utils.c \
				$(CHKR_DIR)freeing_checker.c
CHKR_MAINOBJS = $(CHKR_MAINSRCS:.c=.o)
CHKR_EXE = checker
CHKR_A = checker.a

.PHONY: all clean fclean re bonus

all: $(PS_EXE)

$(PS_EXE) : $(PS_OBJS) $(PS_MAINOBJ) $(LIBFTA)
	cp $(LIBFTA) $(PS_A)
	ar rcs $(PS_A) $(PS_OBJS) $(PS_MAINOBJ)
	cc $(CFLAGS) $(PS_A) -o $(PS_EXE)

$(CHKR_EXE) : $(PS_OBJS) $(CHKR_MAINOBJS) $(LIBFTA)
	cp $(LIBFTA) $(CHKR_A)
	ar rcs $(CHKR_A) $(PS_OBJS) $(CHKR_MAINOBJS)
	cc $(CFLAGS) $(CHKR_A) -o $(CHKR_EXE)

$(PS_OBJS): %.o: %.c 
		cc $(CFLAGS) -c $< -o $@

$(PS_MAINOBJ): %.o: %.c 
		cc $(CFLAGS) -c $< -o $@

$(CHKR_MAINOBJS): %.o: %.c 
		cc $(CFLAGS) -c $< -o $@

$(LIBFTA) :
	make -C libft/

clean:
	rm -f $(PS_OBJS) $(PS_MAINOBJ) $(PS_A) $(PS_EXE)

fclean:	clean
	rm -f $(CHKR_MAINOBJS) $(CHKR_A) $(CHKR_EXE)
	make fclean -C libft/

re:		fclean all
