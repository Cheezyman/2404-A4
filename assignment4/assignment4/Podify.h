#ifndef PODIFY_H
#define PODIFY_H

#include <vector>
#include <string>
#include "Podcast.h"
#include "Episode.h"
#include "Search.h" // Assuming you have a Search class defined elsewhere

class Podify
{
private:
    std::vector<Podcast *> podcasts;

public:
    void addPodcast(Podcast *podcast);
    void addEpisode(Episode *episode, const std::string &podcastTitle);
    const std::vector<Podcast *> &getPodcasts() const;
    Podcast *getPodcast(int index) const;
    Podcast *getPodcast(const std::string &title) const;
    void getEpisodes(const Search &search, std::vector<Episode *> &outEpisodes) const;
};

#endif // PODIFY_H
