# REFINED VERSION
# This is the default target, which will be built when you invoke make
.PHONY: all
# Redefine the target all with the requirement of hello & ut_all
all: hello ut_all

# This rule tells make how to build Helloworld from HelloWorld.cpp
hello: HelloWorld.cpp
	g++ HelloWorld.cpp -o HelloWorld

# Thus rule tells make how to build ut_all from ut_main.cpp
ut_all: ut_main.cpp
	g++ -std=c++11 -Wfatal-errors ut_main.cpp -o ut_all -lgtest -lpthread

# This rule tells make to delete hello and hello.o
.PHONY: clean
clean:
	rm -f HelloWorld
	rm -f ut_all


## ORIGINAL VERSION
# # This is the default target, which will be built when you invoke make
# .PHONY: all

# # This rule tells make how to build HelloWorld from HelloWorld.cpp
# all: HelloWorld.cpp
# 	g++ HelloWorld.cpp -o HelloWorld

# # This rule tells make to delete hello and hello.o 
# .PHONY: clean
# clean:
# 	rm -f HelloWorld
# 	rm -f ut_all
