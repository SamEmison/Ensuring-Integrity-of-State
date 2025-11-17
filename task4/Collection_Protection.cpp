//Collection Protection
//Sam Emison
//11/17/2025

#include <vector>
#include <memory>
#include <algorithm>
#include <numeric>
#include <string>

class OrderItem {
private:
    std::string name;
    double price;
public:
    OrderItem(const std::string& name, double price) : name(name), price(price) {}
    double getPrice() const { return price; }
};

class Order {
private:
    std::vector<std::shared_ptr<OrderItem>> orderItems;

public:
    void addOrderItem(std::shared_ptr<OrderItem> item) {
        if (!item) throw std::invalid_argument("Item cannot be null");
        orderItems.push_back(item);
    }

    void removeOrderItem(std::shared_ptr<OrderItem> item) {
        if (!item) return;
        orderItems.erase(std::remove(orderItems.begin(), orderItems.end(), item), orderItems.end());
    }

    std::vector<std::shared_ptr<const OrderItem>> getOrderItems() const {
        std::vector<std::shared_ptr<const OrderItem>> protectedItems;
        for (auto& item : orderItems) {
            protectedItems.push_back(item);
        }
        return protectedItems;
    }

    double getTotalPrice() const {
        return std::accumulate(orderItems.begin(), orderItems.end(), 0.0,
                               [](double sum, const std::shared_ptr<OrderItem>& item) {
                                   return sum + item->getPrice();
                               });
    }
};
