.PHONY: all clean server clients run_server run_clients

all: server clients

server:
	gcc echo_server.c -o echoserver
clients:
	gcc echo_clients.c -o echoclients
clean:
	rm -rf ./echoclients
	rm -rf ./echoserver
run_server:
	./echoserver 9190 &
run_clients:
	./echoclients 127.0.0.1 9190 &
