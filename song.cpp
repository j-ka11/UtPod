//
// Created by chris_d0m8an5 on 10/24/2018.
//

#include "song.h"

//Constructors
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
// Getters
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

