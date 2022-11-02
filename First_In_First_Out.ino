v/* 	CPU Scheduling Algorithm - First In First Out
 *	Deannah May P. Bacol
 *  BSCpE 4A
 */

void setup() {
  pinMode(13, OUTPUT);  	/*LED 1*/
  pinMode(12, OUTPUT); 		/*LED 2*/
  pinMode(11, OUTPUT); 		/*LED 3*/
  pinMode(10, OUTPUT); 		/*LED 4*/
  pinMode(9, OUTPUT); 		/*LED 5*/
  pinMode(8, OUTPUT); 		/*LED 6*/
  pinMode(7, OUTPUT); 		/*LED 7*/
  pinMode(6, OUTPUT); 		/*LED 8*/
}

void loop() {
  /*declaring time as an array in terms of milliseconds*/
  int time[8] = {4000, 5000, 1000, 3000, 4000, 1000, 2000, 6000}; 
  
  int num = 0;        /*used to identify the element*/
  
  for (int i = 13; i >= 6; i--){
  	digitalWrite(i, HIGH); 		/*LED On*/
    delay(time[num]); 			/*Delay*/
    digitalWrite(i, LOW); 		/*LED Off*/
    num++; 						/*Increment num.*/
  }
}
