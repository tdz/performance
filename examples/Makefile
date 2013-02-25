
.SUFFIXES: .c .o
.PHONY: all clean
.DEFAULT_GOAL := all

# Files

PROGRAMS := align \
            concat_naive \
            concat_reuse \
            concat_str \
            lut_bl \
            lut_if \
            lut_nonconst \
            lut_switch \
            sgn_bl \
            sgn_naive \
            sort_b \
            sort_q

align: align.o

concat_naive: concat.o \
              concat_naive.o \
              readrand.o

concat_reuse: concat.o \
              concat_reuse.o \
              readrand.o

concat_str: concat.o \
            concat_str.o \
            readrand.o

lut_bl: lut.o \
        lut_bl.o \
        readrand.o

lut_if: lut.o \
        lut_if.o \
        readrand.o

lut_nonconst: lut.o \
              lut_nonconst.o \
              readrand.o

lut_switch: lut.o \
            lut_switch.o \
            readrand.o

sgn_bl: readrand.o \
        sgn.o \
        sgn_bl.o

sgn_naive: readrand.o \
           sgn.o \
           sgn_naive.o

sort_b: readrand.o \
        sort.o \
        sort_b.o

sort_q: readrand.o \
        sort.o \
        sort_q.o

# Tools

CC := gcc
CPPFLAGS := -D_GNU_SOURCE=1
CFLAGS := -O0 -ggdb

LD := gcc
LDFLAGS :=
LIBS := -lc

# Rules

all: $(PROGRAMS)

clean:
	$(RM) $(PROGRAMS)
	$(RM) *.o

%.o: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c -o $@ $<

%:
	$(LD) $(LDFLAGS) -o $@ $^ $(LIBS)
