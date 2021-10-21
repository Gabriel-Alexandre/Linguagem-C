#ifndef _FILA_H_
#define _FILA_H_

typedef struct queue Queue;
typedef struct no No;

Queue *create_queue();
int insert_queue(Queue *queue, int valor);
int remove_queue(Queue *queue);
int consult_queue(Queue *queue, char *valor);
int size_queue(Queue *queue);
int isEmpty_queue(Queue *queue);
void clear_queue(Queue *queue);

#endif