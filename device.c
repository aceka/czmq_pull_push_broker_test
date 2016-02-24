#include <zmq.h>
#include <czmq.h>

// gcc -g device.c -lczmq -lzmq -o device

void main(){

    fprintf(stdout,"#####  Device is running - C Broker Test  #####\n");

    void *context = zmq_ctx_new ();
    void *frontend = zmq_socket (context, ZMQ_PULL);
    void *backend = zmq_socket (context, ZMQ_PUSH);

    zmq_bind (frontend, "tcp://127.0.0.1:5559");
    zmq_bind (backend, "tcp://127.0.0.1:5560");
    // Initialize poll set

    zmq_device (ZMQ_STREAM, frontend, backend);

    // We never get here, but clean up anyhow
    zmq_close (frontend);
    zmq_close (backend);
    zmq_ctx_destroy (context);

}
