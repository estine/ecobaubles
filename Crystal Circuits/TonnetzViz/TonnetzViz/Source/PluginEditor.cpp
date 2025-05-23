#include "PluginEditor.h"
#include <cmath>

TonnetzAudioProcessorEditor::TonnetzAudioProcessorEditor(TonnetzAudioProcessor& p)
    : AudioProcessorEditor(&p), processor(p)
{
    setSize(600, 400);
    startTimerHz(30); // update ~30fps
}

TonnetzAudioProcessorEditor::~TonnetzAudioProcessorEditor() {}


void TonnetzAudioProcessorEditor::timerCallback()
{
    auto newNotes = processor.getActiveNotes();
    DBG("Active notes count: " << newNotes.size());

    if (newNotes != currentActiveNotes)
    {
        currentActiveNotes = newNotes;
        repaint();
    }
}


void TonnetzAudioProcessorEditor::paint(juce::Graphics& g)
{

    g.fillAll(juce::Colours::black);

    const int rows = 23, cols = 12;
    const float radius = 15.0f;
    const float hexWidth = 2.5 * radius;
    const float hexHeight = std::sqrt(3.0f) * radius;

    juce::Font font(radius * 0.7f);
    g.setFont(font);

    const auto& notes = currentActiveNotes; // processor.getActiveNotes();

    for (int row = 0; row < rows; ++row)
    {
        for (int col = 0; col < cols; ++col)
        {
            float x = col * hexWidth * 0.75f + 50;
            float y = row * hexHeight + ((col % 2) ? hexHeight / 2 : 0) + 50;

            // Determine pitch class using fifths (horizontal) and thirds (vertical)
            int noteNumber = (7 * col + 3 * row) % 12;
            if (noteNumber < 0) noteNumber += 12;

            static const char* noteNames[] = {
                "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"
            };

            bool isActive = false;
            for (int octave = 0; octave < 11; ++octave)
            {
                if (notes.count(noteNumber + octave * 12) > 0)
                {
                    isActive = true;
                    break;
                }
            }

            g.setColour(isActive ? juce::Colours::orange : juce::Colours::grey);
            g.fillEllipse(x - radius, y - radius, radius * 2, radius * 2);
            g.setColour(juce::Colours::white);
            g.drawEllipse(x - radius, y - radius, radius * 2, radius * 2, 2.0f);
            g.drawText(noteNames[noteNumber], juce::Rectangle<float>(x - radius, y - radius, radius * 2, radius * 2),
                       juce::Justification::centred, false);
        }
    }
}
