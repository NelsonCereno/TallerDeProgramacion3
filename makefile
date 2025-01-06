FLAGS = -g
#FLAGS = -O2

all: main test_graph test_maxflow

main: Graph.o MaxFlow.o Main.o
	g++ ${FLAGS} Graph.o MaxFlow.o Main.o -o main

test_graph: Graph.o MaxFlow.o test_graph.o
	g++ ${FLAGS} Graph.o MaxFlow.o test_graph.o -o test_graph

test_maxflow: Graph.o MaxFlow.o test_maxflow.o
	g++ ${FLAGS} Graph.o MaxFlow.o test_maxflow.o -o test_maxflow

Graph.o: Graph.h Graph.cpp
	g++ ${FLAGS} -c Graph.cpp

MaxFlow.o: MaxFlow.h MaxFlow.cpp
	g++ ${FLAGS} -c MaxFlow.cpp

Main.o: Main.cpp
	g++ ${FLAGS} -c Main.cpp

test_graph.o: test_graph.cpp
	g++ ${FLAGS} -c test_graph.cpp

test_maxflow.o: test_maxflow.cpp
	g++ ${FLAGS} -c test_maxflow.cpp

clean:
	rm -f *.o main test_graph test_maxflow