#include "Harl.hpp"

int main(void)
{
    Harl harl;

    std::string lvl1 = "debug";
    std::string lvl2 = "info";
    std::string lvl3 = "warning";
    std::string lvl4 = "error";

    harl.complain(lvl1);
    harl.complain(lvl2);
    harl.complain(lvl3);
    harl.complain(lvl4);

    return 0;
}
