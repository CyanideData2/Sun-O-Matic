void setup() {
  Serial.begin(9600);
  bluetooth_setup();
  motor_setup();

  //test_start();
}

void loop() {
  switch (bluetooth_receive_command()) {
    case 'i': scheduler_inizialize(); break;

    case 's': bluetooth_send_stream(scheduler_get()); break;
    case 'u': scheduler_update(bluetooth_receive_stream()); break;


    case 'd': display(bluetooth_receive_stream()); break; 

    case 'c': movement_calibrate(bluetooth_receive_stream()); 
    break;

    case 'b': movement_open();break;
    case 'n': movement_close();break;
    default: movement_toggle(scheduler_shouldToggle());
  }
}
