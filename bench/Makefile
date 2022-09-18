INC_DIR := ../include
SRCS	:=	vector_bench.cpp\
			Stopwatch.cpp
OBJS	:= $(SRCS:.cpp=.o)
CXX		:= c++
CXXFLAGS:= 

all: vector

vector: vector_bench.o vector_bench_cases.o Stopwatch.o
	$(CXX) $(CXXFLAGS) $^ -o $@ -I $(INC_DIR)

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $< -I $(INC_DIR)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f vector

re: fclean all

.PHONY: all clean fclean re debug