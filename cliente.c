// Cliente

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

struct sockaddr_in cliente;
int tamanho = sizeof(cliente);


int main (int argc, char *argv[]){
		
	char HOST_SERVIDOR[16];
	strcpy(HOST_SERVIDOR, argv[1]) //host_do_servidor
	int PORTA = atoi(argv[2]); // porta da conexão
	int LENGTH = atoi(argv[4]); // tamanho do buffer 
	char NOME_ARQUIVO[LENGTH];
	strcpy(NOME_ARQUIVO, argv[3]);

	char buffer [LENGTH];
	void *aux = malloc(LENGTH*sizeof(char));
	int socket_des; // descritor do socket
	int bytes_recebidos = 0;
	socket_des = socket (AF_INET, SOCK_STREAM, 0);
	if (socket_des == -1){	
		perror("socket ");
		exit(1);
	}else
		printf("Socket criado com sucesso\n");
	
	cliente.sin_family = AF_INET; // Endereço por IP + Porta
	cliente.sin_port = htons(PORTA); // Porta para conexão
	cliente.sin_addr.s_addr = inet_addr(HOST_SERVIDOR);
	memset(cliente.sin_zero, 0x0, 8); // Zera
	
	if (connect(socket_des, (struct sockaddr*)&cliente, tamanho) == -1){
		perror("connect");
		exit(1);
	} 
	
	strcpy(buffer,NOME_ARQUIVO);
	int slen;

 	send(socket_des, buffer, strlen(buffer), 0);
 	FILE *fp = fopen((const char*) buffer, "w+");

 	memset(buffer, 0x0, LENGTH);			
 	while((slen = recv(socket_des, buffer, LENGTH, 0)) < 0)
 		bytes_recebidos++;

// 	memset(buffer, 0x0, LENGTH);
// 	while(fread(aux, LENGTH, 1, fp) > 0){ 
// 		send(socket_des, aux, LENGTH, 0);
// 		printf("3");
// 	};

	printf("Conexão encerrada\n");
	fclose(fp);
	close(socket_des);

	return 0;
}