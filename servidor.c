// Socket do servidor

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

struct sockaddr_in servidor;
struct sockaddr_in cliente;
int tamanho = sizeof(cliente);


int main (int argc, char *argv[]){
		
	int PORTA = atoi(argv[1]); // porta da conexão
	int LENGHT = atoi (argv[2]); // tamanho do buffer 
	//printf("%d\n%d\n",PORTA,LENGHT);
	int retorno;
	char buffer [LENGHT];
	char aux [LENGHT];
	int socket_des; // descritor do socket
	socket_des = socket (AF_INET, SOCK_STREAM, 0);
	if (socket_des == -1){	
		perror("socket ");
		exit(1);
	}else
		printf("Socket criado com sucesso\n");
	
	servidor.sin_family = AF_INET; // Endereço por IP + Porta
	servidor.sin_port = htons(PORTA); // Porta para conexão
	memset(servidor.sin_zero, 0x0, 8); // Zera
	
	if(bind(socket_des,(struct sockaddr*)&servidor, sizeof(servidor)) == -1){
		perror("bind ");
		exit(1);
	} 
	
	listen (socket_des,1); // Aguarda pelo clinte, Apenas 1 conexão
	
	int Client 	= accept(socket_des, (struct sockaddr*)&cliente, &tamanho);
	if (Client == -1){
		perror("accept ");
		exit(1);
	} 
	
	strcpy(buffer,"Conexão estabelecida\n\0");
	int slen;

	send(Client,buffer,strlen(buffer), 0);
	printf("Aguardando resposta\n");
	memset(buffer,0x0,LENGHT);		
	while((slen = recv(Client, buffer, LENGHT, 0))<0);
	printf("Nome do arquivo: %s",buffer);
	printf("1");
	FILE *fp;
	fp = fopen(buffer,"r");
	printf("2");
	while(fread(&buffer,LENGHT,1,fp)>0){ 
		send(Client,buffer,LENGHT, 0);
		printf("3");
	};


	printf("Conexão encerrada\n");
	fclose(fp);
	close(Client);
	close(socket_des);

	return 0;
}
