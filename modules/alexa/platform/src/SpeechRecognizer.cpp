/*
 * Copyright 2017-2018 Amazon.com, Inc. or its affiliates. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License").
 * You may not use this file except in compliance with the License.
 * A copy of the License is located at
 *
 *     http://aws.amazon.com/apache2.0/
 *
 * or in the "license" file accompanying this file. This file is distributed
 * on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
 * express or implied. See the License for the specific language governing
 * permissions and limitations under the License.
 */

#include "AACE/Alexa/SpeechRecognizer.h"

namespace aace {
namespace alexa {

SpeechRecognizer::SpeechRecognizer( bool wakewordDetectionEnabled ) : m_wakewordDetectionEnabled( wakewordDetectionEnabled ) {
}

SpeechRecognizer::~SpeechRecognizer() = default; // key function

bool SpeechRecognizer::holdToTalk() {
    return m_speechRecognizerEngineInterface != nullptr && m_speechRecognizerEngineInterface->onHoldToTalk();
}

bool SpeechRecognizer::tapToTalk() {
    return m_speechRecognizerEngineInterface != nullptr && m_speechRecognizerEngineInterface->onTapToTalk();
}

bool SpeechRecognizer::stopCapture() {
    return m_speechRecognizerEngineInterface != nullptr && m_speechRecognizerEngineInterface->onStopCapture();
}

ssize_t SpeechRecognizer::write( const int16_t* data, const size_t size ) {
    return m_speechRecognizerEngineInterface != nullptr ? m_speechRecognizerEngineInterface->write( data, size ) : 0;
}

bool SpeechRecognizer::enableWakewordDetection() 
{
    m_wakewordDetectionEnabled = true;

    return m_speechRecognizerEngineInterface != nullptr && m_speechRecognizerEngineInterface->enableWakewordDetection();
}

bool SpeechRecognizer::disableWakewordDetection() 
{
    m_wakewordDetectionEnabled = false;

    return m_speechRecognizerEngineInterface != nullptr && m_speechRecognizerEngineInterface->disableWakewordDetection();
}

bool SpeechRecognizer::isWakewordDetectionEnabled() {
    return m_wakewordDetectionEnabled;
}

bool SpeechRecognizer::wakewordDetected( const std::string& wakeword ) {
    return true;
}

void SpeechRecognizer::endOfSpeechDetected() {
}

void SpeechRecognizer::setEngineInterface( std::shared_ptr<aace::alexa::SpeechRecognizerEngineInterface> speechRecognizerEngineInterface ) {
    m_speechRecognizerEngineInterface = speechRecognizerEngineInterface;
}

} // aace::alexa
} // aac
