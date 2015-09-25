#compiler variables
CCFLAGS = -Wall 

# Rule to link object code files to create executable file
server: server.o
	gcc $(CCFLAGS) -o server server.o

# Rules to compile source code files to object code
server.o: server.cc 
	g++ $(CCFLAGS) -c server.cc

# Pseudo-target to remove object code and executable files
clean:
	-rm *.o server

