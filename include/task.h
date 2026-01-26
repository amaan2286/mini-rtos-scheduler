#ifndef TASK_H
#define TASK_H

typedef enum {
    TASK_READY,
    TASK_RUNNING,
    TASK_BLOCKED
} task_state_t;

typedef struct {
    void (*task_func)(void);   // task entry function
    int priority;              // lower value = higher priority
    task_state_t state;
    int delay;                 // delay in ticks
} task_t;

#endif
