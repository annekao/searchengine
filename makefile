CC = g++

CPPFLAGS = -Wall -g 
SRC_DIR = lib
OBJ_DIR = bin

_OBJS=$(patsubst $(SRC_DIR)/%,$(OBJ_DIR)/%,$(wildcard $(SRC_DIR)/*.cpp))
OBJS=$(patsubst %.cpp,%.o,$(_OBJS))

all: search

$(OBJ_DIR)/search.o: $(SRC_DIR)/search.cpp $(SRC_DIR)/map.h $(SRC_DIR)/set.h $(SRC_DIR)/list.h
	$(CC) -c $< -o $@ $(CPPFLAGS) -I$(OBJ_DIR)/

search: $(OBJS)
	$(CC) $^ -o $@ $(CPPFLAGS) 

clean: 
	rm -f *.o *~ 

