#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define PIPE_NUMBERS "pipe_numbers"
#define PIPE_STRINGS "pipe_strings"

void request_number(size_t buffer_size) {
    int fd;
    char *buffer = malloc(buffer_size);
    if (!buffer) {
        perror("Erro ao alocar memória");
        return;
    }

    fd = open(PIPE_NUMBERS, O_RDONLY);
    if (fd < 0) {
        perror("Erro ao abrir pipe de números");
        free(buffer);
        return;
    }

    read(fd, buffer, buffer_size);
    printf("Resposta do servidor: %s\n", buffer);
    close(fd);
    free(buffer);
}

void request_string(size_t buffer_size) {
    int fd;
    char *buffer = malloc(buffer_size);
    if (!buffer) {
        perror("Erro ao alocar memória");
        return;
    }

    fd = open(PIPE_STRINGS, O_RDONLY);
    if (fd < 0) {
        perror("Erro ao abrir pipe de strings");
        free(buffer);
        return;
    }

    read(fd, buffer, buffer_size);
    printf("Resposta do servidor: %s\n", buffer);
    close(fd);
    free(buffer);
}

int main() {
    int op;
    size_t buffer_size;

    printf("Escolha uma opção:\n");
    printf("1. Solicitar número\n");
    printf("2. Solicitar string\n");
    scanf("%d", &op);

    printf("Digite o tamanho do buffer de alocação:\n");
    scanf("%zu", &buffer_size);

    switch(op) {
        case 1:
            request_number(buffer_size);
            break;
        case 2:
            request_string(buffer_size);
            break;
        default:
            printf("Opção inválida!\n");
            break;
    }

    return 0;
}
