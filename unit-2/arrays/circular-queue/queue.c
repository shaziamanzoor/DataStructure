#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void error(const char* message) {
  fprintf(stderr, "Queue Error: %s\n", message);
  exit(-1);
}

void queue_init(Queue *queue) {
  queue->front = 0;
  queue->rear = -1;
  queue->count = 0;
}
  
void queue_peek(Queue* queue, QueueEntry *entry) {
  if (queue_is_empty(queue))
    error("Queue is empty");

  *entry = queue->elements[queue->front];
}

void queue_enqueue(Queue* queue, QueueEntry entry) {
  if (queue_is_full(queue))
    error("Queue is full");

  queue->count++;
  queue->rear = (queue->rear + 1) % MAX_QUEUE_SIZE;
  queue->elements[queue->rear] = entry;
}

void queue_dequeue(Queue* queue, QueueEntry *entry) {
  if (queue_is_empty(queue))
    error("Queue is empty");

  queue->count--;
  *entry = queue->elements[queue->front];
  queue->front = (queue->front + 1) % MAX_QUEUE_SIZE;

  if (queue_is_empty(queue)) {
    queue_init(queue);
  }
}

bool queue_is_empty(Queue* queue) {
  return queue->count == 0;
}

bool queue_is_full(Queue* queue) {
  return queue->count == MAX_QUEUE_SIZE;
}
