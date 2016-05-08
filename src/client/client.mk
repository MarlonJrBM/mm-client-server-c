CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic -std=c++11
LIBS = 
BIN = cliente
SRC = src/client/ClientMain.cc src/client/ClientApplication.cc src/client/ServerMediator.cc
OBJ = obj/ClientMain.o obj/ClientApplication.o obj/ServerMediator.o
INCLUDES = -Iinclude/  
LDFLAGS = 
DEBUG ?= 0

ifeq ($(DEBUG),1)
	CXXFLAGS += -g
else
	CXXFLAGS += -O2
endif

$(BIN): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LIBS) $(LDFLAGS)
	@echo Compilation of $(BIN) finished successfully.
	
obj/%.o: src/client/%.cc
	$(CXX) $(CXXFLAGS) -o $@ -c $< $(INCLUDES)

run: $(BIN)
	./$(BIN)

.PHONY: clean

clean:
	rm -rf $(OBJ) *~ $(BIN)

depend: $(SRC)
	makedepend $^ $(INCLUDES)

src/client/Client.o: include/ClientApplication.h include/ServerMediator.h
src/client/ClientApplication.o: include/ClientApplication.h
src/client/ClientApplication.o: include/ServerMediator.h
src/client/ServerMediator.o: include/ServerMediator.h


