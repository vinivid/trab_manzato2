Para se compilar o programa é necessario de um compilador que suporte a linguagem C no padrão C99 e a ferramenta GNU Make
para que o projeto inteiro seja construido é simplesmente colocar o comando 'make' com o GNU Make instalado em sua maquina.

## Obs: As instruções de compilação utilizão o GCC como compilador default, se quiser utilizar outro compilador 
## é necessario mudar a váriavel 'CC' quando chamando o comando 'make'.

Uma vez com o programa compilado é necessario chamalo pelo terminal ou usando 'make run'.

O programa tem um argumento obrigatório (o primeiro), que é o método de ordenação a ser utilizado.
Os argumentos possíveis para a primeira posição estão a seguir em que na esquerda é o 
argumento e na direita é o método de ordenação que o programa utilizara para aquele argumento.
NÃO SE PODE UTILIZAR LETRAS MAIUSCULAS OS ARGUMENTOS DEVEM SER ASSIM COMO OS DESCRITOS ABAIXO.
bubble : Bubble Sort
select : Selection Sort
insert : Insert Sort
quick  : Quick Sort
heap   : Heap Sort
merge  : Mege Sort
count  : Contagem dos menores
radix  : Radix Sort

O segundo argumento ao programa é opicional, ao omiti-lo o programa tera como saida apenas os dados de ordenação 
que são formatados da seguinte forma:

QUANTIDADE_DE_COMPARAÇÕES QUANTIDADE_DE_MOVIMENTOS TAMANHO_DO_VETOR TEMPO_DE_PROCESSAMENTO

Sendo que cada um desses dados esta separado por um uníco espaço e no final um newline.

Caso não queira isso é necessario colocar como segundo argumento algum caracter e a saida do programa sera o vetor colocado como
entrada ordenado de forma crescente.

Entradas do programa: 
    Após ter selecionado um método de ordenação e opicionalmente o seugundo argumento o programa lera inputs da seguinte forma:
    A primeira linha sera a quantidade de elementos que tera no vetor.
    Depois disso ele lera a quantidade específicada de elementos que o vetor lera em sequencia.

Junto com o programa é disponibilizado um caso teste chamado 'tst.in'.