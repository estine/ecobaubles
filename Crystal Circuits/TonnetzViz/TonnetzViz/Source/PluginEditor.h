#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

class TonnetzAudioProcessorEditor : public juce::AudioProcessorEditor,
                                    public juce::Timer
{
public:
    TonnetzAudioProcessorEditor(TonnetzAudioProcessor&);
    ~TonnetzAudioProcessorEditor() override;

    void paint(juce::Graphics&) override;
    void resized() override {}

    void timerCallback() override;
    std::set<int> currentActiveNotes;

private:
    TonnetzAudioProcessor& processor;

   //  void timerCallback() override { repaint(); }

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(TonnetzAudioProcessorEditor)
};
