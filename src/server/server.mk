CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic -std=c++11
LIBS = 
BIN = servidor
SRC = src/server/ServerMain.cc src/server/ServerApplication.cc src/server/Server.cc src/server/Ranking.cc
OBJ = obj/ServerMain.o obj/ServerApplication.o obj/Server.o obj/Ranking.o
INCLUDES = -Iinclude/  
LDFLAGS = 
DEBUG ?= 0

ifeq ($(DEBUG), 1)
	CXXFLAGS += -g
else
	CXXFLAGS += -O2
endif

$(BIN): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LIBS) $(LDFLAGS)
	@echo Compilation of $(BIN) finished successfully.
	
obj/%.o: src/server/%.cc
	$(CXX) $(CXXFLAGS) -o $@ -c $< $(INCLUDES)

run: $(BIN)
	./$(BIN)

.PHONY: clean

clean:
	rm -rf $(OBJ) *~ $(BIN)

depend: $(SRC)
	makedepend $^ $(INCLUDES)



