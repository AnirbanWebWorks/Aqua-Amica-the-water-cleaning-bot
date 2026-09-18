# 🤖 Aqua Amica — AI-Based Autonomous River Cleaning Robot

**Smart Waste Segregation & Real-Time Water Quality Monitoring**

![Prototype](images/prototype.png)

---

## 📌 Overview

**Aqua Amica** is an intelligent floating robotic platform designed to automatically detect, collect, and segregate floating waste from water bodies while simultaneously monitoring water quality in real time.

The system combines **Computer Vision, IoT, Embedded Systems, and Environmental Monitoring** to improve river cleanliness and reduce manual intervention.

The robot autonomously detects waste using an **ESP32-CAM**, navigates toward it, collects it via a **conveyor mechanism**, segregates **metallic vs. non-metallic waste**, and continuously measures water quality using **TDS** and **Turbidity** sensors.

> 🏆 Recognized with a granted Indian patent application and international recognition at BRICS IIC.

---

## 🚀 Key Features

### ♻️ Autonomous Waste Detection
- Real-time waste detection using ESP32-CAM
- Computer vision–based object tracking
- Autonomous navigation toward floating waste

### 🛶 Waste Collection System
- Conveyor belt mechanism for waste pickup
- Automatic activation upon waste detection
- Floating PVC frame with buoyancy support

### 🗑️ Smart Waste Segregation
- Inductive proximity sensor for metal detection
- Automatic sorting into:
  - Metallic Waste Bin
  - Non-Metallic Waste Bin
- Servo-controlled segregation gate

### 💧 Water Quality Monitoring
- Real-time TDS measurement
- Real-time Turbidity measurement
- Water quality classification: **Clean / Moderate / Polluted**

### 📡 IoT Integration
- Live sensor monitoring
- Cloud-based data logging
- Environmental data analytics

---

## 🎯 Objectives

- Remove floating waste from rivers, ponds, and lakes
- Reduce manual cleaning efforts
- Improve environmental sustainability
- Monitor water quality continuously
- Segregate collected waste automatically
- Generate useful environmental data

---

## 🏗️ System Architecture

![Block Diagram](images/block_diagram.png)

The system is built around a central microcontroller that interfaces with a suite of sensors (pH, TDS, Turbidity, Inductive Proximity, IR), a camera-based object detection module, an LCD for local readouts, a long-range communication module for remote monitoring, and a motor driver controlling the drive motors. Detected waste is routed through the segregation system into metallic or non-metallic bins.

---

## 🔄 Working Principle — Flowchart

![Flowchart](images/flowchart.png)

### Step 1: Water Quality Monitoring
The robot continuously measures **TDS (Total Dissolved Solids)** and **Turbidity**. This runs in parallel with waste detection and is displayed on the LCD / sent to the IoT platform.

### Step 2: Waste Detection
The ESP32-CAM continuously scans the water surface. When floating waste is detected, its position is calculated and navigation commands are sent to the Arduino UNO:

| Command | Action |
|---------|--------|
| `F` | Forward |
| `L` | Left |
| `R` | Right |
| `S` | Stop |
| `C` | Waste Captured |

### Step 3: Autonomous Navigation
The robot moves toward the detected waste using differential drive motors.

### Step 4: Waste Collection
Once the waste reaches the conveyor zone:
- Drive motors stop
- Conveyor motor starts
- Waste is lifted into the collection chamber

### Step 5: Waste Detection on Conveyor
The top IR sensor detects incoming waste. Upon detection, the conveyor motor stops and the sorting sequence begins.

### Step 6: Waste Segregation
An inductive proximity sensor determines whether the waste is metallic:

- **Metallic Waste** → Metal detected → Servo opens Metal Bin → Waste deposited
- **Non-Metallic Waste** → No metal detected → Servo opens Non-Metal Bin → Waste deposited

### Step 7: Resume Operation
The servo returns to the home position and the robot resumes searching for waste.

---

## 🧠 Technologies Used

| Technology | Purpose |
|---|---|
| Computer Vision | Waste Detection |
| Embedded Systems | Control System |
| IoT | Remote Monitoring |
| Automation | Waste Collection |
| Robotics | Autonomous Navigation |
| Environmental Monitoring | Water Quality Analysis |

---

## 🔧 Hardware Components

**Controller**
- Arduino UNO
- ESP32-CAM

**Sensors**
- IR Sensor
- Inductive Proximity Sensor
- Turbidity Sensor
- TDS Sensor
- pH Sensor

**Actuators**
- DC Motors
- Conveyor Motor
- Servo Motor

**Display**
- 16x2 I2C LCD

**Power System**
- Battery Pack
- Voltage Regulation Circuit

**Mechanical Structure**
- PVC Pipe Frame
- Floating Bottles/Pontoons (as buoyancy)
- Waste Collection Basket
- Conveyor Assembly

---

## 📊 Water Quality Classification

| TDS (ppm) | Turbidity | Water Status |
|---|---|---|
| < 300 | Low | Clean |
| 300 – 600 | Medium | Moderate |
| > 600 | High | Polluted |

---



## 📈 Future Improvements

- YOLO-based waste classification
- GPS-based autonomous navigation
- Obstacle avoidance system
- Cloud dashboard
- Mobile application
- Solar-powered charging system
- AI-based pollution prediction
- Multi-category waste segregation

---

## 🏆 Applications

- River Cleaning
- Lake Cleaning
- Pond Cleaning
- Smart City Projects
- Environmental Monitoring
- Research and Education
- Waste Management Systems

---

## 📚 Research Contribution

This project integrates **Artificial Intelligence, Computer Vision, IoT, Embedded Systems, Robotics,** and **Environmental Monitoring** into a single autonomous platform for sustainable water resource management.

- Granted Indian patent application (IN202531062030 A1), filed via Narula Institute of Technology
- Published as a conference paper at NCCCI-2025 (National Conference on Communication, Computing and IoT)
- International recognition as an outstanding project at BRICS IIC

---

## 👨‍💻 Author

**Anirban Saha**
B.Tech in Electronics & Instrumentation Engineering (EIE)
Narula Institute of Technology

**Connect With Me**
- GitHub: [AnirbanWebWorks](https://github.com/AnirbanWebWorks)
- LinkedIn: *(Add your LinkedIn URL here)*
