# Sample Makefile
CFLAGS := $(shell pkg-config --cflags glib-2.0)
LDFLAGS := $(shell pkg-config --libs glib-2.0)

helloGlib: helloGlib.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)
