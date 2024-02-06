CC = gcc
CFLAGS = -Wall -Wextra -std=c11
SRCS = my_graph.c my_mat.c my_Knapsack.c
OBJS = $(SRCS:.c=.o)
EXECUTABLE1 = my_graph
EXECUTABLE2 = my_Knapsack
LIBRARY = libmy_mat.a

all: $(EXECUTABLE1) $(EXECUTABLE2)

$(EXECUTABLE1): my_graph.o $(LIBRARY)
	$(CC) $(CFLAGS) -o $@ my_graph.o -L. -lmy_mat

$(EXECUTABLE2): my_Knapsack.o
	$(CC) $(CFLAGS) -o $@ my_Knapsack.o

%.o: %.c my_mat.h
	$(CC) $(CFLAGS) -c $<

$(LIBRARY): my_mat.o
	ar -rcs $@ $<

clean:
	rm -f $(OBJS) $(EXECUTABLE1) $(EXECUTABLE2) $(LIBRARY)