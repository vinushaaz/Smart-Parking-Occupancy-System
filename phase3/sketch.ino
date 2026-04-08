#include <WiFi.h>
#include <PubSubClient.h>

// Ultrasonic pins
#define TRIG1 5
#define ECHO1 18
#define TRIG2 17
#define ECHO2 16

// WiFi credentials
const char* ssid = "wimanpro";
const char* password = "WtCom@9654=?";

// MQTT broker
const char* mqtt_server = "broker.hivemq.com";

WiFiClient espClient;
PubSubClient client(espClient);

// Distance function (safe + low load)
float getDistance(int trig, int echo) {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);

  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  long duration = pulseIn(echo, HIGH, 30000);
  if (duration == 0) return 999;

  return duration * 0.034 / 2;
}

// Connect WiFi
void setup_wifi() {
  Serial.print("Connecting WiFi");
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi Connected ✅");
}

// Reconnect MQTT
void reconnect() {
  while (!client.connected()) {
    Serial.print("Connecting MQTT...");

    if (client.connect("ESP32Client")) {
      Serial.println("connected ✅");
    } else {
      Serial.print("failed, retry...");
      delay(2000);
    }
  }
}

void setup() {
  Serial.begin(115200);

  pinMode(TRIG1, OUTPUT);
  pinMode(ECHO1, INPUT);
  pinMode(TRIG2, OUTPUT);
  pinMode(ECHO2, INPUT);

  setup_wifi();
  client.setServer(mqtt_server, 1883);
}

void loop() {
  if (!client.connected()) reconnect();
  client.loop();

  float d1 = getDistance(TRIG1, ECHO1);
  delay(60);
  float d2 = getDistance(TRIG2, ECHO2);

  String slot1 = (d1 < 10) ? "occupied" : "free";
  String slot2 = (d2 < 10) ? "occupied" : "free";

  Serial.println("------ Parking Status ------");
  Serial.print("Slot1: "); Serial.println(slot1);
  Serial.print("Slot2: "); Serial.println(slot2);

  // Publish to MQTT
  client.publish("parkingv/slot1", slot1.c_str());
  client.publish("parkingv/slot2", slot2.c_str());

  Serial.println("Data sent to MQTT 🌐");
  Serial.println("----------------------------\n");

  delay(3000);
}