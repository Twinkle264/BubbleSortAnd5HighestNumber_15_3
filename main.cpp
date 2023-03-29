#include <iostream>
#include <vector>

using namespace std;

vector<int> numbs;
int a = 0;

bool isCorrect(int a) {

    if (cin.fail()) {
        cerr << "Invalid input! Please enter an integer." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    } else if (a < -2) {
        cerr << "Invalid input! Number must be positive either -1 or -2." << endl;
        return false;
    } else {
        return true;
    }
}

void algorithm(int a) {
    if (numbs.empty()) {
        numbs.push_back(a);
    } else {
        bool findInd = false;
        for (int i = 0; i < numbs.size(); ++i) {
            if (numbs[i] > a) {
                findInd = true;
                auto iter = numbs.begin();
                numbs.insert(iter + i, a);
                break;
            }
        }
        if (!findInd) numbs.push_back(a);
    }
    if (numbs.size() > 5) numbs.pop_back();
}

int main() {

    do {
        cout << "Input the number: ";
        cin >> a;
        if (isCorrect(a) && a != -1) {
            algorithm(a);
        } else if (a == -1) {
            if (numbs.size() < 5) {
                cerr << "You entered less than 5 digits" << endl;
            } else {
                cout << "The fifth highest number among the entered is " << numbs[4] << endl;
            }

        }
    } while (a != -2);
    return 0;
}
