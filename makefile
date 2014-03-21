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

all: settest wptest webpage

$(BIN_DIR)/settest.o: $(SRC_DIR)/settest.cpp $(LIB_DIR)/stlset.h
	$(CC) -c $< -o $@ $(CPPFLAGS) -I$(BIN_DIR)/

$(BIN_DIR)/webpagetest.o: $(SRC_DIR)/webpagetest.cpp webpage.h $(LIB_DIR)/stlset.h
	$(CC) -c $< -o $@ $(CPPFLAGS) -I$(BIN_DIR)/

$(BIN_DIR)/webpage.o: $(SRC_DIR)/webpage.cpp webpage.h $(LIB_DIR)/stlset.h
	$(CC) -c $< -o $@ $(CPPFLAGS) -I$(BIN_DIR)/

wptest: $(BIN_DIR)/webpagetest.o
	$(CC) $^ -o $@ $(CPPFLAGS) 

settest: $(BIN_DIR)/settest.o
	$(CC) $^ -o $@ $(CPPFLAGS) 

webpage: $(BIN_DIR)/webpage.o
	$(CC) $^ -o $@ $(CPPFLAGS) 


clean: 
	rm -f *.o *~ 