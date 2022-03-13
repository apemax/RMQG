CC = g++
CXXFLAGS = -no-pie -Werror -Wall -Wextra
DEPS = global.h types.h

ODIR = obj
BUILD_DIR = build

BIN = RMQG

_OBJ = main.o casual.o challenge.o types.o global.o listgen.o listcheck.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

.SECONDEXPANSION:

$(ODIR)/%.o: %.cpp $(DEPS) | $$(@D)
	$(CC) -c -o $@ $< $(CXXFLAGS)

$(BUILD_DIR)/RMQG: $(OBJ) | $$(@D)
	$(CC) -o $@ $^ $(CXXFLAGS)

$(BUILD_DIR):
	mkdir -p $@

$(ODIR):
	mkdir -p $@

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o $(BUILD_DIR)/$(BIN)
