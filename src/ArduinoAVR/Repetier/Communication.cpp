/*
    This file is part of Repetier-Firmware.

    Repetier-Firmware is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Repetier-Firmware is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Repetier-Firmware.  If not, see <http://www.gnu.org/licenses/>.

    This firmware is a nearly complete rewrite of the sprinter firmware
    by kliment (https://github.com/kliment/Sprinter)
    which based on Tonokip RepRap firmware rewrite based off of Hydra-mmm firmware.
*/

#include "Repetier.h"

#if DRIVE_SYSTEM==3
FSTRINGVALUE(Com::tFirmware,"FIRMWARE_NAME:Repetier_" REPETIER_VERSION " FIRMWARE_URL:https://github.com/repetier/Repetier-Firmware/ PROTOCOL_VERSION:1.0 MACHINE_TYPE:Delta EXTRUDER_COUNT:" XSTR(NUM_EXTRUDER) " REPETIER_PROTOCOL:2")
#else
#if DRIVE_SYSTEM==0
FSTRINGVALUE(Com::tFirmware,"FIRMWARE_NAME:Repetier_" REPETIER_VERSION " FIRMWARE_URL:https://github.com/repetier/Repetier-Firmware/ PROTOCOL_VERSION:1.0 MACHINE_TYPE:Mendel EXTRUDER_COUNT:" XSTR(NUM_EXTRUDER) " REPETIER_PROTOCOL:2")
#else
FSTRINGVALUE(Com::tFirmware,"FIRMWARE_NAME:Repetier_" REPETIER_VERSION " FIRMWARE_URL:https://github.com/repetier/Repetier-Firmware/ PROTOCOL_VERSION:1.0 MACHINE_TYPE:Core_XY EXTRUDER_COUNT:" XSTR(NUM_EXTRUDER) " REPETIER_PROTOCOL:2")
#endif
#endif
FSTRINGVALUE(Com::tOk,"ok")
FSTRINGVALUE(Com::tNewline,"\r\n")
FSTRINGVALUE(Com::tNAN,"NAN")
FSTRINGVALUE(Com::tINF,"INF")
FSTRINGVALUE(Com::tError,"Error:")
FSTRINGVALUE(Com::tInfo,"Info:")
FSTRINGVALUE(Com::tWarning,"Warning:")
FSTRINGVALUE(Com::tResend,"Resend:")
FSTRINGVALUE(Com::tEcho,"Echo:")
FSTRINGVALUE(Com::tOkSpace,"ok ")
FSTRINGVALUE(Com::tWrongChecksum,"Wrong checksum")
FSTRINGVALUE(Com::tMissingChecksum,"Missing checksum")
FSTRINGVALUE(Com::tDonePrinting,"Done printing file")
FSTRINGVALUE(Com::tX," X")
FSTRINGVALUE(Com::tY," Y")
FSTRINGVALUE(Com::tZ," Z")
FSTRINGVALUE(Com::tE," E")
FSTRINGVALUE(Com::tF," F")
FSTRINGVALUE(Com::tS," S")
FSTRINGVALUE(Com::tP," P")
FSTRINGVALUE(Com::tI," I")
FSTRINGVALUE(Com::tJ," J")
FSTRINGVALUE(Com::tR," R")
FSTRINGVALUE(Com::tSDReadError,"SD read error")
FSTRINGVALUE(Com::tExpectedLine,"Error:expected line ")
FSTRINGVALUE(Com::tGot," got ")
FSTRINGVALUE(Com::tSkip,"skip ")
FSTRINGVALUE(Com::tBLK,"BLK ")
FSTRINGVALUE(Com::tStart,"start")
FSTRINGVALUE(Com::tPowerUp,"PowerUp")
FSTRINGVALUE(Com::tExternalReset,"External Reset")
FSTRINGVALUE(Com::tBrownOut,"Brown out Reset")
FSTRINGVALUE(Com::tWatchdog,"Watchdog Reset")
FSTRINGVALUE(Com::tSoftwareReset,"Software Reset")
FSTRINGVALUE(Com::tUnknownCommand,"Unknown command:")
FSTRINGVALUE(Com::tFreeRAM,"Free RAM:")
FSTRINGVALUE(Com::tXColon,"X:")
FSTRINGVALUE(Com::tSpaceYColon," Y:")
FSTRINGVALUE(Com::tSpaceZColon," Z:")
FSTRINGVALUE(Com::tSpaceEColon," E:")
FSTRINGVALUE(Com::tTColon,"T:")
FSTRINGVALUE(Com::tSpaceBColon," B:")
FSTRINGVALUE(Com::tSpaceAtColon," @:")
FSTRINGVALUE(Com::tSpaceT," T")
FSTRINGVALUE(Com::tSpaceAt," @")
FSTRINGVALUE(Com::tColon,":")
FSTRINGVALUE(Com::tSlash,"/")
FSTRINGVALUE(Com::tSpeedMultiply,"SpeedMultiply:")
FSTRINGVALUE(Com::tFlowMultiply,"FlowMultiply:")
FSTRINGVALUE(Com::tFanspeed,"Fanspeed:")
FSTRINGVALUE(Com::tPrintedFilament,"Printed filament:")
FSTRINGVALUE(Com::tPrintingTime,"Printing time:")
FSTRINGVALUE(Com::tSpacem," m")
FSTRINGVALUE(Com::tSpaceDaysSpace," days ")
FSTRINGVALUE(Com::tSpaceHoursSpace," hours ")
FSTRINGVALUE(Com::tSpaceMin," min")
FSTRINGVALUE(Com::tInvalidArc,"Invalid arc")
FSTRINGVALUE(Com::tComma,",")
FSTRINGVALUE(Com::tSpace," ")
FSTRINGVALUE(Com::tYColon,"Y:")
FSTRINGVALUE(Com::tZColon,"Z:")
FSTRINGVALUE(Com::tE0Colon,"E0:")
FSTRINGVALUE(Com::tE1Colon,"E1:")
FSTRINGVALUE(Com::tMS1MS2Pins,"MS1,MS2 Pins")
FSTRINGVALUE(Com::tSetOutputSpace,"Set output ")
FSTRINGVALUE(Com::tSpaceToSpace," to ")
FSTRINGVALUE(Com::tHSpace,"H ")
FSTRINGVALUE(Com::tLSpace,"L ")
FSTRINGVALUE(Com::tXMinColon,"x_min:")
FSTRINGVALUE(Com::tXMaxColon,"x_max:")
FSTRINGVALUE(Com::tYMinColon,"y_min:")
FSTRINGVALUE(Com::tYMaxColon,"y_max:")
FSTRINGVALUE(Com::tZMinColon,"z_min:")
FSTRINGVALUE(Com::tZMaxColon,"z_max:")
FSTRINGVALUE(Com::tJerkColon,"Jerk:")
FSTRINGVALUE(Com::tZJerkColon," ZJerk:")
FSTRINGVALUE(Com::tLinearStepsColon," linear steps:")
FSTRINGVALUE(Com::tQuadraticStepsColon," quadratic steps:")
FSTRINGVALUE(Com::tCommaSpeedEqual,", speed=")

FSTRINGVALUE(Com::tOPSDisabled,"OPS disabled")
FSTRINGVALUE(Com::tOPSClassicMode,"OPS classic mode:")
FSTRINGVALUE(Com::tOPSFastMode,"OPS fast mode:")
FSTRINGVALUE(Com::tMinDistance,"min distance = ")
FSTRINGVALUE(Com::tRetractEqual,", retract = ")
FSTRINGVALUE(Com::tBacklashEqual,", backlash = ")
FSTRINGVALUE(Com::tMoveAfter,", move after = ")
FSTRINGVALUE(Com::tRetrSteps,"Ret. steps:")
FSTRINGVALUE(Com::tPushBackSteps,"PushBack Steps:")
FSTRINGVALUE(Com::tMoveAfterSteps,"Move after steps:")
FSTRINGVALUE(Com::tLinearLColon,"linear L:")
FSTRINGVALUE(Com::tQuadraticKColon," quadratic K:")
#if DRIVE_SYSTEM==3
FSTRINGVALUE(Com::tMeasurementReset,"Measurement reset.")
FSTRINGVALUE(Com::tMeasureDeltaSteps,"Measure/delta (Steps) =")
FSTRINGVALUE(Com::tMeasureDelta,"Measure/delta =")
FSTRINGVALUE(Com::tMeasureOriginReset,"Measured origin set. Measurement reset.")
FSTRINGVALUE(Com::tEEPROMUpdated,"EEPROM updated")
FSTRINGVALUE(Com::tInvalidDeltaCoordinate,"Invalid delta coordinate - move ignored")
FSTRINGVALUE(Com::tLevelingCalc,"Leveling calc:")
FSTRINGVALUE(Com::tTower1,"Tower 1:")
FSTRINGVALUE(Com::tTower2,"Tower 2:")
FSTRINGVALUE(Com::tTower3,"Tower 3:")
FSTRINGVALUE(Com::tDBGDeltaNoMoveinDSegment,"No move in delta segment with > 1 segment. This should never happen and may cause a problem!")
#endif // DRIVE_SYSTEM
#ifdef DEBUG_GENERIC
FSTRINGVALUE(Com::tGenTemp,"GenTemp:")
#endif // DEBUG_GENERICFSTRINGVALUE(Com::,"")
FSTRINGVALUE(Com::tTargetExtr,"TargetExtr")
FSTRINGVALUE(Com::tTargetBedColon,"TargetBed:")
FSTRINGVALUE(Com::tPIDAutotuneStart,"PID Autotune start")
FSTRINGVALUE(Com::tAPIDBias," bias: ")
FSTRINGVALUE(Com::tAPIDD," d: ")
FSTRINGVALUE(Com::tAPIDMin," min: ")
FSTRINGVALUE(Com::tAPIDMax," max: ")
FSTRINGVALUE(Com::tAPIDKu," Ku: ")
FSTRINGVALUE(Com::tAPIDTu," Tu: ")
FSTRINGVALUE(Com::tAPIDClassic," Classic PID")
FSTRINGVALUE(Com::tAPIDKp," Kp: ")
FSTRINGVALUE(Com::tAPIDKi," Ki: ")
FSTRINGVALUE(Com::tAPIDKd," Kd: ")
FSTRINGVALUE(Com::tAPIDFailedHigh,"PID Autotune failed! Temperature to high")
FSTRINGVALUE(Com::tAPIDFailedTimeout,"PID Autotune failed! timeout")
FSTRINGVALUE(Com::tAPIDFinished,"PID Autotune finished ! Place the Kp, Ki and Kd constants in the Configuration.h or EEPROM")
FSTRINGVALUE(Com::tMTEMPColon,"MTEMP:")
FSTRINGVALUE(Com::tHeatedBed,"heated bed")
FSTRINGVALUE(Com::tExtruderSpace,"extruder ")
FSTRINGVALUE(Com::tTempSensorDefect,": temp sensor defect")
FSTRINGVALUE(Com::tTempSensorWorking,": working")
FSTRINGVALUE(Com::tDryModeUntilRestart,"Printer set into dry run mode until restart!")
#ifdef DEBUG_QUEUE_MOVE
FSTRINGVALUE(Com::tDBGId,"ID:")
FSTRINGVALUE(Com::tDBGVStartEnd,"vStart/End:")
FSTRINGVALUE(Com::tDBAccelSteps,"accel/decel steps:")
FSTRINGVALUE(Com::tDBGStartEndSpeed,"st./end speed:")
FSTRINGVALUE(Com::tDBGFlags,"Flags:")
FSTRINGVALUE(Com::tDBGJoinFlags,"joinFlags:")
FSTRINGVALUE(Com::tDBGDelta,"Delta")
FSTRINGVALUE(Com::tDBGDir,"Dir:")
FSTRINGVALUE(Com::tDBGFullSpeed,"fullSpeed:")
FSTRINGVALUE(Com::tDBGVMax,"vMax:")
FSTRINGVALUE(Com::tDBGAcceleration,"Acceleration:")
FSTRINGVALUE(Com::tDBGAccelerationPrim,"Acceleration Prim:")
FSTRINGVALUE(Com::tDBGRemainingSteps,"Remaining steps:")
FSTRINGVALUE(Com::tDBGAdvanceFull,"advanceFull:")
FSTRINGVALUE(Com::tDBGAdvanceRate,"advanceRate:")
FSTRINGVALUE(Com::tDBGLimitInterval,"LimitInterval:")
FSTRINGVALUE(Com::tDBGMoveDistance,"Move distance on the XYZ space:")
FSTRINGVALUE(Com::tDBGCommandedFeedrate,"Commanded feedrate:")
FSTRINGVALUE(Com::tDBGConstFullSpeedMoveTime,"Constant full speed move time:")
#endif // DEBUG_QUEUE_MOVEFSTRINGVALUE(Com::,"")
#ifdef DEBUG_DELTA_OVERFLOW
FSTRINGVALUE(Com::tDBGDeltaOverflow,"Delta overflow:")
#endif // DEBUG_DELTA_OVERFLOW
#ifdef DEBUG_SPLIT
FSTRINGVALUE(Com::tDBGDeltaSeconds,"Seconds:")
FSTRINGVALUE(Com::tDBGDeltaZDelta,"Z delta:")
FSTRINGVALUE(Com::tDBGDeltaSegments,"Segments:")
FSTRINGVALUE(Com::tDBGDeltaNumLines,"Num lines:")
FSTRINGVALUE(Com::tDBGDeltaSegmentsPerLine,"segments_per_line:")
FSTRINGVALUE(Com::tDBGDeltaMaxDS,"Max DS:")
FSTRINGVALUE(Com::tDBGDeltaStepsPerSegment,"Steps Per Segment:")
FSTRINGVALUE(Com::tDBGDeltaVirtualAxisSteps,"Virtual axis steps:")
#endif
#ifdef STEP_COUNTER
FSTRINGVALUE(Com::tDBGDeltaMeasurerDelta,"Measure/delta =")
FSTRINGVALUE(Com::tDBGDeltaMeasurementReset,"Measurement reset.")
FSTRINGVALUE(Com::tDBGDeltaMeasuredOriginSet,"Measured origin set. Measurement reset.")
#endif // STEP_COUNTER
//FSTRINGVALUE(Com::,"")
#ifdef WAITING_IDENTIFIER
FSTRINGVALUE(Com::tWait,WAITING_IDENTIFIER)
#endif // WAITING_IDENTIFIER
#if EEPROM_MODE==0
FSTRINGVALUE(Com::tNoEEPROMSupport,"No EEPROM support compiled.\r\n")
#else
FSTRINGVALUE(Com::tConfigStoredEEPROM,"Configuration stored to EEPROM.")
FSTRINGVALUE(Com::tConfigLoadedEEPROM,"Configuration loaded from EEPROM.")
FSTRINGVALUE(Com::tEPRConfigResetDefaults,"Configuration reset to defaults.")
FSTRINGVALUE(Com::tEPRProtocolChanged,"Protocol version changed, upgrading")
FSTRINGVALUE(Com::tExtrDot,"Extr.")
FSTRINGVALUE(Com::tEPR0,"EPR:0 ")
FSTRINGVALUE(Com::tEPR1,"EPR:1 ")
FSTRINGVALUE(Com::tEPR2,"EPR:2 ")
FSTRINGVALUE(Com::tEPR3,"EPR:3 ")
FSTRINGVALUE(Com::tEPRBaudrate,"Baudrate")
FSTRINGVALUE(Com::tEPRFilamentPrinted,"Filament printed [m]")
FSTRINGVALUE(Com::tEPRPrinterActive,"Printer active [s]")
FSTRINGVALUE(Com::tEPRMaxInactiveTime,"Max. inactive time [ms,0=off]")
FSTRINGVALUE(Com::tEPRStopAfterInactivty,"Stop stepper after inactivity [ms,0=off]")
FSTRINGVALUE(Com::tEPRXStepsPerMM,"X-axis steps per mm")
FSTRINGVALUE(Com::tEPRYStepsPerMM,"Y-axis steps per mm")
FSTRINGVALUE(Com::tEPRZStepsPerMM,"Z-axis steps per mm")
FSTRINGVALUE(Com::tEPRXMaxFeedrate,"X-axis max. feedrate [mm/s]")
FSTRINGVALUE(Com::tEPRYMaxFeedrate,"Y-axis max. feedrate [mm/s]")
FSTRINGVALUE(Com::tEPRZMaxFeedrate,"Z-axis max. feedrate [mm/s]")
FSTRINGVALUE(Com::tEPRXHomingFeedrate,"X-axis homing feedrate [mm/s]")
FSTRINGVALUE(Com::tEPRYHomingFeedrate,"Y-axis homing feedrate [mm/s]")
FSTRINGVALUE(Com::tEPRZHomingFeedrate,"Z-axis homing feedrate [mm/s]")
FSTRINGVALUE(Com::tEPRMaxJerk,"Max. jerk [mm/s]")
FSTRINGVALUE(Com::tEPRMaxZJerk,"Max. Z-jerk [mm/s]")
FSTRINGVALUE(Com::tEPRXHomePos,"X home pos [mm]")
FSTRINGVALUE(Com::tEPRYHomePos,"Y home pos [mm]")
FSTRINGVALUE(Com::tEPRZHomePos,"Z home pos [mm]")
FSTRINGVALUE(Com::tEPRXMaxLength,"X max length [mm]")
FSTRINGVALUE(Com::tEPRYMaxLength,"Y max length [mm]")
FSTRINGVALUE(Com::tEPRZMaxLength,"Z max length [mm]")
FSTRINGVALUE(Com::tEPRXBacklash,"X backlash [mm]")
FSTRINGVALUE(Com::tEPRYBacklash,"Y backlash [mm]")
FSTRINGVALUE(Com::tEPRZBacklash,"Z backlash [mm]")
FSTRINGVALUE(Com::tEPRXAcceleration,"X-axis acceleration [mm/s^2]")
FSTRINGVALUE(Com::tEPRYAcceleration,"Y-axis acceleration [mm/s^2]")
FSTRINGVALUE(Com::tEPRZAcceleration,"Z-axis acceleration [mm/s^2]")
FSTRINGVALUE(Com::tEPRXTravelAcceleration,"X-axis travel acceleration [mm/s^2]")
FSTRINGVALUE(Com::tEPRYTravelAcceleration,"Y-axis travel acceleration [mm/s^2]")
FSTRINGVALUE(Com::tEPRZTravelAcceleration,"Z-axis travel acceleration [mm/s^2]")
FSTRINGVALUE(Com::tEPROPSMode,"OPS operation mode [0=Off,1=Classic,2=Fast]")
FSTRINGVALUE(Com::tEPROPSMoveAfter,"OPS move after x% retract [%]")
FSTRINGVALUE(Com::tEPROPSMinDistance,"OPS min. distance for fil. retraction [mm]")
FSTRINGVALUE(Com::tEPROPSRetractionLength,"OPS retraction length [mm]")
FSTRINGVALUE(Com::tEPROPSRetractionBacklash,"OPS retraction backlash [mm]")
FSTRINGVALUE(Com::tEPRBedHeatManager,"Bed Heat Manager [0-2]")
FSTRINGVALUE(Com::tEPRBedPIDDriveMax,"Bed PID drive max")
FSTRINGVALUE(Com::tEPRBedPIDDriveMin,"Bed PID drive min")
FSTRINGVALUE(Com::tEPRBedPGain,"Bed PID P-gain")
FSTRINGVALUE(Com::tEPRBedIGain,"Bed PID I-gain")
FSTRINGVALUE(Com::tEPRBedDGain,"Bed PID D-gain")
FSTRINGVALUE(Com::tEPRBedPISMaxValue,"Bed PID max value [0-255]")
FSTRINGVALUE(Com::tEPRStepsPerMM,"steps per mm")
FSTRINGVALUE(Com::tEPRMaxFeedrate,"max. feedrate [mm/s]")
FSTRINGVALUE(Com::tEPRStartFeedrate,"start feedrate [mm/s]")
FSTRINGVALUE(Com::tEPRAcceleration,"acceleration [mm/s^2]")
FSTRINGVALUE(Com::tEPRHeatManager,"heat manager [0-1]")
FSTRINGVALUE(Com::tEPRDriveMax,"PID drive max")
FSTRINGVALUE(Com::tEPRDriveMin,"PID drive min")
FSTRINGVALUE(Com::tEPRPGain,"PID P-gain")
FSTRINGVALUE(Com::tEPRIGain,"PID I-gain")
FSTRINGVALUE(Com::tEPRDGain,"PID D-gain")
FSTRINGVALUE(Com::tEPRPIDMaxValue,"PID max value [0-255]")
FSTRINGVALUE(Com::tEPRXOffset,"X-offset [steps]")
FSTRINGVALUE(Com::tEPRYOffset,"Y-offset [steps]")
FSTRINGVALUE(Com::tEPRStabilizeTime,"temp. stabilize time [s]")
FSTRINGVALUE(Com::tEPRRetractionWhenHeating,"temp. for retraction when heating [C]")
FSTRINGVALUE(Com::tEPRDistanceRetractHeating,"distance to retract when heating [mm]")
FSTRINGVALUE(Com::tEPRExtruderCoolerSpeed,"extruder cooler speed [0-255]")
FSTRINGVALUE(Com::tEPRAdvanceK,"advance K [0=off]")
FSTRINGVALUE(Com::tEPRAdvanceL,"advance L [0=off]")

#endif
#if SDSUPPORT
FSTRINGVALUE(Com::tSDRemoved,UI_TEXT_SD_REMOVED)
FSTRINGVALUE(Com::tSDInserted,UI_TEXT_SD_INSERTED)
FSTRINGVALUE(Com::tSDInitFail,"SD init fail")
FSTRINGVALUE(Com::tErrorWritingToFile,"error writing to file")
FSTRINGVALUE(Com::tBeginFileList,"Begin file list")
FSTRINGVALUE(Com::tEndFileList,"End file list")
FSTRINGVALUE(Com::tFileOpened,"File opened:")
FSTRINGVALUE(Com::tSpaceSizeColon," Size:")
FSTRINGVALUE(Com::tFileSelected,"File selected")
FSTRINGVALUE(Com::tFileOpenFailed,"file.open failed")
FSTRINGVALUE(Com::tSDPrintingByte,"SD printing byte ")
FSTRINGVALUE(Com::tNotSDPrinting,"Not SD printing")
FSTRINGVALUE(Com::tOpenFailedFile,"open failed, File: ")
FSTRINGVALUE(Com::tWritingToFile,"Writing to file: ")
FSTRINGVALUE(Com::tDoneSavingFile,"Done saving file.")
FSTRINGVALUE(Com::tFileDeleted,"File deleted")
FSTRINGVALUE(Com::tDeletionFailed,"Deletion failed")
FSTRINGVALUE(Com::tDirectoryCreated,"Directory created")
FSTRINGVALUE(Com::tCreationFailed,"Creation failed")
FSTRINGVALUE(Com::tSDErrorCode,"SD errorCode:")
#endif // SDSUPPORT

void Com::printWarningF(FSTRINGPARAM(text)) {
    printF(tWarning);
    printF(text);
}
void Com::printWarningFLN(FSTRINGPARAM(text)) {
    printF(tWarning);
    printFLN(text);
}
void Com::printInfoF(FSTRINGPARAM(text)) {
    printF(tInfo);
    printF(text);
}
void Com::printInfoFLN(FSTRINGPARAM(text)) {
    printF(tInfo);
    printFLN(text);
}

void Com::printErrorF(FSTRINGPARAM(text)) {
    printF(tError);
    printF(text);
}
void Com::printErrorFLN(FSTRINGPARAM(text)) {
    printF(tError);
    printF(text);
}
void Com::printFLN(FSTRINGPARAM(text)) {
    printF(text);
    println();
}
void Com::printFLN(FSTRINGPARAM(text),const char *msg) {
    printF(text);
    print(msg);
    println();
}

void Com::printF(FSTRINGPARAM(ptr)) {
  char c;
  while ((c=HAL::readFlashByte(ptr++)) != 0)
     HAL::serialWriteByte(c);
}
void Com::printF(FSTRINGPARAM(text),const char *msg) {
    printF(text);
    print(msg);
}

void Com::printF(FSTRINGPARAM(text),int value) {
    printF(text);
    print(value);
}
void Com::printF(FSTRINGPARAM(text),long value) {
    printF(text);
    print(value);
}
void Com::printF(FSTRINGPARAM(text),unsigned long value) {
    printF(text);
    printNumber(value);
}
void Com::printFLN(FSTRINGPARAM(text),int value) {
    printF(text);
    print(value);
    println();
}
void Com::printFLN(FSTRINGPARAM(text),long value) {
    printF(text);
    print(value);
    println();
}
void Com::printFLN(FSTRINGPARAM(text),unsigned long value) {
    printF(text);
    printNumber(value);
    println();
}
void Com::printFLN(FSTRINGPARAM(text),float value,byte digits) {
    printF(text);
    printFloat(value,digits);
    println();
}
void Com::printF(FSTRINGPARAM(text),float value,byte digits) {
    printF(text);
    printFloat(value,digits);
}

void Com::print(const char *text) {
  while(*text) {
    HAL::serialWriteByte(*text++);
  }
}
void Com::print(long value) {
    if(value<0) {
        HAL::serialWriteByte('-');
        value = -value;
    }
    printNumber(value);
}

void Com::printNumber(unsigned long n) {
  char buf[11]; // Assumes 8-bit chars plus zero byte.
  char *str = &buf[10];
  *str = '\0';
  do {
    unsigned long m = n;
    n /= 10;
    *--str = '0'+(m - 10 * n);
  } while(n);

  print(str);
}
void Com::printFloat(float number, uint8_t digits)
{
  if (isnan(number)) {
	printF(tNAN);
    return;
  }
  if (isinf(number)) {
	printF(tINF);
    return;
  }
  // Handle negative numbers
  if (number < 0.0)
  {
     print('-');
     number = -number;
  }
  // Round correctly so that print(1.999, 2) prints as "2.00"
  float rounding = 0.5;
  for (uint8_t i=0; i<digits; ++i)
    rounding /= 10.0;

  number += rounding;

  // Extract the integer part of the number and print it
  unsigned long int_part = (unsigned long)number;
  float remainder = number - (float)int_part;
  printNumber(int_part);

  // Print the decimal point, but only if there are digits beyond
  if (digits > 0)
    print('.');

  // Extract digits from the remainder one at a time
  while (digits-- > 0)
  {
    remainder *= 10.0;
    int toPrint = int(remainder);
    print(toPrint);
    remainder -= toPrint;
  }
}