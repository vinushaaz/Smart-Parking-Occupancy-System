Let’s turn your project into something that *looks professional on GitHub* 😄🔥
You can copy this directly into your `README.md`.

---

# 🚗 Smart Parking Occupancy System

## 📌 Overview

A real-time IoT-based smart parking system that detects vehicle occupancy using ultrasonic sensors and displays live availability through a dashboard using MQTT communication.

This project demonstrates end-to-end embedded + IoT integration, from sensing to cloud communication and visualization.

---

## 🚀 Features

* 🅿️ Detects parking slot occupancy using ultrasonic sensors
* 📡 Real-time data transmission using MQTT protocol
* 📊 Live dashboard visualization using Node-RED
* 🔄 Multi-slot scalability (supports multiple parking spaces)
* 🌐 Cloud-ready architecture

---

## 🧠 System Architecture

```
Ultrasonic Sensors → ESP32 → MQTT Broker → Node-RED Dashboard
```

---

## 🛠️ Hardware Components

* ESP32 Development Board
* HC-SR04 Ultrasonic Sensors (x2 or more)
* Jumper Wires
* Breadboard

---

## 💻 Software & Tools

* Arduino IDE / Wokwi Simulator
* MQTT Broker (HiveMQ public broker)
* Node-RED Dashboard
* PubSubClient Library

---

## 🔌 Pin Configuration

| Slot   | TRIG Pin | ECHO Pin |
| ------ | -------- | -------- |
| Slot 1 | GPIO 5   | GPIO 18  |
| Slot 2 | GPIO 17  | GPIO 16  |

---

## 📡 MQTT Configuration

* **Broker:** `broker.hivemq.com`
* **Port:** `1883`
* **Topics:**

  * `parkinv/slot1`
  * `parkinv/slot2`

---

## 📊 Dashboard

Built using Node-RED dashboard nodes.

Displays:

* Slot 1 status (🔴 Occupied / 🟢 Free)
* Slot 2 status
* Real-time updates

---

## ⚙️ How It Works

1. Ultrasonic sensors measure distance
2. If distance < threshold → slot is occupied
3. ESP32 processes data
4. Publishes status via MQTT
5. Node-RED subscribes and updates UI

---

## 🧪 Simulation

You can test the project using Wokwi:

👉 [https://wokwi.com/projects/460712436607496193](https://wokwi.com/projects/460712436607496193)

---

## 🔧 Setup Instructions

### 1. Clone Repository

```bash
git clone https://github.com/your-username/smart-parking-system.git
```

---

### 2. Install Libraries

* PubSubClient
* WiFi (built-in for ESP32)

---

### 3. Update WiFi Credentials

```cpp
const char* ssid = "YOUR_WIFI";
const char* password = "YOUR_PASSWORD";
```

---

### 4. Run Code

Upload to ESP32 or run in Wokwi.

---

### 5. Start Node-RED

```bash
node-red
```

Open:

```
http://localhost:1880/ui
```

---

## 📈 Future Enhancements

* 📱 Mobile App Integration
* 🗺️ Parking Map UI
* 🔔 Notifications (slot availability alerts)
* 🔋 Low-power optimization
* 🛰️ LoRa-based long-range communication
* 📊 Data analytics and prediction

---

## 🎯 Learning Outcomes

* Embedded system design with ESP32
* Sensor interfacing
* MQTT protocol and IoT communication
* Real-time dashboard development
* System scalability and architecture

---

## 👩‍💻 Author

**Sai Vinushaa**

---

## ⭐ Project Status

✅ Completed (Core System)
🚀 In Progress (UI enhancements & advanced features)


