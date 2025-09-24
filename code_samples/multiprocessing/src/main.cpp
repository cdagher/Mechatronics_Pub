#include <Arduino.h>

long func_1_last_run;
long func_2_last_run;

long func_1_delay = 1000; // run every 1 s
long func_2_delay = 50; // Run every 50 ms

void func1(); // one independent process
void func2(); // 2nd independent process

void setup() {
  func1();
  func_1_last_run = millis(); // Millisecond precision is good

  func2();
  func_2_last_run = millis();
}

void loop() {
  long now = millis(); // 100

  if (now - func_1_last_run >= func_1_delay) {
    func1(); // 3 ms to run
    func_1_last_run = now; // func_1_last_run = 100
  }

  // now time is 103

  if (now - func_2_last_run >= func_2_delay) {
    func2(); // 1 ms to run
    func_2_last_run = now; // func_2_last_run = 100
  }
}
