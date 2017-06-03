// Copyright 2017 The Fuchsia Authors
// Copyright (c) 2008-2015 Travis Geiselbrecht
//
// Use of this source code is governed by a MIT-style
// license that can be found in the LICENSE file or at
// https://opensource.org/licenses/MIT
#pragma once

#include <kernel/thread.h>
#include <list.h>
#include <stdbool.h>
#include <zircon/compiler.h>

/* scheduler interface, used internally by thread.c */
/* not intended to be used by regular kernel code */
void sched_init_early(void);

void sched_block(void);
void sched_yield(void);
void sched_preempt(void);
void sched_reschedule(void);
void sched_resched_internal(void);

/* return true if the thread was placed on the current cpu's run queue */
/* this usually means the caller should locally reschedule soon */
bool sched_unblock(thread_t *t) __WARN_UNUSED_RESULT;
bool sched_unblock_list(struct list_node *list) __WARN_UNUSED_RESULT;
