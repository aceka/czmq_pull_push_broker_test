#include <zmq.h>
#include <czmq.h>

// gcc -g client1.c -lczmq -lzmq -o client1

void main(){

    fprintf(stdout,"#####  Client-1 is running - C Broker Test  #####\n");

    void *context = zmq_ctx_new ();
    void *requester = zmq_socket (context, ZMQ_PUSH);
    zmq_connect (requester, "tcp://127.0.0.1:5559");

    char *str_message="i am client-1";
    int request_number;

    //sending 1000000 requests from client
    for (request_number = 1; request_number <= 1000000; request_number++) {

        zstr_send (requester, str_message);

    }

    zmq_close (requester);
    zmq_ctx_destroy (context);

}
