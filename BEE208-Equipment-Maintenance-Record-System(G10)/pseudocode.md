# Pseudocode for Equipment Maintenance Record System


START

Display "EQUIPMENT MAINTENANCE RECORD SYSTEM"

Input numberOfRecords

FOR record = 1 TO numberOfRecords

    Input equipmentName
    Input equipmentID
    Input faultDescription
    Input technicianName

    REPEAT
        Input maintenanceCost
        IF maintenanceCost < 0 THEN
            Display "Invalid maintenance cost. Please enter a non-negative value."
        END IF
    UNTIL maintenanceCost >= 0

    Input repairStatus

    IF repairStatus = "Pending" OR
       repairStatus = "In Progress" OR
       repairStatus = "Completed" THEN

        Display maintenance record

        Save maintenance record to maintenance_records.txt

    ELSE

        Display "Invalid Status"

    END IF

END FOR

Display "Records saved successfully."

STOP

