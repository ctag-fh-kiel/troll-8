# SequenceRecorder

## Description

The SequenceRecorder plays an array fed with specific data in a relative time sequence. This means that each note entry in the array does not save the absolute time but the offset to the next note. 

In addition, the sequenceRecorder enables the device to record input from the ePiano and play this recording. The sequenceRecorder can record 50 notes with the limiting factor being the array size of the recording array. Increasing the array too much  in size can lead the device to be unstable since it is lacking resources.

## The recording array

The recording array is a 2 dimensional unsigned integer16 and can store 50 triplets. A value cannot excede 65535. Since the offset to the next note ist stored in milliseconds, an offset to the next note cannot be over 65 seconds!

```cpp
uint16_t recordingArray[50][3];
```

The triplets in the recording array consist of the following values:

[0] = Offset in milliseconds
[1] = NoteNumber for the ePiano
[2] = The velocity value 

A duration of the note ist not saved.

## Handling

The SequenceRecorder uses several Push buttons to control its functions:

**Push Button 1**: Plays stored sequence until the end
**Push Button 2**: Stops the playback of the sequence
**Push Button 3**: Resets the sequence to the start (starts from beginning)

**Push Button 8**: Starts the recording (First Note has no delay)
**Push Button 7**: Ends the recording session
**Push Button 6**: Deletes the recording

Leds highlight wether a playback is active or a recording session is active.

## How it works

The SequenceRecorder uses the mozzi class EventDelay to schedule notes played from the recording array. The object created  from this class is called *timeControl*.

The following snippet represents the main scheduling code:

```cpp
 if (timeControl.ready() && sequencerActive) {
    if (sequencerPlaying) {
      if ((sizeof(recordingArray) / sizeof(recordingArray[0])) > sequenceNumber ) {
        sequenceNumber++;
        timeControl.set(recordingArray[sequenceNumber][0]);
        timeControl.start();
        sequencerPlaying = false;
      }
      else { 
        //the sequencer loops
        sequenceNumber = 0;
      }
    }
  }
```

The recording is done in the updateControl() function and registers each note played when the recorder is active. The timing values are provided by the mozzi lib function 

```cpp
mozziMicros()
```

Mozzimicros returns a value in microseconds. Since the EventDelay class only accepts milliseconds, the recording array only stores the delay in milliseconds.
```cpp
   //start at first note
        if (recordingIndex == 0) {
          recordingArray[recordingIndex][0] = 0;
        } else {
          recordStartTime = mozziMicros() - recordStartTime ;
          recordingArray[recordingIndex-1][0] = recordStartTime / 1000;
   
          recordingArray[recordingIndex][0] = recordStartTime / 1000;
        }
        recordingArray[recordingIndex][1] = i;
        recordingArray[recordingIndex][2] = gain[i];
        recordingIndex++;
        //reset counter since we are using a relative time sequence
        recordStartTime = mozziMicros();
```

## Known Problems and possible solutions


1. The SequenceRecorder lacks proper duration support. Each note played fades out naturally or is cut off when the next note is played. This saves resources.

Possible Solution: Initiate a second EventDelay object and store quadruples instead of triplets so notes can be scheduled to only play in the duration provided.

2. It lacks true polyphony playback. The duration of the note ends with the fade out or if a next note has been scheduled. So if 2 notes have been scheduled at the same time, only the second note will be played. This problem has already been mitigated in the SequenceRecorder by using a look ahead method. If the offset to the next note is below 30ms, they will be scheduled to play at the same time. So at least 2 notes can be played at the same time.

Possible solution: Introduce duration timers and then schedule accordingly or look even more ahead.

3. After a recording has been saved, the first playback often times has problems and misses some notes. The following playbacks have mostly no problems.

Possible solution: No Idea. Could be some limited resource factor.



 


