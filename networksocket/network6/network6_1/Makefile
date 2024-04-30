.PHONY: all clean server clients run_server run_clients

all: server clients

server:
	gcc uecho_server.c -o uechoserver
clients:
	gcc uecho_clients.c -o uechoclients
clean:
	rm -rf ./uechoclients
	rm -rf ./uechoserver
run_server:
	./uechoserver 9190 &
run_clients:
	./uechoclients 127.0.0.1 9190 &
