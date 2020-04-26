# Example Makefile for this project

# Default value for INPUT is -, or standard input
INPUT=-

build:
	$(CXX) -o main main.cpp 

# To run this, you will need to do:
#   make run T1=path/to/t1 T2=path/to/t2 T3=path/to/t3
#
# If you wish to test this with streaming in the data, use
#   make run T1=path/to/t1 T2=path/to/t2 T3=path/to/t3 INPUT=path/to/input
run:
ifeq ($(INPUT), -)
	./main $(T1) $(T2) $(T3)

endif
