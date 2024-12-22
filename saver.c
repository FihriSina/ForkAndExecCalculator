#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s result\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Dosya yolu masaüstündeki Proje klasörüne ayarlandı
    FILE *file = fopen("/home/sina/Masaüstü/Proje/results.txt", "a");
    if (file == NULL) {
        perror("Dosya oluşturulamadı");
        return EXIT_FAILURE;
    }

    fprintf(file, "Result: %s\n", argv[1]);
    fclose(file);

    return EXIT_SUCCESS;
}
