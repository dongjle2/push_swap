NAME := push_swap
OBJDIR := obj

SRCS_MAND := main.c helper.c instructions_a.c push_swap.c instructions_b.c quick_sort.c validate_input.c
OBJS_MAND := $(SRCS_MAND:%.c=$(OBJDIR)/%.o)
# SRCS_BONUS := fmt_s_bonus.c fmt_u_bonus.c fmt_x_bonus.c \
# 				fmt_c_bonus.c fmt_p_bonus.c fmt_d_bonus.c \
# 				ft_printf_helper_bonus.c ft_numtoa_bonus.c \
# 				ft_printf_bonus.c check_input_bonus.c inits_bonus.c
# OBJS_BONUS := $(SRCS_BONUS:.c=.o)

LIBFT := ./libft/libft.a
# CFLAGS := -Wall -Wextra -Werror


all: $(NAME)

ifdef WITH_BONUS
OBJS_LIST = $(OBJS_MAND) $(OBJS_BONUS)
else
OBJS_LIST = $(OBJS_MAND)
endif

$(OBJDIR):
	mkdir -p $(OBJDIR)


$(NAME): $(LIBFT) $(OBJS_LIST)
	cc -g $(OBJS_MAND) -o $@ -L./libft -lft -fsanitize=address
# cc -g $(OBJS_MAND) -o $@ -L./libft -lft 
# cc $(CFLAGS) $(OBJS_MAND) -o $@ -L./libft -lft

$(OBJDIR)/%.o: %.c | $(OBJDIR)
	cc -g $(CFLAGS) -c $< -o $@

bonus: $(NAME)

clean:
	rm -f $(OBJDIR)/*.o
	rm -r $(OBJDIR)

re: fclean
	make all

fclean: clean
	rm -f $(NAME)

.PHONY : all bonus clean fclean re