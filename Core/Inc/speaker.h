/*
 * @file speaker.h
 * @brief Speaker utility
 *
 * @author Garrett Knuf
 * @date 4/15/2024
 */

#ifndef INC_SPEAKER_H_
#define INC_SPEAKER_H_

typedef enum {
	NOTE_OFF,
	NOTE_C4,
	NOTE_C4_SHARP,
	NOTE_D4,
	NOTE_D4_SHARP,
	NOTE_E4,
	NOTE_F4,
	NOTE_F4_SHARP,
	NOTE_G4,
	NOTE_G4_SHARP,
	NOTE_A4,
	NOTE_A4_SHARP,
	NOTE_B4,
	NUM_NOTES
} note_t;


/**
 * @brief Initialize speaker interface.
 */
void Speaker_Init(void);

/**
 * @brief Set tone (frequency of speaker)
 * @param note (note_t) - note to play
 */
void Speaker_SetTone(note_t note);

#endif /* INC_SPEAKER_H_ */
