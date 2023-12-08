#include "Podify.h"
    
// constructor
Podify::Podify() {}

// destructor
Podify::~Podify() {
    for(int i = 0; i < podcasts.getSize(); i++){
        delete podcasts[i];
    }
}

void Podify::addPodcast(Podcast* podcast) {
    if (podcasts.isFull()){
        cerr << "Not enough space for new Podcasts. Podcast not added!"<<endl;
        return;
    }
    podcasts.add(podcast);  // Use the add method instead of operator+=     
}


void Podify::addEpisode(Episode* episode, const std::string& podcastTitle) {
    for (int i = 0; i < podcasts.getSize(); ++i) {
        if (podcasts[i]->equals(podcastTitle)) {
            podcasts[i]->add(episode);
            return;
        }
    }
    cerr << "Podcast not found. Episode not added!" << endl;
}

const Array<Podcast*>& Podify::getPodcasts() const {
    return podcasts;
}

Podcast* Podify::getPodcast(int index) const {
    if (index >= 0 && index < podcasts.getSize()) {
        return podcasts[index];
    }
    cerr << "Index out of bounds. Podcast not found!" << endl;
    exit(1);
    return nullptr;                                                                                                                                                                                                                                            
}

Podcast* Podify::getPodcast(const std::string& title) const {
    for (int i = 0; i < podcasts.getSize(); ++i) {
        if (podcasts[i]->equals(title)) {
            return podcasts[i];
        }
    }
    cerr << "Podcast not found!" << endl;
    exit(1);
    return nullptr;                                                                                                                                                                                                                                              
}

void Podify::getEpisodes(const Search& searchCriteria, Array<Episode*>& outEpisodes) {
    for (int i = 0; i < podcasts.getSize(); ++i) {
        Podcast* podcast = podcasts[i];
        for (int j = 0; j < podcast->getSize(); ++j) {
            Episode* episode = podcast->get(j);
            if (searchCriteria.matches(episode)) {
                outEpisodes.add(episode);  // Use the add method instead of operator+=                                                                                                                                                                                                    
            }
        }
    }
}

