#include "Episode.h"

Episode::Episode(const std::string &podcastTitle, const std::string &host,
				 const std::string &episodeTitle, const std::string &category,
				 const std::string &audio, const std::string &videoFile)
	: podcastTitle(podcastTitle), host(host), episodeTitle(episodeTitle),
	  category(category), audio(audio), videoFile(videoFile) {}

std::string Episode::getPodcastTitle() const { return podcastTitle; }
std::string Episode::getHost() const { return host; }
std::string Episode::getEpisodeTitle() const { return episodeTitle; }
std::string Episode::getCategory() const { return category; }
std::string Episode::getAudio() const { return audio; }
std::string Episode::getVideoFile() const { return videoFile; }

void Episode::print(std::ostream &out) const
{
	out << "Podcast Title: " << podcastTitle << "\n"
		<< "Host: " << host << "\n"
		<< "Episode Title: " << episodeTitle << "\n"
		<< "Category: " << category << "\n";
}

std::ostream &operator<<(std::ostream &out, const Episode &episode)
{
	episode.print(out);
	return out;
}
