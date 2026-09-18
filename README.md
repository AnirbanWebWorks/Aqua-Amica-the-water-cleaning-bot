🌊 AI-Based Autonomous River Cleaning Robot with Smart Waste Segregation and Water Quality Monitoring
📌 Overview

The AI-Based Autonomous River Cleaning Robot is an intelligent floating robotic platform designed to automatically detect, collect, and segregate floating waste from water bodies while simultaneously monitoring water quality in real time.

The system utilizes Computer Vision, IoT, Embedded Systems, and Environmental Monitoring technologies to improve river cleanliness and reduce manual intervention.

The robot autonomously detects waste using an ESP32-CAM, navigates toward the detected object, collects it using a conveyor mechanism, segregates metallic and non-metallic waste, and continuously measures water quality using TDS and Turbidity sensors.

🚀 Key Features
♻️ Autonomous Waste Detection
Real-time waste detection using ESP32-CAM
Computer Vision-based object tracking
Autonomous navigation toward floating waste
🛶 Waste Collection System
Conveyor belt mechanism for waste pickup
Automatic activation upon waste detection
Floating PVC frame with buoyancy support
🗑️ Smart Waste Segregation
Inductive proximity sensor for metal detection
Automatic sorting into:
Metallic Waste Bin
Non-Metallic Waste Bin
Servo-controlled segregation gate
💧 Water Quality Monitoring
Real-time TDS measurement
Real-time Turbidity measurement
Water quality classification:
Clean
Moderate
Polluted
📡 IoT Integration
Live sensor monitoring
Cloud-based data logging
Environmental data analytics
🎯 Objectives
Remove floating waste from rivers, ponds, and lakes.
Reduce manual cleaning efforts.
Improve environmental sustainability.
Monitor water quality continuously.
Segregate collected waste automatically.
Generate useful environmental data.
🏗️ System Architecture
                    +----------------+
                    |   ESP32-CAM    |
                    | Waste Detection|
                    +-------+--------+
                            |
                            |
                            v
                    +----------------+
                    | Arduino UNO    |
                    | Main Controller|
                    +-------+--------+
                            |
     ------------------------------------------------
     |              |             |                 |
     v              v             v                 v

+---------+   +-----------+  +---------+   +---------------+
| Motors  |   | Conveyor  |  | Servo   |   | LCD Display   |
+---------+   +-----------+  +---------+   +---------------+

     |              |             |
     |              |             |
     v              v             v

+-----------+ +-------------+ +----------------+
| IR Sensor | | Inductive   | | TDS/Turbidity |
+-----------+ | Sensor      | +----------------+
              +-------------+
🔄 Working Principle
Step 1: Water Quality Monitoring

The robot continuously measures:

TDS (Total Dissolved Solids)
Turbidity

Water quality information is displayed on the LCD and can be transmitted to an IoT platform.

Step 2: Waste Detection

The ESP32-CAM continuously scans the water surface.

When floating waste is detected:

Waste position is calculated.
Navigation commands are sent to Arduino UNO.

Commands:

F → Forward
L → Left
R → Right
S → Stop
C → Waste Captured
Step 3: Autonomous Navigation

The robot moves toward the detected waste using differential drive motors.

Step 4: Waste Collection

Once the waste reaches the conveyor zone:

Drive motors stop.
Conveyor motor starts.
Waste is lifted into the collection chamber.
Step 5: Waste Detection on Conveyor

The top IR sensor detects incoming waste.

Upon detection:

Conveyor motor stops.
Sorting sequence starts.
Step 6: Waste Segregation

An inductive proximity sensor determines whether the waste is metallic.

Metallic Waste
Metal Detected
↓
Servo Opens Metal Bin
↓
Waste Deposited
Non-Metallic Waste
Non-Metal Detected
↓
Servo Opens Non-Metal Bin
↓
Waste Deposited
Step 7: Resume Operation

The servo returns to the home position and the robot resumes searching for waste.

🧠 Technologies Used
Technology	Purpose
Computer Vision	Waste Detection
Embedded Systems	Control System
IoT	Remote Monitoring
Automation	Waste Collection
Robotics	Autonomous Navigation
Environmental Monitoring	Water Quality Analysis
🔧 Hardware Components
Controller
Arduino UNO
ESP32-CAM
Sensors
IR Sensor
Inductive Proximity Sensor
Turbidity Sensor
TDS Sensor
Actuators
DC Motors
Conveyor Motor
Servo Motor
Display
16x2 I2C LCD
Power System
Battery Pack
Voltage Regulation Circuit
Mechanical Structure
PVC Pipe Frame
Floating Bottles/Pontoons
Waste Collection Basket
Conveyor Assembly
📊 Water Quality Classification
TDS (ppm)	Turbidity	Water Status
< 300	Low	Clean
300 – 600	Medium	Moderate
> 600	High	Polluted

📈 Future Improvements
YOLO-based waste classification
GPS-based autonomous navigation
Obstacle avoidance system
Cloud dashboard
Mobile application
Solar-powered charging system
AI-based pollution prediction
Multi-category waste segregation
🏆 Applications
River Cleaning
Lake Cleaning
Pond Cleaning
Smart City Projects
Environmental Monitoring
Research and Education
Waste Management Systems
📚 Research Contribution

This project integrates:

Artificial Intelligence
Computer Vision
IoT
Embedded Systems
Robotics
Environmental Monitoring

into a single autonomous platform for sustainable water resource management.
