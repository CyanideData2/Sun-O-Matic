#include <TimeLib.h>
#include <Dictionary.h>

bool is_open = false;
const int maxSize = 25;

struct {
  bool should_open[maxSize];
  int hour[maxSize], minutes[maxSize], dynamicLimit = 0;
} schedule; 

// This whole file assumes that schedule is sent sorted

String scheduler_get() {
  String scheduleReport;
  for (int i = 0; i < schedule.dynamicLimit; i++) {
    scheduleReport += schedule.hour[i] + schedule.minutes[i] + schedule.should_open[i];
  }
  return scheduleReport;
}

void scheduler_update(String scheduleInput) {
  schedule.dynamicLimit = scheduleInput.length() / 3;
  for (int i = 0; i < schedule.dynamicLimit; i ++) {
    schedule.hour[i] = scheduleInput[i*3];
    schedule.minutes[i] = scheduleInput[i*3 + 1];
    schedule.should_open[i] = scheduleInput[i*3 + 2];
  }
}

int findLast(){
  int nowTotalMinutes = minute() + hour() * 60;
  int min = 0, max = schedule.dynamicLimit - 1;
  while (min < max) {
    int  mid =(min + max) / 2, midMinutes = schedule.hour[mid] * 60 + schedule.minutes[mid];
    if(midMinutes <= nowTotalMinutes) min = mid;
    if(midMinutes > nowTotalMinutes) max = mid;
  }
  return min;
}

void scheduler_shouldToggle() {
  int lastState = schedule.should_open[findLast()];
  if (lastState != is_open) return true;
  return false;
}
