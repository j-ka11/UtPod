// Created by Chris Erattuparambil and Josh Kall on 10/24/2018.

/*#ifndef UTPOD_SONG_H
#define UTPOD_SONG_H

#endif //UTPOD_SONG_H


#endif //UTPOD_SONG_H*/
using namespace std;
#include <string>

class Song{
    private:
        string title;
        string artist;
        int size;
    public:
        void createSong();
        string getTitle(){
            return title;
        }
        string getArtist();

        int getSize();

        bool operator >(Song const &rhs);

        Song(string title, string artist, int size);
        Song(string title, string artist);
};

