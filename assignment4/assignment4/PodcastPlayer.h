#ifndef PODCASTPLAYER_H
#define PODCASTPLAYER_H

#include "Episode.h"
#include <iostream>

class PodcastPlayer
{
public:
    // Pure virtual function
    virtual void play(const Episode &episode, std::ostream &ost) const = 0;

    // Virtual destructor for proper cleanup of derived classes
    virtual ~PodcastPlayer() {}
};

#endif // PODCASTPLAYER_H
