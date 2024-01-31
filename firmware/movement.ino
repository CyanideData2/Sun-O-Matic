int sizeOfRod = 50;
bool movement_isOpen = true;
bool movement_closeToRight = true;

void movement_open () {
  display("Opening");
  motor_move(sizeOfRod, !movement_closeToRight);
  movement_isOpen = true;
}
void movement_close () {
  display("closieng");
  motor_move(sizeOfRod, movement_closeToRight);
  movement_isOpen = false;

}
void movement_toggle(bool shouldToggle){
  if (shouldToggle){
    if (movement_isOpen) movement_close();
    else movement_open();
  }
}

void movement_calibrate(String calibrationParameters){
  sizeOfRod = calibrationParameters[0]*2;
  //movement_closeToRight=  calibrationParameters[1];
}
