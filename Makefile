CC = gcc
CFLAGS = -Wall -std=c99
LIBS = -lm
TARGET = calculator
SRC = calculator.c

all: $(TARGET)

$(TARGET): $(SRC)
    $(CC) $(CFLAGS) $(SRC) -o $(TARGET) $(LIBS)

run: $(TARGET)
    ./$(TARGET)

clean:
    rm -f $(TARGET) *.o

help:
    @echo "Available commands:"
    @echo "  make           - Compile the calculator"
    @echo "  make run       - Compile and run the calculator"
    @echo "  make clean     - Remove build artifacts"
    @echo "  make help      - Show this help message"

.PHONY: all run clean help