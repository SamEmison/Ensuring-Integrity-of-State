#include <iostream>
#include <memory>
#include "Collection_Protection.cpp"

int main() {
    Order order;
    auto item1 = std::make_shared<OrderItem>("Laptop", 999.99);
    auto item2 = std::make_shared<OrderItem>("Mouse", 29.99);

    order.addOrderItem(item1);
    order.addOrderItem(item2);

    double total = order.getTotalPrice();
    std::cout << "Total price: $" << total << " (Expected: $1029.98)\n";

    auto items = order.getOrderItems();
    std::cout << "Number of items: " << items.size() << " (Expected: 2)\n";

    order.removeOrderItem(item1);
    total = order.getTotalPrice();
    std::cout << "Total after removal: $" << total << " (Expected: $29.99)\n";

    Order emptyOrder;
    std::cout << "Empty order total: $" << emptyOrder.getTotalPrice() << " (Expected: $0.00)\n";
}
