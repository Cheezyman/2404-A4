#ifndef VIDEOPLAYER_H
#define VIDEOPLAYER_H

#include "AudioPlayer.h"
#include <fstream>

class VideoPlayer : public AudioPlayer
{
public:
    void play(const Episode &episode, std::ostream &ost) const override
    {
        // First play audio using the base class implementation
        AudioPlayer::play(episode, ost);

        // Then play video
        std::ifstream videoFile(episode.getVideoFile());
        if (videoFile.is_open())
        {
            std::string line;
            while (std::getline(videoFile, line))
            {
                ost << line << std::endl;
            }
            videoFile.close();
        }
        else
        {
            ost << "Error opening video file: " << episode.getVideoFile() << std::endl;
        }
    }
};

#endif // VIDEOPLAYER_H
