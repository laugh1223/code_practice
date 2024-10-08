﻿#pragma once

#include "../BasicUsageEnvironment/UsageEnvironment.h"
#include "Sink.h"
#include "MediaSource.h"

class AACFileSink : public Sink
{
public:
    static AACFileSink* createNew(UsageEnvironment* env, MediaSource* mediaSource);;
    
    AACFileSink(UsageEnvironment* env, MediaSource* mediaSource, int payloadType);
    virtual ~AACFileSink();

    virtual std::string getMediaDescription(uint16_t port);
    virtual std::string getAttribute();

protected:
    virtual void sendFrame(MediaFrame* frame);

private:
    RtpPacket mRtpPacket;   //rtp包
    uint32_t mSampleRate;   // 采样频率
    uint32_t mChannels;     // 通道数
    int mFps;   //帧率
};