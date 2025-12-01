#include <stdio.h>
}
if (opcao == 0) {
printf("Encerrando o programa.\n");
break;
}
Peca temporaria;
int sucesso;
switch (opcao) {
case 1: /* Jogar peça: remove da frente da fila (dequeue) */
sucesso = desenfileirar(&fila, &temporaria);
if (sucesso) {
printf("\nVocê jogou a peça [%c %d].\n", temporaria.nome, temporaria.id);
} else {
printf("\nFila vazia — não há peça para jogar.\n");
}
break;
case 2: /* Reservar peça: move da frente da fila para o topo da pilha */
/* primeiro verifica se há peça na fila */
if (fila.quantidade == 0) {
printf("\nFila vazia — não há peça para reservar.\n");
} else if (pilha.topo + 1 >= pilha.capacidade) {
printf("\nPilha de reserva cheia — não é possível reservar.\n");
} else {
desenfileirar(&fila, &temporaria);
if (empilhar(&pilha, temporaria)) {
printf("\nPeça [%c %d] reservada (empilhada).\n", temporaria.nome, temporaria.id);
} else {
/* caso improvável, re-enfileira para não perder a peça */
printf("\nErro ao empilhar — repondo peça na fila.\n");
enfileirar(&fila, temporaria);
}
}
break;
case 3: /* Usar peça reservada: remove do topo da pilha (pop) */
sucesso = desempilhar(&pilha, &temporaria);
if (sucesso) {
printf("\nVocê usou a peça reservada [%c %d].\n", temporaria.nome, temporaria.id);
} else {
printf("\nPilha vazia — não há peça reservada para usar.\n");
}
break;
default:
printf("\nOpção inválida. Escolha 0, 1, 2 ou 3.\n");
break;
}
/* Após cada ação, tentamos garantir que a fila esteja cheia.
* Se a fila não estiver cheia (por exemplo, porque removemos da frente),
* geramos e enfileiramos uma peça nova. Se a fila já estiver cheia (por
* exemplo, ao usar uma peça da reserva), não fazemos nada.
*
* Observação: a especificação pede "A cada ação, uma nova peça é
* automaticamente gerada e adicionada ao final da fila, mantendo-a
* sempre cheia". Para evitar overflow quando nenhuma peça foi
* removida da fila (caso "usar peça reservada"), aqui apenas
* enfileiramos quando há espaço — isto mantém a fila sempre cheia
* quando ela ficou menor após a ação.
*/
if (fila.quantidade < fila.capacidade) {
Peca nova = gerarPeca();
if (enfileirar(&fila, nova)) {
printf("Uma nova peça [%c %d] foi gerada e adicionada ao final da fila.\n", nova.nome, nova.id);
}
}
/* Pequena pausa visual antes de atualizar a tela (opcional) */
/* fflush(stdout); */
}
return 0;
}

