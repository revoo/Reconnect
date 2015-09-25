#compiler variables
CCFLAGS = -Wall 

# Rule to link object code files to create executable file
server: server.o reconnect.o
	gcc $(CCFLAGS) -o server server.o reconnect.o

# Rules to compile source code files to object code
server.o: server.cc reconnect.cc
	g++ $(CCFLAGS) -c server.cc reconnect.cc

# Pseudo-target to remove object code and executable files
clean:
	-rm *.o server

