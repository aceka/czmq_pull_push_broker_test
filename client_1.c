#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <czmq.h>
#include <unistd.h>

void main(){

    fprintf(stdout,"ben client");

    //  Connect application sockets to proxy
    /*
    zsock_t *faucet = zsock_new_push ("tcp://127.0.0.1:5570");
    assert (faucet);
    assert (zsock_resolve (faucet) != faucet);
    assert (streq (zsock_type_str (faucet), "PUSH"));
    */

    zsock_t *send = zsock_new_push(">tcp://127.0.0.1:5570");
    assert(send != NULL);
    int i = 0;
    while (1) {
        char buff[32];
        i++;
        sprintf(buff, "%d", i);
        int res = zstr_send(send, buff);
        if (res < 0)
            break;
        res = sleep(2);
        if (res > 0)
            break;
    }
    zsock_destroy(&send);

}
