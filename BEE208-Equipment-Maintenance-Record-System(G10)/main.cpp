#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class MaintenanceRecord
{
private:
    string equipmentName;
    string equipmentID;
    string faultDescription;
    string technicianName;
    double maintenanceCost;
    string repairStatus;

public:
    void setRecordDetails();
    bool validateCost();
    bool validateStatus();
    void displayRecord();
    void saveToFile();
};

// ---------------- INPUT ----------------

void MaintenanceRecord::setRecordDetails()
{
    cout << "\nEnter equipment name: ";
    getline(cin >> ws, equipmentName);

    cout << "Enter equipment ID: ";
    getline(cin, equipmentID);

    cout << "Enter fault description: ";
    getline(cin, faultDescription);

    cout << "Enter technician name: ";
    getline(cin, technicianName);

    cout << "Enter maintenance cost: ";
    cin >> maintenanceCost;

    cout << "Enter repair status (Pending / InProgress / Completed): ";
    cin >> repairStatus;
}

// ---------------- COST VALIDATION ----------------

bool MaintenanceRecord::validateCost()
{
    return maintenanceCost >= 0;
}

// ---------------- STATUS VALIDATION ----------------

bool MaintenanceRecord::validateStatus()
{
    return (repairStatus == "Pending" ||
            repairStatus == "InProgress" ||
            repairStatus == "Completed");
}

// ---------------- DISPLAY ----------------

void MaintenanceRecord::displayRecord()
{
    cout << "\n=================================\n";
    cout << "Equipment Name   : " << equipmentName << endl;
    cout << "Equipment ID     : " << equipmentID << endl;
    cout << "Fault Description: " << faultDescription << endl;
    cout << "Technician Name  : " << technicianName << endl;
    cout << "Maintenance Cost : GHS " << maintenanceCost << endl;
    cout << "Repair Status    : " << repairStatus << endl;
    cout << "=================================\n";
}

// ---------------- SAVE FILE ----------------

void MaintenanceRecord::saveToFile()
{
    ofstream file("maintenance_records.txt", ios::app);

    file << "Equipment Name   : " << equipmentName << endl;
    file << "Equipment ID     : " << equipmentID << endl;
    file << "Fault Description: " << faultDescription << endl;
    file << "Technician Name  : " << technicianName << endl;
    file << "Maintenance Cost : GHS " << maintenanceCost << endl;
    file << "Repair Status    : " << repairStatus << endl;
    file << "---------------------------------\n";

    file.close();
}

// ---------------- MAIN ----------------

int main()
{
    int numberOfRecords;

    cout << "=====================================\n";
    cout << " EQUIPMENT MAINTENANCE SYSTEM\n";
    cout << "=====================================\n";

    cout << "Enter number of records: ";
    cin >> numberOfRecords;

    for (int i = 0; i < numberOfRecords; i++)
    {
        MaintenanceRecord record;

        cout << "\n---------- RECORD " << i + 1 << " ----------\n";

        record.setRecordDetails();

        // validate cost
        while (!record.validateCost())
        {
            cout << "Invalid cost. Re-enter all details.\n";
            record.setRecordDetails();
        }

        // validate status
        while (!record.validateStatus())
        {
            cout << "Invalid status. Re-enter all details.\n";
            record.setRecordDetails();
        }

        record.displayRecord();
        record.saveToFile();
    }

    cout << "\nRecords saved successfully to maintenance_records.txt\n";
    cout << "Program finished.\n";

    return 0;
}