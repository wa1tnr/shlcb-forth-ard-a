// Sat  5 Mar 12:59:24 UTC 2022

#include <serialStr.h>
#include <strTools.h>

#define blueLED   4
#define purpleLED 3
#define orangeLED 2

serialStr  comReader;

void setup() {
  Serial.begin(115200);
  Serial.println("What light shall we turn on or off?");
  pinMode(orangeLED,OUTPUT);
  pinMode(purpleLED,OUTPUT);
  pinMode(blueLED,OUTPUT);
  comReader.setCallback(readStr);
}

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

void readStr(char* inStr) {
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

void loop( void ) { idle(); }
// END.
