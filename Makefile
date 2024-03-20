NAME = con

SRCS = src/my_main.cpp

OBJS = $(SRCS:.cpp=.o)

CC = c++ 

CFLAGS = -Wall -Wextra -Werror -std=c++98 #-fsanitize=address -g

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) my_main.o

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< 


clean:
	@$(RM) my_main.o

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean