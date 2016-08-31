#!/usr/bin/env make

MODULE=RomanNumeralCalculator
CHECK=$(MODULE).check
TEST=$(MODULE)_test

all:	$(TEST)
	@echo `date +%Y%m%d%H%M%S`
	@./$<

.PHONY:
clean:
	@rm -f \
		$(MODULE).o \
		$(MODULE).a \
		$(TEST).c \
		$(TEST)

$(TEST):	$(TEST).c $(MODULE).a
	@gcc \
		-std=gnu99 \
		-Wall \
		-I/opt/local/include \
		-I. \
		-o $@ \
		$< \
		$(MODULE).a \
		`pkg-config --cflags --libs check` \
		-L/opt/local/lib \
		-lcheck

$(TEST).c:	$(CHECK)
	@checkmk $(CHECK) > $@

$(MODULE).a:	$(MODULE).o
	@ar -rcs $@ $(MODULE).o
	@ranlib $@

$(MODULE).o:	$(MODULE).c
	@gcc -std=gnu99 -c -o $(MODULE).o $<
