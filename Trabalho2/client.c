#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define PIPE_NUMBERS "pipe_numbers"
#define PIPE_STRINGS "pipe_strings"
#define BUFFER_SIZE 256

void request_number() {
    int fd;
    char buffer[BUFFER_SIZE];

    // Tenta abrir o pipe para leitura
    fd = open(PIPE_NUMBERS, O_RDONLY);
    if (fd < 0) {
        perror("Erro ao abrir pipe de números");
        return;
    }

    // Lê o conteúdo do pipe
    ssize_t bytesRead = read(fd, buffer, BUFFER_SIZE);
    if (bytesRead > 0) {
        buffer[bytesRead] = '\0';
        printf("Resposta do servidor: %s\n", buffer);
    } else {
        printf("Nenhuma resposta recebida do servidor.\n");
    }

    close(fd);
}

void request_string() {
    int fd;
    char buffer[BUFFER_SIZE];

    // Tenta abrir o pipe para leitura
    fd = open(PIPE_STRINGS, O_RDONLY);
    if (fd < 0) {
        perror("Erro ao abrir pipe de strings");
        return;
    }

    // Lê o conteúdo do pipe
    ssize_t bytesRead = read(fd, buffer, BUFFER_SIZE);
    if (bytesRead > 0) {
        buffer[bytesRead] = '\0';
        printf("Resposta do servidor: %s\n", buffer);
    } else {
        printf("Nenhuma resposta recebida do servidor.\n");
    }

    close(fd);
}

int main() {
    int op;

    while (1) {
        printf("Escolha uma opção:\n");
        printf("1. Solicitar número\n");
        printf("2. Solicitar string\n");
        printf("3. Sair\n");
        scanf("%d", &op);

        switch(op) {
            case 1:
                request_number();
                break;
            case 2:
                request_string();
                break;
            case 3:
                printf("Saindo...\n");
                return 0;
            default:
                printf("Opção inválida!\n");
                break;
        }
    }

    return 0;
}
