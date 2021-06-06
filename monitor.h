#ifndef MONITOR_H
#define MONITOR_H
#define TRUE 1
#define FALSE 0

//Variavel de condição para os filofos
typedef struct
{
  //Mapeia o estado do filosofo
  enum {PENSANDO,FAMINTO,COMENDO} estado;

}filo;

//Função que resolve um filosofo ocioso
void ocioso(int i);

//Muda o estado do filósofo para comendo se os palitos estiverem disponíveis
void verifica_disponibilidade(int i);

//Função que organiza a pegada dos palitos
void pegar_palitos(int i);

//Função que organiza a devolução dos palitos
void devolve_palitos(int i);

//Função que inicia o monitor e suas variáveis
void iniciar_monitor();

#endif
