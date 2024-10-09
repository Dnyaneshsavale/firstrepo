#include <iostream>
#include <vector>
#include <map>
#include <iomanip>

double convertGradeToPoints(const std::string& grade) {
    static const std::map<std::string, double> gradePoints = {
        {"O", 10.0},
        {"A+", 9.0},
        {"A", 8.0},
        {"B+", 7.0},
        {"B", 6.0},
        {"C", 5.0},
        {"D", 4.0},
        {"F", 0.0}
    };

    auto it = gradePoints.find(grade);
    if (it != gradePoints.end()) {
        return it->second;
    } else {
        std::cerr << "Invalid grade entered: " << grade << ". Please use O, A+, A, B+, B, C, D, or F." << std::endl;
        return -1; // Return -1 to indicate an error
    }
}

int main() {
    int numberOfSubjects;

    // Prompt user for the number of subjects
    std::cout << "Enter the number of subjects: ";
    std::cin >> numberOfSubjects;

    // Check for valid input
    if (numberOfSubjects <= 0) {
        std::cout << "Please enter a valid number of subjects." << std::endl;
        return 1; // Exit with an error code
    }

    std::vector<std::string> subjects = {
        "Mathematics", "Physics", "Chemistry", "Computer Science", 
        "Electrical Engineering", "Mechanical Engineering", 
        "Civil Engineering", "Electronics", "Information Technology"
    };

    std::vector<std::string> grades(numberOfSubjects);
    double totalPoints = 0.0;
    int validGradesCount = 0;

    // Input grades for each subject
    for (int i = 0; i < numberOfSubjects; ++i) {
        std::cout << "Enter the grade for " << subjects[i] << ": ";
        std::string grade;
        std::cin >> grade;

        double points = convertGradeToPoints(grade);
        if (points >= 0) { // Only consider valid grades
            grades[i] = grade;
            totalPoints += points;
            validGradesCount++;
        }
    }

    // Calculate the average if valid grades were entered
    if (validGradesCount > 0) {
        double average = totalPoints / validGradesCount;
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "The average grade point is: " << average << std::endl;
    } else {
        std::cout << "No valid grades were entered." << std::endl;
    }

    return 0; // Successful completion
}
