/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2020 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */

//
// Backlash Menu
//

#include "../../inc/MarlinConfigPre.h"

#if BOTH(HAS_LCD_MENU, BACKLASH_GCODE)

#include "menu_item.h"

#include "../../feature/backlash.h"


void menu_backlash() {
  START_MENU();
  BACK_ITEM(MSG_MAIN);

  EDIT_ITEM_FAST(percent, MSG_BACKLASH_CORRECTION, &backlash.correction, all_off, all_on);
  
  auto axis_can_calibrate = [](const uint8_t a) {
    switch (a) {
      default:
      case X_AXIS: return AXIS_CAN_CALIBRATE(X);
      case Y_AXIS: return AXIS_CAN_CALIBRATE(Y);
      case Z_AXIS: return AXIS_CAN_CALIBRATE(Z);
      //TODO: handle default
    }
  };

  #define EDIT_BACKLASH_DISTANCE(N) EDIT_ITEM_FAST(float43, MSG_BACKLASH_##N, &backlash.distance_mm[_AXIS(N)], 0.0f, 9.9f);
  if (axis_can_calibrate(_AXIS(A))) EDIT_BACKLASH_DISTANCE(A);
  if (axis_can_calibrate(_AXIS(B))) EDIT_BACKLASH_DISTANCE(B);
  if (axis_can_calibrate(_AXIS(C))) EDIT_BACKLASH_DISTANCE(C);

  #ifdef BACKLASH_SMOOTHING_MM
    EDIT_ITEM_FAST(float43, MSG_BACKLASH_SMOOTHING, &backlash.smoothing_mm, 0.0f, 9.9f);
  #endif

  END_MENU();
}

#endif // HAS_LCD_MENU && BACKLASH_GCODE
