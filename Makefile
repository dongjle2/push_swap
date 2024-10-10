NAME := push_swap
OBJDIR := obj

SRCS_MAND := main.c helper.c \
			instructions_a.c \
			malloc_manage.c \
			instructions_b.c \
			simple_sort.c \
			sort_algo.c \
			validate_input.c \
			ck_input.c \
			init.c \
			stack_utils.c \
			mk_int_arr.c
OBJS_MAND := $(SRCS_MAND:%.c=$(OBJDIR)/%.o)
LIBFT := ./libft/libft.a
CFLAGS := -g -Wall -Wextra -Werror

all: $(NAME)

ifdef WITH_BONUS
OBJS_LIST = $(OBJS_MAND) $(OBJS_BONUS)
else
OBJS_LIST = $(OBJS_MAND)
endif

$(OBJDIR):
	mkdir -p $(OBJDIR)

# cc -g $(OBJS_MAND) -o $@ -L./libft -lft -fsanitize=address
$(NAME): $(LIBFT) $(OBJS_LIST)
	cc $(CFLAGS) $(OBJS_MAND) -o $@ -L./libft -lft

$(OBJDIR)/%.o: %.c | $(OBJDIR)
	cc $(CFLAGS) -c $< -o $@

bonus: $(NAME)

clean:
	rm -f $(OBJDIR)/*.o
	rm -r $(OBJDIR)

re: fclean
	make all

fclean: clean
	rm -f $(NAME)

.PHONY : all bonus clean fclean re