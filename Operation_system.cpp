#include <iostream>
#include <string>

using namespace std;

class Pet {
protected:
    string name;
    int age;
public:
    Pet() : age(0) {}

    void setName(const string& newName) {
        name = newName;
    }

    void setAge(int newAge) {
        age = newAge;
    }

    string getName() const {
        return name;
    }

    int getAge() const {
        return age;
    }

    void makeSound() const {
        cout << "Pet makes a sound." << endl;
    }

    bool operator<(const Pet& other) const {
        return age < other.age;
    }

    friend ostream& operator<<(ostream& os, const Pet& pet) {
        os << "Name: " << pet.name << ", Age: " << pet.age;
        return os;
    }
};
class Dog : public Pet {
public:
    Dog() : Pet() {}
};

class Cat : public Pet {
public:
    Cat() : Pet() {}

    void makeSound() const {
        cout << "billi" << endl;
    }
};

class Owner {
private:
    string name;

public:
    Owner() {}

    void setName(const string& newName) {
        name = newName;
    }
    
    string getName() const {
        return name;
    }
};
class Appointment {
private:
    const Pet* pet;
    const Owner* owner;

public:
    Appointment(const Pet* pet, const Owner* owner) : pet(pet), owner(owner) {}

    void printDetails() const {
        cout << "Appointment for: " << *pet << ", Owner: " << owner->getName() << endl;
    }
};
int main() {
    Dog dog;
    Cat cat;
    Owner owner;

    string petName, ownerName;
    int petAge;

    cout << "enter name of pet(dog): ";
    cin >> petName;
    dog.setName(petName);

    cout << "Enter dog's age: ";
    cin >> petAge;
    dog.setAge(petAge);
    
    cout << "Enter name of pet(cat): ";
    cin >> petName;
    cat.setName(petName);

    cout << "Enter cats's age: ";
    cin >> petAge;
    cat.setAge(petAge);

    cout << "Enter owner name of pet: ";
    cin >> ownerName;
    owner.setName(ownerName);

    int choice;
    do {
        cout << "\nMenu:\n"
             << "1. Book Dog Appointment\n"
             << "2. Book Cat Appointment\n"
             << "3. Compare pet details\n"
             << "4. Exit\n"
             << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                Appointment dogAppt(&dog, &owner);
                dogAppt.printDetails();
                break;
            }
            case 3: {
                if (dog.getAge() < cat.getAge()) {
                    cout << "Dog is small." << endl;
                } else if (dog.getAge() > cat.getAge()) {
                    cout << "Cat is small." << endl;
                } else {
                    cout << "Both Dog and Cat are of the same age." << endl;
                }
                break;
            }
            case 4: {
                cout << "exit\n";
                break;
            }
            default:
                cout << "Invalid choice. try again.\n";
        }
    } while (choice != 4);

    return 0;
}