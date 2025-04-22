#include <iostream>
#include <string>
using namespace std;

class Employee {
protected:
    string name;
    string employeeNumber;
    string hireDate;

public:
    Employee() : name(""), employeeNumber(""), hireDate("") {}
    Employee(string n, string eNum, string hDate) : name(n), employeeNumber(eNum), hireDate(hDate) {}

    void setName(string n) { name = n; }
    void setEmployeeNumber(string eNum) { employeeNumber = eNum; }
    void setHireDate(string hDate) { hireDate = hDate; }

    string getName() const { return name; }
    string getEmployeeNumber() const { return employeeNumber; }
    string getHireDate() const { return hireDate; }

    void printEmployee() const {
        cout << "Name: " << name << endl;
        cout << "Employee Number: " << employeeNumber << endl;
        cout << "Hire Date: " << hireDate << endl;
    }
};

class ProductionWorker : public Employee {
protected:
    int shift;
    double hourlyPayRate;

public:
    ProductionWorker() : Employee(), shift(1), hourlyPayRate(0.0) {}
    ProductionWorker(string n, string eNum, string hDate, int s, double rate)
        : Employee(n, eNum, hDate), shift(s), hourlyPayRate(rate) {}

    void setShift(int s) { shift = s; }
    void setHourlyPayRate(double rate) { hourlyPayRate = rate; }

    int getShift() const { return shift; }
    double getHourlyPayRate() const { return hourlyPayRate; }

    void printProductionWorker() const {
        printEmployee();
        cout << "Shift: " << (shift == 1 ? "Day" : "Night") << endl;
        cout << "Hourly Pay Rate: $" << hourlyPayRate << endl;
    }
};

class ShiftSupervisor : public Employee {
protected:
    double annualSalary;
    double annualBonus;

public:
    ShiftSupervisor() : Employee(), annualSalary(0.0), annualBonus(0.0) {}
    ShiftSupervisor(string n, string eNum, string hDate, double salary, double bonus)
        : Employee(n, eNum, hDate), annualSalary(salary), annualBonus(bonus) {}

    void setAnnualSalary(double salary) { annualSalary = salary; }
    void setAnnualBonus(double bonus) { annualBonus = bonus; }

    double getAnnualSalary() const { return annualSalary; }
    double getAnnualBonus() const { return annualBonus; }

    void printShiftSupervisor() const {
        printEmployee();
        cout << "Annual Salary: $" << annualSalary << endl;
        cout << "Annual Bonus: $" << annualBonus << endl;
    }
};

class TeamLeader : public ProductionWorker {
private:
    double monthlyBonus;
    int requiredTrainingHours;
    int attendedTrainingHours;

public:
    TeamLeader() : ProductionWorker(), monthlyBonus(0.0), requiredTrainingHours(0), attendedTrainingHours(0) {}
    TeamLeader(string n, string eNum, string hDate, int s, double rate, double bonus, int reqHours, int attHours)
        : ProductionWorker(n, eNum, hDate, s, rate), monthlyBonus(bonus), requiredTrainingHours(reqHours), attendedTrainingHours(attHours) {}

    void setMonthlyBonus(double bonus) { monthlyBonus = bonus; }
    void setRequiredTrainingHours(int hours) { requiredTrainingHours = hours; }
    void setAttendedTrainingHours(int hours) { attendedTrainingHours = hours; }

    double getMonthlyBonus() const { return monthlyBonus; }
    int getRequiredTrainingHours() const { return requiredTrainingHours; }
    int getAttendedTrainingHours() const { return attendedTrainingHours; }

    void printTeamLeader() const {
        printProductionWorker();
        cout << "Monthly Bonus: $" << monthlyBonus << endl;
        cout << "Required Training Hours: " << requiredTrainingHours << endl;
        cout << "Attended Training Hours: " << attendedTrainingHours << endl;
    }
};

int main() {
    ProductionWorker worker1("Alice Smith", "A123", "03/15/2021", 1, 22.5);
    ProductionWorker worker2("Bob Jones", "B456", "07/10/2019", 2, 24.0);

    cout << "=== Production Workers ===" << endl;
    worker1.printProductionWorker();
    cout << endl;
    worker2.printProductionWorker();
    cout << endl;

    ShiftSupervisor supervisor("Clara Stone", "C789", "01/05/2020", 60000.0, 5000.0);
    cout << "=== Shift Supervisor ===" << endl;
    supervisor.printShiftSupervisor();
    cout << endl;

    TeamLeader leader("David Wright", "D321", "05/23/2018", 1, 26.5, 1000.0, 40, 35);
    cout << "=== Team Leader ===" << endl;
    leader.printTeamLeader();
    cout << endl;

    return 0;
}
