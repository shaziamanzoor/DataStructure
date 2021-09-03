#include <stdio.h>
#include <assert.h>
#include "queue.h"

int main(void) {
  Queue queue;
  Queue *q = &queue;
  queue_init(q);
  assert(queue_is_empty(q));

  for (int i = 0; i < MAX_QUEUE_SIZE; i++)
    queue_enqueue(q, i);

  assert(queue_is_full(q));

  for (int i = 0; i < MAX_QUEUE_SIZE; i++) {
    int value;
    queue_dequeue(q, &value);
    assert(i == value);
  }

  assert(queue_is_empty(q));
  assert(q->rear == -1);

  return 0;
}

    
  
