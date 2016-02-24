#include <zmq.h>
#include <czmq.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// gcc -g device.c -lczmq -lzmq -o device


void main(){






void *context = zmq_ctx_new ();
void *frontend = zmq_socket (context, ZMQ_ROUTER);
void *backend = zmq_socket (context, ZMQ_DEALER);
zmq_bind (frontend, "tcp://127.0.0.1:5570");
zmq_bind (backend, "tcp://127.0.0.1:5571");
// Initialize poll set


// We never get here, but clean up anyhow

/*
zmq_close (frontend);
zmq_close (backend);
zmq_ctx_destroy (context);
*/


/*

    zctx_t *ctx = zctx_new ();

    void *backend = zsocket_new (ctx, ZMQ_PUSH);

    zsocket_bind (backend, "tcp://127.0.0.1:5571");

    void *frontend = zsocket_new (ctx, ZMQ_PULL);
    zsocket_bind (frontend, "tcp://127.0.0.1:5570");




    /* Create ZMQ_STREAM socket

    void *frontend = zmq_socket (ctx, ZMQ_PULL);

    void *backend = zmq_socket (ctx, ZMQ_PULL);

    assert (zmq_bind (frontend, "tcp://*:5570") == 0);
    assert (zmq_bind (backend, "tcp://*:5571") == 0);



    fprintf(stdout,"ben device");


    zmq_device (ZMQ_STREAM, frontend, backend);

/*

    //  Create and configure our proxy
    zactor_t *proxy = zactor_new (zproxy, NULL);

    zstr_sendx (proxy, "FRONTEND", "PULL", "tcp://127.0.0.1:5590", NULL);
    zsock_wait (proxy);
    zstr_sendx (proxy, "BACKEND", "PUSH", "tcp://127.0.0.1:5591", NULL);
    zsock_wait (proxy);

*/

}
