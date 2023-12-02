#include "Podify.h"

Podify::Podify() {
    // Constructor implementation if needed
}

Podify::~Podify() {
    for (int i = 0; i < podcasts.getSize(); ++i) {
        delete podcasts[i];  // Ensure your Array class supports this operation
    }
}

void Podify::addPodcast(Podcast* podcast) {
    if (podcast) {
        podcasts += podcast;  // Assuming your Array class has an overloaded += operator
    }
}

void Podify::addEpisode(Episode* episode, const std::string& podcastTitle) {
    for (int i = 0; i < podcasts.getSize(); ++i) {
        if (podcasts[i]->equals(podcastTitle)) {
            podcasts[i]->add(episode);
            break;
        }
    }
}

const Array<Podcast*>& Podify::getPodcasts() const {
    return podcasts;
}

Podcast* Podify::getPodcast(int index) const {
    if (index >= 0 && index < podcasts.getSize()) {
        return podcasts[index];
    }
    return nullptr; // or throw an exception
}

Podcast* Podify::getPodcast(const std::string& title) const {
    for (int i = 0; i < podcasts.getSize(); ++i) {
        if (podcasts[i]->equals(title)) {
            return podcasts[i];
        }
    }
    return nullptr; // or throw an exception
}

void Podify::getEpisodes(const Search& searchCriteria, Array<Episode*>& outEpisodes) {
    for (int i = 0; i < podcasts.getSize(); ++i) {
        Podcast* podcast = podcasts[i];
        for (int j = 0; j < podcast->getSize(); ++j) {
            Episode* episode = podcast->get(j);
            if (searchCriteria.matches(episode)) {
                outEpisodes += episode; // Assuming the Array class has an overloaded += operator
            }
        }
    }
}
