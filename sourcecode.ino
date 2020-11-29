#include <LiquidCrystal.h>


#define D4 5
#define D5 4
#define D6 3
#define D7 2
#define E 8
#define RS 9


LiquidCrystal lcd(RS, E, D4, D5, D6, D7);  

const int pingPin1 = 11;
const int pingPin2 = 12;
const int pingPin3 = 13;
long duration1,cm_1;
long duration2,cm_2;
long duration3,cm_3;

// 동그라미
byte newChar0[8] = {
        B01110,
        B11011,
        B10001,
        B10001,
        B10001,
        B10001,
        B11011,
        B01110
};


// X 
byte newChar1[8] = {
        B10001,
        B10001,
        B01010,
        B00100,
        B01010,
        B10001,
        B10001,
        B00000
};


void setup() { 
  	Serial.begin(9600);
	lcd.begin(16,2);
    lcd.createChar(0, newChar0);
  	lcd.createChar(1, newChar1);
  	lcd.clear();
  	lcd.print("Student List");
}
 
void loop() {  
  	start_detect(); // 감지시작
  	lcd.setCursor(0,1);
  	lcd.print("1:   2:   3:   ");
  
  	// 1번 학생이 자리에 없다면 X로 바꿈, 있으면  O로 바꿈.
  	if(cm_1 > 100){
      lcd.setCursor(2,1);
      lcd.write(byte(1));
    } else{
      lcd.setCursor(2,1);
      lcd.write(byte(0));
    }
  
  	// 2번 학생이 자리에 없다면 X로 바꿈, 있으면  O로 바꿈.
  	if(cm_2 > 100){
      lcd.setCursor(7,1);
      lcd.write(byte(1));
    } else{
      lcd.setCursor(7,1);
      lcd.write(byte(0));
    }
  
  	// 3번 학생이 자리에 없다면 X로 바꿈, 있으면  O로 바꿈.
  	if(cm_3 > 100){
      lcd.setCursor(12,1);
      lcd.write(byte(1));
    } else{
      lcd.setCursor(12,1);
      lcd.write(byte(0));
    }
  	delay(1000);
}

void start_detect(){
  pinMode(pingPin1, OUTPUT);
  digitalWrite(pingPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin1, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin1, LOW);

  pinMode(pingPin1, INPUT);
  duration1 = pulseIn(pingPin1, HIGH);

  cm_1 = microsecondsToCentimeters(duration1);
  Serial.print(cm_1);
  Serial.print(" ");
  //Serial.print("cm_1");
  //Serial.println();

  pinMode(pingPin2, OUTPUT);
  digitalWrite(pingPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin2, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin2, LOW);

  pinMode(pingPin2, INPUT);
  duration2 = pulseIn(pingPin2, HIGH);

  cm_2 = microsecondsToCentimeters(duration2);
  Serial.print(cm_2);
  Serial.print(" ");
  //Serial.print("cm_2");
  //Serial.println();

  
  pinMode(pingPin3, OUTPUT);
  digitalWrite(pingPin3, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin3, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin3, LOW);

  pinMode(pingPin3, INPUT);
  duration3 = pulseIn(pingPin3, HIGH);

  cm_3 = microsecondsToCentimeters(duration3);
  Serial.print(cm_3);
  //Serial.print("cm_3");
  Serial.println();

}

long microsecondsToCentimeters(long microseconds) {
  return microseconds / 29 / 2;
}
