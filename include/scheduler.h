#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "task.h"

// Scheduler APIs
void scheduler_init(void);
void scheduler_add_task(task_t *task);
void scheduler_run(void);

// Kernel services
void scheduler_tick(void);
void task_delay(task_t *task, int ticks);

#endif
