#include<SoftwareSerial.h>

SoftwareSerial bt(2,3); /* (Rx,Tx) */    

void bluetooth_setup(){
	bt.begin(9600);    /* Define baud rate for software serial communication */
}    /* Define baud rate for serial communication */

String bluetooth_receive_stream() {
	bool transmissionGoing = true;
	String stream;
	while(transmissionGoing){
		if(bt.available()){
			char message = bt.read();
			switch(message){
				if (message == '-') transmissionGoing = false;
				else stream += message;
			}
		}
	}
	return stream;
}

void bluetooth_send_stream(String streamToSend) {
	for(int i = 0; i<streamToSend.length(); i++) bt.write(streamToSend[i]);
	bt.write('-');
}


char bluetooth_receive_command() {
	if(bt.available()){
		return bt.read();
	}
	return '_';
}
