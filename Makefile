NAME = RPN

CPP = c++ 

RM = rm -f

FLG = -lreadline

SRC = main.cpp utils.cpp infix_to_postfix.cpp eval_postfix.cpp 
OBJ = $(SRC:.cpp=.o)

all: $(NAME)


$(NAME): $(OBJ) 
	$(CPP) $(FLG) $^ -o $@

%.o: %.cpp 
	$(CPP) $< -c -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all