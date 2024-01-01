#include "atmega2560.h"
#include <util/delay.h>

void setup() {
    DDRB = (1 << 7);
    PORTB = 0;
}

void loop() {
    PORTB ^= (1 << 7);
    _delay_ms(500);
    PORTB ^= (1 << 7);
    _delay_ms(500);
}

int main() {
    setup();

    while (1) {
        loop();
    }
    return 0;
}
