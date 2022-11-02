/*	CPU Scheduling Algorithm - Round Robin
 *  Deannah May P. Bacol
 *  BSCpE 4A
 */

/*with Time Quantum of 3 seconds or 3000 milliseconds*/

void setup() {
  pinMode(13, OUTPUT);		/*LED 1*/
  pinMode(12, OUTPUT);		/*LED 2*/
  pinMode(11, OUTPUT); 		/*LED 3*/
  pinMode(10, OUTPUT); 		/*LED 4*/
  pinMode(9, OUTPUT); 		/*LED 5*/
  pinMode(8, OUTPUT); 		/*LED 6*/
  pinMode(7, OUTPUT); 		/*LED 7*/
  pinMode(6, OUTPUT); 		/*LED 8*/
}

void loop() {
  /*maximum of 3 Quantum*/
  int time_quantum = 3000;
  
  /*pinModes*/
  int pin[8] = {13, 12, 11, 10, 9, 8, 7, 6};
  
  /*declaring burst_time as an array in terms of milliseconds*/
  int burst_time[8] = {4000, 2000, 5000, 3000, 6000, 1000, 2000, 3000};
  
  /*declaring arrival_time as an array in terms of milliseconds*/
  int arrival_time[8] = {0, 1000, 3000, 5000, 6000, 4000, 3000, 2000};
  
  int temp;		/*temporary value used in swapping*/
  
  for (int i=0; i<8; i++){
    for (int j=0; j<8; j++){
      if (arrival_time[i] < arrival_time[j]){		
      	temp = arrival_time[i];					
        arrival_time[i] = arrival_time[j];
        arrival_time[j] = temp;
        
        temp = burst_time[i];					
        burst_time[i] = burst_time[j];
        burst_time[j] = temp;
        
        temp = pin[i];							
        pin[i] = pin[j];
        pin[j] = temp;
      }		
    }
  }
  /*after executing this loop, the burst time and pin array is sorted in ascending*/

  for (int i=0; i<8; i++){
  	digitalWrite(pin[i], HIGH);		/*LED On*/
    delay(time_quantum);			/*Delay using Time Quantum*/
    digitalWrite(pin[i], LOW);		/*LED Off*/
    burst_time[i]--;				/*Decrement burst time*/
  }
}

