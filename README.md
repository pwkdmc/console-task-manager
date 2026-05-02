# Console Utility Toolkit 🛠️
A collection of six interactive C++ console applications demonstrating fundamental programming concepts: algorithms, data structures, input validation, and real-time user interaction.
## 🌟 Overview
This project is a compilation of standalone utility programs, each focusing on a specific practical task. Built with procedural C++ and modular design, the applications feature robust user input handling, algorithm implementation, and cross-platform console interaction.
## 🧩 Applications
### 🔐 Random Password Generator
Generates cryptographically-themed passwords with customizable complexity:
- **Length**: 6–32 characters
- **Character types**: Digits, lowercase letters, uppercase letters, special symbols
- **Complexity analysis**: Scores passwords as Weak / Medium / Strong based on length and character variety
- **Flexible input**: Enter desired character types as a compact number string (e.g., `123` for digits + lowercase + uppercase)
### 🔢 Number System Converter
Converts integers between arbitrary bases (2 through 16):
- Supports negative numbers
- Handles hexadecimal notation (A–F)
- Performs two-step conversion: source base → decimal → target base
- Validates input digits against the source base
### 🏧 ATM Simulator
A simplified banking terminal with a persistent account balance:
- **Withdraw cash** — with balance validation
- **Deposit funds** — top up the account
- **Operation limit** — maximum 10 transactions per session
- **Balance tracking** — account state persists across menu navigation
### 🪨📄✂️ Rock, Paper, Scissors
A classic game against an AI opponent with three difficulty levels:
- **Easy** — completely random computer choices
- **Medium** — computer counters the player's previous move
- **Hard** — adaptive AI that analyzes move frequency patterns and counter-plays the most used option
- Real-time score tracking with win/loss/draw statistics
- Win rate percentage calculation
### 📝 Text Analyzer
Comprehensive text statistics tool supporting both English and Russian (Cyrillic) text:
- **Character count** — total and excluding spaces
- **Word count** — handles hyphenated words and apostrophes
- **Sentence count** — detects `.`, `!`, `?` terminators
- **Longest and shortest word** identification
- **Letter frequency analysis** — case-insensitive histogram
- **Palindrome detection** — ignores case, spaces, and punctuation
### ⏱️ Countdown Timer with Notifications
Real-time countdown timer with keyboard controls using `<conio.h>`:
- **Single timer mode** — countdown from 10 to 3600 seconds
- **Interval timer mode** — repeating cycles (1–20 repetitions, 5–600 sec each)
- **Progressive notifications** — alerts at 50%, 25%, and 10% remaining
- **Pause/Resume** — toggle with Space bar
- **Cancel** — quit with Q key
- Displays remaining time in `Xm Ys` format
## 🎯 Key Features Across All Applications
- **Comprehensive input validation** — type checking, range checking, format validation
- **Infinite retry on bad input** — user never forced to restart on error
- **Repeatable tasks** — each application loops until user chooses exit
- **Russian language UI** — all prompts and messages in Russian
- **Consistent UX pattern** — numbered menus with `0` as exit
- **Clean compilation** — headers use `#pragma once`, no circular dependencies
## 📄 License
The project is intended for educational purposes. It can be used and modified freely.