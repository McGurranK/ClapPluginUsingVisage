#include "PluginProcessor.h"
#include "PluginEditor.h"


VisagePluginAudioProcessor::VisagePluginAudioProcessor()
     : AudioProcessor (BusesProperties()
                       .withInput  ("Input",  juce::AudioChannelSet::stereo(), true)
                       .withOutput ("Output", juce::AudioChannelSet::stereo(), true))
{
}

VisagePluginAudioProcessor::~VisagePluginAudioProcessor()
{
}

const juce::String VisagePluginAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool VisagePluginAudioProcessor::acceptsMidi() const
{
    return false;
}

bool VisagePluginAudioProcessor::producesMidi() const
{
    return false;
}

bool VisagePluginAudioProcessor::isMidiEffect() const
{
    return false;
}

double VisagePluginAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int VisagePluginAudioProcessor::getNumPrograms()
{
    return 1;
}

int VisagePluginAudioProcessor::getCurrentProgram()
{
    return 0;
}

void VisagePluginAudioProcessor::setCurrentProgram (int index)
{
}

const juce::String VisagePluginAudioProcessor::getProgramName (int index)
{
    return {};
}

void VisagePluginAudioProcessor::changeProgramName (int index, const juce::String& newName)
{
}

void VisagePluginAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
}

void VisagePluginAudioProcessor::releaseResources()
{
}

bool VisagePluginAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
    if (layouts.getMainOutputChannelSet() != juce::AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo())
        return false;

    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;

    return true;
}

void VisagePluginAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    juce::ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        auto* channelData = buffer.getWritePointer (channel);
    }
}

//==============================================================================
bool VisagePluginAudioProcessor::hasEditor() const
{
    return true;
}

juce::AudioProcessorEditor* VisagePluginAudioProcessor::createEditor()
{
    return new VisagePluginAudioProcessorEditor (*this);
}

void VisagePluginAudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
}

void VisagePluginAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
}

juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new VisagePluginAudioProcessor();
}
