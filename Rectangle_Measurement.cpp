#include <iostream>
#include <vector>
#include <algorithm>

struct Politics {
    std::string name;
    std::string leader;
    int members;
};

void addParty(std::vector<Politics>& catalog) {
    Politics newParty;
    std::cout << "Enter Party Name: ";
    std::cin >> newParty.name;
    std::cout << "Enter Party Leader: ";
    std::cin >> newParty.leader;
    std::cout << "Enter Number of Members: ";
    std::cin >> newParty.members;

    auto it = std::find_if(catalog.begin(), catalog.end(),
                           [&](const Politics& party) {
                               return party.name == newParty.name && party.leader == newParty.leader;
                           });

    if (it == catalog.end()) {
        catalog.push_back(newParty);
        std::cout << "Party added successfully!\n";
    } else {
        std::cout << "Party already exists in the catalog.\n";
    }
}

void addMember(std::vector<Politics>& catalog) {
    std::string partyName;
    std::cout << "Enter Party Name to add a member: ";
    std::cin >> partyName;

    auto it = std::find_if(catalog.begin(), catalog.end(),
                           [&](const Politics& party) {
                               return party.name == partyName;
                           });

    if (it != catalog.end()) {
        int newMembers;
        std::cout << "Enter Number of Members to add: ";
        std::cin >> newMembers;
        it->members += newMembers;
        std::cout << "Members added successfully!\n";
    } else {
        std::cout << "Party not found in the catalog.\n";
    }
}

void searchByLeader(const std::vector<Politics>& catalog) {
    std::string leaderName;
    std::cout << "Enter Leader Name to search for a party: ";
    std::cin >> leaderName;

    auto it = std::find_if(catalog.begin(), catalog.end(),
                           [&](const Politics& party) {
                               return party.leader == leaderName;
                           });

    if (it != catalog.end()) {
        std::cout << "Party Name: " << it->name << "\n";
        std::cout << "Party Leader: " << it->leader << "\n";
        std::cout << "Number of Members: " << it->members << "\n";
    } else {
        std::cout << "Party with the given leader not found.\n";
    }
}

void searchByName(const std::vector<Politics>& catalog) {
    std::string partyName;
    std::cout << "Enter Party Name to search for: ";
    std::cin >> partyName;

    auto it = std::find_if(catalog.begin(), catalog.end(),
                           [&](const Politics& party) {
                               return party.name == partyName;
                           });

    if (it != catalog.end()) {
        std::cout << "Party Name: " << it->name << "\n";
        std::cout << "Party Leader: " << it->leader << "\n";
        std::cout << "Number of Members: " << it->members << "\n";
    } else {
        std::cout << "Party not found in the catalog.\n";
    }
}

void displayCatalog(const std::vector<Politics>& catalog) {
    if (catalog.empty()) {
        std::cout << "Political Party Catalog is empty.\n";
    } else {
        std::cout << "Political Party Catalog:\n";
        for (const auto& party : catalog) {
            std::cout << "Party Name: " << party.name << "\n";
            std::cout << "Party Leader: " << party.leader << "\n";
            std::cout << "Number of Members: " << party.members << "\n";
            std::cout << "-------------------------\n";
        }
    }
}

int main() {
    std::vector<Politics> partyCatalog;

    int choice;
    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Add a Party\n";
        std::cout << "2. Add a Member to Existing Party\n";
        std::cout << "3. Search by Leader\n";
        std::cout << "4. Search by Name\n";
        std::cout << "5. Display Catalog\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                addParty(partyCatalog);
                break;
            case 2:
                addMember(partyCatalog);
                break;
            case 3:
                searchByLeader(partyCatalog);
                break;
            case 4:
                searchByName(partyCatalog);
                break;
            case 5:
                displayCatalog(partyCatalog);
                break;
            case 0:
                std::cout << "Exiting the program. Goodbye!\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}
