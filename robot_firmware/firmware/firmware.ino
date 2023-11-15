#include<SoftwareSerial.h>
#include<TimeLib.h>

const int alarmLimit = 10;
int schedule[alarmLimit];
SoftwareSerial bt(2,3); /* (Rx,Tx) */	

void setup() {
	bt.begin(9600);	/* Define baud rate for software serial communication */
	Serial.begin(9600);	/* Define baud rate for serial communication */
}

//-----------------------
void sendSchedule(){
	for(int i = 0; i<alarmLimit; i++){ 
		if(schedule[i] >=0) bt.write(schedule[i]);
	}
	bt.write("-");
}
void updateSchedule(){
	int newSchedule[10], i = 0;
	bool transmissionGoing = true;
	while(transmissionGoing){
		if(bt.available()){
			switch(bt.read()){
				case '-': transmissionGoing = false; break;
			}
		}
	}
}
void displayMessage(){
	bool transmissionGoing = true;
	while(transmissionGoing){
		if(bt.available()){
			char message = bt.read();
			switch(message){
				case '-': transmissionGoing = false; break;
				default: Serial.write(message);
			}
		}
	}
}
//---------------------------

void loop() {
	if (bt.available()) {
    char input= bt.read();
		switch(input){
			case 'w': sendSchedule(); break;
			case 'r': updateSchedule(); break;
			case 'd': displayMessage(); break;
		}	
	}

	//updateState();
}
