#include "TacticalMarine.hpp"

TacticalMarine::TacticalMarine()
{
    std::cout << ANSI_COLOR_YELLOW
              << "Tactical Marine ready for battle!"
              << ANSI_COLOR_RESET
              << std::endl;
}

TacticalMarine::TacticalMarine(const TacticalMarine &tacticalMarine)
{
    *this = tacticalMarine;
    std::cout << ANSI_COLOR_YELLOW
              << "Tactical Marine ready for battle!"
              << ANSI_COLOR_RESET
              << std::endl;
}

TacticalMarine::~TacticalMarine()
{
    std::cout << ANSI_COLOR_YELLOW
              << "Aaargh..."
              << ANSI_COLOR_RESET
              << std::endl;
}

TacticalMarine &TacticalMarine::operator=(const TacticalMarine &tacticalMarine)
{
    (TacticalMarine) tacticalMarine;
    return (*this);
}

TacticalMarine *TacticalMarine::clone() const
{
    return (new TacticalMarine(*this));
}

void TacticalMarine::battleCry() const
{
    std::cout << ANSI_COLOR_YELLOW
              << "For the holy PLOT!"
              << ANSI_COLOR_RESET
              << std::endl;
}

void TacticalMarine::rangedAttack() const
{
    std::cout << ANSI_COLOR_YELLOW
              << "* attacks with a bolter *"
              << ANSI_COLOR_RESET
              << std::endl;
}

void TacticalMarine::meleeAttack() const
{
    std::cout << ANSI_COLOR_YELLOW
              << "* attacks with a chainsword *"
              << ANSI_COLOR_RESET
              << std::endl;
}
