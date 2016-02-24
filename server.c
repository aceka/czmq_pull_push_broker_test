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
