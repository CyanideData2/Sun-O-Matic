#include <TimeLib.h>
#include <Dictionary.h>

const int maxSize = 25;

struct {
  bool should_open[maxSize];
  int hour[maxSize], minutes[maxSize], dynamicLimit = 0;
} schedule; 

void scheduler_synchronize(String timeInput){
  int firstHour = bluetooth_charToInt(timeInput[0]);
  int firstMinute = bluetooth_charToInt(timeInput[1]);
  setTime(firstHour, firstMinute, 0, 1, 1, 2023);
  //Serial.write("Done updating time");
}

String scheduler_get() {
  String scheduleReport;
  for (int i = 0; i < schedule.dynamicLimit; i++) {
    char hour = bluetooth_intToChar(schedule.hour[i]);
    char minutes =  bluetooth_intToChar(schedule.minutes[i]);
    char shouldOpen = bluetooth_intToChar(schedule.should_open[i] % 2);
    scheduleReport += hour;
    scheduleReport += minutes;
    scheduleReport += shouldOpen;
  }
  display(scheduleReport);
  return scheduleReport;
}

void scheduler_update(String scheduleInput) {
  //display("scheduleInput = ");
  //display(scheduleInput);

  schedule.dynamicLimit = scheduleInput.length() / 3;
  //display("dynamicLimit = ");
  //for(int k= 0; k<schedule.dynamicLimit; k++) display("I");
  //display("i = ");

  for (int i = 0; i < schedule.dynamicLimit; i ++) {
    //display("I");
    schedule.hour[i] =  bluetooth_charToInt(scheduleInput[i*3]);
    schedule.minutes[i] = bluetooth_charToInt(scheduleInput[i*3 + 1]);
    schedule.should_open[i] = bluetooth_charToInt(scheduleInput[i*3 + 2]) % 2;
  }
  //display("DONE UPDATING");
}

void scheduler_inizialize(){
  scheduler_synchronize(bluetooth_receive_stream()); 
  bluetooth_send_stream("i" + scheduler_get());
}


int findLast(int minute, int hour){
  int nowTotalMinutes = minute + (hour * 60);
  int min = 0, max = schedule.dynamicLimit - 1;
  //display("We got to the critical point: Binary Search");
  while (min < max) {
    int  mid =(min + max) / 2;
    int midMinutes = (schedule.hour[mid] * 60) + schedule.minutes[mid];
    if(midMinutes <= nowTotalMinutes) min = mid + 1;
    if(midMinutes > nowTotalMinutes) max = mid;
  }
  //display("binary");
  return min;
}

bool scheduler_shouldToggle() {
  if (schedule.dynamicLimit == 0) return false;
  int lastState = schedule.should_open[findLast(minute(), hour())];
  if (lastState != movement_isOpen) return true;
  return false;
}
