NAME = con

SRCS = my_main.cpp

OBJS = $(SRCS:.cpp=.o)

CC = g++ 

CFLAGS = -Wall -Wextra -Werror -std=c++98 #-fsanitize=address -g

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< 


clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean