<<<<<<< HEAD
#include <zmq.h>
#include <czmq.h>
#include <time.h>

// gcc -g server.c -lczmq -lzmq -o server

void main(){

    fprintf(stdout,"#####  Server is running - C Broker Test  #####\n");

    void *context = zmq_ctx_new ();
    void *responder = zmq_socket (context, ZMQ_PULL);
    zmq_connect (responder, "tcp://127.0.0.1:5560");

    time_t first_req;
    time_t last_req;

    int req_number = 1;

    // there are 1000000 request per client
    int total_req = 4000000;
    char *received_str;

    while (1) {

        received_str = zstr_recv (responder);
        if(req_number == 1){
            first_req = clock();
            fprintf(stdout,"\nfirst req time  = %d \n", first_req);
        }

        if(req_number == total_req){
            last_req = clock();
            fprintf(stdout,"\nlast req time  = %d \n\n", last_req);

            float difference_time = (((float)last_req - (float)first_req));

            fprintf(stdout,"----> %f : ( difference first and last req ) \n", difference_time);
            fprintf(stdout,"----> %d : ( total req ) \n", total_req);
            fprintf(stdout,"----> %f : ( time of sending 1 data ) \n", difference_time/total_req);
        }

        req_number = req_number + 1;
        free (received_str);

    }

    zmq_close (responder);
    zmq_ctx_destroy (context);

}

=======
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <czmq.h>
#include <unistd.h>


void main(){

    fprintf(stdout,"ben server");

/*

    zsock_t *sink = zsock_new_pull (">tcp://127.0.0.1:5571");
    assert (sink);
    assert (zsock_resolve (sink) != sink);
    assert (streq (zsock_type_str (sink), "PULL"));
*/

zsock_t *receiver = zsock_new_pull("@tcp://127.0.0.1:5571");
    assert(receiver != NULL);
    while (1) {
        char *msg = zstr_recv(receiver);
        if (msg == NULL)
            break;
        printf("Received: %s\n", msg);
        free(msg);
    }
    zsock_destroy(&receiver);


}
>>>>>>> ab34239b1083aacfba12985eaa6b6fb8152b96fe
