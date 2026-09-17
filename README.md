# 🌊 Aqua Amica — Autonomous Water Cleaning & Quality Monitoring Bot

> An IoT-powered robotic system that collects floating waste from water bodies, segregates it into metallic and non-metallic categories, and monitors water quality in real time — powered by solar energy and controlled over long-range (LoRa) communication.

**🌍 International Recognition** — Outstanding Project, BRICS IIC (China) | **🏆 Granted Indian Patent** — Publication No. `IN202531062030 A1` | **📄 Published Research** — *National Conference on Communication, Computing and IoT (NCCCI-2025)*, Chapter 92, ISBN 978-93-6135-445-8

---

## 📖 Overview

Water pollution from floating debris — plastics, organic waste, and metallic scrap — is a growing environmental problem that manual and conventional cleaning methods can't scale to address. **Aqua Amica** is a semi-autonomous water cleaning bot designed to operate on rivers, lakes, and ponds. It combines:

- **Automated waste collection** via a conveyor belt system
- **Smart waste segregation** into metallic vs. non-metallic compartments
- **Real-time water quality monitoring** (pH, TDS, turbidity)
- **Solar-powered operation** for sustainability and low running cost
- **LoRa-based long-range communication** for navigation and data transmission
- **Android app control interface** for the human operator

The system was developed as a research and patent project at Narula Institute of Technology and has been peer-reviewed and published, in addition to being granted an Indian patent application.

---

## 🎥 Demo

> *Add a photo/GIF/video of the working prototype here — this is the single highest-impact addition to this README.*

```
[ prototype photo / demo GIF / YouTube link ]
```

---

## ❓ Problem It Solves

Urbanization and industrial growth have accelerated the accumulation of plastics and organic waste in water bodies, degrading water quality and harming aquatic ecosystems. Conventional cleaning is manual, slow, and doesn't scale. Aqua Amica offers a **low-cost, solar-powered, single-operator solution** that combines waste collection, intelligent sorting, and continuous water quality assessment — making conservation efforts more efficient and scalable.

---

## ✨ Features

- 🧲 **Inductive proximity sensing** — detects and classifies metallic debris for automatic segregation
- 🌫️ **Real-time water quality metrics** — pH, Total Dissolved Solids (TDS), and turbidity monitoring
- 🛞 **Automated conveyor belt** — continuously collects floating waste from the water surface
- 🔀 **Servo-based sorting mechanism** — routes waste into metallic (right) / non-metallic (left) compartments
- 📡 **LoRa long-range communication** — reliable navigation and data link over extended distances
- ☀️ **Solar-powered** — sustainable, low operating cost, suited for long-term deployment
- 📷 **ESP32-CAM with object detection** — helps the bot detect and navigate toward floating waste
- 📱 **Android app interface** — human-in-the-loop control for navigation and operation
- 🧱 **Modular design** — sensors and components can be replaced/upgraded independently
- 🧪 **Rust-resistant, durable build** — designed for freshwater and marine environments

---

## 🛠️ Hardware & Tech Stack

| Category | Components |
|---|---|
| **Microcontroller** | ESP8266 (main controller, IoT connectivity) |
| **Camera/Vision** | ESP32-CAM (object detection & navigation) |
| **Sensors** | pH sensor, TDS sensor, Turbidity sensor, Inductive Proximity sensor, IR sensor |
| **Actuation** | DC motor + motor driver (conveyor belt), Servo motors (waste sorting) |
| **Communication** | LoRa module (long-range navigation/data), Android app (operator control) |
| **Power** | Solar panel + battery system |
| **Output/Display** | LCD (status/readings display) |

---

## 🧩 System Architecture

```
                     ┌──────────────┐
                     │  POWER SUPPLY │ (Solar)
                     └──────┬───────┘
                            │
  ┌───────────┐      ┌──────▼───────┐      ┌────────┐
  │ pH Sensor  ├─────►│               ├─────►│  LCD   │
  ├───────────┤      │               │      └────────┘
  │ Inductive  ├─────►│               │
  │ Proximity  │      │ MICROCONTROLLER├─────►│ Object      │
  ├───────────┤      │   (ESP8266)   │      │ Detection   │
  │ Turbidity  ├─────►│               │      │ (ESP32-CAM) │
  ├───────────┤      │               │
  │ TDS Sensor ├─────►│               ├─────►┌─────────────────┐
  ├───────────┤      │               │      │ Segregation      │
  │ IR Sensor  ├─────►│               │      │ System (Servo)   ├──► Metallic Waste
  └───────────┘      └──────┬────────┘      └─────────────────┘└─► Non-Metallic Waste
                            │
              ┌─────────────┴──────────────┐
              ▼                             ▼
       ┌─────────────┐             ┌──────────────────┐
       │ Motor Driver │             │ Long Range (LoRa) │
       │  → Motor     │             │  Comm. Module     │
       └─────────────┘             └──────────────────┘
```

*(Replace this ASCII diagram with the actual block diagram image from the paper/patent — see `Fig 1: Block diagram of the proposed Bot`.)*

---

## ⚙️ How It Works

1. **Detection** — The IR sensor detects incoming floating waste and triggers the segregation subsystem.
2. **Collection** — A conveyor belt, driven by a motor and motor driver, continuously gathers surface waste.
3. **Classification** — The inductive proximity sensor determines whether the waste is metallic or non-metallic.
4. **Sorting** — Based on the classification, a servo motor diverts the waste: **right compartment → metallic**, **left compartment → non-metallic**.
5. **Water Quality Monitoring** — The pH, TDS, and turbidity sensors continuously sample the surrounding water and report readings.
6. **Navigation & Comms** — The ESP32-CAM performs object detection to help steer toward waste; the LoRa module handles long-range communication back to the operator/base station.
7. **Control** — The human operator monitors and controls bot movement through an Android application.
8. **Power** — The entire system runs on solar power, supporting long-duration, low-cost deployment.

---

## 📦 Repository Structure

```
aqua-amica/
├── README.md
├── /firmware              # ESP8266 / ESP32-CAM source code
├── /hardware
│   ├── circuit-diagram/   # Wiring & schematic diagrams
│   └── bom.md             # Bill of materials
├── /android-app           # Android control app source (if included)
├── /docs
│   ├── conference-paper.pdf
│   └── patent-application.pdf
├── /images                # Prototype photos, block diagrams, demo GIFs
├── requirements.txt / platformio.ini
└── LICENSE
```

---

## 🚀 Setup & Installation

> Fill in exact steps once firmware/code is added to the repo. Suggested structure below:

```bash
# Clone the repository
git clone https://github.com/<your-username>/aqua-amica.git
cd aqua-amica

# Flash firmware to ESP8266 (example using PlatformIO)
platformio run --target upload

# Flash ESP32-CAM for object detection module
# (see /firmware/esp32-cam for instructions)
```

**Hardware assembly:** refer to `/hardware/circuit-diagram` for wiring the sensors, motor driver, and LoRa module to the ESP8266.

---

## 📊 Results

- Experimentally validated for **effectiveness, scalability, and long-term deployment potential** in aquatic pollution control (per published conference paper).
- Successfully demonstrated **automated metal/non-metal waste segregation** using IR + inductive proximity sensing.
- Real-time water quality data acquisition (pH, TDS, turbidity) validated for environmental assessment use cases.

*(Add specific numbers if available: sorting accuracy %, battery life, operating range via LoRa, waste collection rate, etc.)*

---

## 🏅 Recognition

- **🌍 International Recognition — BRICS IIC** — Recognized as an **outstanding project** at the BRICS International Innovation Competition, with the team representing India in China
- **Indian Patent Application** — *"Design and Development of a Water Cleaning Bot for all Water Bodies"*, Publication No. `IN202531062030 A1`, filed by Narula Institute of Technology (2025)
- **Published Research** — *"Design and Development of a Robotic Solution for Water Surface Pollution Control"*, National Conference on Communication, Computing and IoT (NCCCI-2025), AkiNik Publications, Chapter 92, DOI: [10.22271/ed.book.3224](https://doi.org/10.22271/ed.book.3224)

**Authors/Inventors:** Dr. Bikas Mondal, Mrs. Sanghamitra Layek, Anirban Saha, Somshubhra Bose, Anushka Bharati, Devdipro Bhaduri, Sayan Bag, Soumya Bhattacharyya, Dr. Sourav Saha

---

## 🔭 Future Improvements

- Fully autonomous navigation (currently Android-app-operator-assisted)
- On-board microplastic filtration enhancements
- Expanded pollutant sensor suite (e.g., dissolved oxygen, temperature)
- Cloud dashboard for remote, multi-bot fleet monitoring
- Battery/solar efficiency optimization for extended deployment

---

## 📄 License

*(Add a license — e.g., MIT for the codebase. Note: since this work is tied to a patent application, consult with co-inventors/institution before choosing a license for public release.)*

---

## 🙏 Credits

Developed at **Narula Institute of Technology, Kolkata** as part of ongoing research into IoT-based environmental robotics.
