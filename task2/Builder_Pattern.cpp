//Builder Project
//Sam Emison
//11/17/2025

#include <string>
#include <chrono>
#include <memory>
#include <stdexcept>

enum class ProjectStatus { PLANNING, ACTIVE, COMPLETED };

class Project {
private:
    std::string name;
    std::chrono::system_clock::time_point startDate;
    ProjectStatus status;
    std::chrono::system_clock::time_point completionDate;

    Project(const std::string& name, std::chrono::system_clock::time_point startDate)
        : name(name), startDate(startDate), status(ProjectStatus::PLANNING) {}

public:
    class Builder {
    private:
        std::string name;
        std::chrono::system_clock::time_point startDate;
        std::chrono::system_clock::time_point completionDate{};
        ProjectStatus status = ProjectStatus::PLANNING;

    public:
        Builder(const std::string& name, std::chrono::system_clock::time_point startDate)
            : name(name), startDate(startDate) {
            auto now = std::chrono::system_clock::now();
            if (name.empty()) throw std::invalid_argument("Name must not be empty");
            if (startDate < now) throw std::invalid_argument("Start date must not be in the past");
        }

        Builder& withCompletionDate(std::chrono::system_clock::time_point date) {
            completionDate = date;
            status = ProjectStatus::COMPLETED;
            return *this;
        }

        std::unique_ptr<Project> build() {
            auto now = std::chrono::system_clock::now();

            if (startDate < now)
                throw std::invalid_argument("Start date must not be in the past");

            if (completionDate != std::chrono::system_clock::time_point{} &&
                status != ProjectStatus::COMPLETED)
                throw std::invalid_argument("Completion date requires status COMPLETED");

            if (status == ProjectStatus::COMPLETED &&
                completionDate == std::chrono::system_clock::time_point{})
                throw std::invalid_argument("Completed projects require a completion date");

            if (completionDate != std::chrono::system_clock::time_point{} &&
                completionDate <= startDate)
                throw std::invalid_argument("Completion date must be after start date");

            std::unique_ptr<Project> p(new Project(name, startDate));
            p->status = status;
            p->completionDate = completionDate;
            return p;
        }
    };
};
