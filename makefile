CC     = gcc
CFLAGS = -Wall -I.
 
SRCS = src/main.c src/menu.c \
       src/data_structures/linked_list.c \
       src/data_structures/queue.c \
       src/data_structures/priority_queue.c \
       src/algorithms/linear_search.c \
       src/algorithms/merge_sort.c \
       src/algorithms/greedy.c \
       src/logic/evaluasi.c \
       src/logic/scoring.c \
       src/logic/output.c
 
all:
	$(CC) $(CFLAGS) $(SRCS) -o daosKelompok2
