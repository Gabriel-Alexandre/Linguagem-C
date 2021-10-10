#ifndef _ARRAYESTATICO_H_
#define _ARRAYESTATICO_H_

typedef struct queue Queue;

Queue *create_queue();
int insert_queue(Queue *queue, int valor);
int remove_queue(Queue *queue);
int consult_queue(Queue *queue, int *valor);
int size_queue(Queue *queue);
int isEmpty_queue(Queue *queue);
int isMax_queue(Queue *queue);
void clear_queue(Queue *queue);

#endif