<<<<<<< HEAD
// Created by Chris Erattuparambil and Josh Kall on 10/24/2018.

/*#ifndef UTPOD_SONG_H
#define UTPOD_SONG_H

#endif //UTPOD_SONG_H


#endif //UTPOD_SONG_H*/
using namespace std;
#include <string>

class Song{
private:
    string artist;
    string title;
    int size;
public:
    string getTitle() const;
    string getArtist() const;
    int getSize() const;

    void setTitle(string t);
    void setArtist(string a);
    void setSize(int size);

    bool operator >(Song const &rhs);
    bool operator <(Song const &rhs);
    bool operator ==(Song const &rhs);
    bool operator !=(Song const &rhs);

    Song();
    Song(string artist, string title, int size);
    Song(string artist, string title);
};

=======
// Created by Chris Erattuparambil and Josh Kall on 10/24/2018.

/*#ifndef UTPOD_SONG_H
#define UTPOD_SONG_H

#endif //UTPOD_SONG_H


#endif //UTPOD_SONG_H*/
using namespace std;
#include <string>

class Song{
    private:
        string artist;
        string title;
        int size;
    public:
        string getTitle() const;
        string getArtist() const;
        int getSize() const;

        void setTitle(string t);
        void setArtist(string a);
        void setSize(int size);

        bool operator >(Song const &rhs);
        bool operator <(Song const &rhs);
        bool operator ==(Song const &rhs);
        bool operator !=(Song const &rhs);

        Song();
        Song(string artist, string title, int size);
        Song(string artist, string title);
};

>>>>>>> be59f58a0e88fee5a203080fc63b7bdf9d809f6b
