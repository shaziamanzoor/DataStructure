#ifndef _QUEUE_H
#define _QUEUE_H

#include <stdbool.h>

#define MAX_QUEUE_SIZE 100

typedef int QueueEntry;

typedef struct queue {
  QueueEntry elements[MAX_QUEUE_SIZE];
  int        front;
  int        rear;
  int        count;
} Queue;

void queue_init(Queue *queue);
void queue_peek(Queue* queue, QueueEntry *entry);
void queue_enqueue(Queue* queue, QueueEntry entry);
void queue_dequeue(Queue* queue, QueueEntry *entry);
bool queue_is_empty(Queue* queue);
bool queue_is_full(Queue* queue);

#endif
