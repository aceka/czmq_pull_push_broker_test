#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <czmq.h>
#include <unistd.h>
#include <time.h>


void main(){

    fprintf(stdout,"##### C Broker Test Result #####\n");

    void *context = zmq_ctx_new ();
    // Socket to talk to clients
    void *responder = zmq_socket (context, ZMQ_PULL);
    zmq_connect (responder, "tcp://127.0.0.1:5560");

    time_t first_req;
    time_t last_req;

    int req_number = 1;
    int total_req = 4000000;
    char *string;

    while (1) {
        // Wait for next request from client


            string = zstr_recv (responder);



            if(req_number == 1){

                first_req = clock();
                fprintf(stdout,"first req time  = %d \n", first_req);

            }

            if(req_number == total_req){

                last_req = clock();
                fprintf(stdout,"last req time  = %d \n", last_req);

                float diff = (((float)last_req - (float)first_req));

                fprintf(stdout,"----> difference first and last req = %f \n", diff);
                fprintf(stdout,"----> total req = %d \n", total_req);

                fprintf(stdout,"----> time of sending 1 data = %f \n", diff/total_req);



            }


           // fprintf(stdout,"-- = %d \n", req_number);

            req_number = req_number + 1;
            free (string);
           // sleep(2);




/*

        zstr_send (responder, "i am server");

*/

        // Do some ’work’
    }
    // We never get here, but clean up anyhow
    zmq_close (responder);
    zmq_ctx_destroy (context);

}

