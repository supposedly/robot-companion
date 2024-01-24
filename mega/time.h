#pragma once

#include "Common.h"

void setupTime() {

}

//inline void loopTime() __attribute__((always_inline));
inline void loopTime() {
    Time = millis();
}
