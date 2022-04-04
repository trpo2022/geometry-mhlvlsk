CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -I sorce -MMD
DIR_GUARD = @mkdir -p $(@D)

all: bin/geom

-include obj/inputread.d obj/circle.d obj/point.d obj/triangle.d obj/main.d

bin/geom: obj/inputread.o obj/circle.o obj/point.o obj/triangle.o obj/main.o obj/lib.a
	$(DIR_GUARD)
	gcc $(CFLAGS) $(CPPFLAGS) -o $@ $^ -lm

obj/lib.a: obj/circle.o obj/point.o obj/triangle.o
	ar rcs $@ $^

obj/inputread.o: sorce/geom/inputread.c
	$(DIR_GUARD)
	gcc $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

obj/circle.o: sorce/lib/circle.c
	gcc $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

obj/point.o: sorce/lib/point.c
	gcc $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

obj/triangle.o: sorce/lib/triangle.c
	gcc $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

obj/main.o: sorce/geom/main.c
	gcc $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

clean:
	rm bin/* obj/*
