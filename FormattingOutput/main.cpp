// Formatting output
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

struct City {
    std::string name;
    long population;
    double cost;
};

// Assume each country has at least 1 city
struct Country {
    std::string name;
    std::vector<City> cities;
};

struct Tours {
    std::string title;
    std::vector<Country> countries;
};

int main()
{
    Tours tours
    { "Tour Ticket Prices from Miami",
        {
            {
                "Colombia", {
                    { "Bogota", 8778000, 400.98 },
                    { "Cali", 2401000, 424.12 },
                    { "Medellin", 2464000, 350.98 },
                    { "Cartagena", 972000, 345.34 }
                },
            },
            {
                "Brazil", {
                    { "Rio De Janiero", 13500000, 567.45 },
                    { "Sao Paulo", 11310000, 975.45 },
                    { "Salvador", 18234000, 855.99 }
                },
            },
            {
                "Chile", {
                    { "Valdivia", 260000, 569.12 },
                    { "Santiago", 7040000, 520.00 }
            },
        },
            { "Argentina", {
                { "Buenos Aires", 3010000, 723.77 }
            }
        },
    }
    };

    // Unformatted display so you can see how to access the vector elements
    std::cout << tours.title << std::endl;
    for (auto country : tours.countries) {   // loop through the countries
        std::cout << country.name << std::endl;
        for (auto city : country.cities) {       // loop through the cities for each country
            std::cout << "\t" << city.name
                << "\t" << city.population
                << "\t" << city.cost
                << std::endl;
        }
    }



    std::cout << std::endl << std::endl;


    //formatted display
    std::cout << "1234567890123456789012345678901234567890123456789012345678901234567890\n" << std::endl;
    std::cout << std::setw(50) << tours.title << "\n" << std::endl;
    std::cout << "Country" << std::setw(20) << "City" << std::setw(25) << "Population" << std::right << std::setw(18) << "Price" << std::endl;
    std::cout << "----------------------------------------------------------------------" << std::endl;
    for (auto country : tours.countries) {
        std::cout << country.name << std::endl;
        for (auto city : country.cities) {
            std::cout << std::setw(27) << city.name
                << std::setw(25) << std::fixed << std::setprecision(0) << city.population
                << std::right << std::setw(18) << std::fixed << std::setprecision(2) << city.cost
                << std::endl;
        }
    }


    return 0;
}