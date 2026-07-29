#include <stdio.h>
#include <stdlib.h> /* qsort */

typedef struct {
    int inicio;
    int fim;
} Agendamento;

/* função comparar para o qsort */
int comparar(const void *a, const void *b) {
    Agendamento *p1 = (Agendamento *)a;
    Agendamento *p2 = (Agendamento *)b;
    return p1->inicio - p2->inicio;
}

int main() {
    int i, s, dia = 1;
    char buffer[300];
    
    while (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        if (sscanf(buffer, "%d", &s) != 1) continue;
        
        Agendamento lista[105];

        /* 1. agendamento placeholder do início do dia (10h vira 600min) */
        lista[0].inicio = 600;
        lista[0].fim = 600;
        
        for (i = 1; i <= s; i++) {
            if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
                int h1, m1, h2, m2;
                /* pega o formato hh:mm hh:mm e ignora a descrição */
                sscanf(buffer, "%d:%d %d:%d", &h1, &m1, &h2, &m2);
                
                lista[i].inicio = h1 * 60 + m1;
                lista[i].fim = h2 * 60 + m2;
            }
        }

        /* 2. agendamento placeholder do fim do dia (18h vira 1080 min) */
        lista[s + 1].inicio = 1080;
        lista[s + 1].fim = 1080;

        /* 3. Ordena todos os (s + 2 (0 e s+1)) agendamentos pelo horário de início */
        qsort(lista, s + 2, sizeof(Agendamento), comparar);

        /* 4. busca pela maior soneca */
        int maior_duracao = -1;
        int inicio_soneca = 0;

        for (i = 0; i <= s; i++) {
            int duracao = lista[i + 1].inicio - lista[i].fim;
            if (duracao > maior_duracao) {
                maior_duracao = duracao;
                inicio_soneca = lista[i].fim;
            }
        }

        /* 5. formata a saída */
        int horas = maior_duracao / 60;
        int minutos = maior_duracao % 60;

        if (horas > 0) {
            printf("Day #%d: the longest nap starts at %02d:%02d and will last for %d hours and %d minutes.\n",
                   dia++, inicio_soneca / 60, inicio_soneca % 60, horas, minutos);
        } else {
            printf("Day #%d: the longest nap starts at %02d:%02d and will last for %d minutes.\n",
                   dia++, inicio_soneca / 60, inicio_soneca % 60, minutos);
        }
    }
    
    return 0;
}
