.PHONY: all clean server clients run_server run_clients

all: server clients

server:
	gcc hello_server.c -o helloserver
clients:
	gcc hello_clients.c -o helloclients
clean:
	rm -rf ./helloclients
	rm -rf ./helloserver
run_server:
	./helloserver 9190 &
run_clients:
	./helloclients 127.0.0.1 9190 &
