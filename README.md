# 🏨 C++ Hotel Booking System

A console-based hotel management system built in C++ using OOP and linked lists — a university Data Structures course project.

## 📖 About

This system simulates a hotel's back-end management, supporting guest registration, room booking, and admin operations. All data is persisted to plain-text files.

## 🛠️ Tech Stack

- **Language:** C++
- **Concepts:** Object-Oriented Programming, Linked Lists, File I/O
- **IDE:** VS Code

## ✨ Features

- **Guest Management** — Register, login, and manage guest accounts
- **Room Management** — View available rooms and their details
- **Booking System** — Book and cancel room reservations
- **Admin Panel** — Admin login with elevated privileges
- **File Persistence** — All data saved/loaded from `.txt` files
- **Linked List Data Structures** — Custom linked lists for Guests, Rooms, Admins, and Bookings

## 🗂️ Project Structure

```
cpp-hotel-booking-system/
├── Source.cpp        # Full application source code
└── data/
    ├── Admin.txt     # Admin accounts data
    ├── Guest.txt     # Guest accounts data
    ├── Room.txt      # Room inventory data
    └── Booking.txt   # Active bookings data
```

## 🚀 Getting Started

### Prerequisites
- A C++ compiler: `g++` (Linux/Mac) or MSVC (Windows)

### Compile & Run

**Linux / macOS**
```bash
g++ -o hotel Source.cpp
./hotel
```

**Windows (MinGW)**
```bash
g++ -o hotel.exe Source.cpp
hotel.exe
```

> ⚠️ Make sure the `data/` folder with `.txt` files is in the same directory as the executable.

## 🎓 Course

University Data Structures & OOP Course — C++ Project

## 👥 Contributors
   - Gerges ([@Gerges1245](https://github.com/Gerges1245))
   - Mohamed Bahaa ([@MB1382005](https://github.com/MB1382005))
