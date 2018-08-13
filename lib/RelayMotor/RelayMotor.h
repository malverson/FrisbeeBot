#ifndef RELAYMOTOR_H
#define RELAYMOTOR_H
/*
 * class RelayMotor(PinFwd, PinBwd)
 *  Class to control a Relay Motor controler
 *
 * void Set(Direction)
 *  Function to set the motor direction
 *  Direction is an enum with Fwd, Bwd, and Stop
 *
 * void Off()
 *  Function to kill the motor controller,
 *  for motor safety
 *
 */

enum Direction {
	Fwd,
	Bwd,
	Stop
};

class RelayMotor {
	private:
		int m_pin_fwd;
		int m_pin_bwd;

	public:
		RelayMotor(int pin_fwd, int pin_bwd);
		~RelayMotor();

		void Set(Direction newDirection);
		void Off();
};

#endif