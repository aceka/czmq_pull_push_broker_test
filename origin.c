#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <czmq.h>


void main(){

    fprintf(stdout,"ben device");


   zactor_t *proxy = zactor_new (zproxy, NULL);
assert (proxy);

zstr_sendx (proxy, "FRONTEND", "PULL", "tcp://127.0.0.1:5580", NULL);
zsock_wait (proxy);
zstr_sendx (proxy, "BACKEND", "PUSH", "tcp://127.0.0.1:5581", NULL);
zsock_wait (proxy);

// Connect application sockets to proxy
zsock_t *faucet = zsock_new_push ("tcp://127.0.0.1:5580");
assert (faucet);
zsock_t *sink = zsock_new_pull ("tcp://127.0.0.1:5581");
assert (sink);

// Send some messages and check they arrived
char *hello, *world;
zstr_sendx (faucet, "Hello", "World", NULL);
zstr_recvx (sink, &hello, &world, NULL);
assert (streq (hello, "Hello"));
assert (streq (world, "World"));
zstr_free (&hello);
zstr_free (&world);

// Test pause/resume functionality
zstr_sendx (proxy, "PAUSE", NULL);
zsock_wait (proxy);
zstr_sendx (faucet, "Hello", "World", NULL);
zsock_set_rcvtimeo (sink, 100);
zstr_recvx (sink, &hello, &world, NULL);
assert (!hello && !world);

zstr_sendx (proxy, "RESUME", NULL);
zsock_wait (proxy);
zstr_recvx (sink, &hello, &world, NULL);
assert (streq (hello, "Hello"));
assert (streq (world, "World"));
zstr_free (&hello);
zstr_free (&world);

// Test capture functionality
zsock_t *capture = zsock_new_pull ("tcp://127.0.0.1:5581");
assert (capture);

// Switch on capturing, check that it works
zstr_sendx (proxy, "CAPTURE", "tcp://127.0.0.1:5581", NULL);
zsock_wait (proxy);
zstr_sendx (faucet, "Hello", "World", NULL);
zstr_recvx (sink, &hello, &world, NULL);
assert (streq (hello, "Hello"));
assert (streq (world, "World"));
zstr_free (&hello);
zstr_free (&world);

zstr_recvx (capture, &hello, &world, NULL);
assert (streq (hello, "Hello"));
assert (streq (world, "World"));
zstr_free (&hello);
zstr_free (&world);

zsock_destroy (&faucet);
zsock_destroy (&sink);
zsock_destroy (&capture); zactor_destroy (&proxy);


}
