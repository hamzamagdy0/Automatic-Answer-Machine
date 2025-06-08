# Automatic Answer Machine

A Java-based (or Android/other) application that automatically answers incoming calls (or messages) and can record or respond based on your defined rules, streamlining your communication system.

## 🎯 Features

- **Automatic Call/Message Response**  
  - Answers calls after a specified delay (e.g., 15 seconds)  
  - Records caller's voice or sends a predefined response

- **Configurable Settings**  
  - Customize delay time before answering  
  - Set maximum recording duration  
  - Play a custom greeting or automated message

- **Logging & History**  
  - Keeps a log of answered calls/messages with timestamps and duration  
  - Optionally export logs for review

- **Optional GUI Interface** (if applicable)  
  - Simple interface to view call history, adjust settings, and enable/disable the service

## 🛠️ Tech Stack

| Component       | Technology                        |
|----------------|-----------------------------------|
| Language        | Java (Swing, Android, or pure Java) |
| Storage         | File-based (`.bin` files) or simple SQLite, JSON |
| Audio Recording | Java Sound API or Android MediaRecorder |
| Build Tool      | IntelliJ IDEA or similar Java IDE |

## 📁 Project Structure
Automatic-Answer-Machine/

├── src/ # Source code

│ ├── model/ # Data structures: CallRecord, Settings, etc.

│ ├── service/ # Core logic: answering, recording, rules

│ ├── ui/ # GUI components (if any)

│ └── util/ # File I/O, logging utilities

├── data/ # Storage files (e.g., logs, settings)

├── resources/ # Audio files, config files, images

├── README.md

└── Automatic-Answer-Machine.iml



## 🚀 Getting Started

### Prerequisites

- **Java JDK 8+**  
- **IntelliJ IDEA** (or any Java IDE)  
- If Android: **Android SDK + Java/Kotlin**

### Installation & Running

1. Clone the repository:
   ```bash
   git clone https://github.com/hamzamagdy0/Automatic-Answer-Machine.git

📝 License
For educational use only. For commercial use, please contact the author.
