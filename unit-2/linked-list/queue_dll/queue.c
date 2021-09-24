#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "../doubly_linked_list/doubly_linked_list.h"

static void error(const char* message) {
  fprintf(stderr, "Queue error: %s\n", message);
  exit(-1);
}

void queue_init(Queue *queue){
  queue->front = NULL;
  queue->rear = NULL;
}

void queue_peek(Queue* queue, QueueEntry *entry) {
  if (queue_is_empty(queue))
    error("queue is empty");

  *entry = queue->front->value;
}
    
void queue_enqueue(Queue* queue, QueueEntry entry) {
  if (queue_is_empty(queue)) {
    queue->front = queue->rear = dll_prepend(NULL, entry);
  } else {
    dll_insert_after(queue->rear, entry);
    queue->rear = queue->rear->next;
  }
}

void queue_dequeue(Queue* queue, QueueEntry *entry) {
  if (queue_is_empty(queue))
    error("queue is empty");

  DoubleNode *head = queue->front;
  *entry = head->value;
  queue->front = head->next;
  if (queue->front)
    queue->front->prev = NULL;
  else
    queue->rear = NULL;
  free(head);
}

bool queue_is_empty(Queue* queue) {
  return queue->front == NULL;
}

void queue_for_each(Queue *queue, void (*fn) (DoubleNode*)) {
  dll_for_each(queue->front, fn);
}

