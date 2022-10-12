CXX := g++
CXXFLAGS := -g -Wall --std=c++11
VALGRIND := valgrind --tool=memcheck --leak-check=yes

all: llrec-test llrec-test1.in
	$(VALGRIND) ./$^ 9 19
	$(VALGRIND) ./$^ 0 8

#-----------------------------------------------------
# ADD target(s) to build your llrec-test executable
#-----------------------------------------------------

llrec-test: llrec-test.cpp llrec.o
	$(CXX) $(CXXFLAGS) $^ -o $@

llrec.o: llrec.cpp llrec.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o rh llrec-test *~

.PHONY: clean 