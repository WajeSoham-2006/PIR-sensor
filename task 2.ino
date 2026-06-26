// ============================================
// Motion Detection System using PIR Sensor
// Arduino UNO
// ============================================

#define PIR_PIN     2
#define RED_LED     8
#define YELLOW_LED  9
#define BUZZER      10

void setup()
{
  pinMode(PIR_PIN, INPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  Serial.begin(9600);

  digitalWrite(RED_LED, LOW);
  digitalWrite(YELLOW_LED, HIGH);
}

void loop()
{
  int motion = digitalRead(PIR_PIN);

  if (motion == HIGH)
  {
    Serial.println("Motion Detected!");

    digitalWrite(RED_LED, HIGH);
    digitalWrite(YELLOW_LED, LOW);

    tone(BUZZER, 1000);
  }
  else
  {
    Serial.println("No Motion");

    digitalWrite(RED_LED, LOW);
    digitalWrite(YELLOW_LED, HIGH);

    noTone(BUZZER);
  }

  delay(500);
}