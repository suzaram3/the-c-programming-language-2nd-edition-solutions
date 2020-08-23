rwildcard=$(foreach d, $(wildcard $(1:=/*)), $(call rwildcard, $d, $2) $(filter $(subst *, %, $2), $d))

SOURCES = $(call rwildcard, ., *.c *.h)
EXECS = $(SOURCES:%.c=%)
CFLAGS = -lm

all: $(EXECS)
clean:
	rm -f $(EXECS)
