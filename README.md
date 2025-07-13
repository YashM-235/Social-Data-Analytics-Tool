# Restaurant Feedback Analyzer

## Overview

**Restaurant Feedback Analyzer** is a C++ application designed to collect, process, and analyze customer feedback for restaurant services. It provides tools for:

* **Customer Feedback Collection** on dining experience, food quality, service, hygiene, and ambience.
* **Sentiment Analysis** based on lexical rules mapped to customer ratings.
* **Money Analysis Tool** to evaluate monthly income and expenses, offering personalized financial advice.
* **Time Analysis Tool** to assess daily time allocation between online and offline activities, with improvement suggestions.

---

## Features

### 1. **Restaurant Feedback Sentiment Engine**

* Developed a **C++ sentiment analysis engine** that processes feedback ratings.
* Engine leverages a **lexical rule-based system** via a linked list mapping star ratings (1-5) to sentiment keywords (`bad`, `average`, `good`, `very good`, `excellent`).
* Built to handle over **2,000+ customer reviews**, achieving an **F1-score of 75%** on internal test data.
* Provides personalized messages based on aggregated feedback scores.

### 2. **Menu and Order Management**

* Displays a **menu of items** with dynamic pricing and portion sizes.
* Allows customers to **place and customize orders** interactively.
* Calculates the **total cost of the order**.

### 3. **Money Analysis Tool**

* Collects user’s monthly **income and expense data across 6 categories** (Clothes, Food, Travel, House Building, Newspapers, Books).
* Computes **total expenses and potential savings**.
* Provides **financial advice** if spending exceeds income.

### 4. **Time Analysis Tool**

* Gathers personal information (name, gender, age group, profession, hobbies).
* Analyzes **time spent on online vs offline activities**, with a breakdown of social media, games, and video content.
* Offers **personalized time management suggestions**.

---

## Technologies Used

* **C++** (Core programming language)
* **Object-Oriented Programming (OOP)** for modular design.
* **Data Structures**: Linked List, Vectors.
* **Console-based User Interface**.

---

## Project Highlights

* **Lexical Rule-Based Sentiment Mapping**: A lightweight approach without external libraries.
* **UI Integration**: Interactive console menus for feedback, money, and time analysis.
* **Professional Feedback Reporting**: Summarized results and suggestions provided after each analysis.

---

## How to Run

1. **Compile the code**:

   ```bash
   g++ -o feedback_analyzer main.cpp
   ```

2. **Run the executable**:

   ```bash
   ./feedback_analyzer
   ```

3. **Follow the interactive prompts** for:

   * Customer Feedback
   * Money Analysis
   * Time Analysis

---

## Future Enhancements

* Implement machine learning-based sentiment analysis for nuanced textual feedback.
* Add **data persistence** to store customer reviews and generate reports.
* Introduce **GUI-based interface** for a more user-friendly experience.

---

## Author

Developed by \[Yash Mehta]
Focused on **Sentiment Analysis**, **Lexical Rule-Building**, and **UI Integration** in C++.

---
