CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -I source -MMD
DIR_GUARD = @mkdir -p $(@D)

all: bin/geom

-include obj/inputread.d obj/circle.d obj/point.d obj/triangle.d obj/main.d

bin/geom: obj/inputread.o obj/circle.o obj/point.o obj/triangle.o obj/main.o obj/lib.a
	$(DIR_GUARD)
	gcc $(CFLAGS) $(CPPFLAGS) -o $@ $^ -lm

obj/lib.a: obj/circle.o obj/point.o obj/triangle.o
	ar rcs $@ $^

obj/inputread.o: source/geom/inputread.c
	$(DIR_GUARD)
	gcc $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

obj/circle.o: source/lib/circle.c
	gcc $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

obj/point.o: source/lib/point.c
	gcc $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

obj/triangle.o: source/lib/triangle.c
	gcc $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

obj/main.o: source/geom/main.c
	gcc $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

clean:
	rm bin/* obj/*
