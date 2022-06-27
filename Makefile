CC=clang
# CFLAGS=
# LDFLAGS=
# LDLIBS=
OBJS=main.o asdf.o
TARGET=main

all: $(TARGET)

clean:
	rm -f *.o
	rm -f $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS)
