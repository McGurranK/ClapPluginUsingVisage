/*
 * Basic plugin editor to attach visage too
 */

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

class VisagePluginAudioProcessorEditor final : public juce::AudioProcessorEditor
{
public:
    VisagePluginAudioProcessorEditor (VisagePluginAudioProcessor&);
    ~VisagePluginAudioProcessorEditor() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    VisagePluginAudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (VisagePluginAudioProcessorEditor)
};
