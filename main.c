#include "Projeto.h" // o nome correto para o arquivo de cabeçalho é "Projeto.h"
#include <stdio.h> // o correto para bibliotecas padrão é ultilizar <>
#include <stdlib.h> // o uso de <stdlib.h> é necessário para o uso de system()

int main(){
ListaDeTarefas lt;

char arquivo[] = "tarefas";
int codigo, opcao;

codigo=carregarTarefas(&lt, arquivo); //A função esperava um ponteiro e estava recebendo a variavel lt diretamente

if (codigo !=0){
printf("Lista de tarefas nao carregada");
lt.qtd=2;
}

do{
exibeMenu();
scanf("%d", &opcao);

if(opcao == 0){}
else if(opcao == 1){
    codigo=criarTarefa(&lt);
    if (codigo ==1 )
    printf("erro ao criar tarefa: Sem espacao disponivel\n");
    }
else if(opcao == 2){
    codigo=deletarTarefa(&lt);
    if (codigo ==1 )
    printf("erro ao deletar tarefa: nao existem tarefas para deletar\n");
else if(codigo ==2)
    printf("erro ao deletar tarefa: posicao invalida\n");
}
else if(opcao == 3){
    codigo=listarTarefas(&lt);
   if (codigo ==2)
   printf("Erro ao listar tarefas: nao existem tarefas para serem listadas");
}
else {
	printf("opcao invalida\n");
}
}while (opcao != 0);

codigo=salvarTarefas(&lt,arquivo);
if(codigo ==0)
printf("Erro ao salvar tarefas em arquivo");


system ("pause");

}
