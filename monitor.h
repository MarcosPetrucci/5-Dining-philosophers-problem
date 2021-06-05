#include <semaphore.h>

// Define the data we need to create the monitor
struct monitor_DataType {
  sem_t OKtoRead;
  sem_t OKtoWrite;
  int readerCount;
  int isBusyWriting;
  
  // The read-queue
  int readRequested;
};


// Function that will block until write can start
void monitor_StartWrite();

// Function to signal reading is complete
void monitor_EndWrite();


// Function that will block until read can start
void monitor_StartRead() ;

// Function to signal reading is complete
void monitor_EndRead();


// intialize the monitor
// return's 0 on success, just like sem_init()
int monitor_Initialized();

// Destroys the semphores.
void monitor_Destroy();