#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <vector>

struct Customer {
    std::string phone_number;
    std::string password;
};

std::vector<Customer> readCustomersFromFile(const std::string& filename);
bool login(const std::vector<Customer>& customers, const std::string& phone_number, const std::string& password);
void registerNewCustomer(std::vector<Customer>& customers);

#endif // CUSTOMER_H
