NAME = RPN


src = main.cpp
onj = $(src:cpp=.o)

re:clean all

all: $(NAME)

$(NAME): $(obj)
	c++ $(obj) main.cpp -o $@ -lreadline
%.o: %.cpp 
	c++ -lreadline $< -c -o $@

clean:
	rm -fr $(obj) $(NAME)
