CC=cc
TARGET=fbase

all: fbase

$(TARGET): cat.o
 $(CC) $< -o $@

%.o:%.c
 $(CC) -c $<

clean:
 rm -f *.o $(TARGET)
