all: gpacalc.cpp
	g++ -o valid_calc gpacalc.cpp

clean:
	rm -f valid_calc
