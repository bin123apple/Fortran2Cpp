#include <iostream>
#include <memory>
#include <string>

class Person {
public:
    std::string name = "";
    int ss = 1;
};

class Education : public Person {
public:
    int attainment = 0;
    std::string institution = "";
};

class Service : public Education {
public:
    int personnel_number = 0;
    std::string department = "";
};

class PersonRecord : public Service {
public:
    std::shared_ptr<PersonRecord> supervisor = nullptr;
};

std::shared_ptr<PersonRecord> entry(const std::string& name, int ss, int attainment, const std::string& institution,
                                    int personnel_number, const std::string& department, std::shared_ptr<PersonRecord> supervisor) {
    auto new_person = std::make_shared<PersonRecord>();
    new_person->name = name;
    new_person->ss = ss;
    new_person->attainment = attainment;
    new_person->institution = institution;
    new_person->personnel_number = personnel_number;
    new_person->department = department;
    new_person->supervisor = supervisor;
    return new_person;
}

int main() {
    auto supervisor = std::make_shared<PersonRecord>();
    supervisor->name = "Joe Honcho";
    supervisor->ss = 123455;
    supervisor->attainment = 100;
    supervisor->institution = "Celestial University";
    supervisor->personnel_number = 1;
    supervisor->department = "Directorate";

    auto recruit = entry("John Smith", 123456, 1, "Bog Hill High School", 99, "Records", supervisor);

    // Perform checks
    if (recruit->name != "John Smith") return 1;
    if (recruit->name != recruit->name) return 2;  // This check seems redundant, kept as is from the original request
    if (recruit->supervisor->ss != 123455) return 3;
    if (recruit->supervisor->ss != supervisor->ss) return 4;

    // Output for demonstration
    std::cout << "Recruit Name: " << recruit->name << std::endl;
    std::cout << "Recruit Supervisor: " << recruit->supervisor->name << std::endl;

    return 0;
}