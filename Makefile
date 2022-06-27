CC=clang
CFLAGS=-fno-rtti -flegacy-pass-manager -Xclang -load -Xclang build/mypass/libmypass.*
LDFLAGS=-undefined dynamic_lookup
# LDLIBS=
OBJS=main.o asdf.o
TARGET=main

all: $(TARGET)

clean:
	rm -f *.o
	rm -f $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS)
