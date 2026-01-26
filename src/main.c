#include <stdio.h>
#include "scheduler.h"

task_t t1, t2;

void task1(void) {
    static int count = 0;
    printf("Task 1 [HIGH priority] running (%d)\n", count++);
}

void task2(void) {
    static int count = 0;
    printf("Task 2 [LOW priority] running (%d)\n", count++);
}

int main(void) {
    t1 = (task_t){ task1, 1, TASK_READY, 0 };   // higher priority
    t2 = (task_t){ task2, 3, TASK_READY, 0 };   // lower priority

    scheduler_init();
    scheduler_add_task(&t1);
    scheduler_add_task(&t2);

    scheduler_run();   // kernel never returns
    return 0;
}
