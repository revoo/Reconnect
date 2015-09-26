#compiler variables
CCFLAGS = -Wall 

# Rule to link object code files to create executable file
server: server.o reconnect.o 
	gcc $(CCFLAGS) -o server server.o reconnect.o 
# Rules to compile source code files to object code
server.o: server.cc reconnect.cc
	gcc $(CCFLAGS) -c server.cc reconnect.cc
# Make Client
client: client.o reconnect.o
	gcc $(CCFLAGS) -o client client.o reconnect.o
client.o: client.cc reconnect.cc
	gcc $(CCFLAGS) -c client.cc reconnect.cc 
# Pseudo-target to remove object code and executable files
clean:
	-rm *.o server client

