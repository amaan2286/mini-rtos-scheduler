#include <stdio.h>
#include <unistd.h>     // usleep()
#include "scheduler.h"

#define MAX_TASKS 5
#define TIME_SLICE_US 100000   // 100 ms time slice

static task_t *tasks[MAX_TASKS];
static int task_count = 0;

void scheduler_init(void) {
    task_count = 0;
}

void scheduler_add_task(task_t *task) {
    if (task_count < MAX_TASKS) {
        tasks[task_count++] = task;
    }
}

void task_delay(task_t *task, int ticks) {
    task->delay = ticks;
    task->state = TASK_BLOCKED;
}

void scheduler_tick(void) {
    for (int i = 0; i < task_count; i++) {
        if (tasks[i]->state == TASK_BLOCKED && tasks[i]->delay > 0) {
            tasks[i]->delay--;
            if (tasks[i]->delay == 0) {
                tasks[i]->state = TASK_READY;
            }
        }
    }
}

/*
 * PREEMPTIVE, PRIORITY-BASED SCHEDULER
 * Scheduler controls CPU, not tasks
 */
void scheduler_run(void) {
    while (1) {
        task_t *selected = NULL;

        // Select highest-priority READY task
        for (int i = 0; i < task_count; i++) {
            if (tasks[i]->state == TASK_READY) {
                if (selected == NULL ||
                    tasks[i]->priority < selected->priority) {
                    selected = tasks[i];
                }
            }
        }

        if (selected != NULL) {
            selected->state = TASK_RUNNING;

            // Run task for one time slice
            selected->task_func();

            // Preempt task after time slice
            selected->state = TASK_READY;
        }

        scheduler_tick();          // advance system time
        usleep(TIME_SLICE_US);     // simulate timer interrupt
    }
}
