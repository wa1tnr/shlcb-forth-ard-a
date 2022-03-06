// Sun  6 Mar 02:32:12 UTC 2022 ONLINE edit - captured from wokwi

// thanks to jim lee / Left Coast

// chasseur at best with 42196

#if 0
    [ https://wokwi.com/projects/325338912889242196 ] chasseur 01:34z Sunday 6 March

github:
    [ https://github.com/wa1tnr/shlcb-forth-ard-a ]
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
    int i = 0;
    int pos = 0;
    int counted = 0; // -1 very late change 00:07z
    // Serial.println(" xx hello yy  ");
    tib[pos] = '\0';



    while(inStr[i]) {
        counted++;
        #if 0
        Serial.print("  it is:  ");
        Serial.print(i);
        Serial.print("  ");
        Serial.print(inStr[i]);
        Serial.print("  ");
        #endif

        if (inStr[i] == '\r' ||
            inStr[i] == '\n' ||
            inStr[i] == ' ') {
              i++; // very late change 00:02z
              counted++; // even later change 00:09z
              #if 0
              Serial.println("  OKTHISOK  ");
              Serial.print(" length tib is: ");
              #endif
              int lenTib = strlen(tib);
              #if 0
              Serial.print(lenTib);
              Serial.print("  ");
              Serial.print(" entire tib is: ");
              Serial.print(tib);
              Serial.print(' ');
              #endif

              Serial.print(tib);
              Serial.print(' ');
 
              runword();
              tib[pos] = '\0';
              pos = 0;
                // tib[i] = inStr[i++];
                // tib[i] = '\0';
            }
        if(inStr[i]) {

          if (inStr[i] == ' ') Serial.println("TRAP");

          // Serial.print(" even more i  ");
          tib[pos++] = inStr[i]; i++;
          tib[pos] = '\0';
          #if 0

          Serial.print(" incremental tib: ");
          Serial.print(tib);
          Serial.print(' ');
          #endif

          // runword();
          // Serial.println("   LOWER DECK  ");
          int finLen = strlen(inStr); // finLen--;
          #if 0
          Serial.print("  finLen: ");
          Serial.print(finLen);
          Serial.print(" ");
          Serial.print("  counted: ");
          Serial.print(counted);
          Serial.print("  ");
          #endif
          if (finLen == counted) {
            #if 0
              Serial.print("  last tib is: ");
              Serial.print(tib);
              
              Serial.print("  ");
              Serial.print("  pos is: ");
              Serial.print(pos);
              Serial.print("  tib[pos]: ");
              Serial.print(tib[(pos-1)]);
              Serial.print("  ");
              #endif
              tib[pos] = '\0';
              // pos++;
              // tib[pos] = '\0';
              Serial.print(tib);
              Serial.println(' '); // end of line

              runword();
          }
        }
        // tib[0] = '\0';
        // iterate when tib has more than one word in it
    }
    global_iteration_counter++;
    Serial.print("counter: ");
    Serial.println(global_iteration_counter);
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
