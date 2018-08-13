#include <Arduino.h>
#include <XBOXRECV.h>
#include <Timer.h>
#include "RelayMotor.h"
#include "Map.h"

USB Usb;
XBOXRECV Xbox(&Usb);

RelayMotor aim(AIM_UP, AIM_DOWN);

void setup() {
	if (Usb.Init() == -1) {
		while (1); // halt
	}
	pinMode(7, OUTPUT);
	pinMode(8, OUTPUT);
}

void loop() {
	// put your main code here, to run repeatedly:
	Usb.Task();

	if (Xbox.XboxReceiverConnected) {
		for (uint8_t i = 0; i < 4; i++) {
			if (Xbox.Xbox360Connected[i]) {

				if (Xbox.getButtonPress(L1, i)) {
					// aim.Set(Direction::Bwd);
					digitalWrite(7, LOW);
					digitalWrite(8, HIGH);

				}
				else if (Xbox.getButtonPress(R1, i)) {
					// aim.Set(Direction::Fwd);
					digitalWrite(7, HIGH);
					digitalWrite(8, LOW);
				}
				else {
					// aim.Set(Direction::Stop);
					digitalWrite(7, LOW);
					digitalWrite(8, LOW);
				}
			}
		}
	}
	// Receiver not connected
	aim.Off();
}