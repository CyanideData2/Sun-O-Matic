void display(String stringToDisplay) {
  for(char i : stringToDisplay){
    Serial.write(i);
  }
}

void setup() {
  Serial.begin(9600);
  bluetooth_setup();
}

void loop() {
  switch (bluetooth_receive_command()) {
    case 'w': bluetooth_send_stream(scheduler_get()); break;
    case 'r': scheduler_update(bluetooth_receive_stream()); break;


    case 'd': display(bluetooth_receive_stream()); break;
    
    //case 'c': movement_calibrate(); break;
    //default: movement_toggle(scheduler_shouldToggle());
  }
}
