#include <array>
#include <string>
#include <vector>
#include <cmath>

// Round down all provided student scores.
std::vector<int> round_down_scores(std::vector<double> student_scores) {
    // TODO: Implement round_down_scores
    std::vector<int> scores;
    for(auto s : student_scores){
        int new_score = static_cast<int>(std::floor(s));
        scores.push_back(new_score);
    }
    return scores;
}

// Count the number of failing students out of the group provided.
int count_failed_students(std::vector<int> student_scores) {
    // TODO: Implement count_failed_students
    int count = 0;
    for(auto s : student_scores){
        if(s <= 40){
            count++;
        }
    }
    return count;
}

// Create a list of grade thresholds based on the provided highest grade.
std::array<int, 4> letter_grades(int highest_score) {
    // TODO: Implement letter_grades
    std::array<int, 4> lg {41, 0, 0, 0};
    double i = (highest_score - lg[0]) / 4.0;
    for(int j = 1; j < 4; ++j){
        lg[j] = static_cast<int>(std::ceil(lg[0] + i * j));
    }
    return lg;
}

// Organize the student's rank, name, and grade information in ascending order.
std::vector<std::string> student_ranking(
    std::vector<int> student_scores, std::vector<std::string> student_names) {
    std::vector<std::string> ranks;
    for(int i = 0; i < student_scores.size(); i++){
        std::string temp = std::to_string(i+1) + ". " + student_names.at(i) + ": " + std::to_string(student_scores.at(i));
        ranks.push_back(temp);
    }
    return ranks;
}

// Create a string that contains the name of the first student to make a perfect
// score on the exam.
std::string perfect_score(std::vector<int> student_scores,
                          std::vector<std::string> student_names) {
    for(int i = 0; i < student_scores.size(); ++i){
        if(student_scores.at(i) == 100){
            return student_names.at(i);
        }
    }
    return "";
}
