/*
 * catsem.c
 *
 * 30-1-2003 : GWA : Stub functions created for CS161 Asst1.
 *
 * NB: Please use SEMAPHORES to solve the cat syncronization problem in 
 * this file.
 */


/*
 * 
 * Includes
 *
 */

#include <types.h>
#include <lib.h>
#include <test.h>
#include <thread.h>
#include <synch.h>

/*
 * 
 * Constants
 *
 */

/*
 * Number of food bowls.
 */

#define NFOODBOWLS 2

/*
 * Number of cats.
 */

#define NCATS 30

/*
 * Number of mice.
 */

#define NMICE 20


/*
 * 
 * Function Definitions
 * 
 */


/*
 * catsem()
 *
 * Arguments:
 *      void * unusedpointer: currently unused.
 *      unsigned long catnumber: holds the cat identifier from 0 to NCATS - 1.
 *
 * Returns:
 *      nothing.
 *
 * Notes:
 *      Write and comment this function using semaphores.
 *
 */
// six cat processes are going to try to enter catsem, WOO
static struct semaphore* catSemaphore = NULL;
static struct semaphore* miceSemaphore = NULL;
static struct semaphore* mouseWaiting = NULL;
static struct semaphore* blockCat = NULL;
static struct semaphore* catMouseExclusive = NULL;
static struct semaphore* catMutex=NULL;
static struct semaphore* miceMutex=NULL;
static struct semaphore* dish=NULL;
static struct semaphore* printfMutex=NULL;
int i = 1;
int j = 1;
int catNum = 0;
int miceNum = 0;
static void catsem(void * unusedpointer, unsigned long catnumber) {

	while(i > 0){
		P(blockCat);
		P(catMutex);
			
			catNum++;
			
			if(catNum == 1){
				P(catMouseExclusive);	
				P(printfMutex);
				kprintf("first cat came in, and is now trying to obtain cat mouse exclusive lock \n\n");
				V(printfMutex);

			}
		V(catMutex);
		V(blockCat);
		P(dish);
		
		P(printfMutex);
		kprintf("cat number %d eating \n", catnumber);
		V(printfMutex);
		
		clocksleep(1);	
	
		V(dish);
        
	        P(catMutex);
			P(printfMutex);
			kprintf("cat %d leaving\n\n", catnumber);
			V(printfMutex);
			catNum--;
            if(catNum == 0){
                    V(catMouseExclusive);
            }
            V(catMutex);		
		i--;	
	} 

	(void) unusedpointer;
	(void) catnumber;
}
        

/*
 * mousesem()
 *
 * Arguments:
 *      void * unusedpointer: currently unused.
 *      unsigned long mousenumber: holds the mouse identifier from 0 to 
 *              NMICE - 1.
 *
 * Returns:
 *      nothing.
 *
 * Notes:
 *      Write and comment this function using semaphores.
 *
 */

static
void
mousesem(void * unusedpointer, 
         unsigned long mousenumber)
{
				
				
        while(j > 0){
                P(miceMutex);
                        miceNum++;
			if(miceNum == 1){
				P(blockCat);
				P(catMouseExclusive);
				P(printfMutex);
                kprintf("mouse got exclusive lock it, squeak squeak! \n");
                V(printfMutex);
			}
                V(miceMutex);

		/**** EATING ***/
                P(dish);
                	/* Output status */
			P(printfMutex);
			kprintf("mice number %d eating\n", mousenumber);
                	V(printfMutex);
			/* Eating */
			clocksleep(1);
                
		/**** SIGNAL DONE EATING ****/		
		V(dish);
		

		P(miceMutex);
			miceNum--;	
			P(printfMutex);
			kprintf("mouse number %d leaving \n", mousenumber);
			V(printfMutex);
			
			if(miceNum == 0){
				V(blockCat);
				V(catMouseExclusive);
			}
		V(miceMutex);
		j--;
        }
        /*
         * Avoid unused variable warnings.
         */

        (void) unusedpointer;
        (void) mousenumber;
}


/*
 * catmousesem()
 *
 * Arguments:
 *      int nargs: unused.
 *      char ** args: unused.
 *
 * Returns:
 *      0 on success.
 *
 * Notes:
 *      Driver code to start up catsem() and mousesem() threads.  Change this 
 *      code as necessary for your solution.
 */

int
catmousesem(int nargs,
             char ** args)
{
        int index, error;
        if(catSemaphore == NULL){
          catSemaphore=sem_create("catSemaphore", NCATS);
        }
       if(miceSemaphore == NULL){
          miceSemaphore=sem_create("miceSemaphore", NCATS);
        }
	catMutex = sem_create("catMutex", 1);
	miceMutex = sem_create("miceMutex", 1);   
	dish = sem_create("dish", 2);
	catMouseExclusive = sem_create("catMouseExclusive", 1);
	printfMutex = sem_create("printfMutex", 1);
	mouseWaiting = sem_create("mouseWaiting", 1);
	blockCat = sem_create("blockCat", 1);
        /*
         * Avoid unused variable warnings.
         */
	(void) nargs;
	(void) args;
   
        /*
         * Start NCATS catsem() threads.
         */

        for (index = 0; index < NCATS; index++) {
           
                error = thread_fork("catsem Thread", 
                                    NULL, 
                                    index, 
                                    catsem, 
                                    NULL
                                    );
                
                /*
                 * panic() on error.
                 */

                if (error) {
                 
                        panic("catsem: thread_fork failed: %s\n", 
                              strerror(error)
                              );
                }
        }
        
        /*
         * Start NMICE mousesem() threads.
         */

        for (index = 0; index < NMICE; index++) {
   
                error = thread_fork("mousesem Thread", 
                                    NULL, 
                                    index, 
                                    mousesem, 
                                    NULL
                                    );
                
                /*
                 * panic() on error.
                 */

                if (error) {
         
                        panic("mousesem: thread_fork failed: %s\n", 
                              strerror(error)
                              );
                }
        }

        return 0;
}


/*
 * End of catsem.c
 */
