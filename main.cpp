#include "Keeper.h"
#include "Car.h"
#include "Motorcycle.h"
#include "Bus.h"
#include <iostream>

int main() {
    Keeper keeper;
    int choice;
    try {
        while (true) {
            std::cout << "\nMenu:\n1. Add Car\n2. Add Motorcycle\n3. Add Bus\n4. Remove by index\n5. Show all\n6. Edit by index\n7. Save to file\n8. Load from file\n9. Exit\n";
            std::cout << "Choice: ";
            std::cin >> choice;
            if (choice == 1) {
                std::string mark, model, color, trans;
                double vol;
                std::cout << "Enter mark, model, volume, color, transmission: ";
                std::cin >> mark >> model >> vol >> color >> trans;
                keeper.add(new Car(mark, model, vol, color, trans));
            }
            else if (choice == 2) {
                std::string mark, model, terrain;
                double vol, power;
                std::cout << "Enter mark, model, volume, power, terrain: ";
                std::cin >> mark >> model >> vol >> power >> terrain;
                keeper.add(new Motorcycle(mark, model, vol, power, terrain));
            }
            else if (choice == 3) {
                std::string mark, model, dest;
                int seats, total;
                std::cout << "Enter mark, model, seats, totalSeats, destination: ";
                std::cin >> mark >> model >> seats >> total >> dest;
                keeper.add(new Bus(mark, model, seats, total, dest));
            }
            else if (choice == 4) {
                int idx;
                std::cout << "Enter index to remove: ";
                std::cin >> idx;
                keeper.remove(idx);
            }
            else if (choice == 5) {
                keeper.show();
            }
            else if (choice == 6) {
                int idx;
                std::cout << "Enter index to edit: ";
                std::cin >> idx;
                keeper.edit(idx);
            }
            else if (choice == 7) {
                std::string file;
                std::cout << "Enter filename to save: ";
                std::cin >> file;
                keeper.save(file);
            }
            else if (choice == 8) {
                std::string file;
                std::cout << "Enter filename to load: ";
                std::cin >> file;
                keeper.load(file);
            }
            else if (choice == 9) {
                break;
            }
            else {
                std::cout << "Invalid choice." << std::endl;
            }
        }
    }
    catch (const IndexOutOfRangeException& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    catch (const FileException& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    return 0;
}
