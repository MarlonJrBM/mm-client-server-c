BIN_0 = cliente
BIN_1 = servidor

all: $(BIN_0) $(BIN_1)
	@echo Success

$(BIN_0):
	make -f src/client/client.mk

$(BIN_1):
	make -f src/server/server.mk


.PHONY: clean


clean:
	make clean -f src/client/client.mk
	make clean -f src/server/server.mk

depend:
	make depend -f src/client/client.mk
	make depend -f src/server/server.mk



# DO NOT DELETE
