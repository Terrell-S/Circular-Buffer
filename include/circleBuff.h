#pragma once

#include <stdint.h> //int bit sizes
#include <stddef.h> //size type (unsigned int)
#include <stdbool.h> //c doesn't come with bool guao
#include <pthread.h> //threads

#define CB_CAPACITY 256

/*
No objects/methods in c, so struct for necessary variables
methods are just functions that take struct as argument
*/
typedef struct {
    int32_t data[CB_CAPACITY];
    size_t head;
    size_t tail;
    size_t count;

    pthread_mutex_t lock;
    pthread_cond_t empty;
    pthread_cond_t full;

    uint64_t total_popped;
    uint64_t total_pushed;
    uint64_t total_dropped;
} circular_buffer_t;

//constructor and destructor
void cb_init(circular_buffer_t *cb);
void cb_destroy(circular_buffer_t *cb);

//error code 1 if buffer full, drops input
int cb_push(circular_buffer_t *cb, int32_t value);

//error code 1 if buffer empty
int cb_pop(circular_buffer_t *cb, int32_t *out);

bool cb_is_full(const circular_buffer_t *cb);
bool cb_is_empty(const circular_buffer_t *cb);
size_t cb_size(const circular_buffer_t *cb);
