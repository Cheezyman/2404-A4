#ifndef EPISODE_H
#define EPISODE_H

#include <string>
#include <iostream>

class Episode
{
private:
    std::string podcastTitle;
    std::string host;
    std::string episodeTitle;
    std::string category;
    std::string audio;
    std::string videoFile;

public:
    Episode(const std::string &podcastTitle, const std::string &host,
            const std::string &episodeTitle, const std::string &category,
            const std::string &audio, const std::string &videoFile);

    // Getters
    std::string getPodcastTitle() const;
    std::string getHost() const;
    std::string getEpisodeTitle() const;
    std::string getCategory() const;
    std::string getAudio() const;
    std::string getVideoFile() const;

    void print(std::ostream &out) const;

    friend std::ostream &operator<<(std::ostream &out, const Episode &episode);
};

#endif // EPISODE_H
