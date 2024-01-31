#include <AUnit.h>

test(scheduler_update) {
  String input = "   !!!";
  //display(input);
  scheduler_update(input);

  assertEqual(schedule.hour[0], (int)0);
  assertEqual(schedule.minutes[0], (int)0);
  assertEqual(schedule.should_open[0], false);

  assertEqual(schedule.hour[1], (int)1);
  assertEqual(schedule.minutes[1], (int)1);
  assertEqual(schedule.should_open[1], true);

  assertEqual(schedule.dynamicLimit,  (int)input.length()/ 3);
}

test(scheduler_get) {
  scheduler_update("   !!!");

  assertEqual(scheduler_get(), "   !!!");
}
