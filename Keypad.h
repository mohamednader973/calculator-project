/*
 * Keypad.h
 *
 * Created: 9/13/2020 1:38:59 AM
 *  Author: monad
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_
void Keypad_Init(void);
void Check_Key (unsigned char* num,unsigned char* check);
char key_pressed (void);

#endif /* KEYPAD_H_ */