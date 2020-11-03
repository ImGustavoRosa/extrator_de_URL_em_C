//Autor: Gustavo Rosa || Aluno do 2º Semestre no curso de BSI - UNIME (Lauro de Freitas - Bahia)
//Data: 03/11/2020
/*                  Extrator de URL
    (apenas URL's de href iniciandas com http ou https).
*/

#include <stdio.h>
#include <stdlib.h>
int main(){
    FILE *f;
    FILE *e;
    int c, i = 0, /*arq[1000000],*/ cont, ctrl;
    int *arq =(int*) malloc(sizeof(int)*2000000);

    f = fopen ("URL.txt", "r");
    while(1){
        c = fgetc(f);
        if (feof(f)){
            break;
        }

        arq[i] = c;
        i++;
        if (i+1 == 2000000){
            printf("O tamanho do codigo fonte excede o limite. (2000000)\n");
            return 1;
        }
    }
    fclose(f);

    cont = i;

    e = fopen ("extraidas.txt", "a");
    for (i=0;i<cont;i++){
        ctrl = 0;
        if (arq[i] == 'f' && arq[i+1] == '=' && arq[i+2] == '"' && arq[i+3] == 'h'){
            i+=3;
            while (arq[i] != '"'){
                fprintf(e, "%c", arq[i]);
                ctrl++;
                i++;
            }
            fprintf(e, "\n");
        }
        //printf("%c", arq[i]);
    }
    fclose(e);

    printf("URL's extraidas com sucesso!\n");

    return 0;
}
