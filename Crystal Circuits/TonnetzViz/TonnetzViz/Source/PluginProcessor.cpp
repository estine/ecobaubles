#include "PluginProcessor.h"
#include "PluginEditor.h"

TonnetzAudioProcessor::TonnetzAudioProcessor()
    : AudioProcessor(BusesProperties()
        .withInput("Input", juce::AudioChannelSet::stereo(), true)
        .withOutput("Output", juce::AudioChannelSet::stereo(), true))
{
    // Allow MIDI
}

TonnetzAudioProcessor::~TonnetzAudioProcessor() {}

void TonnetzAudioProcessor::processBlock(juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    juce::ignoreUnused(buffer);

    for (const auto metadata : midiMessages)
    {
        const auto msg = metadata.getMessage();
        if (msg.isNoteOn())
        {
            activeNotes.insert(msg.getNoteNumber());
            DBG("Note On: " << msg.getNoteNumber());
        }
        else if (msg.isNoteOff())
        {
            activeNotes.erase(msg.getNoteNumber());
            DBG("Note Off: " << msg.getNoteNumber());
        }
    }
}

juce::AudioProcessorEditor* TonnetzAudioProcessor::createEditor()
{
    return new TonnetzAudioProcessorEditor(*this);
}

std::set<int> TonnetzAudioProcessor::getActiveNotes() const
{
    return activeNotes;
}

juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new TonnetzAudioProcessor();
}

void TonnetzAudioProcessor::prepareToPlay(double sampleRate, int samplesPerBlock)
{
    juce::ignoreUnused(sampleRate, samplesPerBlock);
    // Any needed setup can go here
}

void TonnetzAudioProcessor::releaseResources()
{
    // Any cleanup can go here
}

bool TonnetzAudioProcessor::isBusesLayoutSupported(const BusesLayout& layouts) const
{
    return layouts.getMainOutputChannelSet() == juce::AudioChannelSet::mono()
        || layouts.getMainOutputChannelSet() == juce::AudioChannelSet::stereo();
}

bool TonnetzAudioProcessor::hasEditor() const
{
    return true;
}

const juce::String TonnetzAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool TonnetzAudioProcessor::acceptsMidi() const
{
    return true;
}

bool TonnetzAudioProcessor::producesMidi() const
{
    return false;
}

bool TonnetzAudioProcessor::isMidiEffect() const
{
    return false;
}

double TonnetzAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int TonnetzAudioProcessor::getNumPrograms()
{
    return 1;
}

int TonnetzAudioProcessor::getCurrentProgram()
{
    return 0;
}

void TonnetzAudioProcessor::setCurrentProgram(int index)
{
    juce::ignoreUnused(index);
}

const juce::String TonnetzAudioProcessor::getProgramName(int index)
{
    juce::ignoreUnused(index);
    return {};
}

void TonnetzAudioProcessor::changeProgramName(int index, const juce::String& newName)
{
    juce::ignoreUnused(index, newName);
}

void TonnetzAudioProcessor::getStateInformation(juce::MemoryBlock& destData)
{
    // You can store plugin state here if needed
    juce::MemoryOutputStream stream(destData, true);
    // Example: stream.writeInt(42);
}

void TonnetzAudioProcessor::setStateInformation(const void* data, int sizeInBytes)
{
    // Restore plugin state here if needed
    juce::MemoryInputStream stream(data, static_cast<size_t> (sizeInBytes), false);
    // Example: int value = stream.readInt();
}

