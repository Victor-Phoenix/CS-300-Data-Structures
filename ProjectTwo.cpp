// 2/25/25 Victor Tran, CS 300
// Advising Assistance Program
// This program allows users to load a course data file, display a sorted list of courses,
// and retrieve course details and prerequisites. The data is stored in a hash table
// for efficient searching and retrieval.

#include <direct.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to store course information
struct Course {
    string courseNumber;
    string courseTitle;
    vector<string> prerequisites;
};

// Hash table to store courses
unordered_map<string, Course> courseCatalog;

// Function to load course data from file
void loadCourses(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cout << "Error: File not found. Check if it's in the correct directory." << endl;
        return;
    }

    // Clear any old data
    courseCatalog.clear();

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string courseNumber, courseTitle, prereq;
        vector<string> prerequisites;

        if (!getline(ss, courseNumber, ',') || !getline(ss, courseTitle, ',')) {
            continue; // Skip bad lines
        }

        while (getline(ss, prereq, ',')) {
            prerequisites.push_back(prereq);
        }

        courseCatalog[courseNumber] = { courseNumber, courseTitle, prerequisites };
    }

    file.close();

    cout << "Course data successfully loaded!\n";
}

// Function to print all courses in alphanumeric order
void printAllCourses() {
    if (courseCatalog.empty()) {
        cout << "No courses available. Please load course data first." << endl;
        return;
    }

    vector<Course> courses;
    for (const auto& pair : courseCatalog) {
        courses.push_back(pair.second);
    }

    sort(courses.begin(), courses.end(), [](const Course& a, const Course& b) {
        return a.courseNumber < b.courseNumber;
        });

    cout << "\nCourse List:\n";
    for (const auto& course : courses) {
        cout << course.courseNumber << ": " << course.courseTitle << endl;
    }
}

// Function to print course details and prerequisites
void printCourseDetails(const string& courseNumber) {
    if (courseCatalog.find(courseNumber) == courseCatalog.end()) {
        cout << "Error: Course not found." << endl;
        return;
    }

    Course course = courseCatalog[courseNumber];
    cout << "\nCourse Number: " << course.courseNumber << endl;
    cout << "Course Title: " << course.courseTitle << endl;
    cout << "Prerequisites: ";

    if (course.prerequisites.empty()) {
        cout << "None";
    }
    else {
        for (const auto& prereq : course.prerequisites) {
            cout << prereq << " ";
        }
    }
    cout << endl;
}

// Function to display menu
void displayMenu() {
    cout << "\nMenu:" << endl;
    cout << "1. Load course data" << endl;
    cout << "2. Print course list" << endl;
    cout << "3. Print course details" << endl;
    cout << "9. Exit" << endl;
}

// Main function to run the program
#include <limits> // Needed to handle input errors

int main() {
    int choice;
    string filename, courseNumber;

    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        // If the input is invalid, reset cin
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid choice. Please enter a number from the menu.\n";
            continue;
        }

        switch (choice) {
        case 1:
            cout << "Enter filename (or press Enter to use default: CS 300 ABCU_Advising_Program_Input.csv): ";
            cin.ignore();
            getline(cin, filename);

            if (filename.empty()) {
                filename = "CS 300 ABCU_Advising_Program_Input.csv";
            }

            loadCourses(filename);
            break;

        case 2:
            printAllCourses();
            break;

        case 3:
            cout << "Enter course number: ";
            cin >> courseNumber;
            printCourseDetails(courseNumber);
            break;

        case 9:
            cout << "Exiting program..." << endl;
            break;

        default:
            cout << "Invalid choice. Please enter a number from the menu.\n";
        }
    } while (choice != 9);

    return 0;
}
