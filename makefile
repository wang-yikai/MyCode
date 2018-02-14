G++ = g++ -std=c++11
input = hw03
output = $(input).out

compile:
	$(G++) -o $(output) $(input).cpp

# Compile and run
run: compile
	./$(output)

clean:
	rm -f $(output)
	rm -f *.out
	rm -f *~
