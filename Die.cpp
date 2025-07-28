#include <cstdlib>
#include <ctime>
#include "Die.h"

Die::Die() {
    m_sides = 6;
    m_die_value = 0;
}

Die::Die(int S) {
    m_sides = S;
    m_die_value = 0;
}

void Die::set_die_value() {
    srand(time(0));
    m_die_value = rand() % m_sides + 1;
}

int Die::get_die_value() {
    return m_die_value;
}
