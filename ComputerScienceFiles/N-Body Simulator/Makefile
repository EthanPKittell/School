CC = g++
CFLAGS = -Wall -Werror -pedantic --std=c++14
LIBS = -lsfml-graphics -lsfml-window -lsfml-system
DEPS = CelestialBody.h Universe.h

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -c $<

all: ps2b

ps2b: CelestialBody.o main.o
	$(CC) $(CFLAGS) -o NBody $^ $(LIBS)

clean:
	rm *.o NBody
