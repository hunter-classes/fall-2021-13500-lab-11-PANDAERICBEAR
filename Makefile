main: main.o profile.o network.o
	g++ -o main main.o profile.o network.o

tests: tests.o profile.o network.o
	g++ -o tests tests.o profile.o network.o

main.o: main.cpp profile.h
	g++ -c -std=c++11 main.cpp

profile.o: profile.cpp profile.h
	g++ -c -std=c++11 profile.cpp

network.o: network.cpp network.h
	g++ -c -std=c++11 network.cpp

tests.o: tests.cpp doctest.h profile.h
	g++ -c -std=c++11 tests.cpp

clean:
	rm -f *.o main tests
