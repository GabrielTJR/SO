#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

#define NUM_THREADS 4
#define PIPE_NUMBERS "pipe_numbers"
#define PIPE_STRINGS "pipe_strings"
#define BUFFER_SIZE 256

// Função que escreve números no pipe PIPE_NUMBERS
void* handle_numbers(void* arg) {
    int fd;
    char buffer[BUFFER_SIZE];
    int number = 42;

    while (1) {
        fd = open(PIPE_NUMBERS, O_WRONLY);
        if (fd < 0) {
            perror("Erro ao abrir pipe de números");
            sleep(1);
            continue;
        }
        sprintf(buffer, "Número: %d", number);
        write(fd, buffer, strlen(buffer) + 1);
        close(fd);
        sleep(2);
    }
    return NULL;
}

// Função que escreve uma string no pipe PIPE_STRINGS
void* handle_strings(void* arg) {
    int fd;
    char buffer[BUFFER_SIZE];
    char* response = "Olá, usuário!";

    while (1) {
        fd = open(PIPE_STRINGS, O_WRONLY);
        if (fd < 0) {
            perror("Erro ao abrir pipe de strings");
            sleep(1);
            continue;
        }
        sprintf(buffer, "Mensagem: %s", response);
        write(fd, buffer, strlen(buffer) + 1);
        close(fd);
        sleep(2);
    }
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];

    if (mkfifo(PIPE_NUMBERS, 0666) == -1) {
        perror("Erro ao criar pipe de números");
        exit(1);
    }
    if (mkfifo(PIPE_STRINGS, 0666) == -1) {
        perror("Erro ao criar pipe de strings");
        exit(1);
    }

    pthread_create(&threads[0], NULL, handle_numbers, NULL);
    pthread_create(&threads[1], NULL, handle_numbers, NULL);
    pthread_create(&threads[2], NULL, handle_strings, NULL);
    pthread_create(&threads[3], NULL, handle_strings, NULL);

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
