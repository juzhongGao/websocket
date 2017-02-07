#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include "websock.h"
#include <event2/event.h>
#include "conv.h"

// call backs
int 
onmessage(libwebsock_client_state *state, libwebsock_message *msg)
{
	fprintf(stderr, "Received message from client: %d\n", state->sockfd);
	fprintf(stderr, "Message opcode: %d\n", msg->opcode);
	fprintf(stderr, "Payload Length: %llu\n", msg->payload_len);
	fprintf(stderr, "Payload: %s\n", msg->payload);
	//now let's send it back.
	//libwebsock_send_text(state, msg->payload);

	char *gbk = "·þÎñ¶Ë»Ø¸´";
	int len = strlen(gbk);
	char *utf8 = calloc(len * 3, sizeof(char));

	int ret = dl_icuuc_gbk2utf8(utf8, len * 3, gbk, strlen(gbk));
	printf("ret: %d \n", ret);

	libwebsock_send_text(state, utf8);

	free(utf8);
	return 0;
}

int
onopen(libwebsock_client_state *state)
{
	fprintf(stderr, "onopen: %d\n", state->sockfd);
	return 0;
}

int
onclose(libwebsock_client_state *state)
{
	fprintf(stderr, "onclose: %d\n", state->sockfd);
	return 0;
}

int main(int argc, char *argv[])
{
	libwebsock_context *ctx = NULL;

  	ctx = libwebsock_init();
	printf("ctx: %p \n", ctx);
	if(ctx == NULL)
	{
		printf("libwebsock_init Failed. \n");
		return 0;
	}

	dl_icuuc_init();

	char *port = "7077";

	libwebsock_bind(ctx, "127.0.0.1", port);

	ctx->onmessage = onmessage;
 	ctx->onopen = onopen;
	ctx->onclose = onclose;

	printf("libwebsock_wait start \n");
	libwebsock_wait(ctx);
	printf("libwebsock_wait end \n");

	return 1;
}