//libincludes
#include <Arduino.h>

//pindefs
#define GPIO5 5
#define GPIO6 6
#define GPIO7 7
#define GPIO8 8
#define GPIO9 9
#define GPIO10 10
int buttons[6] = {GPIO10,GPIO9,GPIO8,GPIO7,GPIO6,GPIO5};
#define uart_tx 21
#define uart_rx 20

String stage_data(String pin_bool, int pin_num);

void setup() {
  pinMode(GPIO5, INPUT);
  pinMode(GPIO6, INPUT);
  pinMode(GPIO7, INPUT);
  pinMode(GPIO8, INPUT);
  pinMode(GPIO9, INPUT);
  pinMode(GPIO10, INPUT);
  pinMode(uart_tx, OUTPUT);
  pinMode(uart_rx, INPUT);  
  Serial.begin(115200); //Serial1 (communicate through the pins) for prod, serial for testing (usb)
}

void loop() {
  int buttoncheck[6] = {0,0,0,0,0,0};
  for (int i = 0;i<sizeof(buttons)/ sizeof(buttons[0]);i++) {
    if (digitalRead(buttons[i]) == 1) {
      buttoncheck[i] = 1; 
    }
    else {
      buttoncheck[i] = 0;
          }
  }
  for (int i2 = 0; i2 <(sizeof(buttoncheck)/ sizeof(buttoncheck[0]))+1;i2++) {
    if (i2<=6 && buttoncheck[i2] == 1) {
      int pin_ind = i2 + 1; 
      stage_data(String(buttoncheck[i2]),pin_ind);
    }
    else {
      continue;
    }
    Serial.println();
  }
}

String stage_data(String pin_bool, int pin_num) {
  String stage_list[6] = {"01","02","03","04","05","06"} ;
  switch (pin_num) {
    case 1:
      stage_list[0] = "11";    
    case 2:
      stage_list[1] = "12";
    case 3:
      stage_list[2] = "13";
    case 4:
      stage_list[3] = "14";
    case 5:
      stage_list[4] = "15";
    case 6:
      stage_list[5] = "16";
  }
  String staged_string;
  for (int i = 0; i < sizeof(stage_list)/sizeof(stage_list[0]);i++) {
    staged_string = staged_string + stage_list[i];
  } 
  return staged_string;
}