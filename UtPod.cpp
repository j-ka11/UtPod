//
// Created by Josh Kall and Chris Erattuparambil on 10/29/2018.
//
#include "UtPod.h"


UtPod::UtPod(){
    memSize = MAX_MEMORY;
    return;
}

UtPod::UtPod(int s)
{
   if(s<0||s>MAX_MEMORY)
   {
       memSize = MAX_MEMORY;
   }
   else
   {
       memSize=s;
   }
}

UtPod::~UtPod()
{

}


int UtPod::addSong(Song const &s){
    SongNode *temp;
    temp=songs;
    songs->s=s;
    songs->next=temp;
}



int UtPod::removeSong(Song const &s){
    SongNode *temp;
    SongNode *trailer;
    if(songs->s == s)
    {songs=songs->next;
    }else{
        temp=songs->next;
        trailer=songs;
        if(temp->s == s) {
            trailer->next = temp->next;
        }else if(temp->next != NULL){
            temp = temp->next;
            trailer = trailer->next;
        } else{
            return NOT_FOUND;
        }
    }
    return SUCCESS;
}

void UtPod::shuffle(){

}

void UtPod::showSongList(){

}

void UtPod::sortSongList(){

}

int UtPod::getRemainingMemory(){

}
void UtPod::swap(SongNode const &n1, SongNode const &n2)
{

}