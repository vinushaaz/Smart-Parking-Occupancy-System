  #define TRIG1 5
#define ECHO1 18

#define TRIG2 17
#define ECHO2 16

// Safe distance function
float getDistance(int trig, int echo) {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);

  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  long duration = pulseIn(echo, HIGH, 30000); // timeout added

  if (duration == 0) return 999; // no signal (safe fallback)

  float distance = duration * 0.034 / 2;
  return distance;
}

void setup() {
  Serial.begin(115200);

  pinMode(TRIG1, OUTPUT);
  pinMode(ECHO1, INPUT);

  pinMode(TRIG2, OUTPUT);
  pinMode(ECHO2, INPUT);
}

void loop() {
  Serial.println("---- Parking Status ----");

  float d1 = getDistance(TRIG1, ECHO1);
  delay(60);  // spacing between sensors

  float d2 = getDistance(TRIG2, ECHO2);
  delay(60);

  // Slot 1
  if (d1 < 10)
    Serial.println("Slot 1: 🚗 OCCUPIED");
  else
    Serial.println("Slot 1: 🟢 FREE");

  // Slot 2
  if (d2 < 10)
    Serial.println("Slot 2: 🚗 OCCUPIED");
  else
    Serial.println("Slot 2: 🟢 FREE");

  // Count free slots
  int freeSlots = 0;
  if (d1 >= 10) freeSlots++;
  if (d2 >= 10) freeSlots++;

  Serial.print("Total Free Slots: ");
  Serial.println(freeSlots);

  Serial.println("------------------------\n");

  delay(2000); // slow loop = low load
}