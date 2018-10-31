//
// Created by Josh Kall and Chris Erattuparambil on 10/24/2018.
//

#include "song.h"


//Constructors

Song::Song(string a, string t){
   title = t;
   artist = a;
   size = 1;
}

Song::Song(string a, string t, int s){
   title = t;
   artist = a;
   size = s;
}

// Getters
string Song::getTitle(){
    return title;
}

int Song::getSize(){
    return size;
}

string Song::getArtist(){
    return artist;
}

//Setters
void Song::setTitle(string t)
{
    title=t;
}

void Song::setArtist(string a){
    artist=a;
}

void Song::setSize(int newsize)
{
    size=newsize;
}

//Operator Overides
/*Using this operator on two instances of the
 * Song class will first compare the artists, then
 * the title, then the size. It returns true if the compared
 * song's artist or title comes alphabetically after this song or
 * if the compared song's size is larger than this
 * song. Otherwise it returns false*/
bool Song::operator >(Song const &rhs){
    if((this->artist.compare(rhs.artist)) > 0){
        return true;
    }else if((this->artist.compare(rhs.artist)) < 0){
        return false;
    }else{
        if((this->title.compare(rhs.title)) > 0){
            return true;
        }else if((this->title.compare(rhs.title)) < 0){
            return false;
        }else{
            if(this->size < rhs.size){
                return true;
            }else if(this->size > rhs.size){
                return false;
            }else{
                return false;
            }
        }
    }
}

/*Using this operator on two instances of the
 * Song class will first compare the artists, then
 * the title, then the size. It returns true if the compared
 * song's artist or title comes alphabetically before this song or
 * if the compared song's size is smaller than this
 * song. Otherwise it returns false*/

bool Song::operator <(Song const &rhs){
    if((this->artist.compare(rhs.artist)) > 0){
        return false;
    }else if((this->artist.compare(rhs.artist)) < 0){
        return true;
    }else{
        if((this->title.compare(rhs.title)) > 0){
            return false;
        }else if((this->title.compare(rhs.title)) < 0){
            return true;
        }else{
            if(this->size < rhs.size){
                return false;
            }else if(this->size > rhs.size){
                return true;
            }else{
                return false;
            }
        }
    }
}

/*Using this operator on two instances of the
 * Song class returns true if the artist, title, and
 * size of the two songs are identical, otherwise it
 * returns false*/
bool Song::operator ==(Song const &rhs) {
    if((this->artist.compare(rhs.artist)) == 0) {
        if ((this->title.compare(rhs.title)) == 0) {
            if (this->size == rhs.size) {
                return true;
            }
        }
    }else{
        return false;
    }
}