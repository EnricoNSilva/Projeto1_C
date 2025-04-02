#define TOTAL_TAREFAS 100 // numero maximo de tarefas estava em 5, porem em ListaDeTarefa tem tamanho 100

typedef struct {
    int prioridade;
    char descricao[300];
    char categoria[100];
} Tarefa;

typedef struct {
    Tarefa tarefas[100];
    int qtd;
} ListaDeTarefa;

int criarTarefa(ListaDeTarefas *lt);
int deletarTarefa(ListaDeTarefas *lt);
int listarTarefas(ListaDeTarefas *lt);

int carregarTarefas(ListaDeTarefas *lt, char *nomes);
int salvarTarefas(ListaDeTarefas *lt, char *nome);
void exibeMenu();
