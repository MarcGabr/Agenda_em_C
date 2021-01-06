#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct
{
    char id[16];
    char name[128];
} Tcont;

Tcont *loadFromFile(Tcont *agenda, char *arquivo, int *c){
    int j;
    char vetor[100][100];
    int valor;
    arquivo = fopen("agenda.txt", "a");
    if(arquivo == NULL){
             printf("Nao foi possivel abrir um arquivo");
    }else{
    /*
    fseek (arquivo , 0 , SEEK_END);
  j = ftell (arquivo);
  rewind (pFile);
  printf("%d", j);*/
    //fscanf(arquivo," %s %d" ,&vetor, &valor);
        //printf("%s %d", vetor , valor);
    Save(agenda,arquivo ,&*c);
    }//inicializar(agenda, &*c);
}
int Save(Tcont *agenda, char *arquivo, int *c){
    int i;
    arquivo = fopen("agenda.txt", "a");
  if(arquivo == NULL){
        printf("Nao foi possivel criar um arquivo");
  }
  for(i=0; i<*c; i++){
    //printf("%s\n", agenda[i].name);
    fprintf(arquivo, " \n"); fprintf(arquivo, agenda[i].name);fprintf(arquivo, "  ");fprintf(arquivo, agenda[i].id);
  }
  arquivo = fopen("agenda.dat", "ab");
  if(arquivo == NULL){
        printf("Nao foi possivel criar um arquivo");
  }
  for(i=0; i<*c; i++){
    //printf("%s\n", agenda[i].name);
    fprintf(arquivo, " \n"); fprintf(arquivo, agenda[i].name);fprintf(arquivo, "  ");fprintf(arquivo, agenda[i].id);
  }
  printf("Arquivo Salvo\n");
  system("PAUSE");
  system("cls");
  inicializar(agenda, &*c);
}

int insert(Tcont *agenda, char *arquivo, int *c)
{
int i,j;
    ++*c;
    printf("%d", *c);
    agenda = (Tcont*)realloc(agenda,(*c) * sizeof(Tcont));
    //agenda =(Tcont*)calloc((*c), sizeof(Tcont));
    if (agenda == NULL)
    {
        printf ("ERRO: memoria nao alocada com realloc\n");
        return 1;
    }

    printf("Digite o nome do cidadao\n");
    scanf(" %[^\n]s", &agenda[(*c-1)].name);
    printf("Digite o telefone\n");
    scanf(" %[^\n]s", &agenda[(*c-1)].id);
    char mudo[100];
    char a;
    int mudo1=0;
   for (i = 0; i < *c; i++) {
   for (j = 0; j < *c; j++) {
      if (strcmp(agenda[j].name, agenda[i].name) > 0) {
         strcpy(mudo, agenda[j].name);
         mudo1 = *(agenda[j]).id;
         strcpy(agenda[j].name, agenda[i].name);
         *(agenda[j]).id = *(agenda[i]).id;
         strcpy(agenda[i].name, mudo);
         *(agenda[i]).id = mudo1;
      }
   }
}
    Save(agenda,arquivo ,&*c);
}

int search(Tcont *agenda, int *c)
{
    char a[32];
    int i;
    printf("Qual o nome que deseja anotar\n");
    scanf("%s", &a);

    for(i=0; i<c; i++){
        if(strcasecmp(a,agenda[i].name)==0){
            printf("\nNome do individuo: %s seu telefone eh %s\n", agenda[i].name, agenda[i].id);
            break;
        }else{
            printf("Nao foi possivel encontrar");
            inicializar(agenda, &*c);
            break;
        }
    }
    system("PAUSE");
    system("cls");
    inicializar(agenda, &*c);
}
void mostra(Tcont *agenda, int *c)
{   int i;
    for(i=0; i<*c; i++)
        {
            printf("nome %s\n",agenda[i].name);
            printf("telefone %s\n",agenda[i].id);
        }
    system("PAUSE");
    system("cls");
inicializar(agenda, &*c);
}

void inicializar(Tcont *agenda, int *c){
    int op;
    char *arquivo;
    //printf("\n%d\n", *c);
    printf("\nInicializando\n");
    printf("O que deseja fazer?\n");
    printf("1 - Adicionar Contato\n");
    printf("2 - Pesquisar\n");
    printf("3 - Imprimir Lista\n");
    printf("4 - Abrir ja existente\n");
    scanf("%d", &op);
    system("cls");
    switch(op)
    {
    case 1:
        insert(agenda,*arquivo, &*c);
        break;
    case 2:
        search(agenda, &*c);
        break;
    case 3:
        mostra(agenda, &*c);
        break;
    case 4:
        //loadFramFile(agenda, *arquivo, &*c);
       //loadFramFile(Tcont *agenda, char *arquivo, int *c)

    default:
        printf("Opcao Invalida");
    }
}
int main()
{
    FILE* fd = fopen("Filename.txt", "a+");
    int c;
    Tcont *agenda;
    agenda =(Tcont*)malloc(sizeof(Tcont));
    //c =(int*)malloc(sizeof(int));
    c = 0;

    inicializar(agenda, &c);

    return (0);
}
