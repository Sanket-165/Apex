#include <bits/stdc++.h>
using namespace std;

void diagnose() {

    cin.ignore();

    cout << "\nDescribe your symptoms (e.g., 'I have fever and cough'): ";
    
    string input;
    getline(cin, input);

    // Convert to lowercase
    transform(input.begin(), input.end(), input.begin(), ::tolower);

    bool fever = input.find("fever") != string::npos;
    bool cough = input.find("cough") != string::npos;
    bool headache = input.find("headache") != string::npos;
    bool bodyPain = (input.find("body pain") != string::npos ||
                     input.find("bodypain") != string::npos);

    bool fatigue = (input.find("fatigue") != string::npos ||
                    input.find("tired") != string::npos ||
                    input.find("weak") != string::npos);

    bool vomiting = (input.find("vomit") != string::npos ||
                     input.find("vomiting") != string::npos);

    bool looseMotion = (input.find("loose motion") != string::npos ||
                        input.find("diarrhea") != string::npos);

    bool sneezing = (input.find("sneeze") != string::npos ||
                     input.find("sneezing") != string::npos);

    cout << "\n--- Diagnosis Result ---\n";

    if (fever && cough && fatigue && headache) {
        cout << "Disease: COVID-LIKE SYMPTOMS\n";
        cout << "Medicines: Paracetamol, Steam inhalation\n";
        cout << "Advice: Isolate and consult doctor\n";
    }

    else if (fever && cough && fatigue) {
        cout << "Disease: FLU\n";
        cout << "Medicines: Paracetamol, Cough Syrup, Vitamin C\n";
        cout << "Advice: Rest and warm fluids\n";
    }

    else if (fever && headache && bodyPain) {
        cout << "Disease: VIRAL FEVER\n";
        cout << "Medicines: Paracetamol, Ibuprofen\n";
        cout << "Advice: Stay hydrated\n";
    }

    else if (vomiting && looseMotion) {
        cout << "Disease: FOOD POISONING\n";
        cout << "Medicines: ORS, Electrolytes\n";
        cout << "Advice: Drink fluids, avoid outside food\n";
    }

    else if (fever && bodyPain && fatigue) {
        cout << "Disease: DENGUE (Possible)\n";
        cout << "Medicines: Paracetamol (avoid ibuprofen)\n";
        cout << "Advice: Consult doctor immediately\n";
    }

    else if (cough) {
        cout << "Disease: COMMON COLD\n";
        cout << "Medicines: Antihistamines, Cough Syrup\n";
        cout << "Advice: Avoid cold food\n";
    }

    else if (headache) {
        cout << "Disease: MIGRAINE\n";
        cout << "Medicines: Pain relievers\n";
        cout << "Advice: Rest in dark room\n";
    }

    else if (sneezing) {
        cout << "Disease: ALLERGY\n";
        cout << "Medicines: Antihistamines\n";
        cout << "Advice: Avoid dust/pollution\n";
    }

    else if (fatigue && vomiting) {
        cout << "Disease: DEHYDRATION\n";
        cout << "Medicines: ORS, Water intake\n";
        cout << "Advice: Stay hydrated\n";
    }

    else if (fatigue && bodyPain) {
        cout << "Disease: STRESS / WEAKNESS\n";
        cout << "Medicines: Multivitamins\n";
        cout << "Advice: Proper sleep and diet\n";
    }

    else {
        cout << "No exact match found.\n";
        cout << "Advice: Please consult a doctor for proper diagnosis.\n";
    }
}

// ================= HEALTH TIPS =================
void healthTips() {
    cout << "\n--- Health Tips ---\n";
    cout << "1. Drink enough water\n";
    cout << "2. Exercise regularly\n";
    cout << "3. Eat healthy food\n";
    cout << "4. Sleep properly\n";
    cout << "5. Avoid stress\n";
}

// ================= MAIN =================
int main() {

    int choice;

    do {
        cout << "\n===== HOSPITAL EXPERT SYSTEM =====\n";
        cout << "1. Diagnose Disease\n";
        cout << "2. Health Tips\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";

        cin >> choice;

        switch (choice) {
            case 1:
                diagnose();
                break;

            case 2:
                healthTips();
                break;

            case 3:
                cout << "Exiting... Stay Healthy!\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 3);

    return 0;
}