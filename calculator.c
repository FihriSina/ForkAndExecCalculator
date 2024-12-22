#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER_SIZE 256

int main() {
    int pipefd[2];
    pid_t pid;
    char operation;
    int num1, num2;
    char result[BUFFER_SIZE];

    while (1) {
        // Her döngüde yeni bir pipe oluştur
        if (pipe(pipefd) == -1) {
            perror("Pipe oluşturulamadı");
            exit(EXIT_FAILURE);
        }

        printf("\nCalculator\n");
        printf("1- Addition\n");
        printf("2- Subtraction\n");
        printf("3- Multiplication\n");
        printf("4- Division\n");
        printf("5- Exit\n");
        printf("Seçiminizi yapın: ");
        scanf(" %c", &operation);

        if (operation == '5') {
            printf("Çıkış yapılıyor...\n");
            break;
        }

        printf("İki sayı girin (num1 num2): ");
        scanf("%d %d", &num1, &num2);

        pid = fork();
        if (pid < 0) {
            perror("Fork hatası");
            exit(EXIT_FAILURE);
        }

        if (pid == 0) {
            // Çocuk sürecin çalışacağı kod
            close(pipefd[0]); // Okuma kapatılır
            dup2(pipefd[1], STDOUT_FILENO); // Yazma yönlendirilir

            char *args[4];
            if (operation == '1') {
                args[0] = "./addition";
            } else if (operation == '2') {
                args[0] = "./subtraction";
            } else if (operation == '3') {
                args[0] = "./multiplication";
            } else if (operation == '4') {
                args[0] = "./division";
            } else {
                printf("Geçersiz seçim.\n");
                exit(EXIT_FAILURE);
            }

            args[1] = malloc(20);
            args[2] = malloc(20);
            sprintf(args[1], "%d", num1);
            sprintf(args[2], "%d", num2);
            args[3] = NULL;

            execvp(args[0], args);
            perror("Exec hatası");
            exit(EXIT_FAILURE);
        } else {
            // Ebeveyn sürecin çalışacağı kod
            close(pipefd[1]); // Yazma kapatılır
            wait(NULL);

            // result'ı sıfırla ve pipe'dan oku
            memset(result, 0, BUFFER_SIZE);
            int bytes_read = read(pipefd[0], result, BUFFER_SIZE - 1);
            if (bytes_read > 0) {
                result[bytes_read] = '\0'; // Null-terminate the string
            }

            // Sonucu ekrana yaz
            printf("Sonuç: %s\n", result);

            // saver programını çağır
            pid_t saver_pid = fork();
            if (saver_pid == 0) {
                char *saver_args[] = {"./saver", result, NULL};
                execvp(saver_args[0], saver_args);
                perror("Saver exec hatası");
                exit(EXIT_FAILURE);
            } else {
                wait(NULL);
            }

            close(pipefd[0]); // Pipe'ı temizle
        }
    }

    return 0;
}
