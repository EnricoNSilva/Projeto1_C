#define TOTAL_TAREFAS 100 
// numero maximo de tarefas estava em 5, porem em ListaDeTarefa tem tamanho 100

typedef struct {
    int prioridade;
    char descricao[150];
    char categoria[50];
    int dia;
    int mes;
    int ano;
} Tarefa;

typedef struct {
    Tarefa tarefas[100];
    int qtd;
} 

ListaDeTarefas; // o chamado da ListaDeTarefas estava com erro de digitação

int criarTarefa(ListaDeTarefas *lt);
int deletarTarefa(ListaDeTarefas *lt);
int listarTarefas(ListaDeTarefas *lt);

int carregarTarefas(ListaDeTarefas *lt, char *nome); // Carregar tarefas estava recebendo um ponteiro chamado *nomes, o correto seria *nome
int salvarTarefas(ListaDeTarefas *lt, char *nome);
void exibeMenu();
int alterarTarefa(ListaDeTarefas *lt);
