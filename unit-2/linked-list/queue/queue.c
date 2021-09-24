#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "queue.h"
#include "../linked_list/linked_list.h"

static void error(const char* message) {
  fprintf(stderr, "Queue error: %s\n", message);
  exit(-1);
}

void queue_init(Queue *queue) {
  queue->front = NULL;
  queue->rear = NULL;
}

void queue_peek(Queue* queue, QueueEntry *entry) {
  if (queue_is_empty(queue))
    error("Queue is empty");

  *entry = queue->front->data;
}

void queue_enqueue(Queue* queue, QueueEntry entry) {
  Node *newNode = ll_make_node(entry);

  if (queue_is_empty(queue))
    queue->front = queue->rear = newNode;
  else {
    queue->rear->next = newNode;
    queue->rear = newNode;
  }
}

void queue_dequeue(Queue* queue, QueueEntry *entry) {
  if (queue_is_empty(queue))
    error("Queue is empty");

  *entry = queue->front->data;
  Node* node = queue->front;
  queue->front = node->next;

  if (queue->front == NULL)
    queue->rear = NULL;

  free(node);
}
       
bool queue_is_empty(Queue* queue) {
  return queue->front == NULL;
}
  
void queue_for_each(Queue* queue, void (*fn)(Node*)){
  for (Node *p = queue->front; p != NULL; p = p->next)
    fn(p);
}

