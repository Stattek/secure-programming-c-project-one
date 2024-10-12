
/**
 * @file CON32-C.c
 * @author Aayaan Shaikh
 * @brief demonstrates how not to reuse threads already detached or joined
 * @version 0.1
 * @date 2024-10-12
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <pthread.h>
#include <stdio.h>

struct multi_thread_ints
{
  unsigned int threadOneInt : 2; // bit-field 1, specify # of bits
  unsigned int threadTwoInt : 2; // bit-field 2, small fields more likely to be adjacent
  unsigned int threadThreeInt : 2;
  unsigned int threadFourInt : 2;
};

struct mtf_mutex
{
  struct multi_thread_ints s;
  pthread_mutex_t mutex;
};

struct mtf_mutex ints;

void *thread1(void *arg)
{

  pthread_mutex_lock(&ints.mutex); // lock struct for operation

  ints.s.threadOneInt = 1; // operation

  pthread_mutex_unlock(&ints.mutex); // unlock struct for operation
  return NULL;
}

void *thread2(void *arg)
{

  pthread_mutex_lock(&ints.mutex);

  ints.s.threadTwoInt = 2;

  pthread_mutex_unlock(&ints.mutex);
  return NULL;
}

void *thread3(void *arg)
{

  pthread_mutex_lock(&ints.mutex);

  ints.s.threadThreeInt = 3;

  pthread_mutex_unlock(&ints.mutex);
  return NULL;
}

int main()
{
  pthread_t t1, t2, t3;

  pthread_mutex_init(&ints.mutex, NULL);

  pthread_create(&t1, NULL, thread1, NULL);
  pthread_create(&t2, NULL, thread2, NULL);

  pthread_join(t1, NULL);
  pthread_join(t2, NULL);

  printf("int1: %d, int2: %d\n", ints.s.threadOneInt, ints.s.threadTwoInt);

  // CON39-C: Do not join or detach a thread that was previously joined or detached
  // avoided detaching thread after it had alrady been joined to reuse it
  // used new threads to do next operations instead

  pthread_create(&t3, NULL, thread3, NULL);

  pthread_join(t3, NULL);

  printf("int3: %d\n", ints.s.threadThreeInt);

  // mutex destroy
  pthread_mutex_destroy(&ints.mutex);

  return 0;
}