#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *thread_generate(void *param)
{
    int *i;

    i = (int *)param;
    printf("Nous sommes dans le thread %d .\n", *i);
    pthread_exit(NULL);
}

int main(void)
{
    pthread_t *thread;
    int i;

    i = 0;
    thread = (pthread_t *)malloc(sizeof(pthread_t) * 4);
    while (i < 4)
    {
      if (pthread_create(&thread[i], NULL, thread_generate, (void *)&i))
  	  {
        return EXIT_FAILURE;
      }
      if (pthread_join(thread[i], NULL))
      {
  	    return EXIT_FAILURE;
      }
      i++;
    }
    return EXIT_SUCCESS;
}
