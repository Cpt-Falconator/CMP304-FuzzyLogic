#pragma once
//Slimmed version of input class used in Y1
class Input {

public:
	//Keyboard registrations
	void setKeyDown(int key);
	void setKeyUp(int key);
	bool isKeyDown(int key);

private:
	//Holds keys for the keyboard
	bool keys[256]{ false };

};