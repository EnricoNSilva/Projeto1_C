<h2>PROJETO DE DESENVOLVIMENTO DE ALGORITMOS</h2>

<p align="center">Esse projeto tem o principal objetivo de analisar códigos e testar a capacidade de corrigir erros técnicos.</p><br>
<p align="center">
<a href="#integrantes">#integrantes</a> 
<a href="#sobre">#Sobre o Projeto</a>
<a href="#problemas">#Problemas Corrigidos</a>
<a href="#funcionalidades">#Funções Novas</a>
</p>

# integrantes
<li><a href"https://github.com/GuilhermeXavier2005">Guilherme Silva Xavier</a></li>
<li><a href="https://github.com/EnricoNSilva">Enrico Nascimento Silva</a><br></li>
Estudantes do curso de Ciências da Computação, atuamente no Segundo Ciclo<br>

# sobre
<p>O projeto detém o principal objetivo de <u>listar tarefas.</u></p><br>
<h3 align="center">Características</h3>
<p>ao acessar, o usuário consegue adicionar suas tarefas no qual deverá preencher algumas opções para seguir adiante.<br></p> <p><strong>Categoria:</strong> cada atividade terá um breve e pequeno título acerca do se tratará a tarefa.<br></p> <p><strong>Prioridade:</strong> em uma listagem das atividades haverá uma prioridade dada por um número inteiro e quanto maior o número, maior sua prioridade<br></p><p><strong>Descrição: </strong>A tarefa deve conter também uma pequena descrição do que será tratado</p>

<p><strong>Observação:</strong> O funcionamento do projeto usa-se o cabeçalho no diretório "header/Projeto.h"</p>

<h3 align="center">Como iniciar o projeto</h3>
<p><u>obtenha</u> o ZIP contendo todos os arquivos do programa e extraia de dentro do .ZIP</p>
<li>Se estiver no windows execute o .exe disponível na pasta</li>
<li>Para outras plataformas busque acessar o replit importando os arquivos para o site</li>
<li>Link para o projeto no replit: <a href="https://replit.com/@enriconascimen2/Projeto#Projeto/header/Projeto.h">replit</a>

# problemas
<div align="center">
<h3>Problemas Corrigidos</h3>
<p><strong>localização do código:</strong><br>
<u>linha 1 - arquivo main.c</u><br>
O nome correto do arquivo do cabeçalho é 'header/Projeto.h'</p>

<p><strong>localização do código:</strong><br>
<u>linha 2 - arquivo main.c</u><br>
O correto para usar a biblioteca padrão é usar a formatacação "<>" invés de aspas duplas</p>

<p><strong>localização do código:</strong><br>
<u>linha 3 - arquivo main.c</u><br>
O uso de "stdlib" é necessário para usar a função system()</p>

<p><strong>localização do código:</strong><br>
<u>linha 11 - arquivo main.c</u><br>
A função esperava um ponteiro e estava recebendo a variavel lt diretamente</p>

<p><strong>localização do código:</strong><br>
<u>linha 15 - arquivo main.c</u><br>
Alterado o valor de listas de 2 para 0</p>

<p><strong>localização do código:</strong><br>
<u>linha 39 - arquivo main.c</u><br>
Aqui estava 2, mas o código de erro na função seria return 1</p>

<p><strong>localização do código:</strong><br>
<u>linha 55 - arquivo main.c</u><br>
Em SalvarTarefas, 0 significa sucesso e 1 significa erro(Estava retornando Erro mesmo quando o arquivo era salvo)</p>

<p><strong>localização do código:</strong><br>
<u>linha 59 - arquivo main.c</u><br>
 A função main estava sem retorno</p>

<p><strong>localização do código:</strong><br>
<u>linha 1 - arquivo Projeto.c</u><br>
O nome do arquivo do cabeçalho é "header/Projeto.c"</p>

<p><strong>localização do código:</strong><br>
<u>linha 2 e linha 3 - arquivo Projeto.c</u><br>
Para bibliotecas padrão C é usado "<>" para importação e não aspas duplas de bibliotecas criadas</p>

<p><strong>localização do código:</strong><br>
<u>linha 62 - arquivo Projeto.c</u><br>
O if estava verificando se < lt->qtd -1, porém deveria ser >, pois a posição não pode ser negativa</p>

<p><strong>localização do código:</strong><br>
<u>linha 67 - arquivo Projeto.c</u><br>
estava copiando descrição para categoria</p>

<p><strong>localização do código:</strong><br>
<u>linha 137 - arquivo Projeto.c</u><br>
a chamada do nome deveria ser um ponteiro mas estava chamando a variavel</p>

<p><strong>localização do código:</strong><br>
<u>linha 148 - arquivo Projeto.c</u><br>
Estava sem ponto e virgula</p>

<p><strong>localização do código:</strong><br>
<u>linha 1 - arquivo Projeto.h</u><br>
Numero de tarefas estava estipulado em 5 mas deve-se suportar até 100 tarefas</p>

<p><strong>localização do código:</strong><br>
<u>linha 18 - arquivo Projeto.h</u><br>
Chamada do struct ListaDeTarefas estava com erro de digitação</p>

<p><strong>localização do código:</strong><br>
<u>linha 24 - arquivo Projeto.h</u><br>
Função carregar tarefas estava recebendo um ponteiro chamado "nomes" o correto seria "nome"</p>
</div>


# funcionalidades

    Essa área é especificamente para novas funções aplicadas ao programa em finalidade de trazer funcionalidades extras que ajudem o usuário
        Funcionalidade de Alterar suas prioridades das atividades, alterar sua descrição e categoria
        Prazos de validade de cada atividade
        Função para filtrar tarefas listadas