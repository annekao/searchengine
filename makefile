UNAME_S=$(shell uname -s)
ifeq ($(UNAME_S),Linux)
	CC=g++-4.8
else
	ifeq ($(UNAME_S),Darwin)
		CC=g++-4.8
	else
		CC=g++
	endif
endif

CPPFLAGS =-std=c++11 -Wall -g 
LIB_DIR = lib
BIN_DIR = bin
SRC_DIR = src

_OBJS=$(patsubst $(SRC_DIR)/%,$(BIN_DIR)/%,$(wildcard $(SRC_DIR)/*.cpp))
OBJS=$(patsubst %.cpp,%.o,$(_OBJS))

all: settest wptest search

$(BIN_DIR)/settest.o: $(SRC_DIR)/settest.cpp $(LIB_DIR)/stlset.h
	$(CC) -c $< -o $@ $(CPPFLAGS) -I$(BIN_DIR)/

$(BIN_DIR)/webpagetest.o: $(SRC_DIR)/webpagetest.cpp webpage.h webpage.cpp $(LIB_DIR)/stlset.h
	$(CC) -c $< -o $@ $(CPPFLAGS) -I$(BIN_DIR)/

$(BIN_DIR)/search.o: $(SRC_DIR)/search.cpp webpage.h webpage.cpp $(LIB_DIR)/stlset.h
	$(CC) -c $< -o $@ $(CPPFLAGS) -I$(BIN_DIR)/

$(BIN_DIR)/webpage.o: webpage.cpp webpage.h $(LIB_DIR)/stlset.h
	$(CC) -c $< -o $@ $(CPPFLAGS) -I$(BIN_DIR)/

wptest: $(BIN_DIR)/webpagetest.o $(BIN_DIR)/webpage.o
	$(CC) $^ -o $@ $(CPPFLAGS) 

settest: $(BIN_DIR)/settest.o
	$(CC) $^ -o $@ $(CPPFLAGS) 

search: $(BIN_DIR)/search.o $(BIN_DIR)/webpage.o
	$(CC) $^ -o $@ $(CPPFLAGS) 


clean: 
	rm -f *.o *~ 