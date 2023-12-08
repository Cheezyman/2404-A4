#ifndef PODCASTPLAYER_H
#define PODCASTPLAYER_H

#include "Episode.h"
#include <iostream>

class PodcastPlayer
{
public:
    // Pure virtual function to play an episode
    virtual void play(const Episode &episode, std::ostream &os) const = 0;
};

class AudioPlayer : public virtual PodcastPlayer
{
public:
    void play(const Episode &episode, std::ostream &ost) const override;
};

class VideoPlayer : public AudioPlayer
{
public:
    void play(const Episode &episode, std::ostream &ost) const override;
};

#endif