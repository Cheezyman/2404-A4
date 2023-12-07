#ifndef PODCASTPLAYER_H
#define PODCASTPLAYER_H

#include "Episode.h"
#include <iostream>

class PodcastPlayer
{
public:
    // Pure virtual function to play an episode
    virtual void play(const Episode &episode, std::ostream &os) = 0;

    // Virtual destructor for safe polymorphic use
    virtual ~PodcastPlayer() {}
};

#endif // PODCASTPLAYER_H
