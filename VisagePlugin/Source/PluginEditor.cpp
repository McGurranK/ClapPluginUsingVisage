/*
 * Basic plugin editor to attach visage too
 */

#include "PluginProcessor.h"
#include "PluginEditor.h"

VisagePluginAudioProcessorEditor::VisagePluginAudioProcessorEditor (VisagePluginAudioProcessor& p)
    : AudioProcessorEditor (&p)
    , audioProcessor (p)
{
    setSize (400, 300);
}

VisagePluginAudioProcessorEditor::~VisagePluginAudioProcessorEditor()
{
}

void VisagePluginAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));
}

void VisagePluginAudioProcessorEditor::resized()
{
}
