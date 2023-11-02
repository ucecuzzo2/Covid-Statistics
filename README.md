# COVID-19 Statistics Analyzer

This C++ project is designed to retrieve and analyze COVID-19 statistics from a data file. This school project encompasses different sorting algorithms from CS 111 (Intro to Computer Science). The overall project allows users to display statistics in a tabular format for various categories and provides functionality to sort, remove, and display statistics for cities severely impacted by COVID-19 within a one-week span of infection surges. This README file provides an overview of the project, its features, and instructions for usage.

## Features

- **Data Retrieval**: The program reads COVID-19 statistics from an input file, which includes information about different cities, such as name, population, and infection statistics for a specific time period.

- **Menu-Based Interface**: The project includes a menu-driven interface to interact with the data. Users can select various commands to perform specific actions.

- **Display Statistics**: Users can display statistics for different categories, such as infection rates, mortality rates, or the number of cases in a tabular format.

- **Sort Data**: The program allows users to sort the data based on different criteria, such as infection rate, mortality rate, or the number of cases. This helps in identifying the most severely impacted cities.

- **Remove Data**: Users can remove cities from the dataset if they wish to focus on specific regions or categories of interest.

- **Identify Surges**: The program can help identify cities that have experienced a one-week surge in COVID-19 infections. This is crucial for tracking regions with rapid virus spread.

## Usage Instructions

1. **Compile the Program**:
   - Use a C++ compiler to compile the source code, ensuring you have the necessary dependencies.

2. **Prepare Data File**:
   - Prepare a data file with the COVID-19 statistics. The data file should have a specific format, including city name, population, and infection statistics for each city.

3. **Run the Program**:
   - Execute the compiled program. You will be presented with a menu.

4. **Select Menu Options**:
   - Use the menu options to perform various operations, such as displaying statistics, sorting data, removing cities, or identifying surges. Follow on-screen instructions to enter relevant information.

5. **View Results**:
   - After performing the desired operations, the program will display the results in a tabular format, making it easy to analyze COVID-19 statistics for different categories.

6. **Repeat as Needed**:
   - Feel free to perform multiple operations and explore the data to gain insights into the COVID-19 impact on different cities.

## Data File Format

The program expects the data file to follow a specific format. Here's an example:

```plaintext
San Diego,California,3347270,3729
136 144 129 160 155 0 281 263 256 152 149 1 561 281
San Francisco,California,883255,544
24 28 20 25 33 34 24 77 23 21 41 39 46 49
...
...
```

---

Thank you for using this COVID-19 Statistics Analyzer. We hope it proves useful for analyzing and understanding the impact of the pandemic on different cities.
