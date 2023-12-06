#ifndef AUDIOPLAYER_H
#define AUDIOPLAYER_H

#include "PodcastPlayer.h"

class AudioPlayer : public PodcastPlayer
{
public:
    void play(const Episode &episode, std::ostream &ost) const override
    {
        ost << "Playing Audio: " << episode.getAudio() << std::endl;
    }
};

#endif // AUDIOPLAYER_H
