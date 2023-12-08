#ifndef PODIFY_H
#define PODIFY_H

#include <string>
#include <iostream>
#include "Podcast.h"
#include "Search.h"


class Podify
{
private:
    Array<Podcast*> podcasts;

public:
    Podify();
    ~Podify();
    void addPodcast(Podcast* podcast);
    void addEpisode(Episode* episode, const std::string& podcastTitle);
    const Array<Podcast*>& getPodcasts() const;
    Podcast* getPodcast(int index) const;
    Podcast* getPodcast(const std::string& title) const;
    void getEpisodes(const Search& searchCriteria, Array<Episode*>& outEpisodes);
};

#endif