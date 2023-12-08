#include "PodcastPlayer.h"

#include <fstream>

// Assuming Episode class has a method getAudio() and a member videoFile

void AudioPlayer::play(const Episode &episode, std::ostream &ost) const {
    ost << episode.getAudio(); 
}



void VideoPlayer::play(const Episode &episode, std::ostream &ost) const
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