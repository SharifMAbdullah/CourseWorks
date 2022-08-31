#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <pthread.h>

int size=3, num_threads=3;

void *functionC();
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
int  counter = 0;

double matrix1[3][3] = {
		   {1.0,1.0,3.0},
		   {2.0,1.0,3.0},
		   {1.0,3.0,1.0}
};

  
void print_matrix(int size)
{
  int i, j;

  for (i = 0; i < size; ++i) {
    for (j = 0; j < size-1; ++j) {
      printf( "%.2lf, ", matrix1[ i ][ j ] );
    }
    printf( "%.2lf", matrix1[ i ][ j ] );
    putchar( '\n' );
  }
}
void *functionC()
{
   pthread_mutex_lock( &mutex1 );
   counter++;
   printf("Counter value: %d\n",counter);
   pthread_mutex_unlock( &mutex1 );
}


/**
 * Thread routine.
 * Each thread works on a portion of the 'matrix1'.
 * The start and end of the portion depend on the 'arg' which
 * is the ID assigned to threads sequentially. 
 */
void * worker( void *arg )
{
  int i, j, tid;

  tid = *(int *)(arg); // get the thread ID assigned sequentially.
    printf("worker for row %d\n",tid);


  for(i=0;i<3;i++)
        if(matrix1[tid][i] == 1.0)
           functionC();
}


int main( int argc, char *argv[] )
{
  int i;
  double sum = 0;
  struct timeval tstart, tend;
  double exectime;
  pthread_t  threads[10];
  
  // size = atoi( argv[1] );

  gettimeofday( &tstart, NULL );
  i = 0;

  gettimeofday( &tend, NULL );

  exectime = (tend.tv_sec - tstart.tv_sec) * 1000.0; // sec to ms
  exectime += (tend.tv_usec - tstart.tv_usec) / 1000.0; // us to ms   

  printf( "Number of threads: %d\tExecution time:%.3lf sec\n",
          1, exectime/1000.0);

  print_matrix(3);

  gettimeofday( &tstart, NULL );
  for ( i = 0; i < num_threads; ++i ) {
    int *tid;
    tid = (int *) malloc( sizeof(int) );
    *tid = i;
    pthread_create( &threads[i], NULL, worker, (void *)tid );
  }

  // if(1)
  //   return 0;

  for ( i = 0; i < num_threads; ++i ) {
    pthread_join( threads[i], NULL );
  }
  gettimeofday( &tend, NULL );

/*
  if ( size <= 10 ) {
    printf( "Matrix 1:\n" );
    print_matrix( matrix1, size );
    printf( "Matrix 2:\n" );
    print_matrix( matrix2, size );
    printf( "Matrix 3:\n" );
    print_matrix( matrix3, size );
  }
*/

  exectime = (tend.tv_sec - tstart.tv_sec) * 1000.0; // sec to ms
  exectime += (tend.tv_usec - tstart.tv_usec) / 1000.0; // us to ms   

  printf( "Number of threads: %d\tExecution time:%.3lf sec\n",
          num_threads, exectime/1000.0);

  printf("value of counter is %d",counter);
  return 0;
}
