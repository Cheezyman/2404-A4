#include "Podify.h"
#include <iostream>

void Podify::addPodcast(Podcast *podcast)
{
    podcasts.push_back(podcast);
}

void Podify::addEpisode(Episode *episode, const std::string &podcastTitle)
{
    for (auto &podcast : podcasts)
    {
        if (podcast->equals(podcastTitle))
        {
            podcast->add(episode);
            return;
        }
    }
    std::cerr << "Error: Podcast with title '" << podcastTitle << "' not found." << std::endl;
}

const std::vector<Podcast *> &Podify::getPodcasts() const
{
    return podcasts;
}

Podcast *Podify::getPodcast(int index) const
{
    if (index < 0 || index >= podcasts.size())
    {
        std::cerr << "Error: Index out of bounds." << std::endl;
        exit(1);
    }
    return podcasts[index];
}

Podcast *Podify::getPodcast(const std::string &title) const
{
    for (auto &podcast : podcasts)
    {
        if (podcast->equals(title))
        {
            return podcast;
        }
    }
    std::cerr << "Error: Podcast with title '" << title << "' not found." << std::endl;
    exit(1);
}

void Podify::getEpisodes(const Search &search, std::vector<Episode *> &outEpisodes) const
{
    // Implementation depends on the Search class structure
    // Iterate through all podcasts and episodes, and add matching episodes to outEpisodes
}
