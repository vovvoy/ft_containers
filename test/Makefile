NAME		=	ft_containers

SRCS		=	main.cpp \
				ListTest.cpp \
				MapTest.cpp \
				QueueTest.cpp \
				StackTest.cpp \
				VectorTest.cpp \


CC			=	g++

OBJS		=	$(SRCS:.cpp=.o)

CPPFLAGS		+=	-c -Wall -Werror -Wextra -I /usr/local/include
CFLAGS			+=	-L /usr/local/lib -l gtest -l pthread

all			:	$(NAME)

run			:	all
	./ft_containers

vector		:	$(OBJS)
				$(CC) -o $(NAME) main.o VectorTest.o $(CFLAGS)
				./ft_containers

list		:	$(OBJS)
				$(CC) -o $(NAME) main.o ListTest.o $(CFLAGS)
				./ft_containers

stack		:	$(OBJS)
				$(CC) -o $(NAME) main.o StackTest.o $(CFLAGS)
				./ft_containers

queue		:	$(OBJS)
				$(CC) -o $(NAME) main.o QueueTest.o $(CFLAGS)
				./ft_containers

map		:	$(OBJS)
				$(CC) -o $(NAME) main.o MapTest.o $(CFLAGS)
				./ft_containers

$(NAME)		:	$(OBJS)
				$(CC) -o $(NAME) $(OBJS) $(CFLAGS)

clean		:
				rm -rf $(OBJS)

fclean		:	clean
				rm -f $(NAME)

re			:	fclean all