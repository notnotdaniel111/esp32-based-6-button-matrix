//libincludes
#include <Arduino.h>

//pindefs
#define GPIO3 3
#define GPIO4 4
#define GPIO5 5
#define GPIO6 6
#define GPIO7 7
#define GPIO10 10
int buttons[6] = {GPIO10, GPIO4, GPIO3, GPIO7, GPIO6, GPIO5};
#define uart_tx 21
#define uart_rx 20

String stage_data(int buttoncheck[6]);

void setup() {
  for (int i = 0; i < 6; i++) {
    pinMode(buttons[i], INPUT_PULLDOWN);
  }
  Serial1.begin(115200, SERIAL_8N1, uart_rx, uart_tx);
  delay(1000);
  Serial1.println("############");
}

void loop() {
  int buttoncheck[6] = {0, 0, 0, 0, 0, 0};
  for (int i = 0; i < sizeof(buttons) / sizeof(buttons[0]); i++) {
    if (digitalRead(buttons[i]) == 1) {
      buttoncheck[i] = 1;
    } else {
      buttoncheck[i] = 0;
    }
  }

  String staged_string = stage_data(buttoncheck);
  Serial1.println(staged_string);
  delay(50);
}

String stage_data(int buttoncheck[6]) {
  String stage_list[6] = {"01", "02", "03", "04", "05", "06"};
  for (int i = 0; i < 6; i++) {
    if (buttoncheck[i] == 1) {
      int pin_ind = i + 1;
      switch (pin_ind) {
        case 1:
          stage_list[0] = "11";
          break;
        case 2:
          stage_list[1] = "12";
          break;
        case 3:
          stage_list[2] = "13";
          break;
        case 4:
          stage_list[3] = "14";
          break;
        case 5:
          stage_list[4] = "15";
          break;
        case 6:
          stage_list[5] = "16";
          break;
      }
    }
  }
  String staged_string;
  for (int i = 0; i < sizeof(stage_list) / sizeof(stage_list[0]); i++) {
    staged_string = staged_string + stage_list[i];
  }
  return staged_string;
}
