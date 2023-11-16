//C++ PROJECT
#include <iostream>
#include <string>
#include <vector>

class MenuItem {
public:
    std::string name;
    double price;
    std::string portionSize;

    MenuItem(const std::string& n, double p, const std::string& ps) : name(n), price(p), portionSize(ps) {}
};

class Order {
public:
    std::vector<MenuItem> items;
    double total;

    Order() : total(0) {}

    void addItem(const MenuItem& item) {
        items.push_back(item);
        total += item.price;
    }
};

class SentimentAnalysis {
private:
    struct KeywordNode {
        int rating;
        std::string keyword;
        KeywordNode* next;

        KeywordNode(int r, const std::string& k) : rating(r), keyword(k), next(nullptr) {}
    };
    KeywordNode* head;

public:
    SentimentAnalysis() : head(nullptr) {
        // Create the linked list mapping star ratings to keywords.
        head = new KeywordNode(1, "bad");
        head->next = new KeywordNode(2, "average");
        head->next->next = new KeywordNode(3, "good");
        head->next->next->next = new KeywordNode(4, "very good");
        head->next->next->next->next = new KeywordNode(5, "excellent");
    }

    std::string mapRatingToKeyword(int rating) {
        KeywordNode* current = head;
        while (current) {
            if (current->rating == rating) {
                return current->keyword;
            }
            current = current->next;
        }
        return "unknown";
    }
};

struct MoneyAnalysis {
    double income;
    double expenses[7];  // [0] - Clothes, [1] - Food, [2] - Travel, [3] - House Building, [4] - Newspapers, [5] - Books
    double totalExpenses;

    MoneyAnalysis() : income(0), totalExpenses(0) {
        for (int i = 0; i < 6; i++) {
            expenses[i] = 0;
        }
    }

    void collectIncome() {
        std::cout << "Enter your monthly income: Rs ";
        std::cin >> income;
    }

    void collectExpenses() {
        std::cout << "Enter your monthly expenses:\n";
        std::string expenseCategories[6] = {"Clothes", "Food", "Travel", "House Building", "Newspapers", "Books"};
        for (int i = 0; i < 6; i++) {
            std::cout << "Expense for " << expenseCategories[i] << ": Rs ";
            std::cin >> expenses[i];
            totalExpenses += expenses[i];
        }
    }

    void analyzeAndSuggest() {
        double savings = income - totalExpenses;

        if (savings > 0) {
            std::cout << "Congratulations! You are saving money every month." << std::endl;
            std::cout << "Your savings for this month: Rs " << savings << std::endl;
        }
        else if (savings == 0) {
            std::cout << "Congratulations! You are not saving money every month." << std::endl;
            std::cout << "Your savings for this month Rs " << savings << std::endl;
        } else {
            std::cout << "You are spending more than your income. Here are some suggestions:\n";
            std::cout << "1. Review and reduce expenses in high spending categories.\n";
            std::cout << "2. Consider creating a budget and stick to it.\n";
            std::cout << "3. Explore additional income sources.\n";
        }
    }
};

struct TimeAnalysis {
    std::string name;
    char gender;
    int ageGroup;
    std::string profession;
    std::string hobbies;
    double onlineTimePercent;
    double offlineTimePercent;
    double socialMediaTimePercent;
    double gamesTimePercent;
    double videosTimePercent;

    TimeAnalysis() : name(""), gender(' '), ageGroup(0), profession(""), hobbies(""), onlineTimePercent(0), offlineTimePercent(0), socialMediaTimePercent(0), gamesTimePercent(0), videosTimePercent(0) {}

    void collectData() {
        std::cout << "Enter your name: ";
        std::cin.ignore();
        std::getline(std::cin, name);

        std::cout << "Enter your gender abbreviation (H for Hindu, C for Christian, M for Muslim, S for Sikh, B for Buddhist, J for Jain, P for Parsi, W for Jew, O for Others, N for Prefer not to mention): ";
        std::cin >> gender;

        std::cout << "Enter your age group (1: 10-15, 2: 15-20, ..., 10: Greater than 70): ";
        std::cin >> ageGroup;

        std::cout << "Enter your profession: ";
        std::cin.ignore();
        std::getline(std::cin, profession);

        std::cout << "Enter your hobbies: ";
        std::cin.ignore();
        std::getline(std::cin, hobbies);

        std::cout << "Enter the percentage of time spent on online activities: ";
        std::cin >> onlineTimePercent;

        if (onlineTimePercent > 50) {
            std::cout << "Enter the percentage of time spent on social media: ";
            std::cin >> socialMediaTimePercent;
            std::cout << "Enter the percentage of time spent on games: ";
            std::cin >> gamesTimePercent;
            std::cout << "Enter the percentage of time spent on videos: ";
            std::cin >> videosTimePercent;
        }

        std::cout << "Enter the percentage of time spent on offline activities: ";
        std::cin >> offlineTimePercent;
    }

    void analyzeAndSuggest() {
        double totalPercent = onlineTimePercent + offlineTimePercent;

        if (totalPercent > 100) {
            std::cout << "Error: Total time percentage cannot exceed 100%.\n";
            return;
        }

        if (onlineTimePercent > 50) {
            std::cout << "You are spending a significant amount of time on online activities. Here is a breakdown:\n";
            std::cout << "Social Media: " << socialMediaTimePercent << "%\n";
            std::cout << "Games: " << gamesTimePercent << "%\n";
            std::cout << "Videos: " << videosTimePercent << "%\n";

            std::cout << "Here are some suggestions for better time management:\n";
            std::cout << "1. Limit your time on social media, games, and videos.\n";
            std::cout << "2. Allocate more time to productive offline activities.\n";
        } else if (offlineTimePercent > 50) {
            std::cout << "Congratulations, " << name << "! You are spending a lot of time on beneficial offline activities. Keep up the good work!\n";
        } else {
            std::cout << "Your time allocation is balanced. Keep up the good work!\n";
        }
    }
};

int main() {
    int choice;

    while (true) {
        std::cout << "Data Analysis Tools Menu:\n";
        std::cout << "1. Collect Customer Feedback\n";
        std::cout << "2. Money Analyzer Tool\n";
        std::cout << "3. Time Analyzer Tool\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                // Collect and display customer feedback
                {
                    std::vector<MenuItem> menu;
                    menu.push_back(MenuItem("Paneer Tikka", 110.99, "half plate"));
                    menu.push_back(MenuItem("Paneer Makhani", 142.99, "full plate"));
                    menu.push_back(MenuItem("Veg Biryani", 220.99, "full plate"));
                    menu.push_back(MenuItem("Butter Naan", 9.99, "per piece"));
                    menu.push_back(MenuItem("Gulab Jamun", 4.99, "per piece"));

                    Order customerOrder;
                    SentimentAnalysis sentimentAnalyzer;

                    // Display the menu and let the customer make selections.
                    std::cout << "Menu:" << std::endl;
                    for (int i = 0; i < menu.size(); i++) {
                        std::cout << i + 1 << ". " << menu[i].name << " - " << menu[i].price << " (" << menu[i].portionSize << ")" << std::endl;
                    }

                    int choice;
                    do {
                        std::cout << "Enter the item number to add to your order (0 to finish): ";
                        std::cin >> choice;
                        if (choice > 0 && choice <= menu.size()) {
                            customerOrder.addItem(menu[choice - 1]);
                        }
                    } while (choice != 0);

                    // Collect ratings and feedback only once.
                    int totalFeedbackScore = 0;
                    std::cout << "Please provide ratings and feedback for the following categories (1-10 for each category):" << std::endl;
                    std::string feedback;
                    std::string ratingDescriptions[5] = {
                        "Food Quality:",
                        "Hygiene:",
                        "Customer Service:",
                        "Ambience:",
                        "Overall Dining Experience:"
                    };
                    for (int i = 0; i < 5; i++) {
                        int rating;
                        std::cout << "Rate " << ratingDescriptions[i] << " (1-10): ";
                        std::cin >> rating;
                        totalFeedbackScore += rating;

                        std::cout << "Please provide feedback for " << ratingDescriptions[i] << ": ";
                        std::cin.ignore();  // Clear the newline character from the previous input
                        std::getline(std::cin, feedback);
                    }
                    // Display a line of hyphens as a separator.
                    std::cout << "------------------------------------" << std::endl;
                    // Calculate the total cost of food.
                    std::cout << "Total Cost of Food: Rs" << customerOrder.total << std::endl;

                    // Display the ratings and thank the customer.
                    std::cout << "Total Feedback Score: " << totalFeedbackScore << std::endl;
                    if (totalFeedbackScore >= 40) {
                        std::cout << "You seemed to love it. Come again next time." << std::endl;
                    } else if (totalFeedbackScore >= 30) {
                        std::cout << "You seemed to like it." << std::endl;
                    } else if (totalFeedbackScore >= 20) {
                        std::cout << "You seemed to be disappointed. Next time you will get a better experience." << std::endl;
                    } else if (totalFeedbackScore >= 10) {
                        std::cout << "You seemed to not like it. Sorry." << std::endl;
                    } else {
                        std::cout << "Today was our worst day when we disappointed a customer like you." << std::endl;
                    }
                    // Display a line of hyphens as a separator.
                    std::cout << "----------------" << std::endl;

                    std::cout << "Thank you!" << std::endl;
                }
                break;
            case 2:
                // Money Analyzer Tool
                {
                    MoneyAnalysis moneyTool;
                    moneyTool.collectIncome();
                    moneyTool.collectExpenses();
                    moneyTool.analyzeAndSuggest();
                }
                break;
            case 3:
                // Time Analyzer Tool
                {
                    TimeAnalysis timeTool;
                    timeTool.collectData();
                    timeTool.analyzeAndSuggest();
                }
                break;
            case 4:
                // Exit the program
                std::cout << "Goodbye!" << std::endl;
                return 0;
            default:
                std::cout << "Invalid choice. Please select a valid option." << std::endl;
                break;
        }
    }

    return 0;
}
