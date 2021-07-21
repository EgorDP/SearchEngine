CXX=g++
CXXFLAGS?=-Wall -pedantic -g -O0 -std=c++11
OUTFILE=VectorSpace
all: $(OUTFILE)

f: clean VectorSpace

VectorSpace: VectorSpace.cpp VectorSpace.hpp Binary.cpp Binary.hpp
	$(CXX) $(CXXFLAGS) -o VectorSpace.o VectorSpace.cpp Binary.cpp

clean:
	$(RM) *.o