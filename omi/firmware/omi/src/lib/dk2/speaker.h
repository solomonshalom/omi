#ifndef SPEAKER_H
#define SPEAKER_H

#include <zephyr/kernel.h>
/**
 * @brief Initialize the Speaker
 *
 * Initializes the speaker
 *
 * @return 0 if successful, negative errno code if error
 */
int speaker_init();

/**
 * @brief Endpoint function for streaming audio
 *
 * Call this function in the following way (Via ble)
 * 1. Send a 2 byte packet containing the audio data size
 * 2. Send to the ble notify id 400 byte packets (with notify), with each 2 bytes being the audio data
 * 3. Repeat step 2 until the audio data is sent. Then the speaker will automatically play the sound
 * when the audio data sent is equal to the audio data size sent in step 1
 * 
 * @return The amount of data successfully sent in bytes.
 */
uint16_t speak(uint16_t len, const void *buf);

/**
 * @brief Play a chime effect
 *
 * This function plays a chime effect. Use this to check if the speaker works correctly
 *
 * @return 0 if successful, negative errno code if error
 */
int play_boot_sound();

void speaker_off();

void register_speaker_service();

#endif
