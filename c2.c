#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <czmq.h>
#include <unistd.h>

void main(){

    fprintf(stdout,"ben client c1");
    void *context = zmq_ctx_new ();
    // Socket to talk to server
    void *requester = zmq_socket (context, ZMQ_PUSH);
    zmq_connect (requester, "tcp://127.0.0.1:5559");

    char *str_message="[1325 bytes][2015-12-01 11:26:27] 91.244.227.88 => 192.168.11.106 request NOTIFY (12) sip:1096@78.187.84.217:65196 SIP/2.0 	CSeq: 1444939351 NOTIFY (12)  Call-ID: uWXD7Gk8iJ (4918c914) request NOTIFY (12) sip:1096@78.187.84.217:65196 SIP/2.0 CSeq: 1444939351 NOTIFY (12) Call-ID: uWXD7Gk8iJ (4918c914) From: 1030@eurotel.roipbx.com ;tag=fmQBdPAuXbzE To: 1096@eurotel.roipbx.com ;tag=wMhG-wmyB Contact: <sip:1030@91.244.227.88:5060> Via: SIP/2.0/UDP 91.244.227.88 ;rport ;branch=z9hG4bKHB2vjpeX5BXeB	content length 437 SDP: ";

    int request_nbr;

    for (request_nbr = 1; request_nbr <= 1000000; request_nbr++) {

        zstr_send (requester, str_message);
/*
        char *string = zstr_recv (requester);
        printf ("server mesaji : %d [%s]\n", request_nbr, string);
        free (string);
*/
    }
    zmq_close (requester);
    zmq_ctx_destroy (context);


}
