const int pingPin1 = 11;
const int pingPin2 = 12;
const int pingPin3 = 13;

void setup() {
  Serial.begin(9600);
}

void loop() {
  long duration1,cm_1;
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
  //Serial.print(" ");
  //Serial.print("cm_1");
  //Serial.println();

      
  long duration2,cm_2;
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

  
  long duration3,cm_3;
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

  delay(1000*60*10);
}
long microsecondsToCentimeters(long microseconds) {
  return microseconds / 29 / 2;
}
