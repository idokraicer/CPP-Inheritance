all:
	g++ -std=c++17 -o Ass5 *.cpp

clean:
	rm -f $(OBJS) $(OUT)