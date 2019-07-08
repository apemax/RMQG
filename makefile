CC = g++
CXXFLAGS = -no-pie -Wall
DEPS = global.h types.h

ODIR = obj

BIN = RMQG

_OBJ = main.o casual.o challenge.o types.o global.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CXXFLAGS)

RMQG: $(OBJ)
	$(CC) -o $@ $^ $(CXXFLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o $(BIN)
