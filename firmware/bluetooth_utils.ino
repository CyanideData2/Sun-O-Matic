#include <SoftwareSerial.h>

SoftwareSerial bt(2, 3); /* (Rx,Tx) */

void bluetooth_setup() {
  bt.begin(9600); /* Define baud rate for software serial communication */
}

/* Define baud rate for serial communication */
void display(String stringToDisplay) {
  //Serial.write("YES");
  for (char i : stringToDisplay) {
    Serial.write(i);
  }
  Serial.write('\n');
}

String bluetooth_receive_stream() {
  //Serial.write("YES");
  bool transmissionGoing = true;
  String stream;
  while (transmissionGoing) {
    if (bt.available()) {
      char message = bt.read();
      Serial.write(message);
      if (message == '-') transmissionGoing = false;
      else stream += message;
    }
  }
  //Serial.write("Done receiving");
  return stream;
}

void bluetooth_send_stream(String streamToSend) {
  display(streamToSend + '-');
  for (int i = 0; i < streamToSend.length(); i++) bt.write(streamToSend[i]);
  bt.write('-');
}

int bluetooth_charToInt(char inputchar){
  return inputchar - 48;
}
char bluetooth_intToChar(char inputchar){
  return inputchar + 48;
}


char bluetooth_receive_command() {
  if (bt.available()) {
    char message = bt.read();
    Serial.write(message);
    return message;
  }
  return '_';
}
