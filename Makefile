NAME = libasm.a
CC = nasm
CFLAGS = -f macho64
LIBC = ar rc
LIBI = ranlib
SRCS = ft_strlen.s\
		ft_strcpy.s\
		ft_strcmp.s\
		ft_write.s\
		ft_read.s\
		ft_strdup.s
OBJS = $(SRCS:.s=.o)
%.o: %.s $(HEADER)
	$(CC) $(CFLAGS) -s $< -o $(<:.s=.o)
all: $(NAME)
$(NAME): $(OBJS)
	@echo "\033[92mOBJECTS CREATED\033[0m"
	$(LIBC) $(NAME) $(OBJS)
	$(LIBI) $(NAME)
	@echo "\033[95mLIBRARY LINKED\033[0m"
re:
	@echo "\033[91mRESTARTING\033[0m"
	@sleep 1
	@echo "\033[92mOK\033[0m"
	@sleep 0.5
	make fclean all
clean:
	@echo "\033[91m...\033[0m"
	rm -f $(OBJS)
	@echo "\033[92m...\033[0m"
fclean: clean
	@echo "\033[91m...\033[0m"
	rm -f $(NAME)
	@echo "\033[92m...\033[0m"
.PHONY: clean fclean re all
