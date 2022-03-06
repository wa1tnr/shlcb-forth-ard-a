// Sun  6 Mar 01:22:45 UTC 2022

#if 0
    [ https://wokwi.com/arduino/projects/325294489810764371 ]
#endif

#include <serialStr.h>
#include <strTools.h>

#define blueLED   4
#define purpleLED 3
#define orangeLED 2

serialStr  comReader;

void blue(bool on) {
  if (on) {
    digitalWrite(blueLED,HIGH);
  } else {
    digitalWrite(blueLED,LOW);
  }
}

void purple(bool on) {
  if (on) {
    digitalWrite(purpleLED,HIGH);
  } else {
    digitalWrite(purpleLED,LOW);
  }
}

void orange(bool on) {
  if (on) {
    digitalWrite(orangeLED,HIGH);
  } else {
    digitalWrite(orangeLED,LOW);
  }
}

// Sat  5 Mar 10:50:44 UTC 2022

// extern char tib[maxtib];

extern const byte maxtib;
extern char tib[];
extern void runword(); // interpreter.cpp

unsigned long global_iteration_counter;

// bool flagged = true;

void readStr(char* inStr) {


// inStr is the feeder string

int aba=strlen(inStr);

memcpy(tib, inStr, aba); // hum
tib[(aba - 0)] = '\0';

// #if 0
// Serial.print("gotcha: ");
// Serial.print(tib);
// Serial.print(" hadya:  ");
// Serial.print(aba);
// tib[0] = '\0';
// tib[1] = '\0';
// #endif

// if (flagged) { runword(); flagged = false; }

// readword() functionality: echo acquired string:
if (tib[0] == 0) { } else {
    Serial.print(tib);
    Serial.print(' ');
}

runword();

global_iteration_counter++;
Serial.print("counter: ");
Serial.println(global_iteration_counter);


#if 0
    Serial.print("command : ");
    Serial.println(inStr);
    lwrCase(inStr);

    if (!strcmp(inStr,"blue on"))    { blue(true);    return; }
    if (!strcmp(inStr,"blue off"))   { blue(false);   return; }
    if (!strcmp(inStr,"purple on"))  { purple(true);  return; }
    if (!strcmp(inStr,"purple off")) { purple(false); return; }
    if (!strcmp(inStr,"orange on"))  { orange(true);  return; }
    if (!strcmp(inStr,"orange off")) { orange(false); return; }

    if (!strcmp(inStr,"all on")) {
        blue(true); purple(true); orange(true); return;
    }
    if (!strcmp(inStr,"all off")) {
        blue(false); purple(false); orange(false); return;
    }
    // did not understand what was typed:
    Serial.println("Look, its color on or color off.");
    Serial.println("Or maybe, all on, or, all off. Try again.");
#endif
}


#if 0
// Sat  5 Mar 10:28:12 UTC 2022

void readStr(char* inStr) {
    Serial.print("command : ");
    Serial.println(inStr);
    lwrCase(inStr);

    if (!strcmp(inStr,"blue on")) {
        blue(true); 
        return;
    }
    if (!strcmp(inStr,"blue off")) {
        blue(false);
        return;
    }
    if (!strcmp(inStr,"purple on")) {
        purple(true);
        return;
    }
    if (!strcmp(inStr,"purple off")) {
        purple(false);
        return;
    }
    if (!strcmp(inStr,"orange on")) {
        orange(true);
        return;
    }
    if (!strcmp(inStr,"orange off")) {
        orange(false);
        return;
    }
    if (!strcmp(inStr,"all on")) {
        blue(true);
        purple(true);
        orange(true);
        return;
    }
    if (!strcmp(inStr,"all off")) {
        blue(false);
        purple(false);
        orange(false);
        return;
    }
    // did not understand what was typed:
    Serial.println("Look, its color on or color off.");
    Serial.println("Or maybe, all on, or, all off. Try again.");
}

#endif

extern void setup_interpreter(void); // interpreter.cpp
void setup(void) {
    Serial.begin(115200);
    // Serial.println("What light shall we turn on or off?");
    pinMode(orangeLED,OUTPUT);
    pinMode(purpleLED,OUTPUT);
    pinMode(blueLED,OUTPUT);
    comReader.setCallback(readStr);
    setup_interpreter();
}

void loop(void) { idle(); }

// END.
