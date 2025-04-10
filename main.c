#include "header/Projeto.h" // o nome correto para o arquivo de cabeçalho é "header/projeto.h"
#include <stdio.h> // o correto para bibliotecas padrão é ultilizar <>
#include <stdlib.h> // o uso de <stdlib.h> é necessário para o uso de system()

int main(){
    ListaDeTarefas lt;

    char arquivo[] = "tarefas";
    int codigo, opcao;

    codigo=carregarTarefas(&lt, arquivo); //A função esperava um ponteiro e estava recebendo a variavel lt diretamente

    if (codigo !=0){
        printf("Lista de tarefas nao carregada");
        lt.qtd = 0; // Alterado o valor de listas de 2 para 0
    }

    do{
        exibeMenu();
        scanf("%d", &opcao);

        if(opcao == 0){

        }
        else if(opcao == 1){        
            codigo=criarTarefa(&lt);
            if (codigo == 1)
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
        if (codigo == 1) // Aqui estava 2, mas o código de erro na função seria return 1
            printf("Erro ao listar tarefas: nao existem tarefas para serem listadas");
        }
        else if(opcao == 4){
            codigo = alterarTarefa(&lt);
        if (codigo == 1)
            printf("Erro ao alterar tarefa: Nao existem tarefas para alterar\n");
        else if (codigo == 2)
            printf("Erro ao alterar tarefa: Posicao invalida\n");
            }
        else {
            printf("opcao invalida\n");
    }
    } while (opcao != 0);

    codigo=salvarTarefas(&lt,arquivo);
    if (codigo != 0) // Em SalvarTarefas, 0 significa sucesso e 1 significa erro(Estava retornando Erro mesmo quando o arquivo era salvo)
        printf("Erro ao salvar tarefas em arquivo");

    //system ("pause");
    return 0; // A função main estava sem retorno
}
