CC = g++
CFLAGS = -Wall -Werror -pedantic --std=c++14
LIBS = -lsfml-graphics -lsfml-window -lsfml-system
DEPS = FibLFSR.h

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -c $<

all: ps1b

ps1b: FibLFSR.o PhotoMagic.o
	$(CC) $(CFLAGS) -o PhotoMagic $^ $(LIBS)

clean:
	rm *.o PhotoMagic
