#pragma once

#include <JuceHeader.h>

class MidiProcessor : AudioProcessorValueTreeState::Listener
{
public:
    explicit MidiProcessor (AudioProcessorValueTreeState& vts);
    ~MidiProcessor() override;

    void processMidiMsgsBlock (MidiBuffer& midi_messages);

private:
    void parameterChanged (const String& parameter_id, float new_value) override;

    int getNegHarmNn (int nn, int key);

    MidiBuffer p_midi_buffer_;

    AudioProcessorValueTreeState& apvts_;

    std::atomic<float>* is_on_;
    std::atomic<float>* cur_key_;

    bool state_changed_;
};