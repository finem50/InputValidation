all: gpacalc.cpp
	g++ -o calculate gpacalc.cpp

clean:
	rm -f calculate
