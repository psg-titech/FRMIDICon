#include <Arduino.h>
#include <MIDI.h>
#include <Wire.h>

#include "FRMIDICon.h"

// #define DEBUG

#define SYNTH_CH 1

MIDI_CREATE_DEFAULT_INSTANCE();

void sendNoteOn(int note, int vel) {
#if defined(DEBUG)
    Serial.print("noteOn: ");
    Serial.print(note, 16);
    Serial.print(" ");
    Serial.println(vel);
#endif
    MIDI.sendNoteOn((uint8_t)note, (uint8_t)vel, SYNTH_CH);
}

void sendNoteOff(int note, int vel) {
#if defined(DEBUG)
    Serial.print("noteOff: ");
    Serial.print(note, 16);
    Serial.print(" ");
    Serial.println(vel);
#endif
    MIDI.sendNoteOff((uint8_t)note, (uint8_t)vel, SYNTH_CH);
}

void sendCC(int cc, int val) {
#if defined(DEBUG)
    Serial.print("cc ");
    Serial.print(cc, 16);
    Serial.print(" ");
    Serial.println(val, 16);
#endif
    MIDI.sendControlChange((uint8_t)cc, (uint8_t)val, SYNTH_CH);
}

void setup_VRA8_1() {
    // RESET
    sendCC(121, 0);
    // ALL SOUNDS OFF
    // sendCC(120, 0, ch);

    // Osc 1 Wave: 0 saw, 64 tri, 96 pulse, 127 square
    sendCC(24, 0);
    // Osc 1 Shape
    sendCC(102, 0);
    // Osc 1 Morph
    sendCC(103, 0);
    // Mixer Sub Osc
    sendCC(26, 0);
    // Osc 2 Wave: 0 saw, 64 tri, 96 pulse, 127 square
    sendCC(55, 127);
    // Osc 2 Coarse
    sendCC(20, 64 + 7);
    // Osc 2 Fine
    sendCC(21, 64);

    // Filter Cutoff
    sendCC(16, 127);
    // Filter Resonance
    sendCC(17, 0);
    // Filter EG
    sendCC(18, 64);

    // LFO Wave (Triangle)
    sendCC(14, 0);
    // LFO Rate (6.3Hz)
    sendCC(80, 96);
    // LFO Depth 
    sendCC(81, 127);
    // LFO OSC AMT
    sendCC(82, 64);
    // LFO Filter AMT
    sendCC(83, 64);

    // EG Attack
    sendCC(23, 0);
    // EG Decay
    sendCC(19, 0);
    // EG Sustain
    sendCC(27, 127);
    // EG Release
    sendCC(28, 0);

    // AMP Attack
    sendCC(56, 0);
    // AMP Decay
    sendCC(57, 0);
    // AMP Sustain
    sendCC(58, 127);
    // AMP Release
    sendCC(59, 0);

    // Patch Bend Range
    sendCC(85, 12);
}

#define TNone 0
#define TCC 1
#define TNoteOn 2
#define TNoteOff 3

enum in_type { IN_POT, IN_BTN };
struct in_t { in_type type; uint8_t pin; };

const in_t INPUTS[] = {
    { IN_POT, A6 },  // pot 1
    { IN_POT, A3 },  // pot 2
    { IN_POT, A2 },  // pot 3
    { IN_POT, A1 },  // pot 4
    { IN_POT, A0 },  // pot 5
    { IN_POT, A7 },  // pot 6
    { IN_POT, A8 },  // pot 7
    { IN_POT, A9 },  // pot 8
    { IN_BTN, 15 },  // left button
    { IN_BTN, 16 },  // right button
    { IN_BTN, 14 }   // mode button
};
#define NINPUTS ((int)(sizeof(INPUTS) / sizeof(in_t)))
int in_idx = 0;
int in_v1[NINPUTS];

#define LED_PIN 10
#define ENCA_PIN 5
#define ENCB_PIN 7

int enca, enca1, encar, encar1;
int encb, encb1, encbr, encbr1;

int bpm = 120;

unsigned long t = 0;
bool note_on = true;

uint8_t notes[] = { 45, 45, 52, 52, 55, 55, 53, 53 };
#define NNOTES ((int)(sizeof(notes) / sizeof(uint8_t)))
int note_idx = 0;

void Input(int *idx, int *iv, int *iv1) {
    unsigned long t1 = millis();
    if (t1 - t >=  6000 / bpm) {
        *iv = *iv1 = notes[note_idx];
        if (note_on) {
            *idx = 11;
            note_on = false;
            digitalWrite(LED_PIN, HIGH);
        }
        else {
            *idx = 12;
            note_on = true;
            note_idx = (note_idx + 1) % NNOTES;
            digitalWrite(LED_PIN, LOW);
        }
        t = t1;
        return;
    }
    *idx = in_idx;
    *iv1 = in_v1[in_idx];
    switch (INPUTS[in_idx].type) {
        case IN_POT:
            *iv = analogRead(INPUTS[in_idx].pin) / 8;
            break;
        case IN_BTN:
            *iv = digitalRead(INPUTS[in_idx].pin);
            break;
    }
    in_v1[in_idx] = *iv;
    in_idx = (in_idx + 1) % NINPUTS;
/*
    encar = digitalRead(ENCA_PIN);
    if (encar == encar1) enca = encar;
    encar1 = encar;
    encbr = digitalRead(ENCB_PIN);
    if (encbr == encbr1) encb = encbr;
    encbr1 = encbr;

    if (!enca && enca1 && encb && encb1) {
        if (bpm < 240) bpm++;
#if defined(DEBUG)
        Serial.print("bpm: ");
        Serial.println(bpm);
#endif
    }
    else if (enca && enca1 && !encb && encb1) {
        if (bpm > 1) bpm--;
#if defined(DEBUG)
        Serial.print("bpm: ");
        Serial.println(bpm);
#endif
    }
*/
}

void Output(int *outt, int *outx, int *outy) {
    switch (*outt) {
        case TNone:
#if defined(DEBUG)
            // Serial.print("none: ");
            // Serial.print(*outx);
            // Serial.print(" ");
            // Serial.println(*outy);
#endif
            break;
        case TCC:
            sendCC(*outx, *outy);
            break;
        case TNoteOn:
            sendNoteOn(*outx, *outy);
            break;
        case TNoteOff:
            sendNoteOff(*outx, *outy);
            break;
    }
}

void setup() {
#if defined(DEBUG)
    Serial.begin(115200);
    while (!Serial);
    Serial.println("FRMIDICon");
#endif
    ADCSRA &= 0xf8;
    ADCSRA |= 0x04;
    MIDI.begin(4);
    setup_VRA8_1();

    pinMode(LED_PIN, OUTPUT);
    pinMode(ENCA_PIN, INPUT_PULLUP);
    pinMode(ENCB_PIN, INPUT_PULLUP);

    enca = enca1 = encar = encar1 = digitalRead(ENCA_PIN);
    encb = encb1 = encbr = encbr1 = digitalRead(ENCB_PIN);

    for (int i = 0; i < NINPUTS; i++) {
        if (INPUTS[i].type == IN_POT) {
            in_v1[i] = analogRead(INPUTS[i].pin) / 8;
        }
        else if (INPUTS[i].type == IN_BTN) {
            pinMode(INPUTS[i].pin, INPUT_PULLUP);
            in_v1[i] = digitalRead(INPUTS[i].pin);
        }
    }

    t = millis();
    ActivateFRMIDICon();
}

void loop() {}
