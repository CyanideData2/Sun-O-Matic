const int adequateVoltage = 255;
const int DIR = 4, PWR = 5;

void motor_setup(){
  pinMode(DIR, OUTPUT);
}

void motor_Left(){
  digitalWrite(DIR, HIGH);
  analogWrite(PWR, adequateVoltage);
}
void motor_Right(){
  digitalWrite(DIR, LOW);
  analogWrite(PWR, adequateVoltage);
}
void motor_stop(){
  analogWrite(PWR, 0);
}

void motor_move(double distance, bool right){
  int sec = 5000;
  if (right) motor_Right();
  else motor_Left();
  delay(sec);
  motor_stop();
}
