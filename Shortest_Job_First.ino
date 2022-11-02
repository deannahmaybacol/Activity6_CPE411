/*	CPU Scheduling Algorithm - Short Job First
 *	Deannah May P. Bacol
 * 	BSCpE 4A
 */

void setup() {
  pinMode(13, OUTPUT); 		/*LED 1*/
  pinMode(12, OUTPUT); 		/*LED 2*/
  pinMode(11, OUTPUT); 		/*LED 3*/
  pinMode(10, OUTPUT); 		/*LED 4*/
  pinMode(9, OUTPUT); 		/*LED 5*/
  pinMode(8, OUTPUT); 		/*LED 6*/
  pinMode(7, OUTPUT); 		/*LED 7*/
  pinMode(6, OUTPUT); 		/*LED 8*/
}

void loop() {
  int pin[6] = {13, 12, 11, 10, 9, 8};		  /*pinModes*/
  
  /*declaring time as an array in terms of milliseconds*/
  int time[6] = {5000, 2000, 4000, 1000, 7000, 3000};
  
  int temp; 	/*temporary value used in swapping*/
  
  for (int i=0; i<6; i++){
    for (int j=0; j<6; j++){
      if (time[i] < time[j]){
      	temp = time[i];
        time[i] = time[j];
        time[j] = temp;
        
        temp = pin[i];
        pin[i] = pin[j];
        pin[j] = temp;
      }
    }
  } /*after executing this loop, the time array and pin array is sorted in ascedning*/
  
  int count = 0; 	/*used to identifies the element of time array*/
  while (count != 6){
  	digitalWrite(pin[count], HIGH);
    delay(time[count]);
    digitalWrite(pin[count], LOW);
    count++;
  }
}

