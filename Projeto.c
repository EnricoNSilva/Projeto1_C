#include "header/Projeto.h" // o nome correto para o arquivo de cabeçalho é "header/Projeto.h"
#include <stdio.h> // o correto para bibliotecas padrão é ultilizar <>
#include <string.h> // o correto para bibliotecas padrão é ultilizar <>
#include <time.h> // inclui biblioteca para obter tempo

int criarTarefa(ListaDeTarefas *lt){
    char escolha;
    if(lt->qtd >= TOTAL_TAREFAS)
    return 1;   
    
	Tarefa *t=&lt->tarefas[lt->qtd];

    time_t tempo;
      tempo = time(NULL);
      struct tm tm = *localtime(&tempo);
      int ano = tm.tm_year + 1900;
      int mes = tm.tm_mon + 1;
      int dia = tm.tm_mday;

        printf("Deseja aplicar um prazo para a tarefa? [s]sim [n]nao: ");
        scanf("%s",&escolha);
        if(escolha=='s'){
          printf("Entre com o dia do prazo: ");
          scanf(" %d", &t->dia);
          printf("Entre com o mes do prazo: ");
          scanf(" %d", &t->mes);
          printf("Entre com o ano do prazo: ");
          scanf(" %d", &t->ano);
          if(ano>t->ano){
            printf("Data invalida tente novamente\n");
            return 9999;
          }
          else if(ano <= t->ano && mes > t->mes){
            printf("Data invalida tente novamente\n");
            return 9999;
          }
        }

    printf("Entre com a prioridade da tarefa: ");
    scanf("%d", &t->prioridade);

    printf("Entre com a categoria da tarefa: ");
    scanf("%s", t->categoria);

    printf("Entre com a descricao da tarefa: ");
    scanf("%s", t->descricao);
    
    lt->qtd++;

    return 0;
}


int deletarTarefa(ListaDeTarefas *lt){
   if (lt->qtd == 0)
   return 1;
   
   int pos;
   printf("Entre com a posicao que deseja deletar: ");
   scanf("%d", &pos);
   
   if (pos <0 || pos > lt->qtd - 1) // O if estava verificando se < lt->qtd -1, porém deveria ser >, pois a posição não pode ser negativa
   return 2;
   
   for (; pos<lt->qtd-1; pos++){
   	lt->tarefas[pos].prioridade = lt->tarefas[pos + 1].prioridade; 
	   strcpy(lt->tarefas[pos].descricao, lt->tarefas[pos+1].descricao);  // estava copiando descrição para categoria
	   strcpy(lt->tarefas[pos].categoria, lt->tarefas[pos+1].categoria);

       for (; pos < lt->qtd - 1; pos++) {
        lt->tarefas[pos].prioridade = lt->tarefas[pos + 1].prioridade; 
        strcpy(lt->tarefas[pos].categoria, lt->tarefas[pos + 1].categoria);
        strcpy(lt->tarefas[pos].descricao, lt->tarefas[pos + 1].descricao);
    }
    
   }
   
    lt->qtd--;
	return 0;
}
int listarTarefas(ListaDeTarefas *lt){
	if(lt->qtd == 0)
	return 1;
    char condicao;
    char listagem;
    int i, anoLista, prioridadeLista;
    printf("Deseja filtrar suas listas de tarefas? [s]sim [n]nao: \n");
    scanf("%s",&condicao);

    getchar();
    if(condicao=='s'){
      printf("Digite por qual opção deseja listar tarefas\n");
      printf("[d]data\n");
      printf("[p]Prioridade\n");
      scanf("%c", &listagem);

      switch(listagem){
        case 'd':
          printf("digite um ano válido: \n");
          scanf("%d", &anoLista);
          for(i=0; i< lt->qtd; i++){
            if(anoLista == lt->tarefas[i].ano){
              printf("Pos: %d \t Prioridade: %d \t Categoria: %s \t Prazo:         %d/%d/%d\n", i, 
              lt->tarefas[i].prioridade, lt->tarefas[i].categoria, lt->tarefas[i].dia, lt->tarefas[i].mes, lt->tarefas[i].ano);
              printf("Descricao: %s\n", lt->tarefas[i].descricao);
            }
          }
          break;
        case 'p':
          printf("digite uma prioridade válida: \n");
          scanf("%d", &prioridadeLista);
          for(i=0; i< lt->qtd; i++){
            if(prioridadeLista == lt->tarefas[i].prioridade){
              printf("Pos: %d \t Prioridade: %d \t Categoria: %s \t Prazo:         %d/%d/%d\n", i, 
              lt->tarefas[i].prioridade, lt->tarefas[i].categoria, lt->tarefas[i].dia, lt->tarefas[i].mes, lt->tarefas[i].ano);
              printf("Descricao: %s\n", lt->tarefas[i].descricao);
            }
          else{
            printf("Não há tarefas com essa prioridade\n");
            return 0;
          }
          }
          break;
      }
    }
      else{
        for(i=0; i< lt->qtd; i++){
          printf("Pos: %d \t Prioridade: %d \t Categoria: %s \t Prazo: %d/%d/%d\n", i, 
          lt->tarefas[i].prioridade, lt->tarefas[i].categoria, lt->tarefas[i].dia, lt->tarefas[i].mes, lt->tarefas[i].ano);
          printf("Descricao: %s\n", lt->tarefas[i].descricao);
        }
        return 0;
      }
      return 0;
}

int carregarTarefas(ListaDeTarefas *lt, char *nome){ // a chamada do nome deveria ser um ponteiro mas estava chamando a variavel
   FILE *fp=fopen(nome, "rb");
   if (fp == NULL)
   return 1;
   
   fread(lt, sizeof(ListaDeTarefas),1,fp);
   fclose(fp);
   return 0;
}    

int salvarTarefas(ListaDeTarefas *lt, char *nome){
   FILE *fp=fopen(nome, "wb"); // Estava sem ponto e virgula
   if (fp == NULL)
   return 1;
   
   fwrite(lt, sizeof(ListaDeTarefas),1,fp);
   fclose(fp);
   return 0;
}

int alterarTarefa(ListaDeTarefas *lt){
    if (lt->qtd == 0) {
        return 1; // Caso não tenha tarefas, retorna erro
    }

    int pos;
    printf("Posicao da tarefa que deseja alterar: ");
    scanf("%d", &pos);
    getchar();

    if (pos < 0 || pos >= lt->qtd) {
        return 2; // Posição inválida
    }

    Tarefa *t = &lt->tarefas[pos]; // Ponteiro para a tarefa a ser alterada

    printf("Tarefa atual:\n");
    printf("Prioridade: %d\n", t->prioridade);
    printf("Categoria: %s\n", t->categoria);
    printf("Descricao: %s\n", t->descricao);

    int opcao;

    // Alterar Prioridade
    printf("Deseja alterar a prioridade? (1: Sim, 0: Nao): ");
    scanf("%d", &opcao);
    getchar(); 
    if (opcao == 1) {
        printf("Entre com a nova prioridade: ");
        scanf("%d", &t->prioridade);
        getchar(); 
    }

    // Alterar Categoria
    printf("Deseja alterar a categoria? (1: Sim, 0: Nao): ");
    scanf("%d", &opcao);
    getchar();
    if (opcao == 1) {
        printf("Entre com a nova categoria: ");
        fgets(t->categoria, sizeof(t->categoria), stdin);
        t->categoria[strcspn(t->categoria, "\n")] = '\0';
    }

    // Alterar Descrição
    printf("Deseja alterar a descricao? (1: Sim, 0: Nao): ");
    scanf("%d", &opcao);
    getchar(); 
    if (opcao == 1) {
        printf("Entre com a nova descricao: ");
        fgets(t->descricao, sizeof(t->descricao), stdin);
        t->descricao[strcspn(t->descricao, "\n")] = '\0';
    }

    return 0;
}

void exibeMenu(){
    printf("menu\n");
    printf("1. Criar tarefa\n");
    printf("2. Deletar tarefa\n");
  	printf("3. Listar tarefa\n");
    printf("4. Alterar tarefa\n");
  	printf("0. Sair\n");
	}

