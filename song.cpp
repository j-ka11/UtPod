//
// Created by Josh Kall and Chris Erattuparambil on 10/24/2018.
//

#include "song.h"


Song::Song(string t, string a){
   title = t;
   artist = a;
   size = 1;
}

Song::Song(string t, string a, int s){
   title = t;
   artist = a;
   size = s;
}

int Song::getSize(){
    return size;
}

string Song::getArtist(){
    return artist;
}

bool Song::operator <(Song const &rhs){
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

bool Song::operator >(Song const &rhs){
    if((this->artist.compare(rhs.artist)) > 0){
        return false;
    }else if((this->artist.compare(rhs.artist)) < 0){
        return false;
    }
}

