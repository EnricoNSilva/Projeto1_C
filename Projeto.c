#include "Projeto.h" // o nome correto para o arquivo de cabeçalho é "Projeto.h"
#include <stdio.h> // o correto para bibliotecas padrão é ultilizar <>
#include <string.h> // o correto para bibliotecas padrão é ultilizar <>

int criarTarefa(ListaDeTarefas *lt){
    if(lt->qtd >= TOTAL_TAREFAS)
    return 1;
    
	Tarefa *t=&lt->tarefas[lt->qtd];

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
   	lt->tarefas[pos].prioridade=lt->tarefas[pos+1].prioridade; 
	   strcpy(lt->tarefas[pos].descricao, lt->tarefas[pos+1].descricao);  // estava copiando descrição para categoria
	   strcpy(lt->tarefas[pos].categoria, lt->tarefas[pos+1].categoria);

   }
   
    lt->qtd--;
	return 0;
}
int listarTarefas(ListaDeTarefas *lt){
	if(lt->qtd == 0)
	return 1;
	

int i;
for(i=0; i< lt->qtd; i++){
	printf("Pos: %d \t Prioridade: %d \t Categoria: %s\n", i, 
	lt->tarefas[i].prioridade, lt->tarefas[i].categoria);
	printf("Descricao: %s\n", lt->tarefas[i].descricao);
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

