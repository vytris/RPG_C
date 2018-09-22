#ifndef DEFAULT_H
#define DEFAULT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <unistd.h>
#include <poll.h>
#include <termios.h>
#include <time.h>
#include <assert.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 512
#define PORT 9003
#define NAME_SIZE 40

typedef struct{
	int champ;
	int vida;
	int atk;
	int def;
	int vidaUP;
	int atkUP;
	int defUP;
}classe;

struct mov_msg{
	char msg;
};

typedef struct 
{
	int vida;
	int atk;
	int def;
	char id;
	
}mob;

struct upd_msg{//Mensagem de atualização do jogo
	int tipo, vida;
    int x, y;
	char novo;
	char inimigo;
};

/*
    tipo
    = 0 atualiza o mapa, (x,y) é a  posição, e new é o novo char
    = 1 mesagem para avisar que vai entrar em batalha/atualiza status do oponente vida é a vida do oponente, x é o ataque, y é a defesa
    = 2 atualiza a meus status, vida é a minha nova vida, x é meu novo ataque, y é minha nova defesa
    = 3 mensagem para avisar que saiu de batalha
    = 4 mensagem para avisar que morreu
    = 5 mensagem para avisar que venceu
*/

struct clientInfo{
    int mapa;
    char nome[NAME_SIZE];
	classe Hero;
};

typedef struct clientInfo clientInfo;
typedef struct mov_msg mov_msg;
typedef struct upd_msg upd_msg;
#endif
