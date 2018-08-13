#include "RelayMotor.h"
#include <Arduino.h>

RelayMotor::RelayMotor(int pin_fwd, int pin_bwd) {
	pinMode(m_pin_fwd, OUTPUT);
	pinMode(m_pin_bwd, OUTPUT);
	digitalWrite(m_pin_fwd, LOW);
	digitalWrite(m_pin_bwd, LOW);
}

RelayMotor::~RelayMotor() {
}

void RelayMotor::Set(Direction newDirection) {
	switch (newDirection) {
		case Direction::Stop:
			digitalWrite(m_pin_fwd, LOW);
			digitalWrite(m_pin_bwd, LOW);
			break;
		case Direction::Fwd:
			digitalWrite(m_pin_fwd, HIGH);
			digitalWrite(m_pin_bwd, LOW);
			break;
		case Direction::Bwd:
			digitalWrite(m_pin_fwd, LOW);
			digitalWrite(m_pin_bwd, HIGH);
			break;
	}
}

void RelayMotor::Off() {
	digitalWrite(m_pin_fwd, LOW);
	digitalWrite(m_pin_bwd, LOW);
}
