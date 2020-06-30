/*
 *   Functions here used as an accurate clock calculating elapsed time from a known start time using 
 *   the millis() function
 * 
 * 
 * 
 */





 
//...................................  Initial Millis  ........................................................................

// Set up inital millis, this sets up the start point for the clock. Called once at the end of setup.       


int32_t initalMillis;

void clockSet() {

  initalMillis = timeToMillis(countdownTime);

}

//.............................................................................................................



//*****************************************  Millis To Time  ***********************************************************************



void millisToTime(int32_t inputMillis) {  // function to convert a total time in millis to  countdownTime. Accepts positive or negative arguments




  outputTime.s = inputMillis / 1000;                         // work out the total elapsed time by divding total elapsed milliseconds 

  outputTime.m =  inputMillis / 60000;

  outputTime.h =  inputMillis  / 3600000;

  
  // This section subtracts the elapsed hours from the total minuites, then the total hours and total minuites from total seconds, leaving a "bucket" of hours, minutes and seconds with each value seperated.
  // this works as the algorithms above round down by cutting off any decimal points

  outputTime.m =  outputTime.m  - ( outputTime.h * 60);

  outputTime.s =  outputTime.s  - (( outputTime.m + ( outputTime.h  * 60) ) * 60 );


  // return outputTime;           // this function does not return anything because C wont let you return structures for some reason. Instead it directly changes outputTime structure which is now declared as a global variable.

}

//*****************************************************************************************************************





//++++++++++++++++++++++++++++++++++++++++++++  Time To Millis ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

// Function to Convert a time passed as a structure containing (h , m , s) to a millisecond value.
// Accepts positive or negative arguments


int32_t timeToMillis(countDownTime inputTime) {


  int32_t outputMillis = ((inputTime.s * 1000) + (inputTime.m * 60 * 1000) + (inputTime.h * 60 * 60 * 1000));             // Convert our current clock back into milliseconds


  return outputMillis;

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++



//IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII    Internal Clock    IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII

void internalClock() {  // this function updates the countdownclock by using the functions above to convert the current countdown value to milliseconds. adding millis(). The converting the value back to a real time



 int32_t millisPassed = millis() + initalMillis;


  millisToTime(millisPassed);


  countdownTime = outputTime;

}

// IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII
