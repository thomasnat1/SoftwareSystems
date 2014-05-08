Pintos - Threading
=====================

In this segment of the homework, we improved upon the existing implementation of `thread_sleep` by modifying the code to block/resume the current thread instead of yielding. 

For emulation we used bochs 2.4, which must be compiled with the --with-nogui flag in order to function properly with pintos.  Installing from apt-get yields errors because the binary installed was not compiled with these options.

Below are the functions we modified, and a brief description of what we did:

```C
/* Sleeps for approximately TICKS timer ticks.  Interrupts must
   be turned on. */
void timer_sleep (int64_t ticks) { 
   // ignore negative `ticks` values
   if (ticks > 0) {
     ASSERT (intr_get_level () == INTR_ON);
     // assign requested sleep time to current thread
     thread_current()->ticks = ticks;
     // disable interrupts to allow thread blocking
     enum intr_level old_level = intr_disable();
     thread_block();
     // revert to old interrupt level to ensure that no other logic crashes 
     intr_set_level(old_level);
   }
}
```

```C
void thread_wake (struct thread *t, void *aux){
  // at every tick, decrement the ticks remaining until unblock
  if (t->status == THREAD_BLOCKED) {
    t->ticks--;
    if (!t->ticks) {
      // when 0 ticks remain, unblock the thread.
      thread_unblock(t);
    }
  }
}
```


We added a uint64 to the thread struct to keep track of how long it needs to block for before waking up. When called on a thread, this new function decrements that counter if the thread is currently blocked.  When the number of ticks for a thread becomes 0, the thread is unblocked.

```
timer_interrupt (struct intr_frame *args UNUSED)
{
  // called every tick
  ticks++;
  thread_tick ();
  thread_foreach(thread_wake, NULL);
}
```

We added a call to the thread_wake function on each thread every time the interrupt triggers, so that sleeping threads can be woken.

We strived for clean, simple code rather than efficiency.

Future work:
-------------
We did not take a crack at prioritization, but to do so we would need to add a priority field to the thread struct, and alter the scheduling procedure to switch context to threads with the highest priority first.  While running, the thread’s priority would be gradually decreased.  To implement this we would want to create a list of threads and sort it based on descending priority, then pop off of the front of that list in the next_thread_to_run function.

 
