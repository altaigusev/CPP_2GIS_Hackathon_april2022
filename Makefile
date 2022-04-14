CXX = g++ -std=c++17
FLAGS = -Wall -Wextra -Werror
FILES = sequence_finder.cpp file_reader.cpp
CFLAGS= -fprofile-arcs -ftest-coverage

all:
	$(CXX) main.cpp $(FILES)
	./a.out

clean:
	rm -rf *.o *.out *.gcda *.gcno *.info *.gch *.a test *.gcov ./report

test:
	$(CXX) test.cpp sequence_finder.cpp file_reader.cpp -o test.out -lgtest -lgtest_main
	./test.out
	make example
	make timetest

timetest:
	$(CXX) simpleTest1.cpp $(FILES) -o ./simpletest1.out
	./simpleTest1.out

example:
	$(CXX) example1.cpp $(FILES) -o example1.out
	./example1.out > example1.txt
	$(CXX) example2.cpp $(FILES) -o example2.out
	./example2.out > example2.txt
	bash ./test.sh

gcov_report: clean
	$(CXX) $(FILES) test.cpp $(CFLAGS) -o test.out -lgtest -lgtest_main -DGCOV
	./test.out
	lcov -o coverage.info -c -d .
	lcov --remove coverage.info '/usr/*' -o filtered_coverage.info
	genhtml -o report filtered_coverage.info
	open report/index.html

cppcheck:
	-cppcheck --enable=all --suppress=missingIncludeSystem  *.cpp -DTEST

leaks: clean test
	leaks -atExit -- ./test.out

git:
	git add -A
	git commit -m"something done"