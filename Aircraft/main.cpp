#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

class VDMToken {
public:
    VDMToken(string valueIn) : value(valueIn) {}

protected:
    string value;
};

class Aircraft : public VDMToken {
public:
    Aircraft(string valueIn) : VDMToken(valueIn) {}

    string toString() const {
        return value;
    }

    bool operator<(const Aircraft& other) const {
        return value < other.value;
    }

    bool operator==(const Aircraft& other) const {
        return value == other.value;
    }
};

class Airport {
public:
    set<Aircraft> permission;
    set<Aircraft> landed;

    Airport() {
        invTest();
    }

    bool inv() const {
        return includes(permission.begin(), permission.end(), landed.begin(), landed.end());
    }

    void givePermission(const Aircraft& craftIn) {
        permission.insert(craftIn);
        invTest();
    }

    void recordLanding(const Aircraft& craftIn) {
        landed.insert(craftIn);
        invTest();
    }

    void recordTakeOff(const Aircraft& craftIn) {
        landed.erase(craftIn);
        invTest();
    }

    int numberWaiting() const {
        return static_cast<int>(permission.size() - landed.size());
    }

    set<Aircraft> getPermission() const {
        return permission;
    }

    set<Aircraft> getLanded() const {
        return landed;
    }

    void invTest() const {
        if (!inv()) {
            cerr << "Invariant violation detected!" << endl;
            exit(EXIT_FAILURE);
        }
    }

    string toString() const {
        string result = "Permission: ";
        for (set<Aircraft>::iterator it = permission.begin(); it != permission.end(); ++it) {
            result += it->toString() + " ";
        }
        result += "\nLanded: ";
        for (set<Aircraft>::iterator it = landed.begin(); it != landed.end(); ++it) {
            result += it->toString() + " ";
        }
        return result;
    }
};

int main() {
    Airport airport;

    do {
        cout << "1. Give Permission\n";
        cout << "2. Record Landing\n";
        cout << "3. Record Takeoff\n";
        cout << "4. Number Waiting\n";
        cout << "5. Display Permission and Landed\n";
        cout << "6. Exit\n";

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string craftName;
                cout << "Enter aircraft name: ";
                cin >> craftName;
                Aircraft craft(craftName);
                airport.givePermission(craft);
                break;
            }
            case 2: {
                string craftName;
                cout << "Enter aircraft name: ";
                cin >> craftName;
                Aircraft craft(craftName);
                airport.recordLanding(craft);
                break;
            }
            case 3: {
                string craftName;
                cout << "Enter aircraft name: ";
                cin >> craftName;
                Aircraft craft(craftName);
                airport.recordTakeOff(craft);
                break;
            }
            case 4:
                cout << "Number of waiting aircraft: " << airport.numberWaiting() << endl;
                break;
            case 5: {
                cout << airport.toString() << endl;
                break;
            }
            case 6:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (true);

    return 0;
}
